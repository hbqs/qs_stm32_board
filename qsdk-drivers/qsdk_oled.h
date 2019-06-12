#ifndef __QSDK_OLED__H_
#define __QSDK_OLED__H_

extern const unsigned char Qi[];
extern const unsigned char Shi[];
extern const unsigned char Zhi[];
extern const unsigned char Neng[];
extern const unsigned char Ke[];
extern const unsigned char Ji[];
extern const unsigned char wen[];
extern const unsigned char shi[];
extern const unsigned char du[];





void qsdk_oled_init(char *i2c_bus_name);

void qsdk_oled_send_byte(unsigned char byte);

void qsdk_oled_set_address(unsigned char page, unsigned char column);

void qsdk_oled_clear_screen(void);

void qsdk_oled_clear_line(unsigned char x);

void qsdk_oled_dis_128x64_picture(const unsigned char *dp);

void qsdk_oled_dis_16x16_char(unsigned short page, unsigned short column, const unsigned char *dp);

void qsdk_oled_dis_6x8_string(unsigned char x, unsigned char y, char *fmt, ...);

void qsdk_oled_dis_8x16_string(unsigned char x, unsigned char y, char *fmt, ...);


#endif
