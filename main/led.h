#ifndef _LED_H_
#define _LED_H_

#include <stdio.h>
#include <stdbool.h>
void led_init(void);
void led_set_brightness(int brightness);

void my_ws2812_init(void);

void my_ws2812_set_rgb(int r,int g,int b);

#endif

