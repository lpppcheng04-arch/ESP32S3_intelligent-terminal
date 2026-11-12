#ifndef _WEATHER_H_
#define _WEATHER_H_

typedef struct {
    int low;
    int high;
    char code[4];
}weather_data_pkt_t;
void init_weather_buffer(void);
void weather_start(void);

#endif

