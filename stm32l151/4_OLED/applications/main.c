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
#include "qsdk_oled.h"


int main(void)
{
	qsdk_oled_init("i2c1");
	qsdk_oled_clear_screen();
	
	while (1)
	{
		qsdk_oled_dis_16x16_char(0, 16, Qi);
		rt_thread_delay(500);
		qsdk_oled_dis_16x16_char(0, 32, Shi);
		rt_thread_delay(500);
		qsdk_oled_dis_16x16_char(0, 48, Zhi);
		rt_thread_delay(500);
		qsdk_oled_dis_16x16_char(0, 64, Neng);
		rt_thread_delay(500);
		qsdk_oled_dis_16x16_char(0, 80, Ke);
		rt_thread_delay(500);
		qsdk_oled_dis_16x16_char(0, 96, Ji);
		rt_thread_delay(500);
		qsdk_oled_dis_8x16_string(2,24,"EVB_IOT_M1");
		rt_thread_delay(500);
		qsdk_oled_clear_screen();
	}
}
