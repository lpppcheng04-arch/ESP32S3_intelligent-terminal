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



void setup_scr_screen_monitor(lv_ui *ui)
{
    //Write codes screen_monitor
    ui->screen_monitor = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_monitor, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_monitor, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_monitor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_cont_cpu
    ui->screen_monitor_cont_cpu = lv_obj_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_cont_cpu, 14, 32);
    lv_obj_set_size(ui->screen_monitor_cont_cpu, 140, 97);
    lv_obj_set_scrollbar_mode(ui->screen_monitor_cont_cpu, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_monitor_cont_cpu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_cont_cpu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_monitor_cont_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_monitor_cont_cpu, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_monitor_cont_cpu, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_cont_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_cont_cpu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_cont_cpu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_cpu
    ui->screen_monitor_label_cpu = lv_label_create(ui->screen_monitor_cont_cpu);
    lv_obj_set_pos(ui->screen_monitor_label_cpu, 3, 4);
    lv_obj_set_size(ui->screen_monitor_label_cpu, 80, 30);
    lv_label_set_text(ui->screen_monitor_label_cpu, "CPU");
    lv_label_set_long_mode(ui->screen_monitor_label_cpu, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_cpu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_cpu, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_cpu, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_cpu, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_label_cpu, lv_color_hex(0xc4d4e0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_label_cpu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_cpu_use
    ui->screen_monitor_label_cpu_use = lv_label_create(ui->screen_monitor_cont_cpu);
    lv_obj_set_pos(ui->screen_monitor_label_cpu_use, 3, 42);
    lv_obj_set_size(ui->screen_monitor_label_cpu_use, 73, 20);
    lv_label_set_text(ui->screen_monitor_label_cpu_use, "使用率:");
    lv_label_set_long_mode(ui->screen_monitor_label_cpu_use, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_cpu_use, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_cpu_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_cpu_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_cpu_use, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_cpu_use, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_cpu_use, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_cpu_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_cpu_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_cpu_use, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_cpu_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_cpu_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_cpu_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_cpu_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_cpu_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_cpu_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_cpu_use_value
    ui->screen_monitor_label_cpu_use_value = lv_label_create(ui->screen_monitor_cont_cpu);
    lv_obj_set_pos(ui->screen_monitor_label_cpu_use_value, 78, 42);
    lv_obj_set_size(ui->screen_monitor_label_cpu_use_value, 49, 23);
    lv_label_set_text(ui->screen_monitor_label_cpu_use_value, "80%");
    lv_label_set_long_mode(ui->screen_monitor_label_cpu_use_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_cpu_use_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_cpu_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_cpu_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_cpu_use_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_cpu_use_value, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_cpu_use_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_cpu_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_cpu_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_cpu_use_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_cpu_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_cpu_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_cpu_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_cpu_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_cpu_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_cpu_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_temp
    ui->screen_monitor_label_temp = lv_label_create(ui->screen_monitor_cont_cpu);
    lv_obj_set_pos(ui->screen_monitor_label_temp, 4, 68);
    lv_obj_set_size(ui->screen_monitor_label_temp, 61, 20);
    lv_label_set_text(ui->screen_monitor_label_temp, "温度:");
    lv_label_set_long_mode(ui->screen_monitor_label_temp, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_temp, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_temp, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_temp_value
    ui->screen_monitor_label_temp_value = lv_label_create(ui->screen_monitor_cont_cpu);
    lv_obj_set_pos(ui->screen_monitor_label_temp_value, 78, 68);
    lv_obj_set_size(ui->screen_monitor_label_temp_value, 54, 21);
    lv_label_set_text(ui->screen_monitor_label_temp_value, "50℃");
    lv_label_set_long_mode(ui->screen_monitor_label_temp_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_temp_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_temp_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_temp_value, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_temp_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_temp_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_cont_mem
    ui->screen_monitor_cont_mem = lv_obj_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_cont_mem, 170, 32);
    lv_obj_set_size(ui->screen_monitor_cont_mem, 140, 97);
    lv_obj_set_scrollbar_mode(ui->screen_monitor_cont_mem, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_monitor_cont_mem, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_cont_mem, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_monitor_cont_mem, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_monitor_cont_mem, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_monitor_cont_mem, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_cont_mem, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_cont_mem, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_cont_mem, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_mem
    ui->screen_monitor_label_mem = lv_label_create(ui->screen_monitor_cont_mem);
    lv_obj_set_pos(ui->screen_monitor_label_mem, 4, 5);
    lv_obj_set_size(ui->screen_monitor_label_mem, 80, 30);
    lv_label_set_text(ui->screen_monitor_label_mem, "内存");
    lv_label_set_long_mode(ui->screen_monitor_label_mem, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_mem, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_mem, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_mem, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_mem, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_mem, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_mem, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_label_mem, lv_color_hex(0xffeb9a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_label_mem, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_mem_use
    ui->screen_monitor_label_mem_use = lv_label_create(ui->screen_monitor_cont_mem);
    lv_obj_set_pos(ui->screen_monitor_label_mem_use, 2, 44);
    lv_obj_set_size(ui->screen_monitor_label_mem_use, 73, 20);
    lv_label_set_text(ui->screen_monitor_label_mem_use, "使用率:");
    lv_label_set_long_mode(ui->screen_monitor_label_mem_use, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_mem_use, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_mem_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_mem_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_mem_use, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_mem_use, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_mem_use, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_mem_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_mem_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_mem_use, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_mem_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_mem_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_mem_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_mem_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_mem_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_mem_use, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_mem_invalid
    ui->screen_monitor_label_mem_invalid = lv_label_create(ui->screen_monitor_cont_mem);
    lv_obj_set_pos(ui->screen_monitor_label_mem_invalid, 6, 67);
    lv_obj_set_size(ui->screen_monitor_label_mem_invalid, 57, 20);
    lv_label_set_text(ui->screen_monitor_label_mem_invalid, "可用:");
    lv_label_set_long_mode(ui->screen_monitor_label_mem_invalid, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_mem_invalid, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_mem_invalid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_mem_invalid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_mem_invalid, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_mem_invalid, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_mem_invalid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_mem_invalid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_mem_invalid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_mem_invalid, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_mem_invalid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_mem_invalid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_mem_invalid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_mem_invalid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_mem_invalid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_mem_invalid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_mem_use_value
    ui->screen_monitor_label_mem_use_value = lv_label_create(ui->screen_monitor_cont_mem);
    lv_obj_set_pos(ui->screen_monitor_label_mem_use_value, 84, 47);
    lv_obj_set_size(ui->screen_monitor_label_mem_use_value, 46, 20);
    lv_label_set_text(ui->screen_monitor_label_mem_use_value, "80%");
    lv_label_set_long_mode(ui->screen_monitor_label_mem_use_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_mem_use_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_mem_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_mem_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_mem_use_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_mem_use_value, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_mem_use_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_mem_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_mem_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_mem_use_value, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_mem_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_mem_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_mem_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_mem_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_mem_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_mem_use_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_mem_invalid_value
    ui->screen_monitor_label_mem_invalid_value = lv_label_create(ui->screen_monitor_cont_mem);
    lv_obj_set_pos(ui->screen_monitor_label_mem_invalid_value, 55, 68);
    lv_obj_set_size(ui->screen_monitor_label_mem_invalid_value, 77, 20);
    lv_label_set_text(ui->screen_monitor_label_mem_invalid_value, "2459MB");
    lv_label_set_long_mode(ui->screen_monitor_label_mem_invalid_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_mem_invalid_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_mem_invalid_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_mem_invalid_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_mem_invalid_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_mem_invalid_value, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_mem_invalid_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_mem_invalid_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_mem_invalid_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_mem_invalid_value, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_mem_invalid_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_mem_invalid_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_mem_invalid_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_mem_invalid_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_mem_invalid_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_mem_invalid_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_ta_ip
    ui->screen_monitor_ta_ip = lv_textarea_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_ta_ip, 30, 170);
    lv_obj_set_size(ui->screen_monitor_ta_ip, 200, 29);
    lv_textarea_set_text(ui->screen_monitor_ta_ip, "192.168.3.100");
    lv_textarea_set_placeholder_text(ui->screen_monitor_ta_ip, "");
    lv_textarea_set_password_bullet(ui->screen_monitor_ta_ip, "*");
    lv_textarea_set_password_mode(ui->screen_monitor_ta_ip, false);
    lv_textarea_set_one_line(ui->screen_monitor_ta_ip, false);
    lv_textarea_set_accepted_chars(ui->screen_monitor_ta_ip, "");
    lv_textarea_set_max_length(ui->screen_monitor_ta_ip, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_monitor_ta_ip, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_monitor_ta_ip, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_monitor_ta_ip, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_ta_ip, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_ta_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_ta_ip, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_ta_ip, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_ta_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_ta_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_ta_ip, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_monitor_ta_ip, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_monitor_ta_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_monitor_ta_ip, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_monitor_ta_ip, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_ta_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_ta_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_ta_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_ta_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_ta_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_monitor_ta_ip, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_monitor_ta_ip, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_ta_ip, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_ta_ip, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_ta_ip, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_monitor_btn_connect
    ui->screen_monitor_btn_connect = lv_button_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_btn_connect, 242, 170);
    lv_obj_set_size(ui->screen_monitor_btn_connect, 69, 35);
    ui->screen_monitor_btn_connect_label = lv_label_create(ui->screen_monitor_btn_connect);
    lv_label_set_text(ui->screen_monitor_btn_connect_label, "连接");
    lv_label_set_long_mode(ui->screen_monitor_btn_connect_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_monitor_btn_connect_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_monitor_btn_connect, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_monitor_btn_connect_label, LV_PCT(100));

    //Write style for screen_monitor_btn_connect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_monitor_btn_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_monitor_btn_connect, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_monitor_btn_connect, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_monitor_btn_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_btn_connect, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_btn_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_btn_connect, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_btn_connect, &lv_customer_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_btn_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_btn_connect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_ip
    ui->screen_monitor_label_ip = lv_label_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_label_ip, 14, 138);
    lv_obj_set_size(ui->screen_monitor_label_ip, 68, 25);
    lv_label_set_text(ui->screen_monitor_label_ip, "主机IP");
    lv_label_set_long_mode(ui->screen_monitor_label_ip, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_ip, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_ip, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_ip, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_label_connect_status
    ui->screen_monitor_label_connect_status = lv_label_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_label_connect_status, 82, 210);
    lv_obj_set_size(ui->screen_monitor_label_connect_status, 93, 22);
    lv_label_set_text(ui->screen_monitor_label_connect_status, "未连接");
    lv_label_set_long_mode(ui->screen_monitor_label_connect_status, LV_LABEL_LONG_WRAP);

    //Write style for screen_monitor_label_connect_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_monitor_label_connect_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_monitor_label_connect_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_monitor_label_connect_status, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_monitor_label_connect_status, &lv_customer_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_monitor_label_connect_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_monitor_label_connect_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_monitor_label_connect_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_monitor_label_connect_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_monitor_label_connect_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_monitor_label_connect_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_monitor_label_connect_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_monitor_label_connect_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_monitor_label_connect_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_monitor_label_connect_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_monitor_img_back
    ui->screen_monitor_img_back = lv_image_create(ui->screen_monitor);
    lv_obj_set_pos(ui->screen_monitor_img_back, 9, 6);
    lv_obj_set_size(ui->screen_monitor_img_back, 22, 22);
    lv_obj_add_flag(ui->screen_monitor_img_back, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_monitor_img_back, &_back_RGB565A8_22x22);
    lv_image_set_pivot(ui->screen_monitor_img_back, 50,50);
    lv_image_set_rotation(ui->screen_monitor_img_back, 0);

    //Write style for screen_monitor_img_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_monitor_img_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->screen_monitor_img_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_monitor_img_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_monitor.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_monitor);

    //Init events for screen.
    events_init_screen_monitor(ui);
}
