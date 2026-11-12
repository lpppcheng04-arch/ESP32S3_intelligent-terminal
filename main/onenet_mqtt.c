#include "onenet_mqtt.h"
#include "esp_log.h"
#include "mqtt_client.h"
#include "onenet_token.h"
#include "cJSON.h"
#include "onenet_dm.h"
#include <string.h>
#include <stdio.h>
#include "device_model.h"
#include "onenet_ota.h"

#define TAG "onenet_mqtt"

static dev_state_t dev_state_cfg = {0};
static esp_mqtt_client_handle_t onenet_handle;
static bool mqtt_connected = false;
static void onenet_subscribe(void);
static esp_err_t onenet_post_property_data(const char* data);
static void onenet_property_ack(const char* id,int code,const char* msg);
static void onenet_ota_ack(const char* id,int code,const char* msg);

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    ESP_LOGD(TAG, "Event dispatched from event loop base=%s, event_id=%" PRIi32 "", base, event_id);
    esp_mqtt_event_handle_t event = event_data;
   // esp_mqtt_client_handle_t client = event->client;
    switch ((esp_mqtt_event_id_t)event_id) {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
        mqtt_connected = true;
        onenet_subscribe();//订阅
        cJSON* property_js = onenet_property_upload(dev_state_cfg); // 属性上报
        char* data = cJSON_PrintUnformatted(property_js); //转换格式
        onenet_post_property_data(data); //发送上行topic和数据 esp_mqtt_client_publish
        onenet_ota_upload_version();
        set_app_valid(true);
        cJSON_free(data);
        cJSON_Delete(property_js);
        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
        mqtt_connected = false;
        break;

    case MQTT_EVENT_SUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_UNSUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_PUBLISHED:
        ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_DATA://ESP32订阅的某个topic收到信息
        ESP_LOGI(TAG, "MQTT_EVENT_DATA");
        printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
        printf("DATA=%.*s\r\n", event->data_len, event->data);
        cJSON* root = cJSON_Parse(event->data);
        if(strstr(event->topic,"property/set"))
        {
            onenet_property_handle(root);
            cJSON* id_js = cJSON_GetObjectItem(root,"id");
            onenet_property_ack(cJSON_GetStringValue(id_js),200,"success");
            cJSON_Delete(root);
        }
        else if(strstr(event->topic,"property/get"))
        {

        }
        else if(strstr(event->topic,"ota/inform"))
        {
            cJSON* ota_js = cJSON_Parse(event->data);
            cJSON* id_js = cJSON_GetObjectItem(ota_js,"id");
            onenet_ota_ack(cJSON_GetStringValue(id_js),200,"success");
            cJSON_Delete(ota_js);

            onenet_ota_start();
        }
        
        break;
    case MQTT_EVENT_ERROR:
        ESP_LOGI(TAG, "MQTT_EVENT_ERROR");
      
        break;
    default:
        ESP_LOGI(TAG, "Other event id:%d", event->event_id);
        break;
    }
}

esp_err_t onenet_start(void)
{
    esp_mqtt_client_config_t mqtt_cfg;
    memset(&mqtt_cfg,0,sizeof(esp_mqtt_client_config_t));

    mqtt_cfg.broker.address.uri = "mqtt://mqtts.heclouds.com";
    mqtt_cfg.broker.address.port = 1883;

    mqtt_cfg.credentials.client_id = ONENET_DEVICE_NAME;
    mqtt_cfg.credentials.username = ONENET_PDORUCT_ID;
    static char token[256];

    dev_token_generate(token,SIG_METHOD_SHA256,2099628748,ONENET_PDORUCT_ID,ONENET_DEVICE_NAME,ONENET_ACCESS_KEY);
    mqtt_cfg.credentials.authentication.password = token;

    onenet_handle = esp_mqtt_client_init(&mqtt_cfg);
    /* The last argument may be used to pass data to the event handler, in this example mqtt_event_handler */
    esp_mqtt_client_register_event(onenet_handle, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);

    return esp_mqtt_client_start(onenet_handle);
}

static void onenet_subscribe(void)
{
    //设备属性上报回应topic
    char post_topic[128];
    snprintf(post_topic,sizeof(post_topic),"$sys/%s/%s/thing/property/post/reply",ONENET_PDORUCT_ID,ONENET_DEVICE_NAME);
    esp_mqtt_client_subscribe(onenet_handle,post_topic,1);

    //设备属性设置下行
    char set_topic[128];
    snprintf(set_topic,sizeof(set_topic),"$sys/%s/%s/thing/property/set",ONENET_PDORUCT_ID,ONENET_DEVICE_NAME);
    esp_mqtt_client_subscribe(onenet_handle,set_topic,1);

    //设备属性获取 下行
     char get_topic[128];
    snprintf(get_topic,sizeof(get_topic),"$sys/%s/%s/thing/property/get",ONENET_PDORUCT_ID,ONENET_DEVICE_NAME);
    esp_mqtt_client_subscribe(onenet_handle,get_topic,1);

    /* 订阅OTA远程升级topic */
    char ota_topic[128];
    snprintf(ota_topic, 128, "$sys/%s/%s/ota/inform",
              ONENET_PDORUCT_ID, ONENET_DEVICE_NAME);
    esp_mqtt_client_subscribe(onenet_handle, ota_topic, 1);

}

static void onenet_ota_ack(const char* id,int code,const char* msg)
{
    /*$sys/{pid}/{device-name}/thing/property/post/reply*/
    char topic[128];
    snprintf(topic,128,"$sys/%s/%s/ota/inform_reply",ONENET_PDORUCT_ID,ONENET_DEVICE_NAME);
    cJSON* reply_js = cJSON_CreateObject();
    cJSON_AddStringToObject(reply_js,"id",id);
    cJSON_AddNumberToObject(reply_js,"code",code);
    cJSON_AddStringToObject(reply_js,"msg",msg);
    cJSON_PrintUnformatted(reply_js);
    char* data = cJSON_PrintUnformatted(reply_js);
    esp_mqtt_client_publish(onenet_handle,topic,data,strlen(data),1,0);
    cJSON_free(data);
    cJSON_Delete(reply_js);
}

static void onenet_property_ack(const char* id,int code,const char* msg)
{
    /*$sys/{pid}/{device-name}/thing/property/post/reply*/
    char topic[128];
    snprintf(topic,128,"$sys/%s/%s/thing/property/set_reply",ONENET_PDORUCT_ID,ONENET_DEVICE_NAME);
    cJSON* reply_js = cJSON_CreateObject();
    cJSON_AddStringToObject(reply_js,"id",id);
    cJSON_AddNumberToObject(reply_js,"code",code);
    cJSON_AddStringToObject(reply_js,"msg",msg);
    //cJSON_PrintUnformatted(reply_js);
    char* data = cJSON_PrintUnformatted(reply_js);
    esp_mqtt_client_publish(onenet_handle,topic,data,strlen(data),1,0);
    cJSON_free(data);
    cJSON_Delete(reply_js);
}

static esp_err_t onenet_post_property_data(const char* data)
{
     char reply_topic[128];
    snprintf(reply_topic, 128, "$sys/%s/%s/thing/property/post",
              ONENET_PDORUCT_ID, ONENET_DEVICE_NAME);
    return esp_mqtt_client_publish(onenet_handle,reply_topic,data,strlen(data),1,0);
}


void onenet_property_report(dev_state_t dev)
{
    if(onenet_handle == NULL || !mqtt_connected)
    {
        ESP_LOGW(TAG,"mqtt client is not connected,report ignore");
        return;
    }
    cJSON* property_js = onenet_property_upload(dev);
    if(property_js == NULL)
    {
        return;
    }
    char* data = cJSON_PrintUnformatted(property_js);
    onenet_post_property_data(data);
    cJSON_free(data);
    cJSON_Delete(property_js);
}

