/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "wifi_manager.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_lvgl_port.h"
#include <string.h>
#include "esp_log.h"
#include "widgets_init.h"
/*********************
 *      DEFINES
 *********************/
int screen_first_page_digital_clock_time_year_value;
int screen_first_page_digital_clock_time_month_value;
int screen_first_page_digital_clock_time_day_value;
int screen_first_page_digital_clock_time_w_day_value;
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
#define TAG "custom"
/**********************
 *  STATIC VARIABLES
 **********************/
static lv_timer_t* wifi_state_timer = NULL;
/**
 * Create a demo application
 */
static void lv_timer_callback(lv_timer_t *t)
{
    lv_ui* ui = (lv_ui*)lv_timer_get_user_data(t);
    lv_label_set_text(ui->screen_set_wifi_label_wifi_status,"未连接");
}

void set_wifi_state(lv_ui* ui,wifi_state state)
{
    lvgl_port_lock(0);
    // if(wifi_state_timer) {
    //     lv_timer_delete(wifi_state_timer);
    //     wifi_state_timer = NULL;
    // }
    if(state)
    {
        lv_label_set_text(ui->screen_set_wifi_label_wifi_status,"连接成功");
        lv_label_set_text(ui->screen_set_wifi_btn_connect_label,"断开");
    }
    else
    {
        lv_label_set_text(ui->screen_set_wifi_btn_connect_label,"连接");
        lv_label_set_text(ui->screen_set_wifi_label_wifi_status,"未连接");
        // lv_timer_create(lv_timer_callback,pdMS_TO_TICKS(2000),ui);
        // lv_timer_set_repeat_count(wifi_state_timer, 1);
        
        
    }
    lvgl_port_unlock();
}
void set_wifi_state_fail(lv_ui* ui)
{
    lvgl_port_lock(0);
    lv_label_set_text(ui->screen_set_wifi_btn_connect_label,"连接");
        lv_label_set_text(ui->screen_set_wifi_label_wifi_status,"连接失败");
    lvgl_port_unlock();
}

void set_temperature(lv_ui* ui,int day,int high,int low,char* img_path)
{   char temperature[48];
    switch (day)
    {
        case 0:
            /* code */
            snprintf(temperature,sizeof(temperature),"%d-%d℃",low,high);
            lvgl_port_lock(0);
            lv_label_set_text(ui->screen_weather_label_temp_today,temperature);
            lv_img_set_src(ui->screen_weather_img_today,img_path);
            lvgl_port_unlock();
            break;
        case 1:
            snprintf(temperature,sizeof(temperature),"%d-%d℃",low,high);
            lvgl_port_lock(0);
            lv_label_set_text(ui->screen_weather_label_temp_tomorrow,temperature);
            lv_img_set_src(ui->screen_weather_img_tomorrow,img_path);
            lvgl_port_unlock();
            break;
        case 2:
            snprintf(temperature,sizeof(temperature),"%d-%d℃",low,high);
            lvgl_port_lock(0);
            lv_label_set_text(ui->screen_weather_label_temp_after,temperature);
            lv_img_set_src(ui->screen_weather_img_after,img_path);
            lvgl_port_unlock();
            break;
        default:
            break;
    }
    memset(temperature,0,sizeof(temperature));
}
extern lv_calendar_date_t screen_calendar_calendar_1_highlihted_days[1];
void set_calendar_date(lv_ui* ui,int day,int month,int year)
{
    // lv_calendar_date_t highlight_date = {
    //     .day = day,
    //     .month = month,
    //     .year = year,
    // };
    //修改原先的局部变量为全局变量，否则函数结束，地址消失。
    screen_calendar_calendar_1_highlihted_days[0].day = day;
    screen_calendar_calendar_1_highlihted_days[0].month = month;
    screen_calendar_calendar_1_highlihted_days[0].year = year;
    lvgl_port_lock(0);
    lv_calendar_set_today_date(ui->screen_calendar_calendar_1,year,month,day);
    lv_calendar_set_showed_date(ui->screen_calendar_calendar_1,year,month);
    lv_calendar_set_highlighted_dates(ui->screen_calendar_calendar_1,screen_calendar_calendar_1_highlihted_days,1);
    lvgl_port_unlock();

}

void set_serial_receive(lv_ui* ui,char* read_word)
{
    ESP_LOGI(TAG,"%s",read_word);
    lvgl_port_lock(0);
    lv_textarea_add_text(ui->screen_serial_ta_receive,read_word);
    lv_textarea_set_cursor_pos(ui->screen_serial_ta_receive,LV_TEXTAREA_CURSOR_LAST);
    lvgl_port_unlock();
}

void set_aida64_monitor_status(lv_ui* ui,bool status)
{
    lvgl_port_lock(0);
    if(status)//连接成功
    {
        lv_label_set_text(ui->screen_monitor_label_connect_status,"已连接");
        lv_label_set_text(ui->screen_monitor_btn_connect_label,"断开");
    }
    else
    {
        lv_label_set_text(ui->screen_monitor_label_connect_status,"连接失败");
        lv_label_set_text(ui->screen_monitor_btn_connect_label,"连接");
    }
    lvgl_port_unlock();
}

void set_aida64_monitor_params(lv_ui* ui,int cpu_rate,int cpu_temp,int mem_rate,int mem_use)
{
    char data[16];
    lvgl_port_lock(0);
    snprintf(data,sizeof(data),"%d%%",cpu_rate);
    lv_label_set_text(ui->screen_monitor_label_cpu_use_value,data);

    snprintf(data,sizeof(data),"%d℃",cpu_temp);
    lv_label_set_text(ui->screen_monitor_label_temp_value,data);

    snprintf(data,sizeof(data),"%d%%",mem_rate);
    lv_label_set_text(ui->screen_monitor_label_mem_use_value,data);

    snprintf(data,sizeof(data),"%dMB",mem_use);
    lv_label_set_text(ui->screen_monitor_label_mem_invalid_value,data);
    lvgl_port_unlock();
}


void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

