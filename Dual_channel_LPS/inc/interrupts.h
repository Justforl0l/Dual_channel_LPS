/*
 * interrupts.h
 *
 * Created: 06.08.2022 17:54:12
 *  Author: shama
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "channel_struct.h"

extern Channel channel_a, channel_b;
extern unsigned long TIMER_TICK;

#endif /* INTERRUPTS_H_ */