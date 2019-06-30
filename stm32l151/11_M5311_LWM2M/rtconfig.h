#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Automatically generated file; DO NOT EDIT. */
/* RT-Thread Configuration */

/* RT-Thread Kernel */

#define RT_NAME_MAX 8
#define RT_ALIGN_SIZE 4
#define RT_THREAD_PRIORITY_32
#define RT_THREAD_PRIORITY_MAX 32
#define RT_TICK_PER_SECOND 1000
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_USING_IDLE_HOOK
#define RT_IDEL_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 256
#define RT_DEBUG

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE

/* Memory Management */

#define RT_USING_MEMPOOL
#define RT_USING_SMALL_MEM
#define RT_USING_HEAP

/* Kernel Device Object */

#define RT_USING_DEVICE
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 128
#define RT_CONSOLE_DEVICE_NAME "uart1"
#define RT_VER_NUM 0x40002
#define ARCH_ARM
#define ARCH_ARM_CORTEX_M
#define ARCH_ARM_CORTEX_M3

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN
#define RT_MAIN_THREAD_STACK_SIZE 2048
#define RT_MAIN_THREAD_PRIORITY 10

/* C++ features */


/* Command shell */

#define RT_USING_FINSH
#define FINSH_THREAD_NAME "tshell"
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_USING_SYMTAB
#define FINSH_USING_DESCRIPTION
#define FINSH_THREAD_PRIORITY 20
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_CMD_SIZE 80
#define FINSH_USING_MSH
#define FINSH_USING_MSH_DEFAULT
#define FINSH_USING_MSH_ONLY
#define FINSH_ARG_MAX 10

/* Device virtual file system */


/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_PIPE_BUFSZ 512
#define RT_USING_SERIAL
#define RT_SERIAL_USING_DMA
#define RT_SERIAL_RB_BUFSZ 64
#define RT_USING_I2C
#define RT_USING_I2C_BITOPS
#define RT_USING_PIN
#define RT_USING_RTC

/* Using Hardware Crypto drivers */


/* Using WiFi */


/* Using USB */


/* POSIX layer and C standard library */

#define RT_USING_LIBC

/* Network */

/* Socket abstraction layer */


/* Network interface device */


/* light weight TCP/IP stack */


/* Modbus master and slave stack */


/* AT commands */

#define RT_USING_AT
#define AT_USING_CLIENT
#define AT_CLIENT_NUM_MAX 1
#define AT_USING_CLI
#define AT_CMD_MAX_LEN 1100
#define AT_SW_VERSION_NUM 0x10300

/* VBUS(Virtual Software BUS) */


/* Utilities */

#define RT_USING_ULOG
#define ULOG_OUTPUT_LVL_D
#define ULOG_OUTPUT_LVL 7
#define ULOG_ASSERT_ENABLE
#define ULOG_LINE_BUF_SIZE 1100

/* log format */

#define ULOG_OUTPUT_FLOAT
#define ULOG_USING_COLOR
#define ULOG_OUTPUT_LEVEL
#define ULOG_OUTPUT_TAG
#define ULOG_BACKEND_USING_CONSOLE

/* RT-Thread online packages */

/* IoT - internet of things */

#define PKG_USING_QSDK
#define QSDK_USING_M5311
#define QSDK_UART "uart2"
#define QSDK_UART_BAUDRATE 115200
#define QSDK_USING_LOG
#define QSDK_HAND_THREAD_STACK_SIZE 1000
#define QSDK_CMD_REV_MAX_LEN 512
#define QSDK_TIME_ZONE 8
#define QSDK_USING_PWRKEY
#define QSDK_PWRKEY_PIN 24
#define QSDK_PWRKEY_PIN_VALUE 1
#define QSDK_RESET_PIN 25
#define QSDK_RESET_PIN_VALUE 1
#define QSDK_WAKEUP_IN_PIN 12
#define QSDK_WAUP_IN_PIN_VALUE 1
#define QSDK_USING_ONENET
#define QSDK_ONENET_OBJECT_MAX_NUM 10
#define QSDK_ONENET_ADDRESS "183.230.40.40"
#define QSDK_ONENET_PORT "5683"
#define QSDK_ONENET_LIFE_TIME 3000
#define PKG_USING_QSDK_LATEST_VERSION

/* Wi-Fi */

/* Marvell WiFi */


/* Wiced WiFi */


/* IoT Cloud */


/* security packages */


/* language packages */


/* multimedia packages */


/* tools packages */


/* system packages */


/* peripheral libraries and drivers */

#define PKG_USING_SHT2X
#define PKG_USING_SHT2X_LATEST_VERSION
#define PKG_USING_BUTTON
#define SINGLE_AND_DOUBLE_TRIGGER
#define LONG_FREE_TRIGGER
#define BUTTON_DEBOUNCE_TIME 2
#define BUTTON_CONTINUOS_CYCLE 1
#define BUTTON_LONG_CYCLE 1
#define BUTTON_DOUBLE_TIME 15
#define BUTTON_LONG_TIME 50
#define PKG_USING_BUTTON_V101

/* miscellaneous packages */


/* samples: kernel and components samples */

#define SOC_FAMILY_STM32
#define SOC_SERIES_STM32L1

/* Hardware Drivers Config */

#define SOC_STM32L151RC

/* On-chip Peripheral Drivers */

#define BSP_USING_GPIO
#define BSP_USING_UART
#define BSP_USING_UART1
#define BSP_USING_UART2
#define BSP_USING_I2C1
#define BSP_I2C1_SCL_PIN 26
#define BSP_I2C1_SDA_PIN 27
#define BSP_USING_ONCHIP_RTC

/* Board extended module qsdk Drivers */

#define BSP_USING_LED
#define BSP_USING_BEEP
#define BSP_USING_KEY
#define BSP_USING_OLED

#endif
