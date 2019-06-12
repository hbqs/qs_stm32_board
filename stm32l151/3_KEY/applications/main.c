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
#include "qsdk_key.h"

int main(void)
{
  //key gpio init
	qsdk_key_init();
	while (1)
	{
		qsdk_key_process();
		rt_thread_mdelay(20);
	}

	return RT_EOK;
}
