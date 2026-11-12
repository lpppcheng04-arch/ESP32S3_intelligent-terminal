/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



int screen_first_page_digital_clock_time_min_value = 25;
int screen_first_page_digital_clock_time_hour_value = 11;
int screen_first_page_digital_clock_time_sec_value = 50;
void setup_scr_screen_first_page(lv_ui *ui)
{
    //Write codes screen_first_page
    ui->screen_first_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_first_page, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_first_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_first_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_first_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_first_page, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_first_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_first_page_digital_clock_time
    static bool screen_first_page_digital_clock_time_timer_enabled = false;
    ui->screen_first_page_digital_clock_time = lv_label_create(ui->screen_first_page);
    lv_obj_set_pos(ui->screen_first_page_digital_clock_time, 63, 12);
    lv_obj_set_size(ui->screen_first_page_digital_clock_time, 179, 40);
    lv_label_set_text(ui->screen_first_page_digital_clock_time, "11:25:50");
    if (!screen_first_page_digital_clock_time_timer_enabled) {
        lv_timer_create(screen_first_page_digital_clock_time_timer, 1000, NULL);
        screen_first_page_digital_clock_time_timer_enabled = true;
    }

    //Write style for screen_first_page_digital_clock_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_first_page_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_first_page_digital_clock_time, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_first_page_digital_clock_time, &lv_font_ZiTiQuanWeiJunHeiW22_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_first_page_digital_clock_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_first_page_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_first_page_digital_clock_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_first_page_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_first_page_digital_clock_time, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_first_page_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_first_page_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_first_page_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_first_page_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_first_page_label_setting
    ui->screen_first_page_label_setting = lv_label_create(ui->screen_first_page);
    lv_obj_set_pos(ui->screen_first_page_label_setting, 14, 196);
    lv_obj_set_size(ui->screen_first_page_label_setting, 65, 32);
    lv_label_set_text(ui->screen_first_page_label_setting, "设置");
    lv_label_set_long_mode(ui->screen_first_page_label_setting, LV_LABEL_LONG_WRAP);

    //Write style for screen_first_page_label_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_first_page_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_first_page_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_first_page_label_setting, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_first_page_label_setting, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_first_page_label_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_first_page_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_first_page_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_first_page_label_setting, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_first_page_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_first_page_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_first_page_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_first_page_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_first_page_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_first_page_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_first_page_label_weather
    ui->screen_first_page_label_weather = lv_label_create(ui->screen_first_page);
    lv_obj_set_pos(ui->screen_first_page_label_weather, 88, 196);
    lv_obj_set_size(ui->screen_first_page_label_weather, 65, 32);
    lv_label_set_text(ui->screen_first_page_label_weather, "天气");
    lv_label_set_long_mode(ui->screen_first_page_label_weather, LV_LABEL_LONG_WRAP);

    //Write style for screen_first_page_label_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_first_page_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_first_page_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_first_page_label_weather, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_first_page_label_weather, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_first_page_label_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_first_page_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_first_page_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_first_page_label_weather, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_first_page_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_first_page_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_first_page_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_first_page_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_first_page_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_first_page_label_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_first_page_label_light
    ui->screen_first_page_label_light = lv_label_create(ui->screen_first_page);
    lv_obj_set_pos(ui->screen_first_page_label_light, 169, 196);
    lv_obj_set_size(ui->screen_first_page_label_light, 65, 32);
    lv_label_set_text(ui->screen_first_page_label_light, "灯光");
    lv_label_set_long_mode(ui->screen_first_page_label_light, LV_LABEL_LONG_WRAP);

    //Write style for screen_first_page_label_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_first_page_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_first_page_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_first_page_label_light, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_first_page_label_light, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_first_page_label_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_first_page_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_first_page_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_first_page_label_light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_first_page_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_first_page_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_first_page_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_first_page_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_first_page_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_first_page_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_first_page_label_serial
    ui->screen_first_page_label_serial = lv_label_create(ui->screen_first_page);
    lv_obj_set_pos(ui->screen_first_page_label_serial, 251, 196);
    lv_obj_set_size(ui->screen_first_page_label_serial, 65, 32);
    lv_label_set_text(ui->screen_first_page_label_serial, "串口");
    lv_label_set_long_mode(ui->screen_first_page_label_serial, LV_LABEL_LONG_WRAP);

    //Write style for screen_first_page_label_serial, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_first_page_label_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_first_page_label_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_first_page_label_serial, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_first_page_label_serial, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_first_page_label_serial, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_first_page_label_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_first_page_label_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_first_page_label_serial, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_first_page_label_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_first_page_label_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_first_page_label_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_first_page_label_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_first_page_label_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_first_page_label_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_first_page_img_setting
    ui->screen_first_page_img_setting = lv_image_create(ui->screen_first_page);
    lv_obj_set_pos(ui->screen_first_page_img_setting, 14, 132);
    lv_obj_set_size(ui->screen_first_page_img_setting, 64, 64);
    lv_obj_add_flag(ui->screen_first_page_img_setting, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_first_page_img_setting, &_set_RGB565A8_64x64);
    lv_image_set_pivot(ui->screen_first_page_img_setting, 64,64);
    lv_image_set_rotation(ui->screen_first_page_img_setting, 0);

    //Write style for screen_first_page_img_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_first_page_img_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_first_page_img_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_first_page_img_weather
    ui->screen_first_page_img_weather = lv_image_create(ui->screen_first_page);
    lv_obj_set_pos(ui->screen_first_page_img_weather, 88, 132);
    lv_obj_set_size(ui->screen_first_page_img_weather, 64, 64);
    lv_obj_add_flag(ui->screen_first_page_img_weather, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_first_page_img_weather, &_weather_RGB565A8_64x64);
    lv_image_set_pivot(ui->screen_first_page_img_weather, 64,64);
    lv_image_set_rotation(ui->screen_first_page_img_weather, 0);

    //Write style for screen_first_page_img_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_first_page_img_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_first_page_img_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_first_page_img_serial
    ui->screen_first_page_img_serial = lv_image_create(ui->screen_first_page);
    lv_obj_set_pos(ui->screen_first_page_img_serial, 248, 132);
    lv_obj_set_size(ui->screen_first_page_img_serial, 64, 64);
    lv_obj_add_flag(ui->screen_first_page_img_serial, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_first_page_img_serial, &_serial_RGB565A8_64x64);
    lv_image_set_pivot(ui->screen_first_page_img_serial, 50,50);
    lv_image_set_rotation(ui->screen_first_page_img_serial, 0);

    //Write style for screen_first_page_img_serial, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_first_page_img_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_first_page_img_serial, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_first_page_img_light
    ui->screen_first_page_img_light = lv_image_create(ui->screen_first_page);
    lv_obj_set_pos(ui->screen_first_page_img_light, 169, 128);
    lv_obj_set_size(ui->screen_first_page_img_light, 64, 64);
    lv_obj_add_flag(ui->screen_first_page_img_light, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_first_page_img_light, &_lights_RGB565A8_64x64);
    lv_image_set_pivot(ui->screen_first_page_img_light, 50,50);
    lv_image_set_rotation(ui->screen_first_page_img_light, 0);

    //Write style for screen_first_page_img_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_first_page_img_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_first_page_img_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_first_page_label_date
    ui->screen_first_page_label_date = lv_label_create(ui->screen_first_page);
    lv_obj_set_pos(ui->screen_first_page_label_date, 8, 71);
    lv_obj_set_size(ui->screen_first_page_label_date, 168, 23);
    lv_label_set_text(ui->screen_first_page_label_date, "2026年8月19日");
    lv_label_set_long_mode(ui->screen_first_page_label_date, LV_LABEL_LONG_WRAP);

    //Write style for screen_first_page_label_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_first_page_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_first_page_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_first_page_label_date, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_first_page_label_date, &lv_customer_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_first_page_label_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_first_page_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_first_page_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_first_page_label_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_first_page_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_first_page_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_first_page_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_first_page_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_first_page_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_first_page_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_first_page_label_week
    ui->screen_first_page_label_week = lv_label_create(ui->screen_first_page);
    lv_obj_set_pos(ui->screen_first_page_label_week, 199, 71);
    lv_obj_set_size(ui->screen_first_page_label_week, 100, 32);
    lv_label_set_text(ui->screen_first_page_label_week, "星期三");
    lv_label_set_long_mode(ui->screen_first_page_label_week, LV_LABEL_LONG_WRAP);

    //Write style for screen_first_page_label_week, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_first_page_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_first_page_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_first_page_label_week, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_first_page_label_week, &lv_customer_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_first_page_label_week, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_first_page_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_first_page_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_first_page_label_week, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_first_page_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_first_page_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_first_page_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_first_page_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_first_page_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_first_page_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_first_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_first_page);

    //Init events for screen.
    events_init_screen_first_page(ui);
}
