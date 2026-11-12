#ifndef _WIFI_MANAGER_H_
#define _WIFI_MANAGER_H_

typedef enum{
    WIFI_STATE_DISCONNECTED,
    WIFI_STATE_CONNECTED,
}wifi_state;

typedef enum{
    WIFI_DISCONNECT_INTENT_NONE = 0, //被动断开
    WIFI_DISCONNECT_INTENT_USER,   //主动断开
    WIFI_DISCONNECT_INTENT_RECONFIGURE, //修改SSID或者密码导致错误
}wifi_disconnect_intent_t;

typedef void (*wifi_event_cb_t)(wifi_state ws);
void wifi_init_sta(wifi_event_cb_t fun);
void wifi_manager_sta_connect(const char* ssid,const char* password);
void wifi_manager_sta_stop(void);
int wifi_manager_sta_isconnect(void);

#endif