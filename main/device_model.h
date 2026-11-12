#ifndef _DEVICE_MODEL_H_
#define _DEVICE_MODEL_H_

#include <stdbool.h>

typedef struct 
{
    /* data */
    int brightness;
    bool lightswitch;
    int r;
    int g;
    int b;
}dev_state_t;

typedef enum
{
    DEV_CMD_SWITCH,
    DEV_CMD_BRIGHTNESS,
    DEV_CMD_RGB,
}dev_cmd_type_t;

typedef struct {
    dev_cmd_type_t type;
    dev_state_t dev_state;
    int from;//from为0来自于屏幕，from为1来自onenet
} dev_cmd_t;

void model_devic_init(void);
void device_model_send_cmd(dev_cmd_t cmd);
#endif

