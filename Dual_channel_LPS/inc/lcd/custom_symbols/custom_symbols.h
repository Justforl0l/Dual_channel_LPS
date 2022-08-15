/*
 * custom_symbols.h
 *
 * Created: 15.08.2022 14:27:23
 *  Author: shama
 */ 


#ifndef CUSTOM_SYMBOLS_H_
#define CUSTOM_SYMBOLS_H_

#define CS_ADDRESS_A_WITH_DASH			0b00010000
#define CS_ADDRESS_V_WITH_DASH			0b00010001
#define CS_ADDRESS_DASH					0b00010010

static const unsigned char __attribute__((section(".rodata.CustomSymbol_A|"), used))
	cs_A_with_dash[8] = 
	{
		0b01001,
		0b10101,
		0b10101,
		0b10101,
		0b11101,
		0b10101,
		0b10101,
		0b00000,
	};
static const unsigned char __attribute__((section(".rodata.CustomSymbol_V|"), used))
	cs_V_with_dash[8] =
	{
		0b11001,
		0b10101,
		0b10101,
		0b11001,
		0b10101,
		0b10101,
		0b11001,
		0b00000,
	};
static const unsigned char __attribute__((section(".rodata.CustomSymbol_|"), used))
	cs_dash[8] =
	{
		0b00001,
		0b00001,
		0b00001,
		0b00001,
		0b00001,
		0b00001,
		0b00001,
		0b00000,
	};

#endif /* CUSTOM_SYMBOLS_H_ */