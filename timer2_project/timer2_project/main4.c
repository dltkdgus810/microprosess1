﻿
/*
 * main4.c
 *
 * Created: 2023-12-10 오후 9:25:03
 *  Author: dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include "fnd.h"
#include <avr/interrupt.h>
#include "sound.h"
#include "music_data.h"

void ioport_init(void);
void timer_init(void);
void interrupt_init(void);

static uint16_t fnd_num = 0;

ISR(TIMER5_COMPA_vect)
{
	fnd_num++;
	if(fnd_num == 1000)
	{
		fnd_num = 0;
	}
	fnd_write_numbers(fnd_num);
}

int main(void)
{
	ioport_init();
	timer_init();
	interrupt_init();
	fnd_init();
	
	fnd_write_numbers(fnd_num);
	
	uint16_t m_notes_size = sizeof(m_notes) / sizeof(uint16_t);
	uint16_t m_duration_size = sizeof(m_duration) / sizeof(uint8_t);
	
	uint8_t i = 0;
	uint16_t m_duration_real = 0;
	
	/* Replace with your application code */
	while (1)
	{
		if (!m_notes[i%m_notes_size])
		{
			sound_mute();
		}
		else
		{
			sound_set_frequency(m_notes[i%m_notes_size]);
		}
		
		m_duration_real = (m_duration[i%m_duration_size] * music_tempo);
		
		_delay_ms(m_duration_real);

		i++;
		
	}
}

void ioport_init(void)
{
	//DDRC의 하위 4bit을 출력하는 단자로 만든다.
	DDRC = _BV(LED1) | _BV(LED2) | _BV(LED3) | _BV(LED4);
	//MCU의 LED보드 4개의 불을 끈다.
	PORTC = 0xff;
	DDRE = _BV(SOUND_OUT);
	DDRB = _BV(PB4);
}
void interrupt_init(void)
{
	// 하강 모서리 (falling edge)에서 INT3이발생하도록 EICRA를설정한다.
	EICRA = _BV(ISC31);
	// 하강 모서리 (falling edge)에서 INT7이발생하도록 EICRB를설정한다.
	EICRB = _BV(ISC71);
	// INT3과 INT7을 enable시킨다.
	EIMSK = _BV(INT7) | _BV(INT3);
	// global interrupt flag을 set시킨다.
	sei();
}
void timer_init(void)
{
	// Timer3을 CTC 모드로 설정
	TCCR3B = _BV(WGM32);
	//compare match가 발생할 때마다 OC3A 핀을 toggle시키도록 설정한다.
	TCCR3A = _BV(COM3A0);
	// Timer5을 CTC 모드로 설정
	TCCR5B = _BV(WGM52) | _BV(CS50) | _BV(CS51);
	//0.1 초 간격으로 compare match interrupt가 발생하도록 설정한다.
	OCR5A = (F_CPU/(64*10))-1;
	//timer5번의 compare match interrupt enable.
	TIMSK5 = _BV(OCIE5A);
}