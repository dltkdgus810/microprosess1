/*
 * sound.c
 *
 * Created: 2023-11-04 오후 4:49:03
 *  Author: dltkd
 */ 
#include "board.h"
#include <avr/io.h>
#include <util/delay.h>
#include "fnd.h"
#include <avr/interrupt.h>

void sound_set_frequency(uint16_t freq_hz);
void sound_mute(void);


void sound_set_frequency(uint16_t freq_hz)
{
	//OCR3A 값 설정
	OCR3A = (F_CPU/(2*8*freq_hz))-1;
	//Timer3의 prescaler 설정
	TCCR3B |= _BV(CS31);
}

void sound_mute(void)
{
	TCCR3B &= ~(_BV(CS32)| _BV(CS31) | _BV(CS30));
	if(PINE & _BV(SOUND_OUT))
	{
		TCCR3C = _BV(FOC3A);	
	}
}