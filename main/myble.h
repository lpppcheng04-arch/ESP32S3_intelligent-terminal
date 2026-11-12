#ifndef _MYBLE_H_
#define _MYBLE_H_
#include "esp_err.h"
void start_advertising(void);
void ble_init(void);
esp_err_t ble_fallback_start(void);
#endif
