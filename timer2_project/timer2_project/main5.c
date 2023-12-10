
/*
 * main5.c
 *
 * Created: 2023-12-10 오후 9:25:17
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
static uint16_t fnd_num_stop = 0;
volatile uint16_t asdf;
static uint8_t SW2_hit = 0;



ISR(INT7_vect)
{
	SW2_hit++;
	if (SW2_hit>=2 && !(SW2_hit%2))
	{
		fnd_num_stop = fnd_num;
	}
	if (SW2_hit>=3 && SW2_hit%2)
	{
		fnd_num = fnd_num_stop;
	}
	
}

ISR(INT3_vect)
{
	asdf = 0;
	fnd_num = 0;
}

ISR(TIMER5_COMPA_vect, ISR_NOBLOCK)
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
	
	
	uint16_t m_duration_real = 0;
	
	asdf=0;
	
	/* Replace with your application code */
	
	while(1)
	{
		
		if (SW2_hit%2)
		{
			if (!m_notes[asdf%m_notes_size])
			{
				sound_mute();
			}
			else
			{
				sound_set_frequency(m_notes[asdf%m_notes_size]);
			}
			
			m_duration_real = (m_duration[asdf%m_duration_size] * music_tempo);
			
			_delay_ms(m_duration_real);

			asdf++;
		}
		else
		{
			sound_mute();
		}
		if (SW2_hit>=2 && !(SW2_hit%2))
		{
			fnd_write_numbers(0);
		}
		
		
	}
}


void ioport_init(void)
{
	//DDRC의 하위 4bit을 출력하는 단자로 만든다.
	DDRC = _BV(LED1) | _BV(LED2) | _BV(LED3) | _BV(LED4);
	//MCU의 LED보드 4개의 불을 끈다.
	PORTC = 0xff;
	//MCU 보드의 SW2의 내부 pull-up저항을 활성화 한다.
	PORTE = _BV(SW2);
	//확장 보드의 SW3의 내부 pull-up저항을 활성화 한다.
	PORTD = _BV(SW3);
	
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