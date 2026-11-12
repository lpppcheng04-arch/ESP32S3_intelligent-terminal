#include "wifi_manager.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_wifi.h"
#include <string.h>
#include "custom.h"
#include "esp_sntp.h"
#include "time.h"
#include <sys/time.h>
#include "myble.h"

#define TAG "wifi_manager"

static bool s_had_ip = false; //是否真正获得过ip
static bool s_ble_fallback_requested = false;//防止重复启动BLE
static wifi_disconnect_intent_t s_disconnect_intent = WIFI_DISCONNECT_INTENT_NONE;
static wifi_event_cb_t wifi_event_callback;
static int esp_maxium_retry = 10;
static int s_retry_num = 0;
static bool is_sta_connected = false; //sta连接状态
static bool sta_configured = false; //是否用户要求断开连接
// static bool wifi_manual_configured = true;
static void initialize_sntp(void);
extern lv_ui guider_ui;


static void event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data)
{
   if(event_base == WIFI_EVENT)
   {
        switch (event_id)
        {
            case WIFI_EVENT_STA_START://STA启动，启动后开始连接
            ESP_LOGI(TAG,"wifi event start");
            if(sta_configured)
            {
                esp_wifi_connect();
            }
            
            /* code */
            break;
            case WIFI_EVENT_STA_DISCONNECTED:
            {
                wifi_event_sta_disconnected_t *dis = (wifi_event_sta_disconnected_t *)event_data;
                ESP_LOGW(TAG,"wifi disconnected, reason:%d", dis ? dis->reason : -1);
                if(is_sta_connected)
                {
                    wifi_event_callback(WIFI_STATE_DISCONNECTED);
                }
                is_sta_connected = false;
                  /*
                * 人为停止，不重连，不启动 BLE。
                * sta_configured = true：用户希望保持 Wi‑Fi 连接；发生断开属于被动掉线，需要重连。
                */
                if (s_disconnect_intent ==WIFI_DISCONNECT_INTENT_USER || !sta_configured) {
                    ESP_LOGI(TAG, "manual wifi disconnect");
                    break;
                }

                if(sta_configured == true && s_retry_num < esp_maxium_retry)
                {
                    s_retry_num++;
                    ESP_LOGI(TAG,"retry to connect (%d/%d)", s_retry_num, esp_maxium_retry);
                    esp_wifi_connect();
                }
                //重连失败
                if(s_retry_num >= esp_maxium_retry)
                {
                    ESP_LOGI(TAG,"retry to connect failed....................");
                    set_wifi_state_fail(&guider_ui);
                }

                //保证已经超过重连次数，获得过IP，非主动断开，第一次初始化蓝牙
                // if(s_retry_num >= esp_maxium_retry && s_had_ip 
                //     && sta_configured && s_disconnect_intent == WIFI_DISCONNECT_INTENT_NONE)
                // {
                //     ESP_LOGI(TAG,"Starting bluetooth....");
                //     s_ble_fallback_requested = true;
                //     ble_fallback_start();
                // }
                
                break;
            }
            case WIFI_EVENT_STA_CONNECTED:
                
                ESP_LOGI(TAG,"connected to AP");
                break;

            default:
                break;
        }
   }

   else if(event_base == IP_EVENT)
   {

        if(event_id == IP_EVENT_STA_GOT_IP)
        {
            esp_netif_ip_info_t *got_ip_info = (esp_netif_ip_info_t*)event_data;
            uint16_t ipv4_1 = esp_ip4_addr1_16(&got_ip_info->ip);
            uint16_t ipv4_2 = esp_ip4_addr2_16(&got_ip_info->ip);
            uint16_t ipv4_3 = esp_ip4_addr3_16(&got_ip_info->ip);
            uint16_t ipv4_4 = esp_ip4_addr4_16(&got_ip_info->ip);
            //uint32_t ip = got_ip_info->ip.addr;
            s_had_ip = true;
            s_ble_fallback_requested = false;
            s_disconnect_intent = WIFI_DISCONNECT_INTENT_NONE;
            is_sta_connected = true;
            s_retry_num = 0;
            set_wifi_state(&guider_ui,is_sta_connected);
            initialize_sntp();
            ESP_LOGI(TAG,"ip:%d.%d.%d.%d",ipv4_1,ipv4_2,ipv4_3,ipv4_4);
            wifi_event_callback(is_sta_connected);
        }
   }
}
   
void wifi_init_sta(wifi_event_cb_t fun)
{
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
     esp_netif_create_default_wifi_sta();

    wifi_init_config_t wifi_config = WIFI_INIT_CONFIG_DEFAULT();
     esp_wifi_init(&wifi_config);
     wifi_event_callback = fun;

     esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_t instance_got_ip;
     ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &event_handler,
                                                        NULL,
                                                        &instance_any_id));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        &event_handler,
                                                        NULL,
                                                        &instance_got_ip));

  
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));

    // ESP_ERROR_CHECK(esp_wifi_start() );
    ESP_LOGI(TAG, "wifi_init_sta finished.");

}

void wifi_manager_sta_connect(const char* ssid,const char* password)
{
   wifi_config_t wifi_cfg = {
        .sta = {
            .threshold.authmode = WIFI_AUTH_WPA2_PSK,
        },
    };
    snprintf((char*)wifi_cfg.sta.ssid,sizeof(wifi_cfg.sta.ssid),"%s",ssid);
    snprintf((char*)wifi_cfg.sta.password,sizeof(wifi_cfg.sta.password),"%s",password);    
    esp_wifi_set_config(WIFI_IF_STA,&wifi_cfg);
    esp_wifi_disconnect();
    s_disconnect_intent = WIFI_DISCONNECT_INTENT_NONE;
    sta_configured = true;
    s_retry_num = 0;
    esp_wifi_start();

}

void wifi_manager_sta_stop(void)
{
    s_disconnect_intent = WIFI_DISCONNECT_INTENT_USER;
    s_had_ip = false;
    
    s_ble_fallback_requested = false;
    s_retry_num = 0;
    sta_configured = false;
    set_wifi_state(&guider_ui, WIFI_STATE_DISCONNECTED);
    esp_wifi_stop();
}

int wifi_manager_sta_isconnect(void)
{
    return is_sta_connected;
}

//SNTP协议的初始化 

static void sntp_sync_time_callback (struct timeval *tv)
{
    ESP_LOGI(TAG,"time is:%lld",tv->tv_sec);
}
static void initialize_sntp(void)
{
    //避免重复初始化
    if(esp_sntp_enabled()) return ;
    ESP_LOGI(TAG,"Initializing SNTP");
    //设置为单播工作模式
    esp_sntp_setoperatingmode(ESP_SNTP_OPMODE_POLL);
    //设置sntp校时服务器
    esp_sntp_setservername(0, "ntp.aliyun.com");
    esp_sntp_setservername(1, "time.asia.apple.com");

    esp_sntp_set_time_sync_notification_cb(sntp_sync_time_callback);//SNTP 成功从服务器获取时间并完成一次校时
    esp_sntp_init();
}

