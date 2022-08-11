/*
 * lcd_settings.h
 *
 * Created: 07.08.2022 16:13:17
 *  Author: shama
 */ 


#ifndef LCD_SETTINGS_H_
#define LCD_SETTINGS_H_

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

#endif /* LCD_SETTINGS_H_ */