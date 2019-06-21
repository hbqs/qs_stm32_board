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

//定义key 控制块
struct key_state_type key0={0};
struct key_state_type key1={0};

int main(void)
{
	while (1)
	{
		qsdk_key_process();
		//按键处理函数
		if(key0.down_state==KEY_PRESS)
		{
			rt_kprintf("key0 dowm press \r\n");
			key0.down_state=KEY_RELEASE;
		}
		else if(key0.double_state==KEY_PRESS)
		{
			rt_kprintf("key0 double press \r\n");
			key0.double_state=KEY_RELEASE;
		}
		else if(key0.long_state==KEY_PRESS)
		{
			rt_kprintf("key0 long press \r\n");
			key0.long_state=KEY_RELEASE;
		}
		
		else if(key1.down_state==KEY_PRESS)
		{
			rt_kprintf("key1 down press \r\n");
			key1.down_state=KEY_RELEASE;
		}
		else if(key1.double_state==KEY_PRESS)
		{
			rt_kprintf("key1 double press \r\n");
			key1.double_state=KEY_RELEASE;
		}			
		else if(key1.long_state==KEY_PRESS)
		{
			rt_kprintf("key1 long press \r\n");
			key1.long_state=KEY_RELEASE;
		}	
		rt_thread_mdelay(20);
	}
}
