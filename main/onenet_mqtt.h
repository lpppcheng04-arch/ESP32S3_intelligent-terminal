#ifndef _ONENET_MQTT_H_
#define _ONENET_MQTT_H_

#include "esp_err.h"
#include "device_model.h"

#define ONENET_PDORUCT_ID "1NhV5y09wN"
#define ONENET_ACCESS_KEY "Ye9nS9uBuW/5ifuZGVtlRynxYVUxXX1ZmU8jQ9MTKV0="
#define ONENET_DEVICE_NAME "esp32led02"

esp_err_t onenet_start(void);
void onenet_property_report(dev_state_t dev);

#endif

