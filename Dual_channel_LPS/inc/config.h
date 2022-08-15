/*
 * config.h
 *
 * Created: 08.08.2022 9:30:18
 *  Author: shama
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

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

#define BUTTON_PIN							PB1
#define LOAD_TOGGLER						PB0

#endif /* CONFIG_H_ */