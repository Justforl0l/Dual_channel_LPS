/*
 * custom_symbols.h
 *
 * Created: 15.08.2022 14:27:23
 *  Author: shama
 */ 


#ifndef CUSTOM_SYMBOLS_H_
#define CUSTOM_SYMBOLS_H_

#define CS_ADDRESS_A_WITH_DASH			0b00000000
#define CS_ADDRESS_V_WITH_DASH			0b00000001
#define CS_ADDRESS_DASH					0b00000010
#define CS_ADDRESS_TWO_WITH_EQUAL		0b00000011

static const unsigned char __attribute__((section(".rodata.CystomSymbols"), used))
	custom_symbols[][8] =
	{
		{
			/* A| */
			0b01001,
			0b10101,
			0b10101,
			0b10101,
			0b11101,
			0b10101,
			0b10101,
			0b00000
		},
		{
			/* B| */
			0b11001,
			0b10101,
			0b10101,
			0b11001,
			0b10101,
			0b10101,
			0b11001,
			0b00000
		},
		{
			/* | */
			0b00001,
			0b00001,
			0b00001,
			0b00001,
			0b00001,
			0b00001,
			0b00001,
			0b00000
		},
		{
			/* 2= */
			0b01000,
			0b10100,
			0b00111,
			0b01000,
			0b10011,
			0b10000,
			0b11100,
			0b00000
		}
	};

#endif /* CUSTOM_SYMBOLS_H_ */