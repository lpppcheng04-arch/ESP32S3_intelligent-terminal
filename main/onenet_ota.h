#ifndef _ONENET_OTA_H_
#define _ONENET_OTA_H_

#include "esp_err.h"
//获取版本号
const char* get_app_version(void);
//标记程序是否合法 修改otadata
void set_app_valid(int valid);
//上传版本号
esp_err_t onenet_ota_upload_version(void);

void onenet_ota_start(void);
#endif

