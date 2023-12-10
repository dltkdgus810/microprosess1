
/*
 * main6.c
 *
 * Created: 2023-12-10 오후 8:53:36
 *  Author: dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include <util/delay.h>
#include "fnd.h"

uint8_t switch_hit(void);
uint8_t switch_hit2(void);
void ioport_init(void);

int main(void)
{
	// initialize on-chip pheriperals
	ioport_init(); // initialize gpio

	// initialize extension board pheriperals
	fnd_init(); // initialize FNDs and LEDs
	
	//7-segment LED옆의 작은 LED의 불을 다 킨다.
	led_write(255);
	
	uint16_t i = 0;
	uint8_t a = 1;
	while(1)
	{
		//sw2 스위치를 눌렀는지 확인한다.
		a += switch_hit();
		//sw3 스위치를 눌렀으면 0으로 초기화하고, 확장 보드의 LED 색을 조정한다.
		if (switch_hit2()==1)
		{
			i=0;
			PORTB ^= _BV(LED_COLOR);
		}
		//sw3 스위치를 홀수번 누르면 노랑, 짝수번 누르면 빨강
		
		
		if (a%2)
		{
			//0.1초의 딜레이 추가
			_delay_ms(100);
			//i의 값에 따라 7-segment LED를 조정한다.
			fnd_write_numbers(i);
			i++;
			//i가 999가 되면 0으로 초기화
			if (i==999)
			{
				i = 0;
			}
			//sw2 스위치를 눌러 작동할 때 확장 보드의 LED를 킨다.
			led_write(255);
		}
		//sw2 스위치를 눌러 멈췄을 때 확장 보드의 LED를 끈다.
		else
		{
			led_write(0);
		}
	}
}

//스위치를 눌렀을 때에만 SW2포트에 1의 값이 출력하게 된다.
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

//스위치를 눌렀을 때에만 SW3포트에 1의 값이 출력하게 된다.
uint8_t switch_hit2(void)
{
	static uint8_t prev_state2 = _BV(SW3);
	uint8_t cur_state2;
	
	cur_state2 = PIND & _BV(SW3);
	if(prev_state2 != cur_state2)
	{
		prev_state2 = cur_state2;
		if(!cur_state2) return 1;
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
	PORTC = 0xff;
	//MCU 보드의 SW2의 내부 pull-up저항을 활성화 한다.
	PORTE = _BV(SW2);
	//확장 보드의 SW3,4,5의 내부 pull-up저항을 활성화 한다.
	PORTD |= _BV(SW3) | _BV(SW4) |_BV(SW5);

}