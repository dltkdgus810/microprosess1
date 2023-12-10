
/*
 * main3.c
 *
 * Created: 2023-12-10 오후 9:03:46
 *  Author: dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include <util/delay.h>
#include "fnd.h"
#include <avr/interrupt.h>

static uint16_t fnd_num = 0;

ISR(INT3_vect)
{
	fnd_num++;

	if (fnd_num>999)
	{
		fnd_num = 0;
	}
	fnd_write_numbers(fnd_num);
}

ISR(INT7_vect)
{
	//fnd_num--;

	/*if (fnd_num==65535)
	{
		fnd_num = 999;
	}*/
	fnd_write_numbers(fnd_num);
}

void ioport_init(void);
void interrupt_init(void);

int main(void)
{
	ioport_init();
	interrupt_init();
	fnd_init();
	
	fnd_write_numbers(fnd_num);
	
	uint8_t i = 0;
	uint8_t led_pattern[] = {0x81, 0xC3, 0xE7, 0xFF, 0x7E, 0x3C, 0x18, 0x00 };
	/* Replace with your application code */
	while (1)
	{
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
	//하강일 때 INT3가 발생하게한다.
	EICRA = _BV(ISC31);
	//INT3, INT7을 활성화한다.
	EIMSK = _BV(INT7) | _BV(INT3);
	// global interrupt flag을 set시킨다.
	sei();
}
