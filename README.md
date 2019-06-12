# qs_stm32_board简介
本代码是河北骑士智能科技有限公司自主STM32开发板配套代码，代码由简入深，在相应的单片机文件内部分为demo、led、beep、key、oled、sht20、oled、rtc以及nb-iot代码。
单片机目前已经适配STM32L151RCT6、STM32F103RET6，其他单片机在后期适配。源码地址：[https://github.com/hbqs/qs_stm32_board] 作者:[longmain](https://github.com/hbqs)

## 前言
由于目前各方都在大力推动NB-IOT产业发展，我们骑士智能科技也代理了NB-IOT模组，为了让大家在使用我们代理的模组时更加方便，我们设计了STM32开发板，编写了qs_stm32_board驱动代码，目前该代码在使用过程中简单方便，使用RTTHREAD 组件，可以图像化配置，减轻了大量的工作，可以促进产品快速开发。
在这里感谢RT-THREAD 这款好用的的物联网系统，同时更感谢广大开源的支持者。让我从中学到了很多，网络也是一个好平台，希望所有的开发者能形成良性循环，从网络中学知识，回馈到网络中去。

## 代码简介
qs_stm32_board是一个驱动stm32单片机的代码，目前支持STM32L151RCT6、STM32F103RET6单片机。更多单片机在后期适配中会支持。
代码中使用我们骑士编写的QSDK组件，可以根据不同的模块启用不同的功能，目前代码支持电信IOT平台、中移ONENET平台（LWM2M协议和MQTT协议）和UDP\TCP协议。目前支持的nb-iot模块型号有M5310、M5310A、M5311，后期将会增加更多模组支持。

##  特点
qs_stm32_board开放源码、模块化编程，在传感器驱动和nb控制方面，均采用单独的.h和.c文件，层次感分明，易于编程和处理。同时代码支持快速初始化NB模块联网，快速连接onenet平台等功能，大大简化了客户的使用方式。

## qs_stm32_board视频教程
关于代码我们已经录制了视频教程，获取视频方式可以联系我们的技术支持。


## 联系人

* 技术支持：longmain	QQ：1239799850
* 邮箱：[longmain@longmain.cn](mailto:longmain@longmain.cn)
* 主页：[qsdk](https://github.com/qs_stm32_board)
* 仓库：[Github](https://github.com/hbqs)