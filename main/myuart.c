#include "myuart.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "custom.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "string.h"
#include "esp_log.h"

#define TAG "myuart"
static bool uart_isinit = false;
void my_uart_init(void)
{
    uart_config_t uart = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
        .stop_bits = UART_STOP_BITS_1,
    };
    uart_param_config(UART_NUM_0,&uart);
    // uart_set_pin(UART_NUM_0,GPIO_NUM_43,GPIO_NUM_44,UART_PIN_NO_CHANGE,UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM_0,256,0,0,NULL,0);
    uart_isinit = true;
}

static bool myuart_isinit(void)
{
    return uart_isinit;
}

static void my_uart_receive_task(void* param)
{
    char buf[256];
    while(1)
    {
        if(myuart_isinit())
        {
            static bool enter_flag = false;
            if(!enter_flag)
            {
                ESP_LOGI(TAG,"uart init successfully,enter receive task");
                enter_flag = true;
            }
            //实现没有接收任务时阻塞 降低功耗
            int len = uart_read_bytes(UART_NUM_0,buf,1,portMAX_DELAY);
            if(len < 0)
            {
                ESP_LOGI(TAG,"uart receive failed!\r\n");
                vTaskDelay(pdMS_TO_TICKS(100));
                continue; 
            }

            int str_len = uart_read_bytes(UART_NUM_0,buf+len,sizeof(buf)-len-1,pdMS_TO_TICKS(20));

            // int len = uart_read_bytes(UART_NUM_0,buf,sizeof(buf)-1, pdMS_TO_TICKS(1000));
            if(str_len > 0)
            {
                buf[str_len+len] = '\0';
                ESP_LOGI(TAG,"%.*s",str_len+len,buf);
                set_serial_receive(&guider_ui,buf);
            }
            memset(buf,0,sizeof(buf));
        }
         vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void uart_receive_start(void)
{
    xTaskCreatePinnedToCore(my_uart_receive_task,"uart receive task",2048,NULL,1,NULL,1);
}