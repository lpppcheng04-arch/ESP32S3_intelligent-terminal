#ifndef _XIAOZHI_UI_H_
#define _XIAOZHI_UI_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SPEAKER_LRCLK   GPIO_NUM_9
#define SPEAKER_BCLK    GPIO_NUM_46
#define SPEAKER_SD      GPIO_NUM_8
#define MICRO_CLK       GPIO_NUM_3
#define MICRO_DATA      GPIO_NUM_42

void xiaozhi_ui_open(void);

#ifdef __cplusplus
}
#endif

#endif
