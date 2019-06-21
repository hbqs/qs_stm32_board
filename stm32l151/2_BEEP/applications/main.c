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
#include "qsdk_beep.h"

int main(void)
{
    while (1)
    {
        qsdk_beep_on();
        rt_thread_mdelay(200);
        qsdk_beep_off();
        rt_thread_mdelay(500);
    }
}
