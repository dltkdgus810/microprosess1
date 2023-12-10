
/*
 * main3.c
 *
 * Created: 2023-12-10 오후 8:42:08
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


int main(void)
{
	/* Replace with your application code */
	//변수 초기화 및 설정값 초기화
	DDRC = _BV(LED1) | _BV(LED2) | _BV(LED3) | _BV(LED4);
	PORTE = _BV(SW2);
	PORTC |= _BV(LED3) | _BV(LED4);
	
	uint8_t i = 0;
	uint8_t led_pattern[4] = {0x0c, 0x09, 0x03, 0x06};
	
	while (1)
	{
		//500ms만큼의 시간이 지날 때마다 PORTC에 다른 패턴의 값이 들어가게 한다.
		_delay_ms(500);
		PORTC = (PORTC & 0xf0) | led_pattern[i++%4];
	}
}
