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



void setup_scr_screen_calculator(lv_ui *ui)
{
    //Write codes screen_calculator
    ui->screen_calculator = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_calculator, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_calculator, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_calculator, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator, lv_color_hex(0xd0d0d0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_cont_1
    ui->screen_calculator_cont_1 = lv_obj_create(ui->screen_calculator);
    lv_obj_set_pos(ui->screen_calculator_cont_1, 11, 57);
    lv_obj_set_size(ui->screen_calculator_cont_1, 300, 176);
    lv_obj_set_scrollbar_mode(ui->screen_calculator_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_calculator_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_calculator_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_calculator_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_calculator_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_calculator_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_calculator_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_calculator_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_calculator_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_calculator_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_calculator_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_2
    ui->screen_calculator_btn_2 = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_2, 76, 110);
    lv_obj_set_size(ui->screen_calculator_btn_2, 60, 25);
    ui->screen_calculator_btn_2_label = lv_label_create(ui->screen_calculator_btn_2);
    lv_label_set_text(ui->screen_calculator_btn_2_label, "2");
    lv_label_set_long_mode(ui->screen_calculator_btn_2_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_2_label, LV_PCT(100));

    //Write style for screen_calculator_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_2, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_2, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_1
    ui->screen_calculator_btn_1 = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_1, 6, 110);
    lv_obj_set_size(ui->screen_calculator_btn_1, 60, 25);
    ui->screen_calculator_btn_1_label = lv_label_create(ui->screen_calculator_btn_1);
    lv_label_set_text(ui->screen_calculator_btn_1_label, "1");
    lv_label_set_long_mode(ui->screen_calculator_btn_1_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_1_label, LV_PCT(100));

    //Write style for screen_calculator_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_1, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_1, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_3
    ui->screen_calculator_btn_3 = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_3, 146, 110);
    lv_obj_set_size(ui->screen_calculator_btn_3, 60, 25);
    ui->screen_calculator_btn_3_label = lv_label_create(ui->screen_calculator_btn_3);
    lv_label_set_text(ui->screen_calculator_btn_3_label, "3");
    lv_label_set_long_mode(ui->screen_calculator_btn_3_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_3_label, LV_PCT(100));

    //Write style for screen_calculator_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_3, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_3, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_equivalent
    ui->screen_calculator_btn_equivalent = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_equivalent, 216, 144);
    lv_obj_set_size(ui->screen_calculator_btn_equivalent, 60, 25);
    ui->screen_calculator_btn_equivalent_label = lv_label_create(ui->screen_calculator_btn_equivalent);
    lv_label_set_text(ui->screen_calculator_btn_equivalent_label, "=");
    lv_label_set_long_mode(ui->screen_calculator_btn_equivalent_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_equivalent_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_equivalent, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_equivalent_label, LV_PCT(100));

    //Write style for screen_calculator_btn_equivalent, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_equivalent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_equivalent, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_equivalent, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_equivalent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_equivalent, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_equivalent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_equivalent, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_equivalent, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_equivalent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_equivalent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_0
    ui->screen_calculator_btn_0 = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_0, 5, 145);
    lv_obj_set_size(ui->screen_calculator_btn_0, 131, 25);
    ui->screen_calculator_btn_0_label = lv_label_create(ui->screen_calculator_btn_0);
    lv_label_set_text(ui->screen_calculator_btn_0_label, "0");
    lv_label_set_long_mode(ui->screen_calculator_btn_0_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_0_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_0, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_0_label, LV_PCT(100));

    //Write style for screen_calculator_btn_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_0, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_0, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_0, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_0, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_0, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_0, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_point
    ui->screen_calculator_btn_point = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_point, 146, 145);
    lv_obj_set_size(ui->screen_calculator_btn_point, 60, 25);
    ui->screen_calculator_btn_point_label = lv_label_create(ui->screen_calculator_btn_point);
    lv_label_set_text(ui->screen_calculator_btn_point_label, ".");
    lv_label_set_long_mode(ui->screen_calculator_btn_point_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_point_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_point, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_point_label, LV_PCT(100));

    //Write style for screen_calculator_btn_point, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_point, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_point, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_point, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_point, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_point, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_point, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_point, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_point, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_point, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_point, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_plus
    ui->screen_calculator_btn_plus = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_plus, 216, 109);
    lv_obj_set_size(ui->screen_calculator_btn_plus, 60, 25);
    ui->screen_calculator_btn_plus_label = lv_label_create(ui->screen_calculator_btn_plus);
    lv_label_set_text(ui->screen_calculator_btn_plus_label, "+");
    lv_label_set_long_mode(ui->screen_calculator_btn_plus_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_plus_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_plus, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_plus_label, LV_PCT(100));

    //Write style for screen_calculator_btn_plus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_plus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_plus, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_plus, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_plus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_plus, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_plus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_plus, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_plus, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_plus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_plus, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_subtract
    ui->screen_calculator_btn_subtract = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_subtract, 216, 75);
    lv_obj_set_size(ui->screen_calculator_btn_subtract, 60, 25);
    ui->screen_calculator_btn_subtract_label = lv_label_create(ui->screen_calculator_btn_subtract);
    lv_label_set_text(ui->screen_calculator_btn_subtract_label, "-");
    lv_label_set_long_mode(ui->screen_calculator_btn_subtract_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_subtract_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_subtract, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_subtract_label, LV_PCT(100));

    //Write style for screen_calculator_btn_subtract, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_subtract, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_subtract, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_subtract, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_subtract, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_subtract, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_subtract, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_subtract, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_subtract, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_subtract, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_subtract, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_multiply
    ui->screen_calculator_btn_multiply = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_multiply, 216, 40);
    lv_obj_set_size(ui->screen_calculator_btn_multiply, 60, 25);
    ui->screen_calculator_btn_multiply_label = lv_label_create(ui->screen_calculator_btn_multiply);
    lv_label_set_text(ui->screen_calculator_btn_multiply_label, "*");
    lv_label_set_long_mode(ui->screen_calculator_btn_multiply_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_multiply_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_multiply, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_multiply_label, LV_PCT(100));

    //Write style for screen_calculator_btn_multiply, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_multiply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_multiply, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_multiply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_multiply, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_multiply, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_multiply, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_multiply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_multiply, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_multiply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_multiply, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_4
    ui->screen_calculator_btn_4 = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_4, 6, 75);
    lv_obj_set_size(ui->screen_calculator_btn_4, 60, 25);
    ui->screen_calculator_btn_4_label = lv_label_create(ui->screen_calculator_btn_4);
    lv_label_set_text(ui->screen_calculator_btn_4_label, "4");
    lv_label_set_long_mode(ui->screen_calculator_btn_4_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_4_label, LV_PCT(100));

    //Write style for screen_calculator_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_4, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_4, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_5
    ui->screen_calculator_btn_5 = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_5, 76, 75);
    lv_obj_set_size(ui->screen_calculator_btn_5, 60, 25);
    ui->screen_calculator_btn_5_label = lv_label_create(ui->screen_calculator_btn_5);
    lv_label_set_text(ui->screen_calculator_btn_5_label, "5");
    lv_label_set_long_mode(ui->screen_calculator_btn_5_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_5_label, LV_PCT(100));

    //Write style for screen_calculator_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_5, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_5, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_6
    ui->screen_calculator_btn_6 = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_6, 146, 75);
    lv_obj_set_size(ui->screen_calculator_btn_6, 60, 25);
    ui->screen_calculator_btn_6_label = lv_label_create(ui->screen_calculator_btn_6);
    lv_label_set_text(ui->screen_calculator_btn_6_label, "6");
    lv_label_set_long_mode(ui->screen_calculator_btn_6_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_6_label, LV_PCT(100));

    //Write style for screen_calculator_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_6, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_6, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_7
    ui->screen_calculator_btn_7 = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_7, 6, 40);
    lv_obj_set_size(ui->screen_calculator_btn_7, 60, 25);
    ui->screen_calculator_btn_7_label = lv_label_create(ui->screen_calculator_btn_7);
    lv_label_set_text(ui->screen_calculator_btn_7_label, "7");
    lv_label_set_long_mode(ui->screen_calculator_btn_7_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_7_label, LV_PCT(100));

    //Write style for screen_calculator_btn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_7, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_7, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_7, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_8
    ui->screen_calculator_btn_8 = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_8, 76, 40);
    lv_obj_set_size(ui->screen_calculator_btn_8, 60, 25);
    ui->screen_calculator_btn_8_label = lv_label_create(ui->screen_calculator_btn_8);
    lv_label_set_text(ui->screen_calculator_btn_8_label, "8");
    lv_label_set_long_mode(ui->screen_calculator_btn_8_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_8_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_8, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_8_label, LV_PCT(100));

    //Write style for screen_calculator_btn_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_8, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_8, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_9
    ui->screen_calculator_btn_9 = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_9, 146, 40);
    lv_obj_set_size(ui->screen_calculator_btn_9, 60, 25);
    ui->screen_calculator_btn_9_label = lv_label_create(ui->screen_calculator_btn_9);
    lv_label_set_text(ui->screen_calculator_btn_9_label, "9");
    lv_label_set_long_mode(ui->screen_calculator_btn_9_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_9_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_9, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_9_label, LV_PCT(100));

    //Write style for screen_calculator_btn_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_9, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_9, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_9, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_divide
    ui->screen_calculator_btn_divide = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_divide, 216, 5);
    lv_obj_set_size(ui->screen_calculator_btn_divide, 60, 25);
    ui->screen_calculator_btn_divide_label = lv_label_create(ui->screen_calculator_btn_divide);
    lv_label_set_text(ui->screen_calculator_btn_divide_label, "/");
    lv_label_set_long_mode(ui->screen_calculator_btn_divide_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_divide_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_divide, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_divide_label, LV_PCT(100));

    //Write style for screen_calculator_btn_divide, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_divide, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_divide, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_divide, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_divide, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_divide, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_divide, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_divide, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_divide, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_divide, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_divide, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_delete
    ui->screen_calculator_btn_delete = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_delete, 146, 5);
    lv_obj_set_size(ui->screen_calculator_btn_delete, 60, 25);
    ui->screen_calculator_btn_delete_label = lv_label_create(ui->screen_calculator_btn_delete);
    lv_label_set_text(ui->screen_calculator_btn_delete_label, "<-");
    lv_label_set_long_mode(ui->screen_calculator_btn_delete_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_delete_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_delete, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_delete_label, LV_PCT(100));

    //Write style for screen_calculator_btn_delete, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_delete, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_delete, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_delete, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_delete, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_delete, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_delete, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_delete, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_delete, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_delete, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_delete, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_clear
    ui->screen_calculator_btn_clear = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_clear, 76, 5);
    lv_obj_set_size(ui->screen_calculator_btn_clear, 60, 25);
    ui->screen_calculator_btn_clear_label = lv_label_create(ui->screen_calculator_btn_clear);
    lv_label_set_text(ui->screen_calculator_btn_clear_label, "C");
    lv_label_set_long_mode(ui->screen_calculator_btn_clear_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_clear_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_clear, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_clear_label, LV_PCT(100));

    //Write style for screen_calculator_btn_clear, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_clear, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_clear, lv_color_hex(0xadadad), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_clear, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_clear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_clear, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_clear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_clear, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_clear, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_clear, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_clear, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_btn_back
    ui->screen_calculator_btn_back = lv_button_create(ui->screen_calculator_cont_1);
    lv_obj_set_pos(ui->screen_calculator_btn_back, 6, 5);
    lv_obj_set_size(ui->screen_calculator_btn_back, 60, 25);
    ui->screen_calculator_btn_back_label = lv_label_create(ui->screen_calculator_btn_back);
    lv_label_set_text(ui->screen_calculator_btn_back_label, "back");
    lv_label_set_long_mode(ui->screen_calculator_btn_back_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui->screen_calculator_btn_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_calculator_btn_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_calculator_btn_back_label, LV_PCT(100));

    //Write style for screen_calculator_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_btn_back, lv_color_hex(0xe05800), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_btn_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_btn_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_calculator_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_btn_back, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_btn_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calculator_ta_calculator
    ui->screen_calculator_ta_calculator = lv_textarea_create(ui->screen_calculator);
    lv_obj_set_pos(ui->screen_calculator_ta_calculator, 11, 16);
    lv_obj_set_size(ui->screen_calculator_ta_calculator, 300, 35);
    lv_textarea_set_text(ui->screen_calculator_ta_calculator, "0");
    lv_textarea_set_placeholder_text(ui->screen_calculator_ta_calculator, "");
    lv_textarea_set_password_bullet(ui->screen_calculator_ta_calculator, "*");
    lv_textarea_set_password_mode(ui->screen_calculator_ta_calculator, false);
    lv_textarea_set_one_line(ui->screen_calculator_ta_calculator, false);
    lv_textarea_set_accepted_chars(ui->screen_calculator_ta_calculator, "");
    lv_textarea_set_max_length(ui->screen_calculator_ta_calculator, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_calculator_ta_calculator, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_calculator_ta_calculator, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_calculator_ta_calculator, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_calculator_ta_calculator, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_calculator_ta_calculator, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_calculator_ta_calculator, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_calculator_ta_calculator, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_calculator_ta_calculator, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_ta_calculator, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_ta_calculator, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_calculator_ta_calculator, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_calculator_ta_calculator, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_calculator_ta_calculator, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_calculator_ta_calculator, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_calculator_ta_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_calculator_ta_calculator, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_calculator_ta_calculator, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_calculator_ta_calculator, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_ta_calculator, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_calculator_ta_calculator, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calculator_ta_calculator, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calculator_ta_calculator, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calculator_ta_calculator, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_calculator_ta_calculator, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //The custom code of screen_calculator.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_calculator);

    //Init events for screen.
    events_init_screen_calculator(ui);
}
