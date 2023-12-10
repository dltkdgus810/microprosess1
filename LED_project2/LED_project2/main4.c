
/*
 * main4.c
 *
 * Created: 2023-12-10 오후 8:46:59
 *  Author: dltkd
 */ 

#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>

#define LED1 PC0
#define LED2 PC1
#define LED3 PC2
#define LED4 PC3
#define SW2 PE7

uint8_t switch_hit(void);

int main(void)
{
	/* Replace with your application code */
	//변수를 초기화하고, 설정값들을 초기화한다.
	DDRC = _BV(LED1) | _BV(LED2) | _BV(LED3) | _BV(LED4);
	PORTE = _BV(SW2);
	PORTC |= _BV(LED3) | _BV(LED4);
	
	uint8_t i = 0;
	uint8_t a = 0;
	uint8_t led_pattern[4] = {0x0c, 0x09, 0x03, 0x06};
	
	while (1)
	{
		//스위치를 눌렀을 때 몇번 눌렀는지 감지한다.
		a = a + switch_hit();
		
		if(a%2)//스위치를 짝수번을 누르면 정방향 패턴을 진행하고, 홀수번이면 반대방향을 진행한다.
		{
			_delay_ms(100);
			PORTC = (PORTC & 0xf0) | led_pattern[i--%4];
		}
		else
		{
			_delay_ms(100);
			PORTC = (PORTC & 0xf0) | led_pattern[i++%4];
		}
	}
}

//스위치를 눌렀다가 땠을 때에만 1의 값이 출력하게 된다.
uint8_t switch_hit(void)
{
	static uint8_t prev_state = _BV(SW2);
	uint8_t cur_state;
	
	cur_state = PINE & _BV(SW2);
	if(prev_state != cur_state)
	{
		prev_state = cur_state;
		if(cur_state) return 1;
		else return 0;
	}
	else
	return 0;
}