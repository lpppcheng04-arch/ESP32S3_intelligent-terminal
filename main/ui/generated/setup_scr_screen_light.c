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



void setup_scr_screen_light(lv_ui *ui)
{
    //Write codes screen_light
    ui->screen_light = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_light, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_light, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_light_label_switch
    ui->screen_light_label_switch = lv_label_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_label_switch, 15, 35);
    lv_obj_set_size(ui->screen_light_label_switch, 100, 32);
    lv_label_set_text(ui->screen_light_label_switch, "主灯开关");
    lv_label_set_long_mode(ui->screen_light_label_switch, LV_LABEL_LONG_WRAP);

    //Write style for screen_light_label_switch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_light_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_light_label_switch, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_light_label_switch, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_light_label_switch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_light_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_light_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_light_label_switch, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_light_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_light_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_light_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_light_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_light_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_light_label_Brightness
    ui->screen_light_label_Brightness = lv_label_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_label_Brightness, 10, 80);
    lv_obj_set_size(ui->screen_light_label_Brightness, 100, 32);
    lv_label_set_text(ui->screen_light_label_Brightness, "主灯明暗度");
    lv_label_set_long_mode(ui->screen_light_label_Brightness, LV_LABEL_LONG_WRAP);

    //Write style for screen_light_label_Brightness, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_light_label_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_label_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_light_label_Brightness, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_light_label_Brightness, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_light_label_Brightness, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_light_label_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_light_label_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_light_label_Brightness, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_light_label_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_light_label_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_light_label_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_light_label_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_light_label_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_label_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_light_sw_1
    ui->screen_light_sw_1 = lv_switch_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_sw_1, 130, 35);
    lv_obj_set_size(ui->screen_light_sw_1, 40, 20);

    //Write style for screen_light_sw_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_light_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_sw_1, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_sw_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_light_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_sw_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_light_sw_1, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_light_sw_1, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_light_sw_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_sw_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_light_sw_1, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_light_sw_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_light_sw_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_sw_1, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_sw_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_light_sw_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_sw_1, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_light_slider_Brightness
    ui->screen_light_slider_Brightness = lv_slider_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_slider_Brightness, 130, 89);
    lv_obj_set_size(ui->screen_light_slider_Brightness, 160, 8);
    lv_slider_set_range(ui->screen_light_slider_Brightness, 0, 100);
    lv_slider_set_mode(ui->screen_light_slider_Brightness, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->screen_light_slider_Brightness, 0, LV_ANIM_OFF);

    //Write style for screen_light_slider_Brightness, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_light_slider_Brightness, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_slider_Brightness, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_slider_Brightness, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_slider_Brightness, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->screen_light_slider_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_slider_Brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_light_slider_Brightness, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_light_slider_Brightness, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_slider_Brightness, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_slider_Brightness, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_slider_Brightness, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_light_slider_Brightness, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_light_slider_Brightness, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_slider_Brightness, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_slider_Brightness, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_slider_Brightness, 8, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_light_label_RGB
    ui->screen_light_label_RGB = lv_label_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_label_RGB, 10, 118);
    lv_obj_set_size(ui->screen_light_label_RGB, 100, 32);
    lv_label_set_text(ui->screen_light_label_RGB, "RGB调色");
    lv_label_set_long_mode(ui->screen_light_label_RGB, LV_LABEL_LONG_WRAP);

    //Write style for screen_light_label_RGB, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_light_label_RGB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_label_RGB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_light_label_RGB, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_light_label_RGB, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_light_label_RGB, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_light_label_RGB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_light_label_RGB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_light_label_RGB, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_light_label_RGB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_light_label_RGB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_light_label_RGB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_light_label_RGB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_light_label_RGB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_label_RGB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_light_ta_R
    ui->screen_light_ta_R = lv_textarea_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_ta_R, 23, 185);
    lv_obj_set_size(ui->screen_light_ta_R, 55, 28);
    lv_textarea_set_text(ui->screen_light_ta_R, "0");
    lv_textarea_set_placeholder_text(ui->screen_light_ta_R, "");
    lv_textarea_set_password_bullet(ui->screen_light_ta_R, "*");
    lv_textarea_set_password_mode(ui->screen_light_ta_R, false);
    lv_textarea_set_one_line(ui->screen_light_ta_R, false);
    lv_textarea_set_accepted_chars(ui->screen_light_ta_R, "");
    lv_textarea_set_max_length(ui->screen_light_ta_R, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_light_ta_R, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_light_ta_R, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_light_ta_R, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_light_ta_R, &lv_font_ZiTiQuanWeiJunHeiW22_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_light_ta_R, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_light_ta_R, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_light_ta_R, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_light_ta_R, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_ta_R, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_ta_R, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_light_ta_R, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_light_ta_R, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_light_ta_R, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_light_ta_R, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_ta_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_light_ta_R, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_light_ta_R, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_light_ta_R, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_ta_R, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_light_ta_R, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_light_ta_R, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_ta_R, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_ta_R, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_ta_R, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_light_ta_G
    ui->screen_light_ta_G = lv_textarea_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_ta_G, 126, 185);
    lv_obj_set_size(ui->screen_light_ta_G, 55, 28);
    lv_textarea_set_text(ui->screen_light_ta_G, "0");
    lv_textarea_set_placeholder_text(ui->screen_light_ta_G, "");
    lv_textarea_set_password_bullet(ui->screen_light_ta_G, "*");
    lv_textarea_set_password_mode(ui->screen_light_ta_G, false);
    lv_textarea_set_one_line(ui->screen_light_ta_G, false);
    lv_textarea_set_accepted_chars(ui->screen_light_ta_G, "");
    lv_textarea_set_max_length(ui->screen_light_ta_G, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_light_ta_G, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_light_ta_G, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_light_ta_G, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_light_ta_G, &lv_font_ZiTiQuanWeiJunHeiW22_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_light_ta_G, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_light_ta_G, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_light_ta_G, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_light_ta_G, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_ta_G, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_ta_G, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_light_ta_G, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_light_ta_G, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_light_ta_G, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_light_ta_G, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_ta_G, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_light_ta_G, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_light_ta_G, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_light_ta_G, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_ta_G, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_light_ta_G, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_light_ta_G, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_ta_G, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_ta_G, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_ta_G, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_light_ta_B
    ui->screen_light_ta_B = lv_textarea_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_ta_B, 217, 185);
    lv_obj_set_size(ui->screen_light_ta_B, 55, 28);
    lv_textarea_set_text(ui->screen_light_ta_B, "0");
    lv_textarea_set_placeholder_text(ui->screen_light_ta_B, "");
    lv_textarea_set_password_bullet(ui->screen_light_ta_B, "*");
    lv_textarea_set_password_mode(ui->screen_light_ta_B, false);
    lv_textarea_set_one_line(ui->screen_light_ta_B, false);
    lv_textarea_set_accepted_chars(ui->screen_light_ta_B, "");
    lv_textarea_set_max_length(ui->screen_light_ta_B, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_light_ta_B, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_light_ta_B, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_light_ta_B, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_light_ta_B, &lv_font_ZiTiQuanWeiJunHeiW22_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_light_ta_B, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_light_ta_B, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_light_ta_B, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_light_ta_B, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_ta_B, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_ta_B, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_light_ta_B, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_light_ta_B, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_light_ta_B, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_light_ta_B, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_ta_B, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_light_ta_B, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_light_ta_B, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_light_ta_B, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_ta_B, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_light_ta_B, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_light_ta_B, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_ta_B, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_ta_B, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_ta_B, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_light_label_R
    ui->screen_light_label_R = lv_label_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_label_R, 20, 154);
    lv_obj_set_size(ui->screen_light_label_R, 56, 26);
    lv_label_set_text(ui->screen_light_label_R, "R");
    lv_label_set_long_mode(ui->screen_light_label_R, LV_LABEL_LONG_WRAP);

    //Write style for screen_light_label_R, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_light_label_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_label_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_light_label_R, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_light_label_R, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_light_label_R, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_light_label_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_light_label_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_light_label_R, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_light_label_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_light_label_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_light_label_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_light_label_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_light_label_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_label_R, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_light_label_G
    ui->screen_light_label_G = lv_label_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_label_G, 130, 154);
    lv_obj_set_size(ui->screen_light_label_G, 49, 23);
    lv_label_set_text(ui->screen_light_label_G, "G");
    lv_label_set_long_mode(ui->screen_light_label_G, LV_LABEL_LONG_WRAP);

    //Write style for screen_light_label_G, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_light_label_G, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_label_G, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_light_label_G, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_light_label_G, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_light_label_G, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_light_label_G, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_light_label_G, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_light_label_G, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_light_label_G, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_light_label_G, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_light_label_G, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_light_label_G, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_light_label_G, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_label_G, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_light_label_B
    ui->screen_light_label_B = lv_label_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_label_B, 213, 154);
    lv_obj_set_size(ui->screen_light_label_B, 59, 22);
    lv_label_set_text(ui->screen_light_label_B, "B");
    lv_label_set_long_mode(ui->screen_light_label_B, LV_LABEL_LONG_WRAP);

    //Write style for screen_light_label_B, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_light_label_B, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_label_B, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_light_label_B, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_light_label_B, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_light_label_B, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_light_label_B, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_light_label_B, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_light_label_B, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_light_label_B, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_light_label_B, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_light_label_B, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_light_label_B, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_light_label_B, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_label_B, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_light_img_1
    ui->screen_light_img_1 = lv_image_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_img_1, 7, 5);
    lv_obj_set_size(ui->screen_light_img_1, 25, 25);
    lv_obj_add_flag(ui->screen_light_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_light_img_1, &_back_RGB565A8_25x25);
    lv_image_set_pivot(ui->screen_light_img_1, 50,50);
    lv_image_set_rotation(ui->screen_light_img_1, 0);

    //Write style for screen_light_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_light_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_light_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_light_btn_confirm
    ui->screen_light_btn_confirm = lv_button_create(ui->screen_light);
    lv_obj_set_pos(ui->screen_light_btn_confirm, 130, 118);
    lv_obj_set_size(ui->screen_light_btn_confirm, 66, 31);
    ui->screen_light_btn_confirm_label = lv_label_create(ui->screen_light_btn_confirm);
    lv_label_set_text(ui->screen_light_btn_confirm_label, "确认");
    lv_label_set_long_mode(ui->screen_light_btn_confirm_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_light_btn_confirm_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_light_btn_confirm, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_light_btn_confirm_label, LV_PCT(100));

    //Write style for screen_light_btn_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_light_btn_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_light_btn_confirm, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_light_btn_confirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_light_btn_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_light_btn_confirm, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_light_btn_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_light_btn_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_light_btn_confirm, &lv_customer_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_light_btn_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_light_btn_confirm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_light.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_light);

    //Init events for screen.
    events_init_screen_light(ui);
}
