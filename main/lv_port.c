#include "lv_port.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include"esp_lvgl_port.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_err.h"
#include "xl9555.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "ft6336u.h"


#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 240
#define LCD_RST_IO IO1_3
#define TAG "lv_port"
static esp_lcd_panel_io_handle_t io_handle = NULL;
static  esp_lcd_panel_handle_t panel_handle = NULL;//操作LCD屏
static lv_display_t *lvgl_disp = NULL;
static lv_indev_t *touch_indev = NULL;


void lv_disp_hard_init(void)
{
     ESP_LOGI(TAG, "Initialize Intel 8080 bus");
    esp_lcd_i80_bus_handle_t i80_bus = NULL;
    /* 物理总线， 描述连接屏幕的8080总线是什么样子的*/
    esp_lcd_i80_bus_config_t bus_config = {
        .clk_src = LCD_CLK_SRC_DEFAULT,
        .dc_gpio_num = GPIO_NUM_1,
        .wr_gpio_num = GPIO_NUM_41,
        .data_gpio_nums = {
            GPIO_NUM_40,
                GPIO_NUM_38,
                GPIO_NUM_39,
                GPIO_NUM_48,
                GPIO_NUM_45,
                GPIO_NUM_21,
                GPIO_NUM_47,
                GPIO_NUM_14,
        },
        .bus_width = 8,
        .max_transfer_bytes = DISPLAY_WIDTH * DISPLAY_HEIGHT,
        .dma_burst_size = 64,
    };
    ESP_ERROR_CHECK(esp_lcd_new_i80_bus(&bus_config, &i80_bus));
    /* 器件协议 在这条总线上挂一个LCD屏时应该根据怎么样的协议收发数据 */
    esp_lcd_panel_io_i80_config_t io_config = {
        .cs_gpio_num = GPIO_NUM_2,
        .pclk_hz = 10*1000*1000,//像素时钟 像素传输的频率 
        .trans_queue_depth = 10,
        .dc_levels = {
            .dc_idle_level = 0,
            .dc_cmd_level = 0,
            .dc_dummy_level = 0,
            .dc_data_level = 1,
        },
        .lcd_cmd_bits = 8,
        .lcd_param_bits = 8,
        .flags = {
            .swap_color_bytes = 1,
            
        },
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_i80(i80_bus, &io_config, &io_handle));//io_handle这个句柄负责“字节流怎么送到屏上”

    ESP_LOGI(TAG, "Install LCD driver of st7789");
    /* 屏幕驱动配置，直接控制ST7789 */
    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = GPIO_NUM_NC,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_RGB,
        .bits_per_pixel = 16,
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_st7789(io_handle, &panel_config, &panel_handle));//创建出panel_handle，以后想控制屏幕都通过panel_handle

    // esp_lcd_panel_reset(panel_handle);
    // esp_lcd_panel_init(panel_handle);
    // // Set inversion, x/y coordinate order, x/y mirror according to your LCD module spec
    // // the gap is LCD panel specific, even panels with the same driver IC, can have different gap value
    // esp_lcd_panel_invert_color(panel_handle, true);
    // esp_lcd_panel_set_gap(panel_handle, 0, 20);
    esp_lcd_panel_reset(panel_handle);
    esp_lcd_panel_init(panel_handle);
    esp_lcd_panel_swap_xy(panel_handle,true);
    esp_lcd_panel_mirror(panel_handle, false, true);
    esp_lcd_panel_disp_on_off(panel_handle, true);//打开显示

}

void ft6336u_callback(lv_indev_t * indev, lv_indev_data_t * data)
{
    int16_t x,y;
    int state;
    ft6336u_read(&x,&y,&state);
    data->point.x = DISPLAY_WIDTH - y - 1;
    data->point.y = x;
    data->state = state;
}


void lv_port_init(void)
{
    /* reset 一下电脑屏幕 */
    xl9555_pin_write(LCD_RST_IO,0);
    vTaskDelay(pdMS_TO_TICKS(50));
    xl9555_pin_write(LCD_RST_IO,1);

    lv_disp_hard_init();
    ft6336u_driver(GPIO_NUM_13,GPIO_NUM_12);
     /* Initialize LVGL */
     /* 初始化LVGL的运行环境 */
    const lvgl_port_cfg_t lvgl_cfg = {
        .task_priority = 4,         /* LVGL task priority */
        .task_stack = 8192,         /* LVGL task stack size */
        .task_affinity = 1,        /* LVGL task pinned to core (-1 is no affinity) */
        .task_max_sleep_ms = 500,   /* Maximum sleep in LVGL task */
        .timer_period_ms = 5        /* LVGL timer tick period in ms */
    };
    lvgl_port_init(&lvgl_cfg);
    
    /* Add LCD screen */
    ESP_LOGD(TAG, "Add LCD screen");
    /* 屏幕注册给 LVGL 它告诉 LVGL“用什么 buffer、什么分辨率、什么颜色格式刷新这块屏”：*/
    const lvgl_port_display_cfg_t disp_cfg = {
        .io_handle = io_handle,
        .panel_handle = panel_handle,
        .buffer_size = 40 * DISPLAY_WIDTH,
        .double_buffer = false,//双缓存模式
        .hres = DISPLAY_WIDTH,
        .vres = DISPLAY_HEIGHT,

        .color_format = LV_COLOR_FORMAT_RGB565,
        .rotation = {
            .swap_xy = true,
            .mirror_x = false,
            .mirror_y = true,
        },
        .flags = {
            .buff_dma = true,
        }
    };
    lvgl_disp = lvgl_port_add_disp(&disp_cfg);

    // /* Add touch input (for selected screen) */
    // const lvgl_port_touch_cfg_t touch_cfg = {
    //     .disp = lvgl_disp,
    //     .handle = touch_handle,
    // };
    // lvgl_touch_indev = lvgl_port_add_touch(&touch_cfg);
    lvgl_port_lock(0);
    touch_indev = lv_indev_create();
    lv_indev_set_type(touch_indev,LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(touch_indev,ft6336u_callback);
    lvgl_port_unlock();

}