/*
 * PCINT_project.c
 *
 * Created: 2023-12-10 오후 9:07:30
 * Author : dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include <util/delay.h>
#include "fnd.h"
#include <avr/interrupt.h>

static uint16_t fnd_num = 0;

void ioport_init(void);
void interrupt_init(void);

int main(void)
{
	ioport_init();
	interrupt_init();
	fnd_init();
	
	/* Replace with your application code */
	while (1)
	{
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