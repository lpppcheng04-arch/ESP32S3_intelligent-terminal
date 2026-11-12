/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"



typedef struct
{
  
	lv_obj_t *screen_first_page;
	bool screen_first_page_del;
	lv_obj_t *screen_first_page_digital_clock_time;
	lv_obj_t *screen_first_page_label_setting;
	lv_obj_t *screen_first_page_label_weather;
	lv_obj_t *screen_first_page_label_light;
	lv_obj_t *screen_first_page_label_serial;
	lv_obj_t *screen_first_page_img_setting;
	lv_obj_t *screen_first_page_img_weather;
	lv_obj_t *screen_first_page_img_serial;
	lv_obj_t *screen_first_page_img_light;
	lv_obj_t *screen_first_page_label_date;
	lv_obj_t *screen_first_page_label_week;
	lv_obj_t *screen_second_page;
	bool screen_second_page_del;
	lv_obj_t *screen_second_page_img_computer;
	lv_obj_t *screen_second_page_img_calendar;
	lv_obj_t *screen_second_page_img_ai;
	lv_obj_t *screen_second_page_img_calculator;
	lv_obj_t *screen_second_page_label_computer;
	lv_obj_t *screen_second_page_label_calendar;
	lv_obj_t *screen_second_page_label_calculator;
	lv_obj_t *screen_second_page_label_ai;
	lv_obj_t *screen_set_wifi;
	bool screen_set_wifi_del;
	lv_obj_t *screen_set_wifi_label_ssid;
	lv_obj_t *screen_set_wifi_label_password;
	lv_obj_t *screen_set_wifi_ta_ssid;
	lv_obj_t *screen_set_wifi_ta_password;
	lv_obj_t *screen_set_wifi_label_wifi_status;
	lv_obj_t *screen_set_wifi_btn_connect;
	lv_obj_t *screen_set_wifi_btn_connect_label;
	lv_obj_t *screen_set_wifi_wifi;
	lv_obj_t *screen_set_wifi_label_4;
	lv_obj_t *screen_set_wifi_img_back;
	lv_obj_t *screen_weather;
	bool screen_weather_del;
	lv_obj_t *screen_weather_label_today;
	lv_obj_t *screen_weather_label_tomorrow;
	lv_obj_t *screen_weather_label_after;
	lv_obj_t *screen_weather_img_today;
	lv_obj_t *screen_weather_img_tomorrow;
	lv_obj_t *screen_weather_img_after;
	lv_obj_t *screen_weather_label_temp_today;
	lv_obj_t *screen_weather_label_temp_tomorrow;
	lv_obj_t *screen_weather_label_temp_after;
	lv_obj_t *screen_weather_img_back;
	lv_obj_t *screen_light;
	bool screen_light_del;
	lv_obj_t *screen_light_label_switch;
	lv_obj_t *screen_light_label_Brightness;
	lv_obj_t *screen_light_sw_1;
	lv_obj_t *screen_light_slider_Brightness;
	lv_obj_t *screen_light_label_RGB;
	lv_obj_t *screen_light_ta_R;
	lv_obj_t *screen_light_ta_G;
	lv_obj_t *screen_light_ta_B;
	lv_obj_t *screen_light_label_R;
	lv_obj_t *screen_light_label_G;
	lv_obj_t *screen_light_label_B;
	lv_obj_t *screen_light_img_1;
	lv_obj_t *screen_light_btn_confirm;
	lv_obj_t *screen_light_btn_confirm_label;
	lv_obj_t *screen_serial;
	bool screen_serial_del;
	lv_obj_t *screen_serial_ta_send;
	lv_obj_t *screen_serial_ta_receive;
	lv_obj_t *screen_serial_label_send;
	lv_obj_t *screen_serial_label_receive;
	lv_obj_t *screen_serial_btn_send;
	lv_obj_t *screen_serial_btn_send_label;
	lv_obj_t *screen_serial_btn_clear;
	lv_obj_t *screen_serial_btn_clear_label;
	lv_obj_t *screen_serial_img_1;
	lv_obj_t *screen_monitor;
	bool screen_monitor_del;
	lv_obj_t *screen_monitor_cont_cpu;
	lv_obj_t *screen_monitor_label_cpu;
	lv_obj_t *screen_monitor_label_cpu_use;
	lv_obj_t *screen_monitor_label_cpu_use_value;
	lv_obj_t *screen_monitor_label_temp;
	lv_obj_t *screen_monitor_label_temp_value;
	lv_obj_t *screen_monitor_cont_mem;
	lv_obj_t *screen_monitor_label_mem;
	lv_obj_t *screen_monitor_label_mem_use;
	lv_obj_t *screen_monitor_label_mem_invalid;
	lv_obj_t *screen_monitor_label_mem_use_value;
	lv_obj_t *screen_monitor_label_mem_invalid_value;
	lv_obj_t *screen_monitor_ta_ip;
	lv_obj_t *screen_monitor_btn_connect;
	lv_obj_t *screen_monitor_btn_connect_label;
	lv_obj_t *screen_monitor_label_ip;
	lv_obj_t *screen_monitor_label_connect_status;
	lv_obj_t *screen_monitor_img_back;
	lv_obj_t *screen_calendar;
	bool screen_calendar_del;
	lv_obj_t *screen_calendar_calendar_1;
	lv_obj_t *screen_calendar_img_1;
	lv_obj_t *screen_calculator;
	bool screen_calculator_del;
	lv_obj_t *screen_calculator_cont_1;
	lv_obj_t *screen_calculator_btn_2;
	lv_obj_t *screen_calculator_btn_2_label;
	lv_obj_t *screen_calculator_btn_1;
	lv_obj_t *screen_calculator_btn_1_label;
	lv_obj_t *screen_calculator_btn_3;
	lv_obj_t *screen_calculator_btn_3_label;
	lv_obj_t *screen_calculator_btn_equivalent;
	lv_obj_t *screen_calculator_btn_equivalent_label;
	lv_obj_t *screen_calculator_btn_0;
	lv_obj_t *screen_calculator_btn_0_label;
	lv_obj_t *screen_calculator_btn_point;
	lv_obj_t *screen_calculator_btn_point_label;
	lv_obj_t *screen_calculator_btn_plus;
	lv_obj_t *screen_calculator_btn_plus_label;
	lv_obj_t *screen_calculator_btn_subtract;
	lv_obj_t *screen_calculator_btn_subtract_label;
	lv_obj_t *screen_calculator_btn_multiply;
	lv_obj_t *screen_calculator_btn_multiply_label;
	lv_obj_t *screen_calculator_btn_4;
	lv_obj_t *screen_calculator_btn_4_label;
	lv_obj_t *screen_calculator_btn_5;
	lv_obj_t *screen_calculator_btn_5_label;
	lv_obj_t *screen_calculator_btn_6;
	lv_obj_t *screen_calculator_btn_6_label;
	lv_obj_t *screen_calculator_btn_7;
	lv_obj_t *screen_calculator_btn_7_label;
	lv_obj_t *screen_calculator_btn_8;
	lv_obj_t *screen_calculator_btn_8_label;
	lv_obj_t *screen_calculator_btn_9;
	lv_obj_t *screen_calculator_btn_9_label;
	lv_obj_t *screen_calculator_btn_divide;
	lv_obj_t *screen_calculator_btn_divide_label;
	lv_obj_t *screen_calculator_btn_delete;
	lv_obj_t *screen_calculator_btn_delete_label;
	lv_obj_t *screen_calculator_btn_clear;
	lv_obj_t *screen_calculator_btn_clear_label;
	lv_obj_t *screen_calculator_btn_back;
	lv_obj_t *screen_calculator_btn_back_label;
	lv_obj_t *screen_calculator_ta_calculator;
	lv_obj_t *g_kb_top_layer;
}lv_ui;
typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen_first_page(lv_ui *ui);
void setup_scr_screen_second_page(lv_ui *ui);
void setup_scr_screen_set_wifi(lv_ui *ui);
void setup_scr_screen_weather(lv_ui *ui);
void setup_scr_screen_light(lv_ui *ui);
void setup_scr_screen_serial(lv_ui *ui);
void setup_scr_screen_monitor(lv_ui *ui);
void setup_scr_screen_calendar(lv_ui *ui);
void setup_scr_screen_calculator(lv_ui *ui);
LV_IMAGE_DECLARE(_set_RGB565A8_64x64);
LV_IMAGE_DECLARE(_weather_RGB565A8_64x64);
LV_IMAGE_DECLARE(_serial_RGB565A8_64x64);
LV_IMAGE_DECLARE(_lights_RGB565A8_64x64);
LV_IMAGE_DECLARE(_computer_RGB565A8_60x60);
LV_IMAGE_DECLARE(_calendar_RGB565A8_68x68);
LV_IMAGE_DECLARE(_robot_RGB565A8_59x59);
LV_IMAGE_DECLARE(_calculator_RGB565A8_55x55);
LV_IMAGE_DECLARE(_wifi_big_RGB565A8_64x55);
LV_IMAGE_DECLARE(_back_RGB565A8_32x32);
LV_IMAGE_DECLARE(_qing_RGB565A8_64x64);
LV_IMAGE_DECLARE(_yu_RGB565A8_64x64);
LV_IMAGE_DECLARE(_yun_RGB565A8_64x64);
LV_IMAGE_DECLARE(_back_RGB565A8_25x25);
LV_IMAGE_DECLARE(_back_RGB565A8_22x22);
LV_IMAGE_DECLARE(_back_RGB565A8_24x24);

LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_35)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_20)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_15)
LV_FONT_DECLARE(lv_font_montserratMedium_15)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_25)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_18)
LV_FONT_DECLARE(lv_customer_font_ZiTiQuanWeiJunHeiW22_20)

#ifdef __cplusplus
}
#endif
#endif
