/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "wifi_manager.h"
#include "led.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include <string.h>
#include "myuart.h"
#include "esp_log.h"
#include "aida64.h"
#include "device_model.h"
#include "xiaozhi_ui.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#define TAG  "events_init"
static dev_cmd_t screen_cmd = {0};


static void screen_first_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_second_page, guider_ui.screen_second_page_del, &guider_ui.screen_first_page_del, setup_scr_screen_second_page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_first_page_img_setting_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_set_wifi, guider_ui.screen_set_wifi_del, &guider_ui.screen_first_page_del, setup_scr_screen_set_wifi, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

static void screen_first_page_img_weather_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_weather, guider_ui.screen_weather_del, &guider_ui.screen_first_page_del, setup_scr_screen_weather, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

static void screen_first_page_img_serial_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    static bool uart_init = false;
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_serial, guider_ui.screen_serial_del, &guider_ui.screen_first_page_del, setup_scr_screen_serial, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        if(!uart_init)
        {
            my_uart_init();
            uart_init = true;
        }
        uart_receive_start();
        break;
    }
    default:
        break;
    }
}

static void screen_first_page_img_light_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {   
        screen_cmd.from = 0;
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_light, guider_ui.screen_light_del, &guider_ui.screen_first_page_del, setup_scr_screen_light, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_first_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_first_page, screen_first_page_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_first_page_img_setting, screen_first_page_img_setting_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_first_page_img_weather, screen_first_page_img_weather_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_first_page_img_serial, screen_first_page_img_serial_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_first_page_img_light, screen_first_page_img_light_event_handler, LV_EVENT_ALL, ui);
}

static void screen_second_page_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_first_page, guider_ui.screen_first_page_del, &guider_ui.screen_second_page_del, setup_scr_screen_first_page, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_second_page_img_computer_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_monitor, guider_ui.screen_monitor_del, &guider_ui.screen_second_page_del, setup_scr_screen_monitor, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

static void screen_second_page_img_calendar_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_calendar, guider_ui.screen_calendar_del, &guider_ui.screen_second_page_del, setup_scr_screen_calendar, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

static void screen_second_page_img_ai_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        xiaozhi_ui_open();
        break;
    }
    default:
        break;
    }
}

static void screen_second_page_img_calculator_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_calculator, guider_ui.screen_calculator_del, &guider_ui.screen_second_page_del, setup_scr_screen_calculator, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_second_page (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_second_page, screen_second_page_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_second_page_img_computer, screen_second_page_img_computer_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_second_page_img_calendar, screen_second_page_img_calendar_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_second_page_img_ai, screen_second_page_img_ai_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_second_page_img_calculator, screen_second_page_img_calculator_event_handler, LV_EVENT_ALL, ui);
}

//设置页面的wifi连接事件
static void screen_set_wifi_btn_connect_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = (lv_ui*)lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(!wifi_manager_sta_isconnect())//未连接状态
        {
            const char *ssid = lv_textarea_get_text(ui->screen_set_wifi_ta_ssid);
            const char *password = lv_textarea_get_text(ui->screen_set_wifi_ta_password);
            wifi_manager_sta_connect(ssid,password);
            //开始连接
        }
        else//连接状态
        {
            wifi_manager_sta_stop();
            
            //断开连接
        }
        break;
    }
    default:
        break;
    }
}

static void screen_set_wifi_img_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_first_page, guider_ui.screen_first_page_del, &guider_ui.screen_set_wifi_del, setup_scr_screen_first_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_set_wifi (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_set_wifi_btn_connect, screen_set_wifi_btn_connect_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_set_wifi_img_back, screen_set_wifi_img_back_event_handler, LV_EVENT_ALL, ui);
}

static void screen_weather_img_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_first_page, guider_ui.screen_first_page_del, &guider_ui.screen_weather_del, setup_scr_screen_first_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_weather (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_weather_img_back, screen_weather_img_back_event_handler, LV_EVENT_ALL, ui);
}

static int led_state = 0;
static int led_brightness = 512;
static void screen_light_sw_1_event_handler (lv_event_t *e)
{
    //static int first_open = 1;
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
        led_state = status;
        if(status)
        {
            screen_cmd.dev_state.lightswitch = 1;
            screen_cmd.type = DEV_CMD_SWITCH;
            device_model_send_cmd(screen_cmd);
            // if(first_open)
            // {
            //     int brightness = 50 * 1024 / 100;
            //     led_set_brightness(brightness);
            //     first_open = 0;
            // }
            // else
            // {
            //     led_set_brightness(led_brightness);
            // }
        }
        else
        {
            screen_cmd.dev_state.lightswitch = 0;
            screen_cmd.type = DEV_CMD_SWITCH;
            device_model_send_cmd(screen_cmd);
            // led_set_brightness(0);
        }
        break;
    }
    default:
        break;
    }
}

void screen_light_sync_state(int state)
{
    led_state = state;
}

static void screen_light_slider_Brightness_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t *slider_obj = lv_event_get_target(e);
        uint16_t brightness = lv_slider_get_value(slider_obj);
        led_brightness = brightness;
        if(led_state)
        {
            screen_cmd.dev_state.brightness = led_brightness;
            screen_cmd.type = DEV_CMD_BRIGHTNESS;
            device_model_send_cmd(screen_cmd);
            // led_set_brightness(led_brightness);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_light_btn_confirm_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        const char* r_text = lv_textarea_get_text(guider_ui.screen_light_ta_R);
        const char* g_text = lv_textarea_get_text(guider_ui.screen_light_ta_G);
        const char* b_text = lv_textarea_get_text(guider_ui.screen_light_ta_B);
        
        int r = 0;
        int g = 0;
        int b = 0;
        sscanf(r_text,"%d",&r);
        sscanf(g_text,"%d",&g);
        sscanf(b_text,"%d",&b);
        screen_cmd.dev_state.r = r;
        screen_cmd.dev_state.g = g;
        screen_cmd.dev_state.b = b;
        screen_cmd.type = DEV_CMD_RGB;;
        device_model_send_cmd(screen_cmd);
        // my_ws2812_set_rgb(r,g,b);
        break;
    }
    default:
        break;
    }
}

static void screen_light_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_first_page, guider_ui.screen_first_page_del, &guider_ui.screen_light_del, setup_scr_screen_first_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_light (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_light_sw_1, screen_light_sw_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_light_slider_Brightness, screen_light_slider_Brightness_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_light_img_1, screen_light_img_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_light_btn_confirm, screen_light_btn_confirm_event_handler, LV_EVENT_ALL, ui);
}

static void screen_serial_btn_send_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        static char send[256];
        snprintf(send,sizeof(send),"%s\r\n",lv_textarea_get_text(guider_ui.screen_serial_ta_send));
        uart_write_bytes(UART_NUM_0,send,strlen(send));
        break;
    }
    default:
        break;
    }
}

static void screen_serial_btn_clear_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_textarea_set_text(guider_ui.screen_serial_ta_receive,"");

        break;
    }
    default:
        break;
    }
}

static void screen_serial_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_first_page, guider_ui.screen_first_page_del, &guider_ui.screen_serial_del, setup_scr_screen_first_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_serial (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_serial_btn_send, screen_serial_btn_send_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_serial_btn_clear, screen_serial_btn_clear_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_serial_img_1, screen_serial_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_monitor_btn_connect_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = (lv_ui*)lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {   
        if(aida64_isconnect())
        {
            aida64_disconnect();
        }
        else
        {
            char ip[64];
            snprintf(ip,sizeof(ip),"%s",lv_textarea_get_text(ui->screen_monitor_ta_ip));
            aida64_monitor_start(ip);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_monitor_img_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_second_page, guider_ui.screen_second_page_del, &guider_ui.screen_monitor_del, setup_scr_screen_second_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_monitor (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_monitor_btn_connect, screen_monitor_btn_connect_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_monitor_img_back, screen_monitor_img_back_event_handler, LV_EVENT_ALL, ui);
}

static void screen_calendar_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_second_page, guider_ui.screen_second_page_del, &guider_ui.screen_calendar_del, setup_scr_screen_second_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_calendar (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_calendar_img_1, screen_calendar_img_1_event_handler, LV_EVENT_ALL, ui);
}
    static char input[64];
static void screen_calculator_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        snprintf(input,sizeof(input),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        if(strlen(input) == 1 && input[0] == '0')
        {
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,"2");
        }
        else
        {
            lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"2");
        }
        lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        snprintf(input,sizeof(input),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        if(strlen(input) == 1 && input[0] == '0')
        {
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,"1");
        }
        else
        {
            lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"1");
        }
        lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        snprintf(input,sizeof(input),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        if(strlen(input) == 1 && input[0] == '0')
        {
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,"3");
        }
        else
        {
            lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"3");
        }
       // lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"3");
        lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_equivalent_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        char input_con[64] = {0};
        snprintf(input_con,sizeof(input_con),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        int len = strlen(input_con);
        int index = 0;
        int num[64] = {0};
        char symbol[16] = {0};
        for(int i = 0 ;i < len;i++)
        {
            if((int)input_con[i] >= '0' && (int)input_con[i] <= '9')
            {
                num[index] = num[index] * 10 + (int)input_con[i]  - '0';
            }
            else
            {
                symbol[index] = input_con[i];
                index++;
                num[index] = 0;   
            }
        }
        
        char symbol_filter[16] = {0};
        int num_filter[64] = {0};
        int index_filter = 0;
        for(int i = 0;i < index;i++)
        {
            switch (symbol[i])
            {
                case '*':
                    /* code */
                    num[i+1] = num[i] * num[i+1];
                    num[i] = 0;
                   
                    break;
                
                case '/':
                    /* code */
                    if(num[i+1] != 0)
                    {
                        num[i+1] = num[i] / num[i+1];
                        num[i] = 0;
                    }
                    break;
                default:
                    num_filter[index_filter] = num[i];
                    symbol_filter[index_filter] = symbol[i];
                    index_filter++;
                    break;
            }
        }
        num_filter[index_filter] = num[index];
         char cal_value[12] = {0};
        if(index_filter != 0)
        {
            int val = num_filter[0];
            for(int i = 0;i < index_filter;i++)
            {
                
                switch (symbol_filter[i])
                {
                case '+':
                    /* code */
                    val += num_filter[i+1];
                    break;
                case '-':
                    /* code */
                    val -= num_filter[i+1];
                    break;
                default:
                    break;
                }
            }
            snprintf(cal_value,sizeof(cal_value),"%d",val);
            ESP_LOGI(TAG,"calc value = %d",val);
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,cal_value);
        }
        else
        {
            snprintf(cal_value,12,"%d",num[index]);
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,cal_value);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_0_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        snprintf(input,sizeof(input),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        if(strlen(input) == 1 && input[0] == '0')
        {
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,"0");
        }
        else
        {
            lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"0");
        }
        lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_point_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,".");
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_plus_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"+");
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_subtract_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"-");
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_multiply_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"*");
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        snprintf(input,sizeof(input),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        if(strlen(input) == 1 && input[0] == '0')
        {
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,"4");
        }
        else
        {
            lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"4");
        }
        lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        snprintf(input,sizeof(input),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        if(strlen(input) == 1 && input[0] == '0')
        {
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,"5");
        }
        else
        {
            lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"5");
        }
        lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        snprintf(input,sizeof(input),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        if(strlen(input) == 1 && input[0] == '0')
        {
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,"6");
        }
        else
        {
            lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"6");
        }
        lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_7_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        snprintf(input,sizeof(input),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        if(strlen(input) == 1 && input[0] == '0')
        {
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,"7");
        }
        else
        {
            lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"7");
        }
        lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_8_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
       snprintf(input,sizeof(input),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        if(strlen(input) == 1 && input[0] == '0')
        {
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,"8");
        }
        else
        {
            lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"8");
        }
        lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_9_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        snprintf(input,sizeof(input),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        if(strlen(input) == 1 && input[0] == '0')
        {
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,"9");
        }
        else
        {
            lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"9");
        }
        lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_divide_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_textarea_add_text(guider_ui.screen_calculator_ta_calculator,"/");
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_delete_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        char input_content[64];
       
        snprintf(input_content,sizeof(input_content),"%s",lv_textarea_get_text(guider_ui.screen_calculator_ta_calculator));
        int len = strlen(input_content);
        if(len > 1)
        {
            ESP_LOGI(TAG,"before : %s",input_content);
            input_content[len - 1] = '\0';
            ESP_LOGI(TAG,"after : %s",input_content);
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,input_content);
            lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        }
        if(len == 1)
        {
            ESP_LOGI(TAG,"before : %s",input_content);
            input_content[len - 1] = '0';
            ESP_LOGI(TAG,"after : %s",input_content);
            lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,input_content);
            lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_clear_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_textarea_delete_char(guider_ui.screen_calculator_ta_calculator);
        lv_textarea_set_text(guider_ui.screen_calculator_ta_calculator,"0");
        lv_textarea_set_cursor_pos(guider_ui.screen_calculator_ta_calculator,LV_TEXTAREA_CURSOR_LAST);
        break;
    }
    default:
        break;
    }
}

static void screen_calculator_btn_back_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_second_page, guider_ui.screen_second_page_del, &guider_ui.screen_calculator_del, setup_scr_screen_second_page, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_calculator (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_calculator_btn_2, screen_calculator_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_1, screen_calculator_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_3, screen_calculator_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_equivalent, screen_calculator_btn_equivalent_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_0, screen_calculator_btn_0_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_point, screen_calculator_btn_point_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_plus, screen_calculator_btn_plus_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_subtract, screen_calculator_btn_subtract_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_multiply, screen_calculator_btn_multiply_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_4, screen_calculator_btn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_5, screen_calculator_btn_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_6, screen_calculator_btn_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_7, screen_calculator_btn_7_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_8, screen_calculator_btn_8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_9, screen_calculator_btn_9_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_divide, screen_calculator_btn_divide_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_delete, screen_calculator_btn_delete_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_clear, screen_calculator_btn_clear_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_calculator_btn_back, screen_calculator_btn_back_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
