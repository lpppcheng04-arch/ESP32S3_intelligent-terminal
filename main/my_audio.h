#ifndef _MY_AUDIO_H_
#define _MY_AUDIO_H_
#include "driver/gpio.h"

void my_audio_init(gpio_num_t lrclk,gpio_num_t bclk,gpio_num_t sd,gpio_num_t clk,gpio_num_t data);

int my_audio_write(const int16_t *src, int samples);


int my_audio_read(int16_t *dest, int samples);
void i2s_close(void);
void i2s_open(void);
#endif

