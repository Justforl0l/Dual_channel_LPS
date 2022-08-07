/*
 * util.h
 *
 * Created: 06.08.2022 13:12:56
 *  Author: shama
 */ 


#ifndef LCD_UTIL_H_
#define LCD_UTIL_H_

#include <avr/io.h>

#define RS					PD0
#define RW					PD1
#define EN					PD2

#define _8_BIT_MODE			1
#define _4_BIT_MODE			0

void lcd_send_command(unsigned char command, unsigned char mode);
void lcd_send_data(unsigned char data);
void lcd_display_string(unsigned char command, char *string);

#endif /* LCD_UTIL_H_ */