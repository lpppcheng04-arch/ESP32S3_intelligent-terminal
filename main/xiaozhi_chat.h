#ifndef _XIAOZHI_CHAT_H_
#define _XIAOZHI_CHAT_H_

#include "esp_err.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    XIAOZHI_EVT_STATUS = 0,
    XIAOZHI_EVT_ACTIVATION_CODE,
    XIAOZHI_EVT_USER_TEXT,
    XIAOZHI_EVT_AI_TEXT,
    XIAOZHI_EVT_EMOJI,
    XIAOZHI_EVT_LISTENING,
    XIAOZHI_EVT_SPEAKING,
    XIAOZHI_EVT_CONNECTED,
    XIAOZHI_EVT_DISCONNECTED,
    XIAOZHI_EVT_ERROR,
} xiaozhi_evt_t;

typedef void (*xiaozhi_evt_cb_t)(xiaozhi_evt_t evt, const char *text);

esp_err_t xiaozhi_chat_start(xiaozhi_evt_cb_t cb);

void xiaozhi_chat_stop(void);

void xiaozhi_chat_listen_now(void);

void xiaozhi_chat_abort_speaking(void);

bool xiaozhi_chat_is_active(void);

#ifdef __cplusplus
}
#endif

#endif
