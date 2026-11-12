#include "my_audio.h"
#include "driver/i2s_common.h"
#include "esp_err.h"
#include "driver/i2s_std.h"
#include "driver/i2s_pdm.h"  
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "xl9555.h"

static i2s_chan_handle_t tx_handle_;
static i2s_chan_handle_t rx_handle_;
static int output_volume = 70;   /* 0-100 */
void my_audio_init(gpio_num_t lrclk,gpio_num_t bclk,gpio_num_t sd,gpio_num_t clk,gpio_num_t data)
{
    // Create a new channel for speaker
    //初始化喇叭
    xl9555_pin_write(IO0_0,1);
    i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_1,I2S_ROLE_MASTER);
    ESP_ERROR_CHECK(i2s_new_channel(&chan_cfg, &tx_handle_, NULL));

    i2s_std_config_t std_cfg = {
        .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG(16000),//用默认时钟
        .slot_cfg = I2S_STD_PHILIPS_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_32BIT,I2S_SLOT_MODE_MONO),
        .gpio_cfg = {
            .mclk = I2S_GPIO_UNUSED,
            .bclk = bclk,
            .ws = lrclk,
            .dout = sd,
            .din = I2S_GPIO_UNUSED,
            .invert_flags = {
                .mclk_inv = false,
                .bclk_inv = false,
                .ws_inv = false
            }
        }
    };
    std_cfg.slot_cfg.slot_mask = I2S_STD_SLOT_RIGHT;
    i2s_channel_init_std_mode(tx_handle_,&std_cfg);
    

    //初始化麦克风
    i2s_chan_config_t micro_chan = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_0,I2S_ROLE_MASTER);
    ESP_ERROR_CHECK(i2s_new_channel(&micro_chan, NULL,&rx_handle_));

    i2s_pdm_rx_config_t i2s_pdm_rx_cfg = {
        .clk_cfg = I2S_PDM_RX_CLK_DEFAULT_CONFIG(16000),
        .slot_cfg = I2S_PDM_RX_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_16BIT,I2S_SLOT_MODE_MONO),
        .gpio_cfg = {
            .clk = clk,
            .din = data,
        }
    };
    i2s_pdm_rx_cfg.slot_cfg.slot_mask = I2S_PDM_SLOT_RIGHT;
    i2s_channel_init_pdm_rx_mode(rx_handle_,&i2s_pdm_rx_cfg);

    // i2s_channel_enable(tx_handle_);
    // i2s_channel_enable(rx_handle_);
}
//关闭i2s通道
void i2s_close(void)
{
    i2s_channel_disable(tx_handle_);
    i2s_channel_disable(rx_handle_);
}
//开启i2s通道
void i2s_open(void)
{
    i2s_channel_enable(tx_handle_);
    i2s_channel_enable(rx_handle_);
}

//
// 写入到扬声器中，返回值样本数（字节 ÷ 4）
//
int my_audio_write(const int16_t *src, int samples)
{
    int32_t *buf = (int32_t *)malloc(samples * sizeof(int32_t));
    if (buf == NULL) return 0;

    /* 参照 no_audio_codec.cc:222-237: 音量平方+左移16，16→32 */
    int32_t volume_factor = (int32_t)(((double)output_volume / 100.0) * ((double)output_volume / 100.0) * 65536);
    for (int i = 0; i < samples; i++) {
        int64_t v = (int64_t)src[i] * volume_factor;
        if (v > INT32_MAX) v = INT32_MAX;
        else if (v < INT32_MIN) v = INT32_MIN;
        buf[i] = (int32_t)v;
    }

    size_t bytes_written = 0;
    esp_err_t err = i2s_channel_write(tx_handle_, buf, samples * sizeof(int32_t),
                                      &bytes_written, portMAX_DELAY);
    free(buf);
    return (err == ESP_OK) ? (int)(bytes_written / sizeof(int32_t)) : 0;
}


int my_audio_read(int16_t *dest, int samples)
{
    size_t bytes_read = 0;
    esp_err_t err = i2s_channel_read(rx_handle_, dest,
                                     samples * sizeof(int16_t), &bytes_read,
                                     pdMS_TO_TICKS(300));
    if (err != ESP_OK) {
        return 0;
    }
    return bytes_read / sizeof(int16_t);
}