/*
 * main.h
 *
 * Created: 04.08.2022 20:25:44
 *  Author: shama
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include <avr/io.h>

#include "init.h"
#include "lcd/lcd_util.h"
#include "button/button_util.h"
#include "mcu_util.h"

volatile unsigned char voltage_chA_counter = 0;
volatile unsigned char current_chA_counter = 0;
unsigned int voltage_chA_value = 0;
unsigned int current_chA_value = 0;

#endif /* MAIN_H_ */