#ifndef _AIDA64_H_
#define _AIDA64_H_

#include <stdbool.h>

typedef struct {
    int cpu_rate;
    int cpu_temp;
    int mem_rate;
    int mem_use;
}aida64_data_t;


static void aida64_connect_init(void);
void aida64_monitor_start(char* ip);
void aida64_disconnect(void);

bool aida64_isconnect(void);


#endif

