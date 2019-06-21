/*
 * File      : main.c
 * This file is part of fun in evb_iot_m1 board
 * Copyright (c) 2018-2030, longmain Development Team
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-04-14     longmain     first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "qsdk_led.h"


int main(void)
{
    while (1)
    {
      qsdk_led_on(LED0);
			qsdk_led_on(LED3);
      rt_thread_mdelay(200);
			qsdk_led_off(LED0);
			qsdk_led_off(LED3);
      qsdk_led_on(LED1);
			qsdk_led_on(LED2);
      rt_thread_mdelay(500);
			qsdk_led_off(LED1);
			qsdk_led_off(LED2);
    }
}
