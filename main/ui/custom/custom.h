/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"
#include "wifi_manager.h"
void set_wifi_state(lv_ui* ui,wifi_state state);
void custom_init(lv_ui *ui);
void set_wifi_state_fail(lv_ui* ui);
void set_temperature(lv_ui* ui,int day,int high,int low,char* img_path);
void set_calendar_date(lv_ui* ui,int day,int month,int year);
void set_serial_receive(lv_ui* ui,char* read_word);
void set_aida64_monitor_status(lv_ui* ui,bool status);
void set_aida64_monitor_params(lv_ui* ui,int cpu_rate,int cpu_temp,int mem_rate,int mem_use);
#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
