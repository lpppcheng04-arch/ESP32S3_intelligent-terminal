#include "aida64.h"
#include "esp_http_client.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "gui_guider.h"
#include "custom.h"

#define TAG "aida64"
#define AIDA64_BIT BIT0

extern lv_ui guider_ui;

static esp_http_client_handle_t aida64_http_handle = NULL;
static EventGroupHandle_t aida64_event_handle = NULL;
static TaskHandle_t g_aida64_task_handle = NULL;
static bool is_aida64_connect = false;
static char aida64_url[64] = {0};
static bool aida64_parse(char* data,aida64_data_t* aida64_data);

static esp_err_t aida64_http_event_handler(esp_http_client_event_t *evt)
{
   
    switch(evt->event_id) {
        case HTTP_EVENT_ERROR:
            ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
            is_aida64_connect = true;
            set_aida64_monitor_status(&guider_ui,is_aida64_connect);
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
            aida64_data_t aida64_data_buf ;
            aida64_parse((char*)evt->data,&aida64_data_buf);
            set_aida64_monitor_params(&guider_ui,aida64_data_buf.cpu_rate,aida64_data_buf.cpu_temp,aida64_data_buf.mem_rate,aida64_data_buf.mem_use);

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

static void aida64_connect_init(void)
{
    esp_http_client_config_t aida64_http_cfg = {
        .url = "http://192.168.3.1/:80/sse",
        .method = HTTP_METHOD_GET,
        .event_handler = aida64_http_event_handler
    };
    
    aida64_http_handle = esp_http_client_init(&aida64_http_cfg);
    
}

static void aida64_monitor_task(void* param)
{
    aida64_connect_init();
    while(1)
    {
        EventBits_t ev = xEventGroupWaitBits(aida64_event_handle,AIDA64_BIT,pdTRUE,pdFALSE,pdMS_TO_TICKS(1000));
        if(ev & AIDA64_BIT)
        {
            esp_http_client_set_url(aida64_http_handle,aida64_url);
            esp_http_client_set_header(aida64_http_handle,"Accept","text/event-stream");
            esp_http_client_perform(aida64_http_handle);
            is_aida64_connect = false;
            //输出UI画面
            set_aida64_monitor_status(&guider_ui,is_aida64_connect);
        }
        

    }
}

void aida64_monitor_start(char* ip)
{
    if(aida64_event_handle == NULL)
    {
        aida64_event_handle = xEventGroupCreate();
        
    }
    if(aida64_http_handle == NULL)
    {
        /* 
        分配任务控制块 TCB 和栈；
        把这个任务放进“就绪队列”。
        */
       
        xTaskCreatePinnedToCore(aida64_monitor_task,"aida64_monitor",4096,NULL,1,&g_aida64_task_handle,1);
    }
   
    snprintf(aida64_url,sizeof(aida64_url),"http://%s:80/sse",ip);
    ESP_LOGI(TAG,"url:%s",aida64_url);
    xEventGroupSetBits(aida64_event_handle,AIDA64_BIT);
    
}


static bool aida64_parse(char* data,aida64_data_t* aida64_data)
{
    const char* search_str = NULL;

    search_str = strstr(data,"CPU rate ");
    if(search_str)
    {
        sscanf(search_str,"%*[^0-9]%d",&aida64_data->cpu_rate);
    }
    else
    {
        return false;
    }
 search_str = strstr(data,"cpu temp ");
    if(search_str)
    {
        sscanf(search_str,"%*[^0-9]%d",&aida64_data->cpu_temp);
    }
    else
        return false;
    search_str = strstr(data,"mem rate ");
    if(search_str)
    {
        sscanf(search_str,"%*[^0-9]%d",&aida64_data->mem_rate);
    }
    else
        return false;

    search_str = strstr(data,"mem use ");
    if(search_str)
    {
        sscanf(search_str,"%*[^0-9]%d",&aida64_data->mem_use);
    }
    else
        return false;
    return true;
}

void aida64_disconnect(void)
{
    esp_http_client_close(aida64_http_handle);

}

bool aida64_isconnect(void)
{
    return is_aida64_connect;
}