#include <stdio.h>
#include "xl9555.h"
#include "driver/gpio.h"
#include "ft6336u.h"
#include "lv_port.h"
#include "esp_lvgl_port.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "custom.h"
#include "nvs_flash.h"
#include "wifi_manager.h"
#include "wifi_manager.h"
#include "esp_log.h"
#include "esp_sntp.h"
#include "time.h"
#include <sys/time.h>
#include "led.h"
#include "weather.h"
#include "myuart.h"
#include "onenet_mqtt.h"
#include"device_model.h"
#include "my_audio.h"
#include "esp_opus_dec.h"
#include "esp_opus_enc.h"
#include "esp_pm.h"

lv_ui guider_ui;
#define XL9555_I2C_SDA  GPIO_NUM_10
#define XL9555_I2C_SCL  GPIO_NUM_11
#define XL9555_INT      GPIO_NUM_17
#define SPEAKER_LRCLK   GPIO_NUM_9
#define SPEAKER_BCLK    GPIO_NUM_46
#define SPEAKER_SD      GPIO_NUM_8
#define MICRO_CLK       GPIO_NUM_3
#define MICRO_DATA      GPIO_NUM_42


#define TAG  "main"
static uint16_t xl9555_button_level = 0xffff;

void xl9555_input_callback(uint16_t io_num,int level)
{

    if(level)
        xl9555_button_level |= io_num;
    else
        xl9555_button_level &= ~io_num;
    
    if(io_num == IO1_1)
    {
        if(level == 0)
        {
            ft6336u_int_info(true);
        }
        else
        {
            ft6336u_int_info(false);
        }
    }
}

void wifi_event_call(wifi_state ws)
{
    if(ws)
    {
        ESP_LOGI(TAG,"wifi init success");
        //wifi启动成功后 启动Onenet 和 weather 
        weather_start();
        onenet_start();
    }
    else
    {
        ESP_LOGI(TAG,"wifi init failed");
    }
}
static void app_pm_init(void)
{
    const esp_pm_config_t pm_cfg = {
        .max_freq_mhz = 240,
        .min_freq_mhz = 80,
        .light_sleep_enable = true,
    };
    ESP_ERROR_CHECK(esp_pm_configure(&pm_cfg));
}
// static void audio_selftest_task(void *arg)
// {
//     int16_t buf[960];
//     ESP_LOGI("AUDIO", "selftest task running");
//     while (true) {
//         if (my_audio_read(buf, 960) > 0) {
//             /* 打印波形检查 */
//             ESP_LOGI("AUDIO", "samples: %d %d %d %d", buf[0], buf[1], buf[2], buf[3]);
//         }
//         vTaskDelay(pdMS_TO_TICKS(100));
//     }
// }


void app_main(void)
{
    app_pm_init();
    nvs_flash_init();
    xl9555_init(XL9555_I2C_SDA,XL9555_I2C_SCL,XL9555_INT,xl9555_input_callback);
    wifi_init_sta(wifi_event_call);
    led_init();
    my_ws2812_init();
    init_weather_buffer();
    model_devic_init();
    // my_uart_init(); 改成打开serial 页面后初始化
    //my_audio_init(SPEAKER_LRCLK,SPEAKER_BCLK,SPEAKER_SD,MICRO_CLK,MICRO_DATA);//改成打开小智页面后初始化

    xl9555_ioconfig(~(IO1_2 | IO1_3 | IO0_0) & 0xffff);
    xl9555_pin_write(IO1_2,1);
    //xl9555_pin_write(IO0_0,1);
    vTaskDelay(pdMS_TO_TICKS(100));

    lv_port_init();
    lvgl_port_lock(0);
    setup_ui(&guider_ui);
    custom_init(&guider_ui);
    lvgl_port_unlock();
    setenv("TZ","CST-8",1);
    tzset();

    // weather_start();
    // onenet_start();
    ESP_LOGI("main", "before uart_receive_start");
    //uart_receive_start();
   
    while(1)
    {
        time_t t = time(NULL);

        // ESP_LOGI(TAG,"now time is :%lld",t);
        // ESP_ERROR_CHECK(esp_pm_dump_locks(stdout));
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}
