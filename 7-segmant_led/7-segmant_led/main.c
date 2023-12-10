/*
 * 7-segmant_led.c
 *
 * Created: 2023-12-10 오후 8:50:45
 * Author : dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include <util/delay.h>
#include "fnd.h"

uint8_t switch_hit(void);
void ioport_init(void);

int main(void)
{
	// initialize on-chip pheriperals
	ioport_init(); // initialize gpio

	// initialize extension board pheriperals
	fnd_init(); // initialize FNDs and LEDs
	
	//7-segment LED옆의 작은 LED의 불을 다 킨다.
	led_write(255);
	

	
	
	while(1)
	{
		
	}
}

//스위치를 눌렀을 때에만 1의 값이 출력하게 된다.
uint8_t switch_hit(void)
{
	static uint8_t prev_state = _BV(SW2);
	uint8_t cur_state;
	
	cur_state = PINE & _BV(SW2);
	if(prev_state != cur_state)
	{
		prev_state = cur_state;
		if(!cur_state) return 1;
		else return 0;
	}
	else
	return 0;
}

void ioport_init(void)
{
	
	//DDRC의 하위 4bit을 출력하는 단자로 만든다.
	DDRC = _BV(LED1) | _BV(LED2) | _BV(LED3) | _BV(LED4);
	//MCU의 LED보드 4개의 불을 끈다.
	PORTC = 0x00;
	//MCU 보드의 SW2의 내부 pull-up저항을 활성화 한다.
	PORTE = _BV(SW2);
	//확장 보드의 SW3,4,5의 내부 pull-up저항을 활성화 한다.
	PORTD |= _BV(SW3) | _BV(SW4) |_BV(SW5);


}
