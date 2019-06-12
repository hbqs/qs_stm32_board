#include "qsdk_led.h"

void qsdk_led_init(void)
{
	rt_pin_mode(LED0,PIN_MODE_OUTPUT);
	rt_pin_write(LED0,PIN_HIGH);
	
	rt_pin_mode(LED1,PIN_MODE_OUTPUT);
	rt_pin_write(LED1,PIN_HIGH);
	
	rt_pin_mode(LED2,PIN_MODE_OUTPUT);
	rt_pin_write(LED2,PIN_HIGH);
	
	rt_pin_mode(LED3,PIN_MODE_OUTPUT);
	rt_pin_write(LED3,PIN_HIGH);
}

void qsdk_led_on(rt_base_t pin)
{
    rt_pin_write(pin,PIN_LOW);
}


void qsdk_led_off(rt_base_t pin)
{
	rt_pin_write(pin,PIN_HIGH);
}
