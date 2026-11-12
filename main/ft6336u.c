#include "ft6336u.h"
#include "driver/i2c_master.h"
#include "esp_log.h"

#define TAG "ft6336u"

static i2c_master_bus_handle_t ft6336u_bus_handle = NULL;
static i2c_master_dev_handle_t ft6336u_dev_handle = NULL;
static bool ft6336u_press = false;
esp_err_t ft6336u_driver(gpio_num_t sda,gpio_num_t scl)
{
    i2c_master_bus_config_t bus_config = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .i2c_port = -1,//-1自动分配
        .scl_io_num = scl,
        .sda_io_num = sda,
    };
    i2c_new_master_bus(&bus_config,&ft6336u_bus_handle);

    i2c_device_config_t dev_config = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = 0x38,
        .scl_speed_hz = 400*1000, //标准模式100K，快速模式400K
    };
    i2c_master_bus_add_device(ft6336u_bus_handle,&dev_config,&ft6336u_dev_handle);

    uint8_t read_buf[1];
    uint8_t write_buf[2];
    esp_err_t ret = ESP_FAIL;
    write_buf[0] = 0xA3;
    ret = i2c_master_transmit_receive(ft6336u_dev_handle,write_buf,1,read_buf,1,1000);
    if(ret != ESP_OK)
    {
        ESP_LOGI(TAG,"read dev ID Fail");
        return ret;
    }
    ESP_LOGI(TAG,"read ID successfully, ID:%d",read_buf[0]);
    // uint8_t write_buf[2];
    write_buf[0] = 0xA4;
    write_buf[1] = 0x00;
    ret = i2c_master_transmit(ft6336u_dev_handle,write_buf,2,1000);
    if(ret != ESP_OK)
    {
        ESP_LOGI(TAG,"set int Fail");
        return ret;
    }
    return ESP_OK;
}

void ft6336u_read(int16_t* x,int16_t* y,int* state)
{
    /* 读取0x02寄存器开始的五个寄存器值 */
    uint8_t write_buf[1];
    uint8_t read_buf[5];
    esp_err_t ret = ESP_FAIL;
    write_buf[0] = 0x02;
    static int16_t last_x = 0;
    static int16_t last_y = 0;
    /* 如果没有检测到屏幕按下则不读取 */
    if(ft6336u_press == false)
    {
        *x = last_x;
        *y = last_y;
        *state = 0;
        return;
    }
    //
    // 读完一次要不要设置回true?
    //
    ret = i2c_master_transmit_receive(ft6336u_dev_handle,write_buf,1,read_buf,5,1000);
    if(ret != ESP_OK)
    {
        *x = last_x;
        *y = last_y;
        *state = 0;
        ESP_LOGI(TAG,"read 0x02 fail");
        return;
    }
    int num = read_buf[0]&0x0f;
    if(num != 1)
    {
        *x = last_x;
        *y = last_y;
        *state = 0;
        ESP_LOGI(TAG,"number of point fail");
        return;
    }

    *x = ((read_buf[1] & 0x0f) << 8) | read_buf[2];
    *y = ((read_buf[3] & 0x0f) << 8) | read_buf[4];
    *state = 1;
    last_x = *x;
    last_y = *y;

}

//屏幕按下，产生下降沿才才开始读取
void ft6336u_int_info(bool flag)
{
    ft6336u_press = flag;
}


