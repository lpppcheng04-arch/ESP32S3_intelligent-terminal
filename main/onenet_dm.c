#include "onenet_dm.h"
#include "cJSON.h"
#include "led_ws2812.h"
#include "driver/ledc.h"
#include <string.h>
#include "device_model.h"

// static dev_state_t onenet_state = {0};
static ws2812_strip_handle_t ws2812_handle = NULL;
static int led_brightness = 0;
static bool led_status = 0;
static int ws2812_red = 0;
static int ws2812_green = 0;
static int ws2812_blue = 0;
static dev_cmd_t onenet_cmd = {0};
//设备属性上报
cJSON* onenet_property_upload(dev_state_t dev)
{
    cJSON* root = cJSON_CreateObject();
    cJSON_AddStringToObject(root,"id","123");
    cJSON_AddStringToObject(root,"version","1.0");

    cJSON* param_js = cJSON_AddObjectToObject(root,"params");
    /*
    "params":
    {
    "led":
       "Brightness": {
        "value" : 100,
        }

        "LightSwitch": {
         "value": true/false,
        }
        "RGBColor":{
            "Red" : 1
            "Green" : 1
            "Blue" : 1
        }
    }
    
    */
   cJSON* brightness_js = cJSON_AddObjectToObject(param_js,"Brightness");
    cJSON_AddNumberToObject(brightness_js,"value",dev.brightness);
    cJSON* lightswitch_js = cJSON_AddObjectToObject(param_js,"LightSwitch");
    cJSON_AddBoolToObject(lightswitch_js,"value",dev.lightswitch);

    cJSON* RGBcolor_js = cJSON_AddObjectToObject(param_js,"RGBColor");
    cJSON* RGBcolor_value_js = cJSON_AddObjectToObject(RGBcolor_js,"value");
    cJSON_AddNumberToObject(RGBcolor_value_js,"Red",dev.r);
    cJSON_AddNumberToObject(RGBcolor_value_js,"Green",dev.g);
    cJSON_AddNumberToObject(RGBcolor_value_js,"Blue",dev.b);
    return root;
}


//设备属性设置
void onenet_property_handle(cJSON* property)
{
    onenet_cmd.from = 1;
    
    cJSON* param_js = cJSON_GetObjectItem(property,"params");
    if(param_js)
    {
        cJSON* name_js = param_js->child;
        if(strcmp(name_js->string,"Brightness") == 0)
        {
            led_brightness = cJSON_GetNumberValue(name_js);
            int duty = led_brightness;
            
            onenet_cmd.type = DEV_CMD_BRIGHTNESS;
            onenet_cmd.dev_state.brightness = duty ;
            
            // ledc_set_duty_and_update(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0,duty,0);
        }
        else if(strcmp(name_js->string,"LightSwitch") == 0)
        {
            onenet_cmd.type = DEV_CMD_SWITCH;
            if(cJSON_IsTrue(name_js))
            {
                led_status = 1;
                led_brightness = 50;
                
                onenet_cmd.dev_state.lightswitch = 1;
                

                // ledc_set_duty_and_update(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0,duty,0);
            }
            else
            {
                led_status = 0;
                led_brightness = 0;
                onenet_cmd.dev_state.lightswitch = 0;
                // ledc_set_duty_and_update(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0,0,0);
            }
        }
        else if(strcmp(name_js->string,"RGBColor") == 0)
        {
            ws2812_red = cJSON_GetNumberValue(cJSON_GetObjectItem(name_js,"Red"));
            ws2812_green = cJSON_GetNumberValue(cJSON_GetObjectItem(name_js,"Green"));
            ws2812_blue = cJSON_GetNumberValue(cJSON_GetObjectItem(name_js,"Blue"));
            onenet_cmd.type = DEV_CMD_RGB;
            onenet_cmd.dev_state.r = ws2812_red;
            onenet_cmd.dev_state.g = ws2812_green;
            onenet_cmd.dev_state.b = ws2812_blue;

            // for(int i = 0;i < 3;i++)
            // {
            //     ws2812_write(ws2812_handle,i,ws2812_red,ws2812_green,ws2812_blue);
            // }
        }
        device_model_send_cmd(onenet_cmd);
        name_js = name_js->next;
    }
    /*
        {
            "id" : "123"
            "version": "1.0",
            "params":{
                "Brightness" : 50,
                "LightSwitch" : true,
                "RGBColor" : {
                    "Red" : 100
                    "Green" : 100
                    "Blue" : 100
                }    
            }
        }
    
    */
}
