/*
 * lcd_commands.h
 *
 * Created: 07.08.2022 16:00:59
 *  Author: shama
 */ 


#ifndef LCD_COMMANDS_H_
#define LCD_COMMANDS_H_

#define LCD_CMD_CLEAR_DISPLAY				0x01
#define LCD_CMD_RETURN_HOME					0x02
#define LCD_CMD_ENTRY_MODE_SET				0x04
#define LCD_CMD_DISPLAY_ON_OFF_CTRL			0x08
#define LCD_CMD_CURSOR_OR_DISPLAY_SHIFT		0x10
#define LCD_CMD_FUNCTION_SET				0x20
#define LCD_CMD_SET_CGRAM_ADDRESS			0x40
#define LCD_CMD_SET_DDRAM_ADDRESS			0x80

#endif /* LCD_COMMANDS_H_ */