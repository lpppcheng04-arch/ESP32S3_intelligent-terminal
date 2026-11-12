#ifndef _ONENET_DM_H
#define _ONENET_DM_H
#include "cJSON.h"
#include "device_model.h"
cJSON* onenet_property_upload(dev_state_t dev);
void onenet_property_handle(cJSON* property);

#endif

