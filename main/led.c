#include "led.h"
#include "driver/gpio.h"
#include "led_ws2812.h"
#include "driver/ledc.h"
#include "lvgl.h"
#include "custom.h"
#include "gui_guider.h"
#include "esp_err.h"
static ws2812_strip_handle_t ws2812_handle;

void led_init(void)
{
    // gpio_config_t gpio_cfg = {
    //     .pin_bit_mask = (1 << 15),
    //     .mode = GPIO_MODE_OUTPUT,
    //     .intr_type = GPIO_INTR_DISABLE,
    //     .pull_down_en = GPIO_PULLDOWN_ENABLE,
    //     .pull_up_en = GPIO_PULLUP_DISABLE,
    // };
    // gpio_config(&gpio_cfg);
     ledc_timer_config_t timer_cfg = {
        .clk_cfg = LEDC_AUTO_CLK,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
        .duty_resolution = LEDC_TIMER_10_BIT,//2^duty_res - 1
        .freq_hz = 50,
    };
    ledc_timer_config(&timer_cfg);
    ledc_channel_config_t channnel_cfg = {
        .channel = LEDC_CHANNEL_0,
        .gpio_num = GPIO_NUM_15,
        .timer_sel = LEDC_TIMER_0,
        .speed_mode = LEDC_LOW_SPEED_MODE,
    };
    ledc_channel_config(&channnel_cfg);
    ledc_fade_func_install(true);
}

void led_set_brightness(int brightness)
{ 
    ledc_set_duty_and_update(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0,brightness,0);
}

void my_ws2812_init(void)
{
    ESP_ERROR_CHECK(ws2812_init(GPIO_NUM_18,3,&ws2812_handle));
}

void my_ws2812_set_rgb(int r,int g,int b)
{
    for(int i = 0;i < 3;i++)
    {
        ws2812_write(ws2812_handle,i,r,g,b);
    }
   
}