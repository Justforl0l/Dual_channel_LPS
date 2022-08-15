/*
 * util.h
 *
 * Created: 06.08.2022 13:12:56
 *  Author: shama
 */ 


#ifndef LCD_UTIL_H_
#define LCD_UTIL_H_

#include <avr/io.h>
#include <stdbool.h>

#define F_CPU 8000000
#include <util/delay.h>

#include "config.h"
#include "lcd/lcd_commands.h"
#include "lcd/lcd_settings.h"
#include "lcd/custom_symbols/custom_symbols.h"

#define _8_BIT_MODE						1
#define _4_BIT_MODE						0
#define CHECK_BUSY_FLAG					1
#define DONT_CHECK_BUSY_FLAG			0

void lcd_send_command(unsigned char command, unsigned char mode,
					  unsigned char check_busy_flag);
void lcd_send_data(unsigned char data);
void lcd_display_string(unsigned char character_address, char *string);
void lcd_display_screensaver_template(void);
bool lcd_is_busy(void);

#endif /* LCD_UTIL_H_ */