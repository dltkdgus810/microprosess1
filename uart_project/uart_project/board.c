/*
 * board.c
 *
 * Created: 2023-11-15 오후 7:29:41
 *  Author: dltkd
 */ 

#define F_CPU 16000000L
#include <avr/io.h>

// PORTC
#define LED1 PC0
#define LED2 PC1
#define LED3 PC2
#define LED4 PC3
// PORTB
#define LED_COLOR PB4
// PORTD
#define SW3 PD3
#define SW4 PD4
#define SW5 PD5
// PORTE
#define SW2 PE7
#define SOUND_OUT PE3

void prescaler_set1(uint8_t num);
void prescaler_set2(uint8_t num);
void prescaler_set3(uint8_t num);
void prescaler_set4(uint8_t num);
void prescaler_set5(uint8_t num);

void prescaler_set1(uint8_t num)
{
	if (num==1)
	{
		TCCR1B |= _BV(CS10);
	}
	else if (num==8)
	{
		TCCR1B |= _BV(CS11);
	}
	else if (num==64)
	{
		TCCR1B |= _BV(CS11) | _BV(CS10);
	}
	else if (num==256)
	{
		TCCR1B |= _BV(CS12);
	}
	else if (num==1024)
	{
		TCCR1B |= _BV(CS12) | _BV(CS10);
	}
}

void prescaler_set2(uint8_t num)
{
	if (num==1)
	{
		TCCR2B |= _BV(CS20);
	}
	else if (num==8)
	{
		TCCR2B |= _BV(CS21);
	}
	else if (num==64)
	{
		TCCR2B |= _BV(CS21) | _BV(CS20);
	}
	else if (num==256)
	{
		TCCR2B |= _BV(CS22);
	}
	else if (num==1024)
	{
		TCCR2B |= _BV(CS22) | _BV(CS20);
	}
}

void prescaler_set3(uint8_t num)
{
	if (num==1)
	{
		TCCR3B |= _BV(CS30);
	}
	else if (num==8)
	{
		TCCR3B |= _BV(CS31);
	}
	else if (num==64)
	{
		TCCR3B |= _BV(CS31) | _BV(CS30);
	}
	else if (num==256)
	{
		TCCR3B |= _BV(CS32);
	}
	else if (num==1024)
	{
		TCCR3B |= _BV(CS32) | _BV(CS30);
	}
}

void prescaler_set4(uint8_t num)
{
	if (num==1)
	{
		TCCR4B |= _BV(CS40);
	}
	else if (num==8)
	{
		TCCR4B |= _BV(CS41);
	}
	else if (num==64)
	{
		TCCR4B |= _BV(CS41) | _BV(CS40);
	}
	else if (num==256)
	{
		TCCR4B |= _BV(CS42);
	}
	else if (num==1024)
	{
		TCCR4B |= _BV(CS42) | _BV(CS40);
	}
}

void prescaler_set5(uint8_t num)
{
	if (num==1)
	{
		TCCR5B |= _BV(CS50);
	}
	else if (num==8)
	{
		TCCR5B |= _BV(CS51);
	}
	else if (num==64)
	{
		TCCR5B |= _BV(CS51) | _BV(CS50);
	}
	else if (num==256)
	{
		TCCR5B |= _BV(CS52);
	}
	else if (num==1024)
	{
		TCCR5B |= _BV(CS52) | _BV(CS50);
	}
}
