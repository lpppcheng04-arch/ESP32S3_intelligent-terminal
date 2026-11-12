#include "onenet_ota.h"
#include "esp_https_ota.h"
#include "esp_system.h"
#include "esp_ota_ops.h"
#include "esp_log.h"
#include "onenet_mqtt.h"
#include "onenet_token.h"
#include "cJSON.h"
#define TAG             "ONENET-OTA"
#define ONENET_OTA_URL  "http://iot-api.heclouds.com/fuse-ota"
#define OTA_BUFF_LEN  1024

static uint8_t ota_data_buff[OTA_BUFF_LEN];
static int ota_data_size = 0;
static int task_id;
static char target_version[32] = {0};
static bool ota_is_running;
//获取版本号
const char* get_app_version(void)
{
    static char app_version[32] = {0};
    //获取partition信息
    const esp_partition_t* running = esp_ota_get_running_partition();
    if(running == NULL)
    {
        ESP_LOGI(TAG,"get running partition fail....");
    }
    esp_app_desc_t app_desc;
    if(esp_ota_get_partition_description(running,&app_desc) != ESP_OK)
    {
        ESP_LOGI(TAG,"reading version fail");
    }
    snprintf(app_version,sizeof(app_version),"%s",app_desc.version);
    ESP_LOGI(TAG,"Current Version:%s",app_version);
    return app_version;
}


//标记程序是否合法
void set_app_valid(int valid)
{
    //获取当前运行程序分区
    const esp_partition_t * running = esp_ota_get_running_partition();
    esp_ota_img_states_t ota_state;
    if(esp_ota_get_state_partition(running,&ota_state) == ESP_OK)
    {
        if(ota_state == ESP_OTA_IMG_PENDING_VERIFY)
        {
            if(valid)
            {
                esp_ota_mark_app_valid_cancel_rollback();
            }
            else
            {
                esp_ota_mark_app_invalid_rollback_and_reboot();
            }
        }
    }
}

static esp_err_t onenet_ota_http_event_handler(esp_http_client_event_t *evt)
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
            //数据长度大于可接受长度
            if( evt->data_len > OTA_BUFF_LEN -  ota_data_size)
            {
                copy_len = OTA_BUFF_LEN -  ota_data_size;
            }
            else
            {
                copy_len = evt->data_len;
            }
            memcpy(&ota_data_buff[ota_data_size],evt->data,copy_len);
            ota_data_size += copy_len;
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

// 发起http协议连接
// @ 参数 url:请求的目标连接地址, method:连接方法, payload:传输数据
//
static esp_err_t onenet_ota_http_connect(const char* url,esp_http_client_method_t method,const char* payload)
{
    esp_http_client_config_t config = {
        .url = url,
        .method = method,
        .event_handler = onenet_ota_http_event_handler,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);//初始化http句柄
    //初始化token 
    char* token = (char*)malloc(256);
    memset(token,0,256);
    dev_token_generate(token,SIG_METHOD_SHA256,2099628748,ONENET_PDORUCT_ID, NULL, ONENET_ACCESS_KEY);
    esp_http_client_set_header(client,"Content-Type","application/json");
    esp_http_client_set_header(client,"host","iot-api.heclouds.com");
    esp_http_client_set_header(client,"Authorization",token);
    esp_err_t err = ESP_FAIL;
    if(payload) //传输数据不为空
    {
        ESP_LOGI(TAG,"post data:%s",payload);
        err = esp_http_client_set_post_field(client,payload,strlen(payload));//保存要发送的数据和长度
        if(err != ESP_OK)
        {
            ESP_LOGI(TAG,"set post field failed!....");
            return ESP_FAIL;
        }
    }
    
    memset(ota_data_buff,0,sizeof(ota_data_buff));
    ota_data_size = 0;
    err = esp_http_client_perform(client);//完成发送数据
    if(err != ESP_OK)
    {
        ESP_LOGI(TAG,"http perform failed!....");
        return ESP_FAIL;
    }
    free(token);
    esp_http_client_cleanup(client);
    return ESP_OK;
}

//上传版本号 
//和http://iot-api.heclouds.com/fuse-ota/{pro_id}/{dev_name}/version
//onenet_ota
esp_err_t onenet_ota_upload_version(void)
{
    char version[256];
    char url[256];
    esp_err_t ret = ESP_FAIL;
    const char* app_version = get_app_version();
    snprintf(version,256,"{\"s_version\":\"%s\",\"f_version\": \"%s\"}",app_version,app_version);
    snprintf(url,256,"%s/%s/%s/version",ONENET_OTA_URL,ONENET_PDORUCT_ID,ONENET_DEVICE_NAME);

    if(onenet_ota_http_connect(url,HTTP_METHOD_POST,version)!= ESP_OK)
    {
        ESP_LOGI(TAG,"Upload Version Fail.....");
        return ESP_FAIL;
    }
    //上报版本号完成
    //解析数据
    cJSON *root = cJSON_Parse((char *)ota_data_buff);
    if(root)
    {
        const cJSON* code_js = cJSON_GetObjectItem(root,"code");
        if(code_js && (cJSON_GetNumberValue(code_js) == 0))
        {
            ret = ESP_OK;
            cJSON_Delete(root);
        }
    }
    else
    {
        ESP_LOGI(TAG,"Uploade Version Fail");
    }
    return ret;
   
}
//
/*
{
	"code": 0,
	"msg": "succ",
	"request_id": "**********",
	"data": {
		"target": "1.2", // 升级任务的目标版本
		"tid": 12, //任务ID
		"size": 123, //文件大小
		"md5": "dfkdajkfd", //升级文件的md5
		"status": 1 | 2 | 3, //1 ：待升级， 2 ：下载中， 3 ：升级中
		"type": 1 | 2 // 1:完整包，2：差分包  
	}
}
*/
//
esp_err_t onenet_ota_check_task(const char* type,const char* version)
{
    char url[256];
    snprintf(url,256,"%s/%s/%s/check?type=1&version=1.2",ONENET_OTA_URL,ONENET_PDORUCT_ID,ONENET_DEVICE_NAME);
    if(ESP_OK == onenet_ota_http_connect(url,HTTP_METHOD_GET,NULL))
    {
        cJSON *root = cJSON_Parse((char *)ota_data_buff);
        const cJSON* code_js = cJSON_GetObjectItem(root,"code");
        const cJSON* data_js = cJSON_GetObjectItem(root,"data");
        cJSON* target_js = cJSON_GetObjectItem(data_js,"target");
        cJSON* task_js = cJSON_GetObjectItem(data_js,"tid");
        if(code_js && (cJSON_GetNumberValue(code_js) == 0))
        {
            if(target_js && task_js)
            {
                //保存升级任务的目标版本和ID
                snprintf(target_version,sizeof(version),"%s",cJSON_GetStringValue(target_js));
                task_id = cJSON_GetNumberValue(task_js);
            }
            else
            {
                ESP_LOGI(TAG,"Check Task Fail...........");
                return ESP_FAIL;
            }
        }
        else
        {
            ESP_LOGI(TAG,"Check Task Fail...........");
            return ESP_FAIL;
        }
       ESP_LOGI(TAG,"Checking Task successfully!");
       return ESP_OK;
    }
    return ESP_FAIL;
}
/*
{
	"code": 0,
	"msg": "succ",
	"request_id": "**********",
        "data": {
		"status":1 //1: 待升级、2: 下载中、3:升级中、4:升级成功、5: 升级失败、6:升级取消  
	}
}
*/
int onenet_ota_check_upload_status(void)
{
    int status_num = 0;
    char version[256];
    char url[256];
    const char* app_version = get_app_version();
    snprintf(version,sizeof(version),"{\"s_version\":\"%s\",\"f_version\": \"%s\"}",app_version,app_version);
    snprintf(url,sizeof(url),"%s/%s/%s/check",ONENET_OTA_URL,ONENET_PDORUCT_ID,ONENET_DEVICE_NAME);
    if(onenet_ota_http_connect(url,HTTP_METHOD_GET,NULL)!= ESP_OK)
    {
        ESP_LOGI(TAG,"Checking upload status Fail.....");
        return ESP_FAIL;
    }
    cJSON* root = cJSON_Parse((char *)ota_data_buff);
    cJSON* code_js = cJSON_GetObjectItem(root,"code");
    cJSON* data_js = cJSON_GetObjectItem(root,"data");
    if(code_js && (cJSON_GetNumberValue(code_js) == 0))
    {
        if(data_js)
        {
            cJSON* status_js = cJSON_GetObjectItem(data_js,"status");
            status_num = cJSON_GetNumberValue(status_js);
            switch (status_num)
            {
                case 1:
                    ESP_LOGI(TAG,"Pending Upgrade.....");
                    break;
                case 2:
                    ESP_LOGI(TAG,"Downloading.........");
                    break;
                case 3:
                        ESP_LOGI(TAG,"Upgrading.........");
                    break;
                case 4:
                    ESP_LOGI(TAG,"Upgrade succeeded.........");
                    break;
                case 5:
                    ESP_LOGI(TAG,"Upgrade failed.........");
                    break;
                default:
                    break;
            }   

        }
        
    }
    return status_num;
}

//上报升级状态
esp_err_t onenet_ota_upload_task(int tid,int step)
{
    char url[256];
    char payload[256];
    snprintf(payload,256,"{\"step\":%d}",step);
    snprintf(url,256,"%s/%s/%s/%d/status",ONENET_OTA_URL,ONENET_PDORUCT_ID,ONENET_DEVICE_NAME,tid);
    esp_err_t ret = ESP_FAIL;
    if(onenet_ota_http_connect(url,HTTP_METHOD_POST,payload) == ESP_OK)
    {
        cJSON *root = cJSON_Parse((const char*)ota_data_buff);
        if(root)
        {
            const cJSON *code_js = cJSON_GetObjectItem(root,"code");
            if(code_js && cJSON_GetNumberValue(code_js) == 0)
            {
                ret = ESP_OK;
                cJSON_Delete(root);
            }
        }
    }
    else
    {
        ESP_LOGI(TAG,"Upload Task Status Fail");
    }
    return ret;
}
esp_err_t http_client_init_callback(esp_http_client_handle_t client)
{
    static char token[256];
    memset(token,0,256);
    dev_token_generate(token, SIG_METHOD_SHA256, 2099628748, ONENET_PDORUCT_ID, NULL, ONENET_ACCESS_KEY);
    esp_http_client_set_method(client, HTTP_METHOD_GET);
    esp_http_client_set_header(client, "Content-Type", "application/json");
    esp_http_client_set_header(client, "host", "iot-api.heclouds.com");
    esp_http_client_set_header(client, "Authorization", token);
    return ESP_OK;
}
//下载升级包
esp_err_t onenet_ota_download(int tid)
{
    char url[128];
    snprintf(url,128,"%s/%s/%s/%d/download",ONENET_OTA_URL,ONENET_PDORUCT_ID,ONENET_DEVICE_NAME,tid);
    esp_http_client_config_t http_config = {
        .url = url,
        .timeout_ms = 60000,//OTA区域较大，要设置较长的timeout
    };
    esp_https_ota_config_t ota_config = {
        .http_config = &http_config,
        .http_client_init_cb = http_client_init_callback,
    };
    esp_err_t ota_ret = ESP_FAIL;
    if(esp_https_ota(&ota_config) == ESP_OK)//镜像已经成功写入并设置为下次启动分区
    {
        ota_ret = ESP_OK;
        ESP_LOGI(TAG,"OTA image installed, reboot required");
    }
    else
    {
        ESP_LOGI(TAG,"OTA Download Fail");
    }
    return ota_ret;

}
static void onenet_ota_task(void* param)
{
    esp_err_t ret = ESP_FAIL;
    //1.上报版本号
    ret = onenet_ota_upload_version();
    if(ret != ESP_OK)
    {
        ESP_LOGE(TAG,"Upload Version Fail");
        goto onenet_ota_task_fail;
    }
    //2.检测升级任务
    ret = onenet_ota_check_task("1",get_app_version());
    if(ret != ESP_OK)
    {
        ESP_LOGE(TAG,"Check Task Fail");
        goto onenet_ota_task_fail;
    }
    // 3.上报升级状态10%
    ret = onenet_ota_upload_task(task_id,10);
    if(ret != ESP_OK)
    {
        ESP_LOGE(TAG,"Upload Status Fail");
        goto onenet_ota_task_fail;
    }
    // 4.下载升级包
    ret = onenet_ota_download(task_id);
    if(ret != ESP_OK)
    {
        ESP_LOGE(TAG,"Download Task Fail");
        goto onenet_ota_task_fail;
    }
    // 5.上报升级状态100%
    ret = onenet_ota_upload_task(task_id,100);
    if(ret != ESP_OK)
    {
        ESP_LOGE(TAG,"Upload Status Fail");
        goto onenet_ota_task_fail;
    }
    ESP_LOGI(TAG,"OTA Finished!");
    // 6. 重启
    esp_restart();
onenet_ota_task_fail:
    ota_is_running = false;
    vTaskDelete(NULL);
}
void onenet_ota_start(void)
{
    if(ota_is_running)
    {
        return;
    }
    ESP_LOGI(TAG,"Start OTA");
    ota_is_running = true;
    xTaskCreatePinnedToCore(onenet_ota_task,"ONENET_OTA",8192,NULL,2,NULL,1);
}