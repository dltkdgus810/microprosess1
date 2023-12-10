
/*
 * main2.c
 *
 * Created: 2023-11-30 오후 6:13:46
 *  Author: dltkd
 */ /*
 * 1111.c
 *
 * Created: 2023-11-29 오후 9:03:24
 * Author : dltkd
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "board.h"
#include <util/delay.h>
#include "uart.h"
#include "fnd.h"

void adc_init(void);
uint16_t adc_get_result(uint8_t channel_num);
void ioport_init(void);

int main(void)
{
	adc_init();
	ioport_init();
	fnd_init();
	uart_init();
	fdevopen(uart_putch, uart_getch);
	
    /* Replace with your application code */
    while (1) 
    {
		if (!(PIND&_BV(SW3)))
		{
			printf("%d",adc_get_result(3));
		}
    }
}

void adc_init(void)
{
	//ADC enable
	ADCSRA |= _BV(ADEN);
	//AD 변환 범위는 0 ~ AVCC가 되도록설정
	ADMUX |= _BV(REFS0);
	//ADC interrupt enable
	//ADCSRA |= _BV(ADIE);
	//ADC 50kHz ~ 200kHz 사이의 갑을 가지도록 prescaler 설정
	ADCSRA |= _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
}

uint16_t adc_get_result(uint8_t channel_num)
{
	//MUX 입력을 제외한 다른 비트의 값을 보호하기 위한 설정
	ADMUX = 0xf0 & ADMUX;
	//MUX에 입력 값 넣기
	ADMUX |= 0x0f & channel_num;
	//AD 변환 시작
	ADCSRA |= _BV(ADSC);
	//AD 변환 끝날 때 까지 기다린다.
	while(ADCSRA & _BV(ADSC)){}
	//끝나면 변환 값을 반환
	return ADCL;
} 

void ioport_init(void)
{
	PORTD |= _BV(PD3);
}


