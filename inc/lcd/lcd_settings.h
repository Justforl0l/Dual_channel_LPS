/*
 * lcd_settings.h
 *
 * Created: 07.08.2022 16:13:17
 *  Author: shama
 */ 


#ifndef LCD_SETTINGS_H_
#define LCD_SETTINGS_H_

/* Параметры команд дисплея */
#define LCD_SETTING_INCREMENT				(1 << 1)
#define LCD_SETTING_DECREMENT				(0 << 1)
#define LCD_SETTING_SHIFT					 0
#define LCD_SETTING_DISPLAY_ON				(1 << 2)
#define LCD_SETTING_DISPLAY_OFF				(0 << 2)
#define LCD_SETTING_CURSOR_ON				(1 << 1)
#define LCD_SETTING_CURSOR_OFF				(0 << 1)
#define LCD_SETTING_BLINKING_CURSOR			 1
#define LCD_SETTING_NORMAL_CURSOR			 0
#define LCD_SETTING_DISPLAY_SHIFT			(1 << 3)
#define LCD_SETTING_CURSOR_MOVE				(0 << 3)
#define LCD_SETTING_SHIFT_TO_THE_RIGHT		(1 << 2)
#define LCD_SETTING_SHIFT_TO_THE_LEFT		(0 << 2)
#define LCD_SETTING_DATA_LENGTH_8_BIT		(1 << 4)
#define LCD_SETTING_DATA_LENGTH_4_BIT		(0 << 4)
#define LCD_SETTING_2_LINES_DISPLAY			(1 << 3)
#define LCD_SETTING_1_LINE_DISPLAY			(0 << 3)
#define LCD_SETTING_FONT_5x10_DOTS			(1 << 2)
#define LCD_SETTING_FONT_5x8_DOTS			(0 << 2)

/* Адреса знакомест дисплея */
#define LCD_ADDRESS_1ST_LINE				 0x00
#define LCD_ADDRESS_2ND_LINE				 0x40

#define LCD_ADDRESS_SIGN_1					 0x00
#define LCD_ADDRESS_SIGN_2					 0x01
#define LCD_ADDRESS_SIGN_3					 0x02
#define LCD_ADDRESS_SIGN_4					 0x03
#define LCD_ADDRESS_SIGN_5					 0x04
#define LCD_ADDRESS_SIGN_6					 0x05
#define LCD_ADDRESS_SIGN_7					 0x06
#define LCD_ADDRESS_SIGN_8					 0x07
#define LCD_ADDRESS_SIGN_9					 0x08
#define LCD_ADDRESS_SIGN_10					 0x09
#define LCD_ADDRESS_SIGN_11					 0x0A
#define LCD_ADDRESS_SIGN_12					 0x0B
#define LCD_ADDRESS_SIGN_13					 0x0C
#define LCD_ADDRESS_SIGN_14					 0x0D
#define LCD_ADDRESS_SIGN_15					 0x0E
#define LCD_ADDRESS_SIGN_16					 0x0F

#endif /* LCD_SETTINGS_H_ */