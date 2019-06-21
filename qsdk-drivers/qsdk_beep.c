#include "qsdk_beep.h"
#include "rtthread.h"

int qsdk_beep_init(void)
{
	rt_pin_mode(BEEP,PIN_MODE_OUTPUT);
	rt_pin_write(BEEP,PIN_LOW);
	
	return RT_EOK;
}

void qsdk_beep_on(void)
{
	rt_pin_write(BEEP,PIN_HIGH);
}

void qsdk_beep_off(void)
{
	rt_pin_write(BEEP,PIN_LOW);
}

INIT_APP_EXPORT(qsdk_beep_init);
