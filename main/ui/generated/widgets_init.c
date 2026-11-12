/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include "gui_guider.h"
#include "widgets_init.h"
#include <stdlib.h>
#include <string.h>
#include "esp_sntp.h"
#include "time.h"
#include "custom.h"
#include "esp_log.h"

#define TAG  "widgets_init"

__attribute__((unused)) void kb_event_cb (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_target(e);
    if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

__attribute__((unused)) void ta_event_cb (lv_event_t *e) {
#if LV_USE_KEYBOARD
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);

    if(code == LV_EVENT_FOCUSED) {
        if(lv_indev_get_type(lv_indev_active()) != LV_INDEV_TYPE_KEYPAD) {
            lv_keyboard_set_textarea(kb, ta);
            lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);
        }
    } else if(code == LV_EVENT_READY) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_state(ta, LV_STATE_FOCUSED);
        lv_indev_reset(NULL, ta);
    } else if(code == LV_EVENT_DEFOCUSED) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
#endif
}

void clock_count(int *hour, int *min, int *sec)
{
    (*sec)++;
    if(*sec == 60)
    {
        *sec = 0;
        (*min)++;
    }
    if(*min == 60)
    {
        *min = 0;
        if(*hour < 12)
        {
            (*hour)++;
        } else {
            (*hour)++;
            *hour = *hour %12;
        }
    }
}

void digital_clock_count(int * hour, int * minute, int * seconds, char * meridiem)
{

    (*seconds)++;
    if(*seconds == 60) {
        *seconds = 0;
        (*minute)++;
    }
    if(*minute == 60) {
        *minute = 0;
        if(*hour < 24) {
            (*hour)++;
        }
        else {
            (*hour)++;
            (*hour) = (*hour) % 24;
        }
    }
    if(*hour == 12 && *seconds == 0 && *minute == 0) {
        if((lv_strcmp(meridiem, "PM") == 0)) {
            lv_strcpy(meridiem, "AM");
        }
        else {
            lv_strcpy(meridiem, "PM");
        }
    }
}


extern int screen_first_page_digital_clock_time_hour_value;
extern int screen_first_page_digital_clock_time_min_value;
extern int screen_first_page_digital_clock_time_sec_value;

extern int screen_first_page_digital_clock_time_year_value;
extern int screen_first_page_digital_clock_time_month_value;
extern int screen_first_page_digital_clock_time_day_value;
extern int screen_first_page_digital_clock_time_w_day_value;
// extern lv_ui guider_ui;
void screen_first_page_digital_clock_time_timer(lv_timer_t *timer)
{
    // clock_count(&screen_first_page_digital_clock_time_hour_value, &screen_first_page_digital_clock_time_min_value, &screen_first_page_digital_clock_time_sec_value);
    
    static bool time_valid = false;

    // sntp_get_sync_status() 返回一次 COMPLETED 后会自动复位，
    // 所以用静态标志锁存“已经校时成功”的状态
    if (!time_valid) {
        if (esp_sntp_get_sync_status() != SNTP_SYNC_STATUS_COMPLETED) {
            return; // 还没同步时间，保持 GUI Guider 的初始显示
        }
        time_valid = true;
    }
    //返回系统当前时间戳
    time_t now = time(NULL);
    struct tm t;
    localtime_r(&now,&t);//将时间戳转换为结构体格式存储
    
    screen_first_page_digital_clock_time_hour_value = t.tm_hour;
    screen_first_page_digital_clock_time_min_value = t.tm_min;
    screen_first_page_digital_clock_time_sec_value = t.tm_sec;
    screen_first_page_digital_clock_time_year_value = t.tm_year + 1900;
    screen_first_page_digital_clock_time_month_value = t.tm_mon+1;
    screen_first_page_digital_clock_time_day_value = t.tm_mday;
    screen_first_page_digital_clock_time_w_day_value = t.tm_wday;

    static const char* weekday[] = {
        "星期日",
        "星期一",
        "星期二",
        "星期三",
        "星期四",
        "星期五",
        "星期六"
    };
    static int last_year = -1;
    static int last_month = -1;
    static int last_day = -1;
    static bool calendar_change = 0;
    bool date_change = false;
    if(last_year != screen_first_page_digital_clock_time_year_value || 
        last_day != screen_first_page_digital_clock_time_day_value || 
        last_month != screen_first_page_digital_clock_time_month_value)
    {
        date_change = true;
    }
    if(date_change)
    {
        last_year = screen_first_page_digital_clock_time_year_value;
        last_month = screen_first_page_digital_clock_time_month_value;
        last_day = screen_first_page_digital_clock_time_day_value;
        static char date[64];
        snprintf(date,sizeof(date),"%d年%d月%d日",screen_first_page_digital_clock_time_year_value,screen_first_page_digital_clock_time_month_value,screen_first_page_digital_clock_time_day_value);
        lv_label_set_text(guider_ui.screen_first_page_label_date,date);
        lv_label_set_text(guider_ui.screen_first_page_label_week,weekday[screen_first_page_digital_clock_time_w_day_value]);
        calendar_change = 1;
    }
    if(guider_ui.screen_calendar!= NULL && calendar_change)
    {
        set_calendar_date(&guider_ui,screen_first_page_digital_clock_time_day_value,screen_first_page_digital_clock_time_month_value,screen_first_page_digital_clock_time_year_value);
        calendar_change = 0;
        ESP_LOGI(TAG,"Calendar updates successfully!");
    }
    if (lv_obj_is_valid(guider_ui.screen_first_page_digital_clock_time))
    {
        lv_label_set_text_fmt(guider_ui.screen_first_page_digital_clock_time, "%d:%02d:%02d", screen_first_page_digital_clock_time_hour_value, screen_first_page_digital_clock_time_min_value, screen_first_page_digital_clock_time_sec_value);
    }
}
void screen_calendar_calendar_1_draw_part_begin_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_draw_task_t * draw_task = lv_event_get_param(e);
    lv_draw_dsc_base_t * base_dsc = draw_task->draw_dsc;
    if(base_dsc->part != LV_PART_ITEMS) return;

    lv_draw_label_dsc_t * label_dsc = lv_draw_task_get_label_dsc(draw_task);
    lv_draw_border_dsc_t * border_dsc = lv_draw_task_get_border_dsc(draw_task);
    lv_draw_fill_dsc_t * fill_dsc = lv_draw_task_get_fill_dsc(draw_task);

    if(base_dsc->id1 < 7) {
        if(label_dsc) label_dsc->color = lv_color_hex(0x0D3055);
        if(label_dsc) label_dsc->font = &lv_font_montserratMedium_12;
    } else if (lv_buttonmatrix_has_button_ctrl(obj, base_dsc->id1, LV_BUTTONMATRIX_CTRL_DISABLED)) {
        if(label_dsc) label_dsc->color = lv_color_hex(0xA9A2A2);
        if(label_dsc) label_dsc->font = &lv_font_montserratMedium_12;
        if(fill_dsc) fill_dsc->opa = 255;
        if(fill_dsc) fill_dsc->color = lv_color_hex(0xffffff);
    }
    if(lv_buttonmatrix_has_button_ctrl(obj, base_dsc->id1, LV_BUTTONMATRIX_CTRL_CUSTOM_1)) {
        if(label_dsc) label_dsc->color = lv_color_hex(0x0D3055);
        if(label_dsc) label_dsc->font = &lv_font_montserratMedium_12;
        if(fill_dsc) fill_dsc->opa = 255;
        if(fill_dsc) fill_dsc->color = lv_color_hex(0x01a2b1);
        if(border_dsc) border_dsc->opa = 255;
        if(border_dsc) border_dsc->width = 1;
        if(border_dsc) border_dsc->color = lv_color_hex(0xc0c0c0);
    }
    if(lv_buttonmatrix_has_button_ctrl(obj, base_dsc->id1, LV_BUTTONMATRIX_CTRL_CUSTOM_2)) {
        if(label_dsc) label_dsc->color = lv_color_hex(0x0D3055);
        if(label_dsc) label_dsc->font = &lv_font_montserratMedium_12;
        if(fill_dsc) fill_dsc->opa = 255;
        if(fill_dsc) fill_dsc->color = lv_color_hex(0x2195f6);
    } else {
    }
}

void screen_calendar_calendar_1_event_handler(lv_event_t * e)
{
    lv_calendar_date_t date;
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t * obj = lv_event_get_current_target(e);
        lv_calendar_get_pressed_date(obj,&date);
        lv_calendar_set_highlighted_dates(obj, &date, 1);
    }
}

