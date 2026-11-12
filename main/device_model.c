#include "device_model.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "led.h"
#include "onenet_mqtt.h"
#include "esp_lvgl_port.h"
#include "gui_guider.h"
#include "esp_log.h"
#include "events_init.h"
#define SWITCH_BIT   BIT0
#define BRIGHTNESS_BIT  BIT1
#define RGB_BIT   BIT2
#define TAG  "device_model"
static QueueHandle_t   cmd_queue;
static SemaphoreHandle_t state_mutex;
static dev_state_t     g_dev_state = {
    .lightswitch = 0,
    .brightness = 0,
    .r = 0,
    .g = 0,
    .b = 0,
};   // 唯一的"真相源"
static EventGroupHandle_t screen_change_handle = NULL;

static int brightness_cmd_on = 512;

static void apply_cmd(dev_cmd_t *cmd)
{
    
    switch (cmd->type)
    {
    case DEV_CMD_SWITCH:
        /* code */
        g_dev_state.lightswitch = cmd->dev_state.lightswitch;
        if(cmd->dev_state.lightswitch)
        {
            led_set_brightness(brightness_cmd_on);
        }
        else
        {
            led_set_brightness(0);
        }
        if(cmd->from)
        {
            xEventGroupSetBits(screen_change_handle,SWITCH_BIT);
        }
        
        break;
    case DEV_CMD_BRIGHTNESS:
        g_dev_state.brightness = cmd->dev_state.brightness;
        led_set_brightness(cmd->dev_state.brightness * 1023 / 100);
        if(cmd->from)
        {
            xEventGroupSetBits(screen_change_handle,BRIGHTNESS_BIT);
        }
        
        break;
    case DEV_CMD_RGB:
        g_dev_state.r = cmd->dev_state.r;
        g_dev_state.g = cmd->dev_state.g;
        g_dev_state.b = cmd->dev_state.b;
        my_ws2812_set_rgb(cmd->dev_state.r,cmd->dev_state.g,cmd->dev_state.b);
        if(cmd->from)
        { 
            xEventGroupSetBits(screen_change_handle,RGB_BIT);
        }
       
        break;
    default:
        break;
    }
}

static void device_task(void* param)
{
    dev_cmd_t cmd_buf = {0};
    while(1)
    {
        xQueueReceive(cmd_queue,&cmd_buf,portMAX_DELAY);
        apply_cmd(&cmd_buf);
        if(!cmd_buf.from)//数据来源屏幕
        {
            onenet_property_report(cmd_buf.dev_state);
        }
        else
        {
            ESP_LOGI(TAG,"queue cmd_buf is from onenet");
        }

    }
}

static void ui_refresh_task(void* param)
{
    EventBits_t change_bits = SWITCH_BIT | BRIGHTNESS_BIT | RGB_BIT;
    while(1)
    {
        EventBits_t ev = xEventGroupWaitBits(screen_change_handle,change_bits,pdTRUE,pdFALSE,pdMS_TO_TICKS(5000));
        if(guider_ui.screen_light == NULL)
        {
            ESP_LOGI(TAG,"screen light is not exist");
            continue;
        }
        if(ev & SWITCH_BIT)
        {
            lvgl_port_lock(0);
            // lv_obj_set_state(guider_ui.screen_light_sw_1,)
             if(g_dev_state.lightswitch)
                lv_obj_add_state(guider_ui.screen_light_sw_1, LV_STATE_CHECKED);
            else
                lv_obj_remove_state(guider_ui.screen_light_sw_1, LV_STATE_CHECKED);
            screen_light_sync_state(g_dev_state.lightswitch);
            lvgl_port_unlock();
        }
        if(ev & BRIGHTNESS_BIT)
        {
            lvgl_port_lock(0);
            lv_slider_set_value(guider_ui.screen_light_slider_Brightness,g_dev_state.brightness,LV_ANIM_ON);
            lvgl_port_unlock();
        }
        if (ev & RGB_BIT)
        {
            char r_buf[8];
            char g_buf[8];
            char b_buf[8];
            snprintf(r_buf, sizeof(r_buf), "%d", g_dev_state.r);
            snprintf(g_buf, sizeof(g_buf), "%d", g_dev_state.g);
            snprintf(b_buf, sizeof(b_buf), "%d", g_dev_state.b);
            
            lvgl_port_lock(0);
            lv_textarea_set_text(guider_ui.screen_light_ta_R, r_buf);
            lv_textarea_set_text(guider_ui.screen_light_ta_G, g_buf);
            lv_textarea_set_text(guider_ui.screen_light_ta_B, b_buf);
            lvgl_port_unlock();
        }
        
        ESP_LOGI(TAG,"receive bit is:%d",ev);
    }
    
   
}

void model_devic_init(void)
{
    cmd_queue = xQueueCreate(10,sizeof(dev_cmd_t));
    state_mutex = xSemaphoreCreateMutex();
    screen_change_handle = xEventGroupCreate();

    xTaskCreatePinnedToCore(device_task,"device task",4096,NULL,1,NULL,1);
   xTaskCreatePinnedToCore(ui_refresh_task,"refresh task",4096,NULL,1,NULL,1);
}

void device_model_send_cmd(dev_cmd_t cmd)
{
    xQueueSend(cmd_queue,&cmd,pdMS_TO_TICKS(100));
}
