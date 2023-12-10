
/*
 * main5.c
 *
 * Created: 2023-12-10 오후 9:14:59
 *  Author: dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include <util/delay.h>
#include "fnd.h"
#include <avr/interrupt.h>

static uint16_t fnd_num = 0;

void ioport_init(void);
void interrupt_init(void);
void timer_init(void);

ISR(TIMER5_OVF_vect)
{
	TCNT5 = 0xF63B;
	PORTB ^= _BV(PB5);   // PB5 반전
}

int main(void)
{
	ioport_init();
	timer_init();
	interrupt_init();
	fnd_init();
	
	
	
	
	/* Replace with your application code */
	while (1)
	{

	}
}

void ioport_init(void)
{
	
	DDRE = _BV(SOUND_OUT);
	DDRB = _BV(PB5);
	
}

void interrupt_init(void)
{
	
	sei();
}

void timer_init(void)
{
	// 16-bit 타이머인 Timer3을 CTC 모드로 동작하도록 설정하고, prescaler는 8로설정한다.
	TCCR3B = _BV(WGM32) | _BV(CS31);
	TCCR3A = _BV(COM3A0);
	//정확하게 250 개의 타이머 입력 clock 마다 compare match가 발생하도록 OCR3A 레지스터의 값을 설정한다.
	OCR3A = 249;
	
	// 16-bit 타이머인 Timer5를 Normal 모드로 동작하도록 설정하고 prescaler를 64로설정한다.
	TCCR5B = _BV(CS51) | _BV(CS50);
	TCNT5 = 0xF63B;;
