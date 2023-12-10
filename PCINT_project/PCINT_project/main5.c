﻿
/*
 * main5.c
 *
 * Created: 2023-12-10 오후 9:08:50
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

ISR(PCINT0_vect)
{
	static uint8_t a = _BV(PINB5);
	static uint8_t b = _BV(PINB6);
	
	uint8_t aa = PINB & _BV(PINB5);
	uint8_t bb = PINB & _BV(PINB6);
	
	if (a != aa)
	{
		a = aa;
		if (!aa)
		{
			fnd_num++;
			
			if(fnd_num == 1000)
			{
				fnd_num = 0;
			}
		}
	}
	else if (b != bb)
	{
		b = bb;
		if (!bb)
		{
			fnd_num--;
			
			if(fnd_num == 65535)
			{
				fnd_num = 999;
			}
		}
		
	}
	fnd_write_numbers(fnd_num);
	
}


int main(void)
{
	ioport_init();
	interrupt_init();
	fnd_init();
	
	//fnd를 0으로 초기화 한다.
	fnd_write_numbers(fnd_num);
	uint16_t i = 0;
	//확장보드 LED패턴
	uint8_t led_pattern[8] = {0x81, 0xC3, 0xE7, 0xFF, 0x7E, 0x3C, 0x18, 0x00};
	
	/* Replace with your application code */
	while (1)
	{
		//미리 만들어둔 확장보드 LED패턴으로 작동된다.
		led_write(led_pattern[i++%8]);
		_delay_ms(250);
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
	//확장 보드의 SW3,4,5의 내부 pull-up저항을 활성화 한다.
	PORTD |= _BV(SW3) | _BV(SW4) |_BV(SW5);

}

void interrupt_init(void)
{
	// PCINT5와 PCINT6을 PCINT 입력으로 사용하도록 PCMSK0 레지스터를 설정한다.
	PCMSK0 = _BV(PCINT5) | _BV(PCINT6);
	// PCINT5와 PCINT6을 사용한 PCINT를 enable시키도록 PCICR 레지스터를 설정한다.
	PCICR = _BV(PCIE0);
	sei();
}