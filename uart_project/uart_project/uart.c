/*
 * 1010.c
 *
 * Created: 2023-11-22 오후 7:43:26
 * Author : dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include <avr/interrupt.h>


void uart_init(void);
int8_t uart_getch(void);
void uart_putch(int8_t ch);
void uart_puts(int8_t *str);
void num2ascii(int8_t ch);

void uart_init(void)
{
	#define BAUDRATE 115200L
	
	//UBRR0 값 설정
	UBRR0 = (F_CPU/(8*BAUDRATE))-0.5;
	//U2X0를 1로 설정
	UCSR0A |= _BV(U2X0);
	//인터럽트를 활성화
	UCSR0B |= _BV(RXCIE0);
	// 송신과 수신 모두 enable
	UCSR0B |= _BV(RXEN0) | _BV(TXEN0);
	// 송수신 데이터는 각각 8 비트, stop 비트는 1 비트, no parity
	UCSR0C |= _BV(UCSZ01) | _BV(UCSZ00);
	sei();
}

int8_t uart_getch(void)
{
	while(!(UCSR0A & (1<<RXC0))) ;
	return UDR0;
}
void uart_putch(int8_t ch)
{
	while(!(UCSR0A & (1<<UDRE0))) ;
	UDR0 = ch;
}

void uart_puts(int8_t *str)
{
	while(!(*str == '\0'))
	uart_putch(*str++);
}

void num2ascii(int8_t ch)
{
	int8_t tmp;

	tmp = (ch>>4) & 0x0f; // 상위 4 비트
	if(tmp >= 0 && tmp <= 9)
	{
		uart_putch(tmp + '0'); // 상위 4 비트가 0~9 사이의값이라면 
	}
	else
	{
		uart_putch(tmp -10 + 'A'); // 상위 4 비트가 A~F 사이의값이라면 
	}
	tmp = ch & 0x0f; // 하위 4 비트
	if(tmp >= 0 && tmp <= 9)
	{
		uart_putch(tmp + '0'); // 하위 4 비트가 0~9 사이의값이라면 
	}
	else
	{
		uart_putch(tmp - 10 + 'A'); // 하위 4 비트가 A~F 사이의값이라면
	}
}

