#include <stdio.h>
#include <string.h>
#include "lvgl.h"
#include "esp_lvgl_port.h"
#include "esp_log.h"
#include "gui_guider.h"
#include "xiaozhi_chat.h"
#include "xiaozhi_ui.h"
#include "my_audio.h"
#define TAG "xiaozhi_ui"

#define AI_TEXT_BUF_SZ 768

static lv_obj_t *s_scr = NULL;
static lv_obj_t *s_status_label = NULL;
static lv_obj_t *s_user_label = NULL;
static lv_obj_t *s_ai_label = NULL;
static lv_obj_t *s_btn_listen = NULL;
static lv_obj_t *s_btn_abort = NULL;
static bool xiaozhiui_first_init = true;
static char s_ai_buf[AI_TEXT_BUF_SZ];

static void xiaozhi_ui_evt(xiaozhi_evt_t evt, const char *text);

static bool ui_valid(void)
{
    return s_scr != NULL;
}

static void set_status(const char *text)
{
    lvgl_port_lock(0);
    if (ui_valid() && s_status_label) {
        lv_label_set_text(s_status_label, text);
    }
    lvgl_port_unlock();
}

static void xz_scr_delete_cb(lv_event_t *e)
{
    s_scr = NULL;
    s_status_label = NULL;
    s_user_label = NULL;
    s_ai_label = NULL;
    s_btn_listen = NULL;
    s_btn_abort = NULL;
}

static void xz_back_cb(lv_event_t *e)
{
    xiaozhi_chat_stop();
    lv_screen_load_anim(guider_ui.screen_second_page, LV_SCR_LOAD_ANIM_MOVE_RIGHT,
                        200, 0, true);
}

static void xz_listen_cb(lv_event_t *e)
{
    if (xiaozhi_chat_is_active()) {
        xiaozhi_chat_listen_now();
    } else {
        if (xiaozhi_chat_start(xiaozhi_ui_evt) != ESP_OK) {
            set_status("上一个会话还未结束,请稍候再试");
        }
    }
}

static void xz_abort_cb(lv_event_t *e)
{
    xiaozhi_chat_abort_speaking();
}

static void xz_scr_click_cb(lv_event_t *e)
{
    xiaozhi_chat_abort_speaking();
}

static lv_obj_t *make_label(lv_obj_t *parent, int x, int y, int w, int h,
                            const char *text, const lv_font_t *font, lv_color_t color)
{
    lv_obj_t *label = lv_label_create(parent);
    lv_obj_set_pos(label, x, y);
    lv_obj_set_size(label, w, h);
    lv_label_set_text(label, text);
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(label, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    return label;
}

static lv_obj_t *make_button(lv_obj_t *parent, int x, int y, int w, int h,
                             const char *text, lv_event_cb_t cb)
{
    lv_obj_t *btn = lv_button_create(parent);
    lv_obj_set_pos(btn, x, y);
    lv_obj_set_size(btn, w, h);
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, text);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(label, &lv_customer_font_ZiTiQuanWeiJunHeiW22_20,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(btn, cb, LV_EVENT_CLICKED, NULL);
    return btn;
}

static void xiaozhi_ui_create_screen(void)
{
    s_scr = lv_obj_create(NULL);
    lv_obj_set_size(s_scr, 320, 240);
    lv_obj_set_scrollbar_mode(s_scr, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(s_scr, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(s_scr, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(s_scr, xz_scr_delete_cb, LV_EVENT_DELETE, NULL);
    lv_obj_add_event_cb(s_scr, xz_scr_click_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t *back = lv_image_create(s_scr);
    lv_obj_set_pos(back, 10, 8);
    lv_obj_set_size(back, 32, 32);
    lv_obj_add_flag(back, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(back, &_back_RGB565A8_32x32);
    lv_obj_add_event_cb(back, xz_back_cb, LV_EVENT_CLICKED, NULL);

    make_label(s_scr, 52, 13, 200, 26, "小智 AI", &lv_customer_font_ZiTiQuanWeiJunHeiW22_20,
               lv_color_hex(0x000000));

    s_status_label = make_label(s_scr, 10, 44, 300, 26, "正在启动...",
                                &lv_customer_font_ZiTiQuanWeiJunHeiW22_20, lv_color_hex(0x666666));

    s_user_label = make_label(s_scr, 10, 74, 300, 52, "我: ",
                              &lv_customer_font_ZiTiQuanWeiJunHeiW22_20, lv_color_hex(0x0066cc));

    s_ai_label = make_label(s_scr, 10, 130, 300, 66, "小智: ",
                            &lv_customer_font_ZiTiQuanWeiJunHeiW22_20, lv_color_hex(0x000000));

    s_btn_listen = make_button(s_scr, 30, 202, 130, 30, "倾听", xz_listen_cb);
    s_btn_abort = make_button(s_scr, 180, 202, 130, 30, "打断", xz_abort_cb);
}

static void xiaozhi_ui_evt(xiaozhi_evt_t evt, const char *text)
{
    switch (evt) {
    case XIAOZHI_EVT_STATUS:
        set_status(text);
        break;
    case XIAOZHI_EVT_ACTIVATION_CODE: {
        char buf[192];
        snprintf(buf, sizeof(buf), "激活码: %s\n请到 xiaozhi.me 绑定后点\"倾听\"重试", text);
        set_status(buf);
        break;
    }
    case XIAOZHI_EVT_USER_TEXT:
        lvgl_port_lock(0);
        if (ui_valid()) {
            char buf[256];
            snprintf(buf, sizeof(buf), "我: %s", text);
            lv_label_set_text(s_user_label, buf);
            s_ai_buf[0] = '\0';
            lv_label_set_text(s_ai_label, "小智: ");
        }
        lvgl_port_unlock();
        break;
    case XIAOZHI_EVT_AI_TEXT:
        lvgl_port_lock(0);
        if (ui_valid()) {
            size_t used = strlen(s_ai_buf);
            if (used > 0 && used < sizeof(s_ai_buf) - 2) {
                strncat(s_ai_buf, "\n", sizeof(s_ai_buf) - used - 1);
            }
            strncat(s_ai_buf, text, sizeof(s_ai_buf) - strlen(s_ai_buf) - 1);
            char buf[AI_TEXT_BUF_SZ + 16];
            snprintf(buf, sizeof(buf), "小智: %s", s_ai_buf);
            lv_label_set_text(s_ai_label, buf);
        }
        lvgl_port_unlock();
        break;
    case XIAOZHI_EVT_LISTENING:
        set_status("倾听中...");
        break;
    case XIAOZHI_EVT_SPEAKING:
        set_status("小智说话中,点屏幕可打断");
        break;
    case XIAOZHI_EVT_CONNECTED:
        set_status("已连接服务器");
        break;
    case XIAOZHI_EVT_DISCONNECTED:
        set_status("已断开连接");
        break;
    case XIAOZHI_EVT_ERROR: {
        char buf[160];
        snprintf(buf, sizeof(buf), "错误: %s", text);
        set_status(buf);
        break;
    }
    case XIAOZHI_EVT_EMOJI:
        ESP_LOGI(TAG, "emotion: %s", text);
        break;
    default:
        break;
    }
}

void xiaozhi_ui_open(void)
{
    xiaozhi_ui_create_screen();
    if(xiaozhiui_first_init)
    {
        my_audio_init(SPEAKER_LRCLK,SPEAKER_BCLK,SPEAKER_SD,MICRO_CLK,MICRO_DATA);
        xiaozhiui_first_init = false;
    }
    i2s_open();
    lv_screen_load_anim(s_scr, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false);
    if (xiaozhi_chat_start(xiaozhi_ui_evt) != ESP_OK) {
        set_status("上一个会话还未结束,请稍候再试");
    }

}
