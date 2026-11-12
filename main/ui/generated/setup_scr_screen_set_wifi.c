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



void setup_scr_screen_set_wifi(lv_ui *ui)
{
    //Write codes screen_set_wifi
    ui->screen_set_wifi = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_set_wifi, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_set_wifi, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_set_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_set_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_set_wifi, lv_color_hex(0xa1d2ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_set_wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_set_wifi_label_ssid
    ui->screen_set_wifi_label_ssid = lv_label_create(ui->screen_set_wifi);
    lv_obj_set_pos(ui->screen_set_wifi_label_ssid, 9, 108);
    lv_obj_set_size(ui->screen_set_wifi_label_ssid, 64, 23);
    lv_label_set_text(ui->screen_set_wifi_label_ssid, "SSID");
    lv_label_set_long_mode(ui->screen_set_wifi_label_ssid, LV_LABEL_LONG_WRAP);

    //Write style for screen_set_wifi_label_ssid, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_set_wifi_label_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_set_wifi_label_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_set_wifi_label_ssid, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_set_wifi_label_ssid, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_set_wifi_label_ssid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_set_wifi_label_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_set_wifi_label_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_set_wifi_label_ssid, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_set_wifi_label_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_set_wifi_label_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_set_wifi_label_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_set_wifi_label_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_set_wifi_label_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_set_wifi_label_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_set_wifi_label_password
    ui->screen_set_wifi_label_password = lv_label_create(ui->screen_set_wifi);
    lv_obj_set_pos(ui->screen_set_wifi_label_password, 9, 158);
    lv_obj_set_size(ui->screen_set_wifi_label_password, 62, 32);
    lv_label_set_text(ui->screen_set_wifi_label_password, "密码");
    lv_label_set_long_mode(ui->screen_set_wifi_label_password, LV_LABEL_LONG_WRAP);

    //Write style for screen_set_wifi_label_password, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_set_wifi_label_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_set_wifi_label_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_set_wifi_label_password, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_set_wifi_label_password, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_set_wifi_label_password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_set_wifi_label_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_set_wifi_label_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_set_wifi_label_password, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_set_wifi_label_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_set_wifi_label_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_set_wifi_label_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_set_wifi_label_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_set_wifi_label_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_set_wifi_label_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_set_wifi_ta_ssid
    ui->screen_set_wifi_ta_ssid = lv_textarea_create(ui->screen_set_wifi);
    lv_obj_set_pos(ui->screen_set_wifi_ta_ssid, 84, 99);
    lv_obj_set_size(ui->screen_set_wifi_ta_ssid, 168, 32);
    lv_textarea_set_text(ui->screen_set_wifi_ta_ssid, "Bespoke");
    lv_textarea_set_placeholder_text(ui->screen_set_wifi_ta_ssid, "");
    lv_textarea_set_password_bullet(ui->screen_set_wifi_ta_ssid, "*");
    lv_textarea_set_password_mode(ui->screen_set_wifi_ta_ssid, false);
    lv_textarea_set_one_line(ui->screen_set_wifi_ta_ssid, false);
    lv_textarea_set_accepted_chars(ui->screen_set_wifi_ta_ssid, "");
    lv_textarea_set_max_length(ui->screen_set_wifi_ta_ssid, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_set_wifi_ta_ssid, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_set_wifi_ta_ssid, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_set_wifi_ta_ssid, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_set_wifi_ta_ssid, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_set_wifi_ta_ssid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_set_wifi_ta_ssid, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_set_wifi_ta_ssid, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_set_wifi_ta_ssid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_set_wifi_ta_ssid, lv_color_hex(0xfffbfb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_set_wifi_ta_ssid, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_set_wifi_ta_ssid, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_set_wifi_ta_ssid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_set_wifi_ta_ssid, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_set_wifi_ta_ssid, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_set_wifi_ta_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_set_wifi_ta_ssid, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_set_wifi_ta_ssid, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_set_wifi_ta_ssid, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_set_wifi_ta_ssid, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_set_wifi_ta_ssid, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_set_wifi_ta_ssid, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_set_wifi_ta_ssid, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_set_wifi_ta_ssid, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_set_wifi_ta_ssid, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_set_wifi_ta_password
    ui->screen_set_wifi_ta_password = lv_textarea_create(ui->screen_set_wifi);
    lv_obj_set_pos(ui->screen_set_wifi_ta_password, 84, 150);
    lv_obj_set_size(ui->screen_set_wifi_ta_password, 169, 31);
    lv_textarea_set_text(ui->screen_set_wifi_ta_password, "Habitat888");
    lv_textarea_set_placeholder_text(ui->screen_set_wifi_ta_password, "");
    lv_textarea_set_password_bullet(ui->screen_set_wifi_ta_password, "*");
    lv_textarea_set_password_mode(ui->screen_set_wifi_ta_password, false);
    lv_textarea_set_one_line(ui->screen_set_wifi_ta_password, false);
    lv_textarea_set_accepted_chars(ui->screen_set_wifi_ta_password, "");
    lv_textarea_set_max_length(ui->screen_set_wifi_ta_password, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_set_wifi_ta_password, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_set_wifi_ta_password, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_set_wifi_ta_password, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_set_wifi_ta_password, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_set_wifi_ta_password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_set_wifi_ta_password, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_set_wifi_ta_password, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_set_wifi_ta_password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_set_wifi_ta_password, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_set_wifi_ta_password, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_set_wifi_ta_password, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_set_wifi_ta_password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_set_wifi_ta_password, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_set_wifi_ta_password, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_set_wifi_ta_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_set_wifi_ta_password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_set_wifi_ta_password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_set_wifi_ta_password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_set_wifi_ta_password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_set_wifi_ta_password, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_set_wifi_ta_password, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_set_wifi_ta_password, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_set_wifi_ta_password, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_set_wifi_ta_password, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_set_wifi_label_wifi_status
    ui->screen_set_wifi_label_wifi_status = lv_label_create(ui->screen_set_wifi);
    lv_obj_set_pos(ui->screen_set_wifi_label_wifi_status, 28, 201);
    lv_obj_set_size(ui->screen_set_wifi_label_wifi_status, 100, 24);
    lv_label_set_text(ui->screen_set_wifi_label_wifi_status, "未连接");
    lv_label_set_long_mode(ui->screen_set_wifi_label_wifi_status, LV_LABEL_LONG_WRAP);

    //Write style for screen_set_wifi_label_wifi_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_set_wifi_label_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_set_wifi_label_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_set_wifi_label_wifi_status, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_set_wifi_label_wifi_status, &lv_customer_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_set_wifi_label_wifi_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_set_wifi_label_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_set_wifi_label_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_set_wifi_label_wifi_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_set_wifi_label_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_set_wifi_label_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_set_wifi_label_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_set_wifi_label_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_set_wifi_label_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_set_wifi_label_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_set_wifi_btn_connect
    ui->screen_set_wifi_btn_connect = lv_button_create(ui->screen_set_wifi);
    lv_obj_set_pos(ui->screen_set_wifi_btn_connect, 221, 190);
    lv_obj_set_size(ui->screen_set_wifi_btn_connect, 69, 39);
    ui->screen_set_wifi_btn_connect_label = lv_label_create(ui->screen_set_wifi_btn_connect);
    lv_label_set_text(ui->screen_set_wifi_btn_connect_label, "连接");
    lv_label_set_long_mode(ui->screen_set_wifi_btn_connect_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_set_wifi_btn_connect_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_set_wifi_btn_connect, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_set_wifi_btn_connect_label, LV_PCT(100));

    //Write style for screen_set_wifi_btn_connect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_set_wifi_btn_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_set_wifi_btn_connect, lv_color_hex(0xfcefa0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_set_wifi_btn_connect, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_set_wifi_btn_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_set_wifi_btn_connect, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_set_wifi_btn_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_set_wifi_btn_connect, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_set_wifi_btn_connect, &lv_customer_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_set_wifi_btn_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_set_wifi_btn_connect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_set_wifi_wifi
    ui->screen_set_wifi_wifi = lv_image_create(ui->screen_set_wifi);
    lv_obj_set_pos(ui->screen_set_wifi_wifi, 127, 7);
    lv_obj_set_size(ui->screen_set_wifi_wifi, 64, 55);
    lv_obj_add_flag(ui->screen_set_wifi_wifi, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_set_wifi_wifi, &_wifi_big_RGB565A8_64x55);
    lv_image_set_pivot(ui->screen_set_wifi_wifi, 50,50);
    lv_image_set_rotation(ui->screen_set_wifi_wifi, 0);

    //Write style for screen_set_wifi_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_set_wifi_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_set_wifi_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_set_wifi_label_4
    ui->screen_set_wifi_label_4 = lv_label_create(ui->screen_set_wifi);
    lv_obj_set_pos(ui->screen_set_wifi_label_4, 113, 70);
    lv_obj_set_size(ui->screen_set_wifi_label_4, 100, 24);
    lv_label_set_text(ui->screen_set_wifi_label_4, "WI-FI连接");
    lv_label_set_long_mode(ui->screen_set_wifi_label_4, LV_LABEL_LONG_WRAP);

    //Write style for screen_set_wifi_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_set_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_set_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_set_wifi_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_set_wifi_label_4, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_set_wifi_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_set_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_set_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_set_wifi_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_set_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_set_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_set_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_set_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_set_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_set_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_set_wifi_img_back
    ui->screen_set_wifi_img_back = lv_image_create(ui->screen_set_wifi);
    lv_obj_set_pos(ui->screen_set_wifi_img_back, 9, 15);
    lv_obj_set_size(ui->screen_set_wifi_img_back, 32, 32);
    lv_obj_add_flag(ui->screen_set_wifi_img_back, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_set_wifi_img_back, &_back_RGB565A8_32x32);
    lv_image_set_pivot(ui->screen_set_wifi_img_back, 50,50);
    lv_image_set_rotation(ui->screen_set_wifi_img_back, 0);

    //Write style for screen_set_wifi_img_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_set_wifi_img_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_set_wifi_img_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_set_wifi.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_set_wifi);

    //Init events for screen.
    events_init_screen_set_wifi(ui);
}
