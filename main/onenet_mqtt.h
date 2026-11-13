#ifndef _ONENET_MQTT_H_
#define _ONENET_MQTT_H_

#include "esp_err.h"
#include "device_model.h"
#include "onenet_secrets.h"
#define ONENET_PDORUCT_ID  MY_ONENET_PDORUCT_ID   //replace it with yours
#define ONENET_ACCESS_KEY  MY_ONENET_ACCESS_KEY   //replace it with yours
#define ONENET_DEVICE_NAME MY_ONENET_DEVICE_NAME  //replace it with yours

esp_err_t onenet_start(void);
void onenet_property_report(dev_state_t dev);

#endif

