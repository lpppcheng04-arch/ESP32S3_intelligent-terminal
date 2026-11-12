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



lv_calendar_date_t screen_calendar_calendar_1_today;
lv_calendar_date_t screen_calendar_calendar_1_highlihted_days[1];
void setup_scr_screen_calendar(lv_ui *ui)
{
    //Write codes screen_calendar
    ui->screen_calendar = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_calendar, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_calendar, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_calendar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_calendar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_calendar, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_calendar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_calendar_calendar_1
    ui->screen_calendar_calendar_1 = lv_calendar_create(ui->screen_calendar);
    lv_obj_set_pos(ui->screen_calendar_calendar_1, 0, 36);
    lv_obj_set_size(ui->screen_calendar_calendar_1, 320, 204);
    screen_calendar_calendar_1_today.year = 2026;
    screen_calendar_calendar_1_today.month = 8;
    screen_calendar_calendar_1_today.day = 19;
    lv_calendar_set_today_date(ui->screen_calendar_calendar_1, screen_calendar_calendar_1_today.year, screen_calendar_calendar_1_today.month, screen_calendar_calendar_1_today.day);
    lv_calendar_set_showed_date(ui->screen_calendar_calendar_1, screen_calendar_calendar_1_today.year, screen_calendar_calendar_1_today.month);
    screen_calendar_calendar_1_highlihted_days[0].year = 2026;
    screen_calendar_calendar_1_highlihted_days[0].month = 8;
    screen_calendar_calendar_1_highlihted_days[0].day = 20;
    lv_calendar_set_highlighted_dates(ui->screen_calendar_calendar_1, screen_calendar_calendar_1_highlihted_days, 1);
    lv_obj_t *screen_calendar_calendar_1_header = lv_calendar_header_arrow_create(ui->screen_calendar_calendar_1);
    lv_calendar_t *screen_calendar_calendar_1 = (lv_calendar_t *)ui->screen_calendar_calendar_1;
    lv_obj_add_event_cb(screen_calendar_calendar_1->btnm, screen_calendar_calendar_1_draw_part_begin_event_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_event_cb(ui->screen_calendar_calendar_1, screen_calendar_calendar_1_event_handler, LV_EVENT_ALL, NULL);

    //Write style state: LV_STATE_DEFAULT for &style_screen_calendar_calendar_1_main_main_default
    static lv_style_t style_screen_calendar_calendar_1_main_main_default;
    ui_init_style(&style_screen_calendar_calendar_1_main_main_default);

    lv_style_set_border_width(&style_screen_calendar_calendar_1_main_main_default, 1);
    lv_style_set_border_opa(&style_screen_calendar_calendar_1_main_main_default, 255);
    lv_style_set_border_color(&style_screen_calendar_calendar_1_main_main_default, lv_color_hex(0xc0c0c0));
    lv_style_set_border_side(&style_screen_calendar_calendar_1_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_bg_opa(&style_screen_calendar_calendar_1_main_main_default, 255);
    lv_style_set_bg_color(&style_screen_calendar_calendar_1_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_calendar_calendar_1_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_shadow_width(&style_screen_calendar_calendar_1_main_main_default, 0);
    lv_style_set_radius(&style_screen_calendar_calendar_1_main_main_default, 0);
    lv_obj_add_style(ui->screen_calendar_calendar_1, &style_screen_calendar_calendar_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_calendar_calendar_1_extra_header_main_default
    static lv_style_t style_screen_calendar_calendar_1_extra_header_main_default;
    ui_init_style(&style_screen_calendar_calendar_1_extra_header_main_default);

    lv_style_set_text_color(&style_screen_calendar_calendar_1_extra_header_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_calendar_calendar_1_extra_header_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_calendar_calendar_1_extra_header_main_default, 255);
    lv_style_set_bg_opa(&style_screen_calendar_calendar_1_extra_header_main_default, 255);
    lv_style_set_bg_color(&style_screen_calendar_calendar_1_extra_header_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_calendar_calendar_1_extra_header_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(screen_calendar_calendar_1_header, &style_screen_calendar_calendar_1_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_calendar_calendar_1_main_items_default
    static lv_style_t style_screen_calendar_calendar_1_main_items_default;
    ui_init_style(&style_screen_calendar_calendar_1_main_items_default);

    lv_style_set_bg_opa(&style_screen_calendar_calendar_1_main_items_default, 255);
    lv_style_set_bg_color(&style_screen_calendar_calendar_1_main_items_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_calendar_calendar_1_main_items_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_calendar_calendar_1_main_items_default, 1);
    lv_style_set_border_opa(&style_screen_calendar_calendar_1_main_items_default, 255);
    lv_style_set_border_color(&style_screen_calendar_calendar_1_main_items_default, lv_color_hex(0xc0c0c0));
    lv_style_set_border_side(&style_screen_calendar_calendar_1_main_items_default, LV_BORDER_SIDE_FULL);
    lv_style_set_text_color(&style_screen_calendar_calendar_1_main_items_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_calendar_calendar_1_main_items_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_calendar_calendar_1_main_items_default, 255);
    lv_obj_add_style(lv_calendar_get_btnmatrix(ui->screen_calendar_calendar_1), &style_screen_calendar_calendar_1_main_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes screen_calendar_img_1
    ui->screen_calendar_img_1 = lv_image_create(ui->screen_calendar);
    lv_obj_set_pos(ui->screen_calendar_img_1, 8, 6);
    lv_obj_set_size(ui->screen_calendar_img_1, 24, 24);
    lv_obj_add_flag(ui->screen_calendar_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_calendar_img_1, &_back_RGB565A8_24x24);
    lv_image_set_pivot(ui->screen_calendar_img_1, 50,50);
    lv_image_set_rotation(ui->screen_calendar_img_1, 0);

    //Write style for screen_calendar_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_calendar_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_calendar_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_calendar.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_calendar);

    //Init events for screen.
    events_init_screen_calendar(ui);
}
