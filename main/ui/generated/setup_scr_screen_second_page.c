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



void setup_scr_screen_second_page(lv_ui *ui)
{
    //Write codes screen_second_page
    ui->screen_second_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_second_page, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_second_page, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_second_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_second_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_second_page, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_second_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_second_page_img_computer
    ui->screen_second_page_img_computer = lv_image_create(ui->screen_second_page);
    lv_obj_set_pos(ui->screen_second_page_img_computer, 12, 107);
    lv_obj_set_size(ui->screen_second_page_img_computer, 60, 60);
    lv_obj_add_flag(ui->screen_second_page_img_computer, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_second_page_img_computer, &_computer_RGB565A8_60x60);
    lv_image_set_pivot(ui->screen_second_page_img_computer, 50,50);
    lv_image_set_rotation(ui->screen_second_page_img_computer, 0);

    //Write style for screen_second_page_img_computer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_second_page_img_computer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_second_page_img_computer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_second_page_img_calendar
    ui->screen_second_page_img_calendar = lv_image_create(ui->screen_second_page);
    lv_obj_set_pos(ui->screen_second_page_img_calendar, 89, 107);
    lv_obj_set_size(ui->screen_second_page_img_calendar, 68, 68);
    lv_obj_add_flag(ui->screen_second_page_img_calendar, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_second_page_img_calendar, &_calendar_RGB565A8_68x68);
    lv_image_set_pivot(ui->screen_second_page_img_calendar, 50,50);
    lv_image_set_rotation(ui->screen_second_page_img_calendar, 0);

    //Write style for screen_second_page_img_calendar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_second_page_img_calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_second_page_img_calendar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_second_page_img_ai
    ui->screen_second_page_img_ai = lv_image_create(ui->screen_second_page);
    lv_obj_set_pos(ui->screen_second_page_img_ai, 242, 109);
    lv_obj_set_size(ui->screen_second_page_img_ai, 59, 59);
    lv_obj_add_flag(ui->screen_second_page_img_ai, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_second_page_img_ai, &_robot_RGB565A8_59x59);
    lv_image_set_pivot(ui->screen_second_page_img_ai, 50,50);
    lv_image_set_rotation(ui->screen_second_page_img_ai, 0);

    //Write style for screen_second_page_img_ai, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_second_page_img_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_second_page_img_ai, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_second_page_img_calculator
    ui->screen_second_page_img_calculator = lv_image_create(ui->screen_second_page);
    lv_obj_set_pos(ui->screen_second_page_img_calculator, 168, 112);
    lv_obj_set_size(ui->screen_second_page_img_calculator, 55, 55);
    lv_obj_add_flag(ui->screen_second_page_img_calculator, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_second_page_img_calculator, &_calculator_RGB565A8_55x55);
    lv_image_set_pivot(ui->screen_second_page_img_calculator, 50,50);
    lv_image_set_rotation(ui->screen_second_page_img_calculator, 0);

    //Write style for screen_second_page_img_calculator, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_second_page_img_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_second_page_img_calculator, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_second_page_label_computer
    ui->screen_second_page_label_computer = lv_label_create(ui->screen_second_page);
    lv_obj_set_pos(ui->screen_second_page_label_computer, 12, 177);
    lv_obj_set_size(ui->screen_second_page_label_computer, 58, 47);
    lv_label_set_text(ui->screen_second_page_label_computer, "电脑\n性能");
    lv_label_set_long_mode(ui->screen_second_page_label_computer, LV_LABEL_LONG_WRAP);

    //Write style for screen_second_page_label_computer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_second_page_label_computer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_second_page_label_computer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_second_page_label_computer, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_second_page_label_computer, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_second_page_label_computer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_second_page_label_computer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_second_page_label_computer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_second_page_label_computer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_second_page_label_computer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_second_page_label_computer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_second_page_label_computer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_second_page_label_computer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_second_page_label_computer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_second_page_label_computer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_second_page_label_calendar
    ui->screen_second_page_label_calendar = lv_label_create(ui->screen_second_page);
    lv_obj_set_pos(ui->screen_second_page_label_calendar, 89, 187);
    lv_obj_set_size(ui->screen_second_page_label_calendar, 52, 26);
    lv_label_set_text(ui->screen_second_page_label_calendar, "日历");
    lv_label_set_long_mode(ui->screen_second_page_label_calendar, LV_LABEL_LONG_WRAP);

    //Write style for screen_second_page_label_calendar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_second_page_label_calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_second_page_label_calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_second_page_label_calendar, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_second_page_label_calendar, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_second_page_label_calendar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_second_page_label_calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_second_page_label_calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_second_page_label_calendar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_second_page_label_calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_second_page_label_calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_second_page_label_calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_second_page_label_calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_second_page_label_calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_second_page_label_calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_second_page_label_calculator
    ui->screen_second_page_label_calculator = lv_label_create(ui->screen_second_page);
    lv_obj_set_pos(ui->screen_second_page_label_calculator, 163, 187);
    lv_obj_set_size(ui->screen_second_page_label_calculator, 68, 23);
    lv_label_set_text(ui->screen_second_page_label_calculator, "计算器");
    lv_label_set_long_mode(ui->screen_second_page_label_calculator, LV_LABEL_LONG_WRAP);

    //Write style for screen_second_page_label_calculator, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_second_page_label_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_second_page_label_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_second_page_label_calculator, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_second_page_label_calculator, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_second_page_label_calculator, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_second_page_label_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_second_page_label_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_second_page_label_calculator, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_second_page_label_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_second_page_label_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_second_page_label_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_second_page_label_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_second_page_label_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_second_page_label_calculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_second_page_label_ai
    ui->screen_second_page_label_ai = lv_label_create(ui->screen_second_page);
    lv_obj_set_pos(ui->screen_second_page_label_ai, 237, 187);
    lv_obj_set_size(ui->screen_second_page_label_ai, 66, 22);
    lv_label_set_text(ui->screen_second_page_label_ai, "AI");
    lv_label_set_long_mode(ui->screen_second_page_label_ai, LV_LABEL_LONG_WRAP);

    //Write style for screen_second_page_label_ai, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_second_page_label_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_second_page_label_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_second_page_label_ai, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_second_page_label_ai, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_second_page_label_ai, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_second_page_label_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_second_page_label_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_second_page_label_ai, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_second_page_label_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_second_page_label_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_second_page_label_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_second_page_label_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_second_page_label_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_second_page_label_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_second_page.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_second_page);

    //Init events for screen.
    events_init_screen_second_page(ui);
}
