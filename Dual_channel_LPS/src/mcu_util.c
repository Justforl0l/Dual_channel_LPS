/*
 * mcu_util.c
 *
 * Created: 06.08.2022 14:42:41
 *  Author: shama
 */ 

#include "mcu_util.h"

void voltage_calculation(Channel* channelX)
{
	channelX->voltage_value = ((channelX->voltage_buffer * ADC_VOLTAGE_REFERENCE * VOLTAGE_DIVIDER_RATIO) / 1024) /
								channelX->voltage_counter;
	channelX->voltage_counter = 0;
	channelX->voltage_buffer = 0;
}

void voltage_display(Channel* channelX)
{
	lcd_clear_voltage_values(channelX);
	unsigned int sign_offset = 0;
	
	if (channelX->id == 2)
	{
		sign_offset = 8;
	}
	
	lcd_send_command((LCD_CMD_SET_DDRAM_ADDRESS | LCD_ADDRESS_1ST_LINE | (LCD_ADDRESS_SIGN_4 + sign_offset)),
					  _4_BIT_MODE, CHECK_BUSY_FLAG);
	lcd_send_data((channelX->voltage_value / 1000) % 10);
	lcd_send_data((channelX->voltage_value / 100) % 10);
	lcd_send_command((LCD_CMD_SET_DDRAM_ADDRESS | LCD_ADDRESS_1ST_LINE | (LCD_ADDRESS_SIGN_7 + sign_offset)),
					  _4_BIT_MODE, CHECK_BUSY_FLAG);
	lcd_send_data((channelX->voltage_value / 10) % 10);
}

void current_calculation(Channel* channelX)
{
	channelX->current_value = ((channelX->current_buffer * ADC_VOLTAGE_REFERENCE) / 1024) /
								channelX->current_counter;
	channelX->current_counter = 0;
	channelX->current_buffer = 0;
}

void current_display(Channel* channelX)
{
	lcd_clear_current_values(channelX);
	unsigned int sign_offset = 0;
	
	if (channelX->id == 2)
	{
		sign_offset = 8;
	}
	
	lcd_send_command((LCD_CMD_SET_DDRAM_ADDRESS | LCD_ADDRESS_2ND_LINE | (LCD_ADDRESS_SIGN_4 + sign_offset)),
					  _4_BIT_MODE, CHECK_BUSY_FLAG);
	lcd_send_data((channelX->current_value / 1000) % 10);
	lcd_send_command((LCD_CMD_SET_DDRAM_ADDRESS | LCD_ADDRESS_2ND_LINE | (LCD_ADDRESS_SIGN_7 + sign_offset)),
					  _4_BIT_MODE, CHECK_BUSY_FLAG);
	lcd_send_data((channelX->current_value / 100) % 10);
	lcd_send_data((channelX->current_value / 10) % 10);
}

void toggle_output_load(void)
{
	DDRB ^= (1 << LOAD_TOGGLER);
}
