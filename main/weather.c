#include "weather.h"
#include "esp_http_client.h"
#include "esp_err.h"
#include "esp_log.h"
#include "cJSON.h"
#include "wifi_manager.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_spiffs.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "custom.h"
#define WEATHER_HTTP_URL   "http://api.seniverse.com/v3/weather/daily.json?key=S3qyRJLM7f7lzgiST&location=wenzhou&language=zh-Hans&unit=c&start=0&days=5"
#define TAG "weather"
#define WEATHER_BUFF_LEN 1024

static char weather_data_buff[WEATHER_BUFF_LEN];
static int weather_data_size = 0;
static TaskHandle_t g_pxWeatherTask = NULL;
static weather_data_pkt_t weather_data[3];
static char weather_img_path[3][32];
extern lv_ui guider_ui;
static bool weather_data_ready = false;

void init_weather_buffer(void)
{
    esp_vfs_spiffs_conf_t weather_buf_spiffs = {
        .base_path = "/img",
        .partition_label = "img",
        .max_files = 5,
        .format_if_mount_failed = false,
    };
    ESP_ERROR_CHECK(esp_vfs_spiffs_register(&weather_buf_spiffs));
}

static esp_err_t weather_http_event_handler(esp_http_client_event_t *evt)
{
   
    switch(evt->event_id) {
        case HTTP_EVENT_ERROR:
            ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:
            ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
            break;
        case HTTP_EVENT_ON_DATA://接收到Onenet返回数据
            ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
            printf("HTTP_EVENT_OTA_ON_DATA = %.*s\r\n", evt->data_len, (char*)evt->data);
            int copy_len = 0;
            if( evt->data_len > WEATHER_BUFF_LEN -  weather_data_size)//数据长度大于剩余长度
            {
                copy_len = WEATHER_BUFF_LEN -  weather_data_size;
            }
            else
            {
                copy_len = evt->data_len;
            }
            memcpy(&weather_data_buff[weather_data_size],evt->data,copy_len);
            weather_data_size += copy_len;
            break;
        case HTTP_EVENT_ON_FINISH:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
           
            break;
        case HTTP_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
            break;
        case HTTP_EVENT_REDIRECT:
            ESP_LOGD(TAG, "HTTP_EVENT_REDIRECT");
           
            break;
        default:
            break;
    }
    return ESP_OK;
}

static void weather_http_parase(char* data)
{
    cJSON* root = cJSON_Parse(data);
    if(!root)
    {
        ESP_LOGI(TAG,"root parse failed");
        return ;
    }
    cJSON* results_js = cJSON_GetObjectItem(root,"results");
    if(!results_js)
    {
        ESP_LOGI(TAG,"results_js parse failed");
        cJSON_Delete(root);
        return ;
    }
    cJSON* result_js = results_js->child;
    if(!result_js)
    {
        ESP_LOGI(TAG,"result_js parse failed");
        cJSON_Delete(root);
        return ;
    }
    cJSON* daily_js = cJSON_GetObjectItem(result_js,"daily");
    if(daily_js)
    {
        cJSON* daily_child_js = daily_js->child;
       
        int index = 0;
        memset(weather_data,0,sizeof(weather_data));
        while(daily_child_js)
        { 
            cJSON* code_js = cJSON_GetObjectItem(daily_child_js,"code_day");
            cJSON* high_js = cJSON_GetObjectItem(daily_child_js,"high");
            cJSON* low_js = cJSON_GetObjectItem(daily_child_js,"low");
            if(index < 3)
            {   
                ESP_LOGI(TAG, "before set_temperature, day=%d", index);
                sscanf(cJSON_GetStringValue(high_js),"%d",&weather_data[index].high);
                sscanf(cJSON_GetStringValue(low_js),"%d",&weather_data[index].low);
                snprintf(weather_data[index].code,4,"%s",cJSON_GetStringValue(code_js));
                ESP_LOGI(TAG,"code day is:%s,low temperature is:%d,high temperature is:%d",weather_data[index].code,weather_data[index].low,weather_data[index].high);
                snprintf(weather_img_path[index],sizeof(weather_img_path[index]),"/img/%s@1x.png",weather_data[index].code);
            }
            index++;
            daily_child_js = daily_child_js->next;
        }
    }
}


static esp_err_t weather_http_conect(void)
{
    esp_http_client_config_t weather_http_cfg = {
        .url = WEATHER_HTTP_URL,
        .event_handler = weather_http_event_handler,
        .method = HTTP_METHOD_GET,
    };
   esp_http_client_handle_t weather_http_handle = esp_http_client_init(&weather_http_cfg);
    if(!weather_http_handle)
    {
        ESP_LOGI(TAG,"weather http client init failed");
        return ESP_FAIL;
    }
    memset(weather_data_buff,0,WEATHER_BUFF_LEN);
    esp_err_t err = esp_http_client_perform(weather_http_handle);
    if(err != ESP_OK)
    {
        ESP_LOGI(TAG,"weather http client perform fail");
        esp_http_client_cleanup(weather_http_handle);
        return err;
    }
    else
    {
        ESP_LOGI(TAG,"http client perform successfully!");
        weather_http_parase(weather_data_buff);
    }
    esp_http_client_cleanup(weather_http_handle);
    return ESP_OK;
} 


static void weather_task(void* param)
{
    while(1)
    {
        if(!wifi_manager_sta_isconnect())
        {
            ESP_LOGI(TAG, "invalid wifi, weather request skipped");
            vTaskDelay(pdMS_TO_TICKS(5000));
            continue;
        }
        if(!weather_data_ready)
        {
             esp_err_t err = weather_http_conect();

            if(err != ESP_OK)
            {
                ESP_LOGI(TAG, "weather connect failed");
                vTaskDelay(pdMS_TO_TICKS(5000));
                continue;
            }

            weather_data_ready = true;
        }
        // 天气页面已经创建
        if(guider_ui.screen_weather != NULL)
        {
            for(int i = 0; i < 3; i++)
            {
                set_temperature(&guider_ui,
                                i,
                                weather_data[i].high,
                                weather_data[i].low,
                                weather_img_path[i]);
            }

            // 界面更新完成后，30分钟后再请求下一次天气
            weather_data_ready = false;
            vTaskDelay(pdMS_TO_TICKS(1800000));
        }
        else
        {
            // 页面还没创建，只等待，不重复请求 HTTP
            vTaskDelay(pdMS_TO_TICKS(3000));
        }
       
        
    }
   
}

void weather_start(void)
{
    xTaskCreatePinnedToCore(weather_task,"weather task",4096,NULL,1,&g_pxWeatherTask,1);
}
