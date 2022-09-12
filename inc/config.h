/*
 * config.h
 *
 * Created: 08.08.2022 9:30:18
 *  Author: shama
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

/* Параметры микроконтроллера */
#define F_CPU								1000000UL
#define TIMER_PRESCALER						((0 << CS02) | (1 << CS01) | (0 << CS00))
#define TIMER_COUNTER_VALUE					(255 - (125 - 1))

/* Параметры схемы */
#define VOLTAGE_DIVIDER_RATIO				10
#define ADC_VOLTAGE_REFERENCE				5000		// Величина опорного напряжения АЦП (в мВ)

/* ID каналов ЛБП */
#define LPS_POSITIVE_VOLTAGE_CHANNEL		1
#define LPS_NEGATIVE_VOLTAGE_CHANNEL		2

/* Управляющие выводы LCD дисплея */
#define RS									PD0
#define RW									PD1
#define EN									PD2
#define LCD_PORT							PORTD
#define LCD_DDR								DDRD

#define BUTTON_PORT							DDRB
#define LOAD_TOGGLER_PORT					DDRB
#define BUTTON_PIN							PB1
#define LOAD_TOGGLER_PIN					PB0

/* Настройки кнопки */
#define BUTTON_DEBOUNCE_TIME				60			// Время нажатия кнопки (в мс)

#endif /* CONFIG_H_ */