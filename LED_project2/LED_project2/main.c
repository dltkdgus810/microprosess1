/*
 * LED_project2.c
 *
 * Created: 2023-12-10 오후 8:41:14
 * Author : dltkd
 */ 

#include <avr/io.h>

#define LED1 PC0
#define LED2 PC1
#define LED3 PC2
#define LED4 PC3
#define SW2 PE7

uint8_t switch_hit(void);

int main(void)
{
	/* Replace with your application code */
	
	//변수와 초기값을 설정한다.
	DDRC = _BV(LED1) | _BV(LED2) | _BV(LED3) | _BV(LED4);
	PORTE = _BV(SW2);
	PORTC |= _BV(LED2) | _BV(LED3);
	uint8_t i = 0;
	uint8_t led_pattern[2] = {0x06, 0x09};
	
	while (1)
	{
		//스위치를 누르면 값이 다른 패턴이 나오게 한다.
		if(switch_hit())
		{
			PORTC = (PORTC & 0xf0) | led_pattern[i++%2];
		}
	}
}

//스위치를 눌렀을 때에만 1이라는 값을 쓰게 한다.
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
