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


int main(void)
{
	time_t rtc;
	struct tm *rtc_tab;
	while (1)
	{
		time(&rtc);
		rtc_tab=localtime(&rtc);
		rt_kprintf("%d-%d-%d_%d-%d-%d\r\n",rtc_tab->tm_year+1900,rtc_tab->tm_mon+1,rtc_tab->tm_mday,rtc_tab->tm_hour,rtc_tab->tm_min,rtc_tab->tm_sec);
		rt_thread_delay(10000);
	}

    return RT_EOK;
}
