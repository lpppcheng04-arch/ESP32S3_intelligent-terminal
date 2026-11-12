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



void setup_scr_screen_weather(lv_ui *ui)
{
    //Write codes screen_weather
    ui->screen_weather = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_weather, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_weather, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_weather, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_weather, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_weather_label_today
    ui->screen_weather_label_today = lv_label_create(ui->screen_weather);
    lv_obj_set_pos(ui->screen_weather_label_today, 10, 49);
    lv_obj_set_size(ui->screen_weather_label_today, 77, 32);
    lv_label_set_text(ui->screen_weather_label_today, "今日");
    lv_label_set_long_mode(ui->screen_weather_label_today, LV_LABEL_LONG_WRAP);

    //Write style for screen_weather_label_today, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_weather_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_weather_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_weather_label_today, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_weather_label_today, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_weather_label_today, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_weather_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_weather_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_weather_label_today, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_weather_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_weather_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_weather_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_weather_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_weather_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_weather_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_weather_label_tomorrow
    ui->screen_weather_label_tomorrow = lv_label_create(ui->screen_weather);
    lv_obj_set_pos(ui->screen_weather_label_tomorrow, 107, 49);
    lv_obj_set_size(ui->screen_weather_label_tomorrow, 100, 32);
    lv_label_set_text(ui->screen_weather_label_tomorrow, "明日");
    lv_label_set_long_mode(ui->screen_weather_label_tomorrow, LV_LABEL_LONG_WRAP);

    //Write style for screen_weather_label_tomorrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_weather_label_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_weather_label_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_weather_label_tomorrow, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_weather_label_tomorrow, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_weather_label_tomorrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_weather_label_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_weather_label_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_weather_label_tomorrow, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_weather_label_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_weather_label_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_weather_label_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_weather_label_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_weather_label_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_weather_label_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_weather_label_after
    ui->screen_weather_label_after = lv_label_create(ui->screen_weather);
    lv_obj_set_pos(ui->screen_weather_label_after, 218, 49);
    lv_obj_set_size(ui->screen_weather_label_after, 100, 32);
    lv_label_set_text(ui->screen_weather_label_after, "后日");
    lv_label_set_long_mode(ui->screen_weather_label_after, LV_LABEL_LONG_WRAP);

    //Write style for screen_weather_label_after, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_weather_label_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_weather_label_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_weather_label_after, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_weather_label_after, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_weather_label_after, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_weather_label_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_weather_label_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_weather_label_after, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_weather_label_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_weather_label_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_weather_label_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_weather_label_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_weather_label_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_weather_label_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_weather_img_today
    ui->screen_weather_img_today = lv_image_create(ui->screen_weather);
    lv_obj_set_pos(ui->screen_weather_img_today, 17, 91);
    lv_obj_set_size(ui->screen_weather_img_today, 64, 64);
    lv_obj_add_flag(ui->screen_weather_img_today, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_weather_img_today, &_qing_RGB565A8_64x64);
    lv_image_set_pivot(ui->screen_weather_img_today, 50,50);
    lv_image_set_rotation(ui->screen_weather_img_today, 0);

    //Write style for screen_weather_img_today, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_weather_img_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_weather_img_today, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_weather_img_tomorrow
    ui->screen_weather_img_tomorrow = lv_image_create(ui->screen_weather);
    lv_obj_set_pos(ui->screen_weather_img_tomorrow, 126, 91);
    lv_obj_set_size(ui->screen_weather_img_tomorrow, 64, 64);
    lv_obj_add_flag(ui->screen_weather_img_tomorrow, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_weather_img_tomorrow, &_yu_RGB565A8_64x64);
    lv_image_set_pivot(ui->screen_weather_img_tomorrow, 50,50);
    lv_image_set_rotation(ui->screen_weather_img_tomorrow, 0);

    //Write style for screen_weather_img_tomorrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_weather_img_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_weather_img_tomorrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_weather_img_after
    ui->screen_weather_img_after = lv_image_create(ui->screen_weather);
    lv_obj_set_pos(ui->screen_weather_img_after, 239, 91);
    lv_obj_set_size(ui->screen_weather_img_after, 64, 64);
    lv_obj_add_flag(ui->screen_weather_img_after, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_weather_img_after, &_yun_RGB565A8_64x64);
    lv_image_set_pivot(ui->screen_weather_img_after, 50,50);
    lv_image_set_rotation(ui->screen_weather_img_after, 0);

    //Write style for screen_weather_img_after, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_weather_img_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_weather_img_after, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_weather_label_temp_today
    ui->screen_weather_label_temp_today = lv_label_create(ui->screen_weather);
    lv_obj_set_pos(ui->screen_weather_label_temp_today, 10, 179);
    lv_obj_set_size(ui->screen_weather_label_temp_today, 89, 32);
    lv_label_set_text(ui->screen_weather_label_temp_today, "28-32℃");
    lv_label_set_long_mode(ui->screen_weather_label_temp_today, LV_LABEL_LONG_WRAP);

    //Write style for screen_weather_label_temp_today, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_weather_label_temp_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_weather_label_temp_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_weather_label_temp_today, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_weather_label_temp_today, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_weather_label_temp_today, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_weather_label_temp_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_weather_label_temp_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_weather_label_temp_today, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_weather_label_temp_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_weather_label_temp_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_weather_label_temp_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_weather_label_temp_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_weather_label_temp_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_weather_label_temp_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_weather_label_temp_tomorrow
    ui->screen_weather_label_temp_tomorrow = lv_label_create(ui->screen_weather);
    lv_obj_set_pos(ui->screen_weather_label_temp_tomorrow, 117, 179);
    lv_obj_set_size(ui->screen_weather_label_temp_tomorrow, 89, 32);
    lv_label_set_text(ui->screen_weather_label_temp_tomorrow, "25-29℃");
    lv_label_set_long_mode(ui->screen_weather_label_temp_tomorrow, LV_LABEL_LONG_WRAP);

    //Write style for screen_weather_label_temp_tomorrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_weather_label_temp_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_weather_label_temp_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_weather_label_temp_tomorrow, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_weather_label_temp_tomorrow, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_weather_label_temp_tomorrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_weather_label_temp_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_weather_label_temp_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_weather_label_temp_tomorrow, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_weather_label_temp_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_weather_label_temp_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_weather_label_temp_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_weather_label_temp_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_weather_label_temp_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_weather_label_temp_tomorrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_weather_label_temp_after
    ui->screen_weather_label_temp_after = lv_label_create(ui->screen_weather);
    lv_obj_set_pos(ui->screen_weather_label_temp_after, 225, 179);
    lv_obj_set_size(ui->screen_weather_label_temp_after, 89, 32);
    lv_label_set_text(ui->screen_weather_label_temp_after, "26-30℃");
    lv_label_set_long_mode(ui->screen_weather_label_temp_after, LV_LABEL_LONG_WRAP);

    //Write style for screen_weather_label_temp_after, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_weather_label_temp_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_weather_label_temp_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_weather_label_temp_after, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_weather_label_temp_after, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_weather_label_temp_after, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_weather_label_temp_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_weather_label_temp_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_weather_label_temp_after, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_weather_label_temp_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_weather_label_temp_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_weather_label_temp_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_weather_label_temp_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_weather_label_temp_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_weather_label_temp_after, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_weather_img_back
    ui->screen_weather_img_back = lv_image_create(ui->screen_weather);
    lv_obj_set_pos(ui->screen_weather_img_back, 5, 8);
    lv_obj_set_size(ui->screen_weather_img_back, 25, 25);
    lv_obj_add_flag(ui->screen_weather_img_back, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_weather_img_back, &_back_RGB565A8_25x25);
    lv_image_set_pivot(ui->screen_weather_img_back, 50,50);
    lv_image_set_rotation(ui->screen_weather_img_back, 0);

    //Write style for screen_weather_img_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_weather_img_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->screen_weather_img_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_weather_img_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_weather.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_weather);

    //Init events for screen.
    events_init_screen_weather(ui);
}
