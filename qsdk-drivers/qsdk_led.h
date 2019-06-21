#ifndef __QSDK_LED__H_
#define __QSDK_LED__H_

#include "rtthread.h"
#include "board.h"

#define LED0 GET_PIN(C, 6)
#define LED1 GET_PIN(C, 7)
#define LED2 GET_PIN(C, 8)
#define LED3 GET_PIN(C, 9)

#define LED_ON	PIN_HIGH
#define LED_OFF PIN_LOW

//定义led 状态结构体
struct led_state_type
{
	int current_state;
	int last_state;
};

void qsdk_led_on(rt_base_t pin);
void qsdk_led_off(rt_base_t pin);



#endif
