/*
 * config.h
 *
 * Created: 08.08.2022 9:30:18
 *  Author: shama
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

/* ��������� ���������������� */
#define F_CPU								1000000UL
#define TIMER_PRESCALER						((0 << CS02) | (1 << CS01) | (0 << CS00))
#define TIMER_COUNTER_VALUE					(255 - (125 - 1))

/* ��������� ����� */
#define VOLTAGE_DIVIDER_RATIO				10
#define ADC_VOLTAGE_REFERENCE				5000		// �������� �������� ���������� ��� (� ��)

/* ID ������� ��� */
#define LPS_POSITIVE_VOLTAGE_CHANNEL		1
#define LPS_NEGATIVE_VOLTAGE_CHANNEL		2

/* ����������� ������ LCD ������� */
#define RS									PD0
#define RW									PD1
#define EN									PD2
#define LCD_PORT							PORTD
#define LCD_DDR								DDRD

#define BUTTON_PORT							DDRB
#define LOAD_TOGGLER_PORT					DDRB
#define BUTTON_PIN							PB1
#define LOAD_TOGGLER_PIN					PB0

/* ��������� ������ */
#define BUTTON_DEBOUNCE_TIME				60			// ����� ������� ������ (� ��)

#endif /* CONFIG_H_ */