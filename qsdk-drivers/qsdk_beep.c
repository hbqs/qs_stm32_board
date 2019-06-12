#include "qsdk_beep.h"
#include "rtthread.h"

void qsdk_beep_init(void)
{
	rt_pin_mode(BEEP,PIN_MODE_OUTPUT);
	rt_pin_write(BEEP,PIN_LOW);
}

void qsdk_beep_on(void)
{
	rt_pin_write(BEEP,PIN_HIGH);
}

void qsdk_beep_off(void)
{
	rt_pin_write(BEEP,PIN_LOW);
}

