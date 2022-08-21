/*
 * util.c
 *
 * Created: 06.08.2022 13:21:07
 *  Author: shama
 */ 

#include "lcd/lcd_util.h"

void lcd_send_command(unsigned char command, unsigned char mode,
					  unsigned char check_busy_flag)
{
	LCD_PORT &= ~((1 << RS) | (1 << RW));
	_delay_us(1);
	
	/* Старший нибл */
	LCD_PORT |= (1 << EN);
	LCD_PORT &= 0x0F;
	LCD_PORT |= (command & 0xF0);
	_delay_us(1);
	LCD_PORT &= ~(1 << EN);
	_delay_us(1);
	
	if (mode == _4_BIT_MODE)
	{
		/* Младший нибл */
		LCD_PORT |= (1 << EN);
		LCD_PORT &= 0x0F;
		LCD_PORT |= (command << 4);
		_delay_us(1);
		LCD_PORT &= ~(1 << EN);
		_delay_us(1);
	}
	if (check_busy_flag)
	{
		while (lcd_is_busy());
	}
}

void lcd_send_data(unsigned char data)
{
	LCD_PORT &= ~(1 << RW);
	LCD_PORT |= (1 << RS);
	_delay_us(1);
	
	/* Старший нибл */
	LCD_PORT |= (1 << EN);
	LCD_PORT &= 0x0F;
	LCD_PORT |= (data & 0xF0);
	_delay_us(1);
	LCD_PORT &= ~(1 << EN);
	_delay_us(1);
	
	/* Младший нибл */
	LCD_PORT |= (1 << EN);
	LCD_PORT &= 0x0F;
	LCD_PORT |= (data << 4);
	_delay_us(1);
	LCD_PORT &= ~(1 << EN);
	_delay_us(1);
}

void lcd_display_string(unsigned char character_address, char *string)
{
	lcd_send_command((LCD_CMD_DISPLAY_ON_OFF_CTRL | LCD_SETTING_DISPLAY_ON),
					  _4_BIT_MODE, CHECK_BUSY_FLAG);
	lcd_send_command((LCD_CMD_SET_DDRAM_ADDRESS | character_address),
					  _4_BIT_MODE, CHECK_BUSY_FLAG);
	while (*string != '\0')
	{
		lcd_send_data(*string);
		string++;
	}
}

void lcd_display_screensaver_template(void)
{
	lcd_display_string((LCD_ADDRESS_1ST_LINE | LCD_ADDRESS_SIGN_1),
					    "U1=  .  U2=  . B");
	lcd_display_string((LCD_ADDRESS_2ND_LINE | LCD_ADDRESS_SIGN_1),
						"A1= .   A2= .  A");
	lcd_send_command((LCD_CMD_SET_DDRAM_ADDRESS | LCD_ADDRESS_1ST_LINE | LCD_ADDRESS_SIGN_8),
					  _4_BIT_MODE, CHECK_BUSY_FLAG);
	lcd_send_data(CS_ADDRESS_V_WITH_DASH);
	lcd_send_command((LCD_CMD_SET_DDRAM_ADDRESS | LCD_ADDRESS_2ND_LINE | LCD_ADDRESS_SIGN_8),
					  _4_BIT_MODE, CHECK_BUSY_FLAG);
	lcd_send_data(CS_ADDRESS_A_WITH_DASH);
}

void lcd_clear_voltage_values(Channel* channelX)
{
	unsigned int sign_offset = 0;
	
	if (channelX->id == 2)
	{
		sign_offset = 8;
	}
	
	lcd_display_string((LCD_ADDRESS_1ST_LINE | (LCD_ADDRESS_SIGN_4 + sign_offset)), "  . ");
}

void lcd_clear_current_values(Channel* channelX)
{
	unsigned int sign_offset = 0;
	
	if (channelX->id == 2)
	{
		sign_offset = 8;
	}
	
	lcd_display_string((LCD_ADDRESS_2ND_LINE | (LCD_ADDRESS_SIGN_4 + sign_offset)), " .   ");
}

bool lcd_is_busy(void)
{
	unsigned char busy_flag = 0;
	LCD_PORT &= ~(1 << RS);
	LCD_PORT |= (1 << RW);
	_delay_us(1);
	LCD_PORT |= (1 << EN);
	_delay_us(1);
	LCD_PORT &= ~(1 << EN);
	busy_flag = (LCD_PORT >> 7);
	_delay_us(1);
	LCD_PORT |= (1 << EN);
	_delay_us(1);
	LCD_PORT &= ~(1 << EN);
	_delay_us(1);
	
	return busy_flag;
}
