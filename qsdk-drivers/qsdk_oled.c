//硬件驱动
#include "qsdk_oled.h"
#include "board.h"
//字库
#include "qsdk_oled_zk.h"

//C库
#include <stdarg.h>
#include <stdio.h>

#define DBG_ENABLE
#define DBG_SECTION_NAME "OLED"
#define DBG_LEVEL DBG_LOG
#define DBG_COLOR
#include <rtdbg.h>


static struct rt_i2c_bus_device *i2c_bus;
static rt_mutex_t i2c_lock;

#define OLED_ADDRESS		0x3C
#define OLED_WRITE_CMD 	0x00
#define OLED_WRITE_DATE 0x40

/*
************************************************************
*	函数名称：	qsdk_oled_write_data
*
*	函数功能：	OLED写入一个数据
*
*	入口参数：	byte：需要写入的数据
*
*	返回参数：	写入结果
*
*	说明：		0-成功		1-失败
************************************************************
*/
static _Bool qsdk_oled_write_data(unsigned char byte)
{
	rt_uint8_t buf[2];
	
	buf[0]=OLED_WRITE_DATE;
	buf[1]=byte;
	
	if(rt_i2c_master_send(i2c_bus,OLED_ADDRESS,0,buf,2)==2)
	{
		return RT_EOK;
	}
	else
	{
		LOG_E("oled write data error,plese check i2c gpio init\r\n");
		return RT_ERROR;
	}
}

/*
************************************************************
*	函数名称：	qsdk_oled_write_cmd
*
*	函数功能：	OLED写入一个命令
*
*	入口参数：	cmd：需要写入的命令
*
*	返回参数：	写入结果
*
*	说明：		0-成功		1-失败
************************************************************
*/
static _Bool qsdk_oled_write_cmd(unsigned char cmd)
{
	rt_uint8_t buf[2];
	
	buf[0]=OLED_WRITE_CMD;
	buf[1]=cmd;
	
	if(rt_i2c_master_send(i2c_bus,OLED_ADDRESS,0,buf,2)==2)
	{
		return RT_EOK;
	}
	else
	{
		LOG_E("oled write cmd error,plese check i2c gpio init\r\n");
		return RT_ERROR;
	}
}

/*
************************************************************
*	函数名称：	qsdk_oled_init
*
*	函数功能：	OLED初始化
*
*	入口参数：	无
*
*	返回参数：	无
*
*	说明：		
************************************************************
*/
void qsdk_oled_init(char *i2c_bus_name)
{
	i2c_bus=(struct rt_i2c_bus_device*)rt_device_find(i2c_bus_name);
	if(i2c_bus==RT_NULL)
	{
		LOG_E("no find i2c device:%s\r\n",i2c_bus_name);
	}
	i2c_lock=rt_mutex_create("i2c_lock",RT_IPC_FLAG_FIFO);
	if(i2c_lock==RT_NULL)
	{
		LOG_E("i2c create mutex fail\r\n");
	}
	rt_thread_delay(100);
#if 1
	qsdk_oled_write_cmd(0xAE); //关闭显示
	qsdk_oled_write_cmd(0x20); //Set Memory Addressing Mode	
	qsdk_oled_write_cmd(0x10); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	qsdk_oled_write_cmd(0xb0); //Set Page Start Address for Page Addressing Mode,0-7
	qsdk_oled_write_cmd(0xa1); //0xa0，X轴正常显示；0xa1，X轴镜像显示
	qsdk_oled_write_cmd(0xc8); //0xc0，Y轴正常显示；0xc8，Y轴镜像显示
	qsdk_oled_write_cmd(0x00); //设置列地址低4位
	qsdk_oled_write_cmd(0x10); //设置列地址高4位
	qsdk_oled_write_cmd(0x40); //设置起始线地址
	qsdk_oled_write_cmd(0x81); //设置对比度值
	qsdk_oled_write_cmd(0x7f); //------
	qsdk_oled_write_cmd(0xa6); //0xa6,正常显示模式;0xa7，
	qsdk_oled_write_cmd(0xa8); //--set multiplex ratio(1 to 64)
	qsdk_oled_write_cmd(0x3F); //------
	qsdk_oled_write_cmd(0xa4); //0xa4,显示跟随RAM的改变而改变;0xa5,显示内容忽略RAM的内容
	qsdk_oled_write_cmd(0xd3); //设置显示偏移
	qsdk_oled_write_cmd(0x00); //------
	qsdk_oled_write_cmd(0xd5); //设置内部显示时钟频率
	qsdk_oled_write_cmd(0xf0); //------
	qsdk_oled_write_cmd(0xd9); //--set pre-charge period//
	qsdk_oled_write_cmd(0x22); //------
	qsdk_oled_write_cmd(0xda); //--set com pins hardware configuration//
	qsdk_oled_write_cmd(0x12); //------
	qsdk_oled_write_cmd(0xdb); //--set vcomh//
	qsdk_oled_write_cmd(0x20); //------
	qsdk_oled_write_cmd(0x8d); //--set DC-DC enable//
	qsdk_oled_write_cmd(0x14); //------
	qsdk_oled_write_cmd(0xaf); //打开显示
#else
	qsdk_oled_write_cmd(0xAE);   //display off
	qsdk_oled_write_cmd(0x00);	//Set Memory Addressing Mode	
	qsdk_oled_write_cmd(0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	qsdk_oled_write_cmd(0x40);	//Set Page Start Address for Page Addressing Mode,0-7
	qsdk_oled_write_cmd(0xb0);	//Set COM Output Scan Direction
	qsdk_oled_write_cmd(0x81);//---set low column address
	qsdk_oled_write_cmd(0xff);//---set high column address
	qsdk_oled_write_cmd(0xa1);//--set start line address
	qsdk_oled_write_cmd(0xa6);//--set contrast control register
	qsdk_oled_write_cmd(0xa8);
	qsdk_oled_write_cmd(0x3f);//--set segment re-map 0 to 127
	qsdk_oled_write_cmd(0xad);//--set normal display
	qsdk_oled_write_cmd(0x8b);//--set multiplex ratio(1 to 64)
	qsdk_oled_write_cmd(0x33);//
	qsdk_oled_write_cmd(0xc8);//0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	qsdk_oled_write_cmd(0xd3);//-set display offset
	qsdk_oled_write_cmd(0x00);//-not offset
	qsdk_oled_write_cmd(0xd5);//--set display clock divide ratio/oscillator frequency
	qsdk_oled_write_cmd(0x80);//--set divide ratio
	qsdk_oled_write_cmd(0xd9);//--set pre-charge period
	qsdk_oled_write_cmd(0x1f); //
	qsdk_oled_write_cmd(0xda);//--set com pins hardware configuration
	qsdk_oled_write_cmd(0x12);
	qsdk_oled_write_cmd(0xdb);//--set vcomh
	qsdk_oled_write_cmd(0x40);//0x20,0.77xVcc
//	qsdk_oled_write_cmd(0x8d);//--set DC-DC enable
//	qsdk_oled_write_cmd(0x14);//
	qsdk_oled_write_cmd(0xaf);//--turn on oled panel
#endif

}

/*
************************************************************
*	函数名称：	qsdk_oled_set_address
*
*	函数功能：	设置OLED显示地址
*
*	入口参数：	x：行地址
*				y：列地址
*
*	返回参数：	无
*
*	说明：		
************************************************************
*/
void qsdk_oled_set_address(unsigned char x, unsigned char y)
{

	qsdk_oled_write_cmd(0xb0 + x);					//设置行地址
	//HAL_Delay_us(5);
	qsdk_oled_write_cmd(((y & 0xf0) >> 4) | 0x10);	//设置列地址的高4位
	//HAL_Delay_us(5);
	qsdk_oled_write_cmd(y & 0x0f);					//设置列地址的低4位
	//HAL_Delay_us(5);
	
}

/*
************************************************************
*	函数名称：	qsdk_oled_clear_screen
*
*	函数功能：	OLED全屏清除
*
*	入口参数：	无
*
*	返回参数：	无
*
*	说明：		
************************************************************
*/
void qsdk_oled_clear_screen(void)
{
	
	unsigned char i = 0, j = 0;
	
	rt_enter_critical();
	for(; i < 8; i++)
	{
		qsdk_oled_write_cmd(0xb0 + i);
		qsdk_oled_write_cmd(0x10);
		qsdk_oled_write_cmd(0x00);
			
		for(j = 0; j < 128; j++)
		{
			qsdk_oled_write_data(0x00);
		}
	}
	rt_exit_critical();
	
}

/*
************************************************************
*	函数名称：	qsdk_oled_clear_line
*
*	函数功能：	OLED清除指定行
*
*	入口参数：	x：需要清除的行
*
*	返回参数：	无
*
*	说明：		
************************************************************
*/
void qsdk_oled_clear_line(unsigned char x)
{

	unsigned char i = 0;
		
	qsdk_oled_write_cmd(0xb0 + x);
	qsdk_oled_write_cmd(0x10);
	qsdk_oled_write_cmd(0x00);
			
	for(; i < 128; i++)
	{
		qsdk_oled_write_data(0x00);
	}

}

/*
************************************************************
*	函数名称：	qsdk_oled_dis_128x64_picture
*
*	函数功能：	显示一幅128*64的图片
*
*	入口参数：	dp：图片数据指针
*
*	返回参数：	无
*
*	说明：		
************************************************************
*/
void qsdk_oled_dis_128x64_picture(const unsigned char *dp)
{
	
	unsigned char i = 0, j = 0;
	
		
	for(; j < 8; j++)
	{
		qsdk_oled_set_address(j, 0);
		
		for (i = 0; i < 128; i++)
		{	
			qsdk_oled_write_data(*dp++); //写数据到LCD,每写完一个8位的数据后列地址自动加1
		}
	}
	
}

/*
************************************************************
*	函数名称：	qsdk_oled_dis_16x16_char
*
*	函数功能：	显示16x16的点阵数据
*
*	入口参数：	dp：图片数据指针
*
*	返回参数：	无
*
*	说明：		显示16x16点阵图像、汉字、生僻字或16x16点阵的其他图标
************************************************************
*/
void qsdk_oled_dis_16x16_char(unsigned short x, unsigned short y, const unsigned char *dp)
{
	
	unsigned short i = 0, j = 0;
		
	for(j = 2; j > 0; j--)
	{
		qsdk_oled_set_address(x, y);
		
		for (i = 0; i < 16; i++)
		{
			qsdk_oled_write_data(*dp++);		//写数据到OLED,每写完一个8位的数据后列地址自动加1
		}
		
		x++;
	}
	
}

/*
************************************************************
*	函数名称：	qsdk_oled_dis_6x8_string
*
*	函数功能：	显示6x8的点阵数据
*
*	入口参数：	x：显示行
*				y：显示列
*				fmt：不定长参
*
*	返回参数：	无
*
*	说明：		能显示7行
************************************************************
*/
void qsdk_oled_dis_6x8_string(unsigned char x, unsigned char y, char *fmt, ...)
{

	unsigned char i = 0, ch = 0;
	unsigned char OledPrintfBuf[300];
	
	va_list ap;
	unsigned char *pStr = OledPrintfBuf;
	
	va_start(ap,fmt);
	vsprintf((char *)OledPrintfBuf, fmt, ap);
	va_end(ap);
	
	y += 2;
		
	while(*pStr != '\0')
	{
		ch = *pStr - 32;
		
		if(y > 126)
		{
			y = 2;
			x++;
		}
		
		qsdk_oled_set_address(x, y);
		for(i = 0; i < 6; i++)
			qsdk_oled_write_data(F6x8[ch][i]);
		
		y += 6;
		pStr++;
	}

}

/*
************************************************************
*	函数名称：	qsdk_oled_dis_8x16_string
*
*	函数功能：	显示8x16的点阵数据
*
*	入口参数：	x：显示行
*				y：显示列
*				fmt：不定长参
*
*	返回参数：	无
*
*	说明：		能显示4行
************************************************************
*/
void qsdk_oled_dis_8x16_string(unsigned char x, unsigned char y, char *fmt, ...)
{

	unsigned char i = 0, ch = 0;
	unsigned char OledPrintfBuf[300];
	
	va_list ap;
	unsigned char *pStr = OledPrintfBuf;
	
	va_start(ap,fmt);
	vsprintf((char *)OledPrintfBuf, fmt, ap);
	va_end(ap);
	
	y += 2;
		
	while(*pStr != '\0')
	{
		ch = *pStr - 32;
			
		if(y > 128)
		{
			y = 2;
			x += 2;
		}
			
		qsdk_oled_set_address(x, y);
		for(i = 0; i < 8; i++)
			qsdk_oled_write_data(F8X16[(ch << 4) + i]);
		
		qsdk_oled_set_address(x + 1, y);
		for(i = 0; i < 8; i++)
			qsdk_oled_write_data(F8X16[(ch << 4) + i + 8]);
		
		y += 8;
		pStr++;
	}

}
