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



void setup_scr_screen_serial(lv_ui *ui)
{
    //Write codes screen_serial
    ui->screen_serial = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_serial, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_serial, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_serial, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_serial, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_serial, lv_color_hex(0xf8fbba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_serial, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serial_ta_send
    ui->screen_serial_ta_send = lv_textarea_create(ui->screen_serial);
    lv_obj_set_pos(ui->screen_serial_ta_send, 26, 74);
    lv_obj_set_size(ui->screen_serial_ta_send, 200, 60);
    lv_textarea_set_text(ui->screen_serial_ta_send, "Hello World");
    lv_textarea_set_placeholder_text(ui->screen_serial_ta_send, "");
    lv_textarea_set_password_bullet(ui->screen_serial_ta_send, "*");
    lv_textarea_set_password_mode(ui->screen_serial_ta_send, false);
    lv_textarea_set_one_line(ui->screen_serial_ta_send, false);
    lv_textarea_set_accepted_chars(ui->screen_serial_ta_send, "");
    lv_textarea_set_max_length(ui->screen_serial_ta_send, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_serial_ta_send, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_serial_ta_send, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_serial_ta_send, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serial_ta_send, &lv_font_ZiTiQuanWeiJunHeiW22_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serial_ta_send, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_serial_ta_send, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serial_ta_send, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_serial_ta_send, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_serial_ta_send, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_serial_ta_send, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_serial_ta_send, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_serial_ta_send, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_serial_ta_send, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_serial_ta_send, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serial_ta_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_serial_ta_send, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_serial_ta_send, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_serial_ta_send, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serial_ta_send, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_serial_ta_send, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_serial_ta_send, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_serial_ta_send, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_serial_ta_send, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serial_ta_send, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_serial_ta_receive
    ui->screen_serial_ta_receive = lv_textarea_create(ui->screen_serial);
    lv_obj_set_pos(ui->screen_serial_ta_receive, 26, 169);
    lv_obj_set_size(ui->screen_serial_ta_receive, 200, 60);
    lv_textarea_set_text(ui->screen_serial_ta_receive, "Hello");
    lv_textarea_set_placeholder_text(ui->screen_serial_ta_receive, "");
    lv_textarea_set_password_bullet(ui->screen_serial_ta_receive, "*");
    lv_textarea_set_password_mode(ui->screen_serial_ta_receive, false);
    lv_textarea_set_one_line(ui->screen_serial_ta_receive, false);
    lv_textarea_set_accepted_chars(ui->screen_serial_ta_receive, "");
    lv_textarea_set_max_length(ui->screen_serial_ta_receive, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_serial_ta_receive, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_serial_ta_receive, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_serial_ta_receive, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serial_ta_receive, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serial_ta_receive, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_serial_ta_receive, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serial_ta_receive, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_serial_ta_receive, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_serial_ta_receive, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_serial_ta_receive, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_serial_ta_receive, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_serial_ta_receive, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_serial_ta_receive, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_serial_ta_receive, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serial_ta_receive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_serial_ta_receive, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_serial_ta_receive, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_serial_ta_receive, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serial_ta_receive, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_serial_ta_receive, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_serial_ta_receive, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_serial_ta_receive, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_serial_ta_receive, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serial_ta_receive, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_serial_label_send
    ui->screen_serial_label_send = lv_label_create(ui->screen_serial);
    lv_obj_set_pos(ui->screen_serial_label_send, 9, 42);
    lv_obj_set_size(ui->screen_serial_label_send, 85, 32);
    lv_label_set_text(ui->screen_serial_label_send, "发送区");
    lv_label_set_long_mode(ui->screen_serial_label_send, LV_LABEL_LONG_WRAP);

    //Write style for screen_serial_label_send, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_serial_label_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serial_label_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_serial_label_send, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serial_label_send, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serial_label_send, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_serial_label_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_serial_label_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serial_label_send, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_serial_label_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_serial_label_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_serial_label_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_serial_label_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_serial_label_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serial_label_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serial_label_receive
    ui->screen_serial_label_receive = lv_label_create(ui->screen_serial);
    lv_obj_set_pos(ui->screen_serial_label_receive, 9, 141);
    lv_obj_set_size(ui->screen_serial_label_receive, 85, 32);
    lv_label_set_text(ui->screen_serial_label_receive, "接收区");
    lv_label_set_long_mode(ui->screen_serial_label_receive, LV_LABEL_LONG_WRAP);

    //Write style for screen_serial_label_receive, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_serial_label_receive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serial_label_receive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_serial_label_receive, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serial_label_receive, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serial_label_receive, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_serial_label_receive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_serial_label_receive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serial_label_receive, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_serial_label_receive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_serial_label_receive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_serial_label_receive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_serial_label_receive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_serial_label_receive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serial_label_receive, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serial_btn_send
    ui->screen_serial_btn_send = lv_button_create(ui->screen_serial);
    lv_obj_set_pos(ui->screen_serial_btn_send, 236, 87);
    lv_obj_set_size(ui->screen_serial_btn_send, 74, 41);
    ui->screen_serial_btn_send_label = lv_label_create(ui->screen_serial_btn_send);
    lv_label_set_text(ui->screen_serial_btn_send_label, "发送");
    lv_label_set_long_mode(ui->screen_serial_btn_send_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_serial_btn_send_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_serial_btn_send, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_serial_btn_send_label, LV_PCT(100));

    //Write style for screen_serial_btn_send, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_serial_btn_send, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_serial_btn_send, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_serial_btn_send, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_serial_btn_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serial_btn_send, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serial_btn_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_serial_btn_send, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serial_btn_send, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serial_btn_send, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serial_btn_send, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serial_btn_clear
    ui->screen_serial_btn_clear = lv_button_create(ui->screen_serial);
    lv_obj_set_pos(ui->screen_serial_btn_clear, 236, 181);
    lv_obj_set_size(ui->screen_serial_btn_clear, 74, 41);
    ui->screen_serial_btn_clear_label = lv_label_create(ui->screen_serial_btn_clear);
    lv_label_set_text(ui->screen_serial_btn_clear_label, "清空");
    lv_label_set_long_mode(ui->screen_serial_btn_clear_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_serial_btn_clear_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_serial_btn_clear, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_serial_btn_clear_label, LV_PCT(100));

    //Write style for screen_serial_btn_clear, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_serial_btn_clear, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_serial_btn_clear, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_serial_btn_clear, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_serial_btn_clear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serial_btn_clear, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serial_btn_clear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_serial_btn_clear, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serial_btn_clear, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serial_btn_clear, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serial_btn_clear, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serial_img_1
    ui->screen_serial_img_1 = lv_image_create(ui->screen_serial);
    lv_obj_set_pos(ui->screen_serial_img_1, 2, 5);
    lv_obj_set_size(ui->screen_serial_img_1, 32, 32);
    lv_obj_add_flag(ui->screen_serial_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_serial_img_1, &_back_RGB565A8_32x32);
    lv_image_set_pivot(ui->screen_serial_img_1, 50,50);
    lv_image_set_rotation(ui->screen_serial_img_1, 0);

    //Write style for screen_serial_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_serial_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_serial_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_serial.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_serial);

    //Init events for screen.
    events_init_screen_serial(ui);
}
