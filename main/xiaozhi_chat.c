#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "esp_event.h"
#include "esp_heap_caps.h"
#include "esp_xiaozhi_chat.h"
#include "esp_xiaozhi_info.h"
#include "esp_mcp_engine.h"
#include "esp_opus_enc.h"
#include "esp_opus_dec.h"
#include "my_audio.h"
#include "wifi_manager.h"
#include "xiaozhi_chat.h"

#define TAG "xiaozhi_chat"

#define XZ_SAMPLE_RATE      16000
#define XZ_FRAME_MS         60
#define XZ_FRAME_SAMPLES    (XZ_SAMPLE_RATE * XZ_FRAME_MS / 1000)
#define XZ_OPUS_OUT_BUF_SZ  1024

#define XZ_CONN_BIT         (1 << 0)
#define XZ_CONN_TIMEOUT_MS  15000

typedef enum {
    XZ_STATE_IDLE = 0,
    XZ_STATE_CONNECTING,
    XZ_STATE_LISTENING,
    XZ_STATE_SPEAKING,
} xz_state_t;

static volatile xz_state_t s_state = XZ_STATE_IDLE;
static volatile bool s_active = false;
static volatile bool s_stop_req = false;
static volatile bool s_mic_streaming = false;

static xiaozhi_evt_cb_t s_evt_cb = NULL;
static TaskHandle_t s_session_task = NULL;
static TaskHandle_t s_mic_task = NULL;

static esp_xiaozhi_chat_handle_t s_chat_handle = 0;
static esp_mcp_t *s_mcp = NULL;
static void *s_opus_enc = NULL;
static void *s_opus_dec = NULL;
static bool s_event_registered = false;
static EventGroupHandle_t s_conn_events = NULL;

static uint8_t s_dec_pcm[XZ_FRAME_SAMPLES * 2 * 2];

static void emit(xiaozhi_evt_t evt, const char *text)
{
    if (s_evt_cb) {
        s_evt_cb(evt, text ? text : "");
    }
}

static void xz_audio_rx_cb(const uint8_t *data, int len, void *ctx)
{
    if (s_state != XZ_STATE_SPEAKING || s_opus_dec == NULL || len <= 0) {
        return;
    }
    esp_audio_dec_in_raw_t raw = {
        .buffer = (uint8_t *)data,
        .len = (uint32_t)len,
    };
    esp_audio_dec_out_frame_t out = {
        .buffer = s_dec_pcm,
        .len = sizeof(s_dec_pcm),
    };
    esp_audio_dec_info_t dec_info = {0};
    if (esp_opus_dec_decode(s_opus_dec, &raw, &out, &dec_info) == ESP_AUDIO_ERR_OK &&
        out.decoded_size > 0) {
        my_audio_write((const int16_t *)out.buffer, (int)(out.decoded_size / sizeof(int16_t)));
    }
}

static void xz_listen_now_internal(void)
{
    if (!s_active || s_chat_handle == 0) {
        return;
    }
    esp_err_t err = esp_xiaozhi_chat_send_start_listening(s_chat_handle,
                                                          ESP_XIAOZHI_CHAT_LISTENING_MODE_AUTO);
    if (err == ESP_OK) {
        s_state = XZ_STATE_LISTENING;
        s_mic_streaming = true;
        ESP_LOGI(TAG, "listen start ok, streaming=%d", s_mic_streaming);
        emit(XIAOZHI_EVT_LISTENING, NULL);
    } else {
        ESP_LOGW(TAG, "send start listening failed: %s", esp_err_to_name(err));
    }
}

static void xz_chat_evt_cb(esp_xiaozhi_chat_event_t event, void *event_data, void *ctx)
{
    switch (event) {
    case ESP_XIAOZHI_CHAT_EVENT_CHAT_TTS_STATE: {
        esp_xiaozhi_chat_tts_state_t *tts = (esp_xiaozhi_chat_tts_state_t *)event_data;
        if (tts == NULL) {
            break;
        }
        if (tts->state == ESP_XIAOZHI_CHAT_TTS_STATE_START) {
            s_state = XZ_STATE_SPEAKING;
            s_mic_streaming = false;
            if (s_opus_dec) {
                esp_opus_dec_reset(s_opus_dec);
            }
            emit(XIAOZHI_EVT_SPEAKING, NULL);
        } else if (tts->state == ESP_XIAOZHI_CHAT_TTS_STATE_STOP) {
            if (s_state == XZ_STATE_SPEAKING) {
                xz_listen_now_internal();
            }
        }
        break;
    }
    case ESP_XIAOZHI_CHAT_EVENT_CHAT_TEXT: {
        esp_xiaozhi_chat_text_data_t *text = (esp_xiaozhi_chat_text_data_t *)event_data;
        if (text == NULL || text->text == NULL) {
            break;
        }
        if (text->role == ESP_XIAOZHI_CHAT_TEXT_ROLE_USER) {
            emit(XIAOZHI_EVT_USER_TEXT, text->text);
        } else {
            emit(XIAOZHI_EVT_AI_TEXT, text->text);
        }
        break;
    }
    case ESP_XIAOZHI_CHAT_EVENT_CHAT_EMOJI:
        emit(XIAOZHI_EVT_EMOJI, (const char *)event_data);
        break;
    case ESP_XIAOZHI_CHAT_EVENT_CHAT_ERROR: {
        esp_xiaozhi_chat_error_info_t *err = (esp_xiaozhi_chat_error_info_t *)event_data;
        ESP_LOGE(TAG, "chat error from %s: %s", err ? err->source : "?",
                 err ? esp_err_to_name(err->code) : "?");
        emit(XIAOZHI_EVT_ERROR, err ? esp_err_to_name(err->code) : "error");
        break;
    }
    default:
        break;
    }
}

static void xz_esp_event_handler(void *arg, esp_event_base_t base, int32_t event_id, void *data)
{
    if (event_id == ESP_XIAOZHI_CHAT_EVENT_CONNECTED) {
        if (s_conn_events) {
            xEventGroupSetBits(s_conn_events, XZ_CONN_BIT);
        }
        emit(XIAOZHI_EVT_CONNECTED, NULL);
    } else if (event_id == ESP_XIAOZHI_CHAT_EVENT_DISCONNECTED) {
        if (s_conn_events) {
            xEventGroupClearBits(s_conn_events, XZ_CONN_BIT);
        }
        emit(XIAOZHI_EVT_DISCONNECTED, NULL);
    }
}

static void xz_mic_task(void *arg)
{
    int16_t *pcm = malloc(XZ_FRAME_SAMPLES * sizeof(int16_t));
    uint8_t *opus = malloc(XZ_OPUS_OUT_BUF_SZ);
    if (pcm == NULL || opus == NULL) {
        ESP_LOGE(TAG, "mic task alloc failed");
        free(pcm);
        free(opus);
        s_mic_task = NULL;
        vTaskDelete(NULL);
        return;
    }

    int fill = 0;
    uint32_t last_no_data_log = 0;
    uint32_t last_send_err_log = 0;
    int frames_sent = 0;

    while (!s_stop_req) {
        int got = my_audio_read(pcm + fill, XZ_FRAME_SAMPLES - fill);
        if (got <= 0) {
            uint32_t now = xTaskGetTickCount();
            if (now - last_no_data_log > pdMS_TO_TICKS(2000)) {
                ESP_LOGW(TAG, "mic read got=%d fill=%d", got, fill);
                last_no_data_log = now;
            }
            continue;
        }
        fill += got;
        if (fill < XZ_FRAME_SAMPLES) {
            continue;
        }
        fill = 0;
        if (!s_mic_streaming || s_opus_enc == NULL) {
            continue;
        }

        esp_audio_enc_in_frame_t in = {
            .buffer = (uint8_t *)pcm,
            .len = XZ_FRAME_SAMPLES * sizeof(int16_t),
        };
        esp_audio_enc_out_frame_t out = {
            .buffer = opus,
            .len = XZ_OPUS_OUT_BUF_SZ,
        };
        if (esp_opus_enc_process(s_opus_enc, &in, &out) == ESP_AUDIO_ERR_OK &&
            out.encoded_bytes > 0) {
            esp_err_t err = esp_xiaozhi_chat_send_audio_data(s_chat_handle,
                                                             (const char *)opus,
                                                             out.encoded_bytes);
            if (err != ESP_OK) {
                uint32_t now = xTaskGetTickCount();
                if (now - last_send_err_log > pdMS_TO_TICKS(2000)) {
                    ESP_LOGE(TAG, "mic send audio failed: %s", esp_err_to_name(err));
                    last_send_err_log = now;
                }
            } else if (frames_sent < 5) {
                ESP_LOGI(TAG, "mic frame sent: %d bytes", out.encoded_bytes);
                frames_sent++;
            }
        }
    }

    free(pcm);
    free(opus);
    s_mic_task = NULL;
    vTaskDeleteWithCaps(s_mic_task);
    //vTaskDelete(NULL);
}

static bool xz_open_codecs(void)
{
    esp_opus_dec_cfg_t dec_cfg = {
        .sample_rate = XZ_SAMPLE_RATE,
        .channel = ESP_AUDIO_MONO,
        .frame_duration = ESP_OPUS_DEC_FRAME_DURATION_60_MS,
        .self_delimited = false,
    };
    if (esp_opus_dec_open(&dec_cfg, sizeof(dec_cfg), &s_opus_dec) != ESP_AUDIO_ERR_OK ||
        s_opus_dec == NULL) {
        ESP_LOGE(TAG, "opus decoder open failed");
        return false;
    }

    esp_opus_enc_config_t enc_cfg = {
        .sample_rate = ESP_AUDIO_SAMPLE_RATE_16K,
        .channel = ESP_AUDIO_MONO,
        .bits_per_sample = ESP_AUDIO_BIT16,
        .bitrate = ESP_OPUS_BITRATE_AUTO,
        .frame_duration = ESP_OPUS_ENC_FRAME_DURATION_60_MS,
        .application_mode = ESP_OPUS_ENC_APPLICATION_AUDIO,
        .complexity = 0,
        .enable_fec = false,
        .enable_dtx = true,
        .enable_vbr = true,
    };
    if (esp_opus_enc_open(&enc_cfg, sizeof(enc_cfg), &s_opus_enc) != ESP_AUDIO_ERR_OK ||
        s_opus_enc == NULL) {
        ESP_LOGE(TAG, "opus encoder open failed");
        return false;
    }
    return true;
}

static void xz_close_codecs(void)
{
    if (s_opus_enc) {
        esp_opus_enc_close(s_opus_enc);
        s_opus_enc = NULL;
    }
    if (s_opus_dec) {
        esp_opus_dec_close(s_opus_dec);
        s_opus_dec = NULL;
    }
}

static void xz_teardown(void)
{
    s_mic_streaming = false;
    s_state = XZ_STATE_IDLE;

    for (int i = 0; i < 100 && s_mic_task != NULL; i++) {
        vTaskDelay(pdMS_TO_TICKS(10));
    }

    if (s_event_registered) {
        esp_event_handler_unregister(ESP_XIAOZHI_CHAT_EVENTS, ESP_EVENT_ANY_ID,
                                     xz_esp_event_handler);
        s_event_registered = false;
    }
    if (s_conn_events) {
        vEventGroupDelete(s_conn_events);
        s_conn_events = NULL;
    }
    if (s_chat_handle) {
        esp_xiaozhi_chat_stop(s_chat_handle);
        esp_xiaozhi_chat_deinit(s_chat_handle);
        s_chat_handle = 0;
    }
    if (s_mcp) {
        esp_mcp_destroy(s_mcp);
        s_mcp = NULL;
    }
    i2s_close();
    xz_close_codecs();
}

static void xz_session_task(void *arg)
{
    s_state = XZ_STATE_CONNECTING;
    if (!wifi_manager_sta_isconnect()) {
        emit(XIAOZHI_EVT_ERROR, "请先连接 WiFi");
        goto done;
    }
    emit(XIAOZHI_EVT_STATUS, "正在获取小智服务器信息...");

    esp_xiaozhi_chat_info_t info = {0};
    esp_err_t err = esp_xiaozhi_chat_get_info(&info);
    if (s_stop_req) {
        goto done;
    }
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "get info failed: %s", esp_err_to_name(err));
        emit(XIAOZHI_EVT_ERROR, "获取服务器信息失败,请检查网络");
        goto done;
    }

    if (info.has_activation_code) {
        ESP_LOGW(TAG, "device not activated, code: %s", info.activation_code);
        emit(XIAOZHI_EVT_ACTIVATION_CODE, info.activation_code);
        goto done;
    }
    if (!info.has_mqtt_config && !info.has_websocket_config) {
        emit(XIAOZHI_EVT_ERROR, "服务器未返回连接配置");
        goto done;
    }

    err = esp_mcp_create(&s_mcp);
    if (err != ESP_OK || s_mcp == NULL) {
        ESP_LOGE(TAG, "mcp create failed: %s", esp_err_to_name(err));
        emit(XIAOZHI_EVT_ERROR, "MCP 初始化失败");
        goto done;
    }

    if (!xz_open_codecs()) {
        emit(XIAOZHI_EVT_ERROR, "OPUS 编解码初始化失败");
        goto done;
    }

    /* MQTT 连接被服务器断开时(常见于网络环境限制),优先改用 WebSocket */
    bool use_websocket = info.has_websocket_config;

    esp_xiaozhi_chat_config_t config = ESP_XIAOZHI_CHAT_DEFAULT_CONFIG();
    config.audio_callback = xz_audio_rx_cb;
    config.event_callback = xz_chat_evt_cb;
    config.mcp_engine = s_mcp;
    config.owns_mcp_engine = false;
    config.has_mqtt_config = info.has_mqtt_config && !use_websocket;
    config.has_websocket_config = info.has_websocket_config;
    ESP_LOGI(TAG, "transport: %s", use_websocket ? "websocket" : "mqtt");

    err = esp_xiaozhi_chat_init(&config, &s_chat_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "chat init failed: %s", esp_err_to_name(err));
        emit(XIAOZHI_EVT_ERROR, "聊天初始化失败");
        goto done;
    }

    s_conn_events = xEventGroupCreate();
    err = esp_event_handler_register(ESP_XIAOZHI_CHAT_EVENTS, ESP_EVENT_ANY_ID,
                                     xz_esp_event_handler, NULL);
    s_event_registered = (err == ESP_OK);

    emit(XIAOZHI_EVT_STATUS, "正在连接小智服务器...");
    err = esp_xiaozhi_chat_start(s_chat_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "chat start failed: %s", esp_err_to_name(err));
        emit(XIAOZHI_EVT_ERROR, "连接服务器失败");
        goto done;
    }

    /* MQTT/WebSocket 客户端是异步连接的,必须等连上之后再发 hello */
    EventBits_t bits = xEventGroupWaitBits(s_conn_events, XZ_CONN_BIT, pdFALSE, pdTRUE,
                                           pdMS_TO_TICKS(XZ_CONN_TIMEOUT_MS));
    if (s_stop_req) {
        goto done;
    }
    if (!(bits & XZ_CONN_BIT)) {
        ESP_LOGE(TAG, "wait connect timeout");
        emit(XIAOZHI_EVT_ERROR, "连接服务器超时,请检查网络");
        goto done;
    }

    err = esp_xiaozhi_chat_open_audio_channel(s_chat_handle, NULL, NULL, 0);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "open audio channel failed: %s", esp_err_to_name(err));
        emit(XIAOZHI_EVT_ERROR, "音频通道打开失败");
        goto done;
    }
    if (s_stop_req) {
        goto done;
    }

    if (xTaskCreatePinnedToCoreWithCaps(xz_mic_task, "xz_mic", 24 * 1024, NULL, 6,
                                        &s_mic_task, tskNO_AFFINITY,
                                        MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT) != pdPASS) {
        ESP_LOGE(TAG, "xz_mic task create failed (PSRAM stack)");
        s_mic_task = NULL;
    } else {
        ESP_LOGI(TAG, "xz_mic task created (PSRAM stack)");
    }
    xz_listen_now_internal();

    while (!s_stop_req) {
        vTaskDelay(pdMS_TO_TICKS(100));
    }

done:
    esp_xiaozhi_chat_free_info(&info);
    xz_teardown();
    s_active = false;
    s_session_task = NULL;
    //vTaskDeleteWithCaps(s_mic_task);
    vTaskDelete(NULL);
}

esp_err_t xiaozhi_chat_start(xiaozhi_evt_cb_t cb)
{
    for (int i = 0; i < 100 && s_session_task != NULL; i++) {
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    if (s_session_task != NULL) {
        return ESP_ERR_INVALID_STATE;
    }

    s_evt_cb = cb;
    s_stop_req = false;
    s_active = true;
    if (xTaskCreate(xz_session_task, "xz_session", 16 * 1024, NULL, 5,
                    &s_session_task) != pdPASS) {
        s_active = false;
        s_session_task = NULL;
        return ESP_ERR_NO_MEM;
    }
    return ESP_OK;
}

void xiaozhi_chat_stop(void)
{
    s_stop_req = true;
}

void xiaozhi_chat_listen_now(void)
{
    xz_listen_now_internal();
}

void xiaozhi_chat_abort_speaking(void)
{
    if (!s_active || s_chat_handle == 0 || s_state != XZ_STATE_SPEAKING) {
        return;
    }
    if (s_opus_dec) {
        esp_opus_dec_reset(s_opus_dec);
    }
    esp_xiaozhi_chat_send_abort_speaking(s_chat_handle,
                                         ESP_XIAOZHI_CHAT_ABORT_SPEAKING_REASON_WAKE_WORD_DETECTED);
    xz_listen_now_internal();
}

bool xiaozhi_chat_is_active(void)
{
    return s_active;
}
