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

#include "config.h"
#include "channel_struct.h"
#include "lcd/lcd_commands.h"
#include "lcd/lcd_settings.h"
#include "lcd/custom_symbols/custom_symbols.h"

#include <util/delay.h>

#define _8_BIT_MODE						1
#define _4_BIT_MODE						0
#define CHECK_BUSY_FLAG					1
#define DONT_CHECK_BUSY_FLAG			0

void lcd_send_command(unsigned char command, unsigned char mode,
					  unsigned char check_busy_flag);
void lcd_send_data(unsigned char data);
void lcd_display_string(unsigned char character_address, char *string);
void lcd_display_screensaver_template(void);
void lcd_clear_voltage_values(Channel* channelX);
void lcd_clear_current_values(Channel* channelX);
bool lcd_is_busy(void);

#endif /* LCD_UTIL_H_ */