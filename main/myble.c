#include "myble.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "host/ble_hs.h"
#include "host/util/util.h"
#include "nimble/nimble_port.h"
#include "nimble/nimble_port_freertos.h"
#include "services/gap/ble_svc_gap.h"
#include "services/gatt/ble_svc_gatt.h"
#include "driver/gpio.h"
#define DEVICE_NAME "ESP32S3-NimBLE"
#define TAG "BLE"
static uint16_t rx_value_handler;
static uint16_t tx_value_handler;
static bool ble_adv_active = false;
static bool s_ble_ready = false;
static bool s_ble_initialized = false;

//事件回调函数
static int gatt_event_handler(uint16_t conn_handle, uint16_t attr_handle,
                               struct ble_gatt_access_ctxt *ctxt, void *arg)
{
    switch (ctxt->op)
    {
    case BLE_GATT_ACCESS_OP_WRITE_CHR:
        /* code */
        if(attr_handle == rx_value_handler)
        {
            if(ctxt->om->om_data[0] == 0x00)
            {
                gpio_set_level(GPIO_NUM_15,0);
            }
             if(ctxt->om->om_data[0] == 0x01)
            {
                gpio_set_level(GPIO_NUM_15,1);
            }
        }
        break;
    case BLE_GATT_ACCESS_OP_READ_CHR: //手机读取数据 esp32发送数据
        if(attr_handle == tx_value_handler)
        {
            const char* value = "Hello";
            os_mbuf_append(ctxt->om,value,strlen(value));
        }
        break;
    default:
        break;
    }
    return 0;
}
//gap事件回调函数
static int gap_event_handler(struct ble_gap_event *event, void *arg)
{
    switch (event->type)
    {
        case BLE_GAP_EVENT_CONNECT :
            /* code */
            if(event->connect.status == 0)//the connection was successfully established.
            {
                ESP_LOGI(TAG,"设备已连接");
                ble_adv_active = false;
            }
            else
            {
                ESP_LOGI(TAG,"连接失败，重新广播");
                if(!ble_adv_active)
                {
                    start_advertising();
                }
            }
            break;
        case BLE_GAP_EVENT_DISCONNECT:
            ESP_LOGI(TAG,"设备断开连接");
            if(!ble_adv_active)
            {
                start_advertising();
            }
        default:
            break;
    }
    return 0;



}
//
//  GATT 属性是从“手机客户端”的角度定义的
//
const struct ble_gatt_svc_def gatt_svcs[] = {
    {
        .type = BLE_GATT_SVC_TYPE_PRIMARY,
        .uuid = BLE_UUID16_DECLARE(0x00FF),
        .characteristics = (struct ble_gatt_chr_def[])
        {
            //RX特征 接收数据
            {
                .uuid = BLE_UUID16_DECLARE(0xFF01),
                .arg = NULL,
                .access_cb = gatt_event_handler,
                .flags = BLE_GATT_CHR_F_WRITE,
                .val_handle = &rx_value_handler,
            },
            //TX特征 发送数据
            {
                .uuid = BLE_UUID16_DECLARE(0xFF02),
                .arg = NULL,
                .access_cb = gatt_event_handler,
                .flags = BLE_GATT_CHR_F_READ | BLE_GATT_CHR_F_NOTIFY,
                .val_handle = &tx_value_handler,
            },
            {0}//不设置0容易数组越界
        }
    },
    {

    },
    {0}
};


//蓝牙开启广播
void start_advertising(void)
{
    if(!s_ble_ready)
    {
        ESP_LOGW(TAG,"BLE host is not ready!");
        return ;
    }
    struct ble_hs_adv_fields ble_hs = {0};
    ble_hs.name = (uint8_t*)DEVICE_NAME;
    ble_hs.name_len = strlen(DEVICE_NAME);
    ble_hs.name_is_complete = 1;
    ble_hs.flags = BLE_HS_ADV_F_DISC_GEN | BLE_HS_ADV_F_BREDR_UNSUP;
    ble_hs.tx_pwr_lvl_is_present = 1;//当前广播信号中是否包含功率信息
    ble_hs.tx_pwr_lvl = BLE_HS_ADV_TX_PWR_LVL_AUTO;
    //函数配置广播内容
    int rc = ble_gap_adv_set_fields(&ble_hs);
    if(rc != 0)
    {
        ESP_LOGE(TAG,"广播内容设置失败");
    }
    struct ble_gap_adv_params adv_params = {
        .conn_mode = BLE_GAP_CONN_MODE_UND,
        .disc_mode = BLE_GAP_DISC_MODE_GEN,
        .itvl_min = BLE_GAP_ADV_ITVL_MS(200),
        .itvl_max = BLE_GAP_ADV_ITVL_MS(500),
    };
    //函数开启广播
    rc = ble_gap_adv_start(BLE_OWN_ADDR_PUBLIC, NULL,BLE_HS_FOREVER,&adv_params,gap_event_handler, NULL);
    if(rc != 0)
    {
        ESP_LOGE(TAG,"广播内容开始失败");
    }
    ESP_LOGI(TAG,"广播开启成功...");
    ble_adv_active = true;
}
//蓝牙初始化成功
//调用该函数
static void on_sync(void)
{
    s_ble_ready = true;
    ESP_LOGI(TAG,"蓝牙初始化成功，开启广播...");
    start_advertising();
}
void host_task(void* arg)
{
    nimble_port_run();
    nimble_port_freertos_deinit();
}
void ble_init(void)
{
    nimble_port_init();
    ble_svc_gap_init();
    ble_svc_gatt_init();
    ble_svc_gap_device_name_set(DEVICE_NAME);
    //通信开始之前 ESP32S3先发送配置文件 
    ble_gatts_count_cfg(gatt_svcs);
    ble_gatts_add_svcs(gatt_svcs);

    ble_hs_cfg.sync_cb = on_sync; 
    nimble_port_freertos_init(host_task);//创建监听任务
}

esp_err_t ble_fallback_start(void)
{
    /*
     * 已经初始化过：
     * 只检查是否需要重新广播，绝不再次初始化。
     */
    if (s_ble_initialized) {
        return ESP_OK;
    }

    esp_err_t err = nimble_port_init();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "nimble_port_init failed: %s",
                 esp_err_to_name(err));
        return err;
    }

    ble_svc_gap_init();
    ble_svc_gatt_init();

    int rc = ble_svc_gap_device_name_set(DEVICE_NAME);
    if (rc != 0) {
        nimble_port_deinit();
        return ESP_FAIL;
    }

    rc = ble_gatts_count_cfg(gatt_svcs);
    if (rc != 0) {
        nimble_port_deinit();
        return ESP_FAIL;
    }

    rc = ble_gatts_add_svcs(gatt_svcs);
    if (rc != 0) {
        nimble_port_deinit();
        return ESP_FAIL;
    }

    ble_hs_cfg.sync_cb = on_sync;

    /*
     * 就是在这里变为 true。
     *
     * 表示 NimBLE 和 GATT 已经初始化完成，
     * 后续不能再次执行 nimble_port_init()。
     */
    s_ble_initialized = true;

    /*
     * 创建 NimBLE Host 任务。
     * Host 同步完成后会调用 on_sync()，再开始广播。
     */
    nimble_port_freertos_init(host_task);

    return ESP_OK;
}