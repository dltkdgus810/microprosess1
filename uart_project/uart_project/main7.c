
/*
 * main7.c
 *
 * Created: 2023-12-10 오후 9:38:04
 *  Author: dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include "uart.h"
#include <stdio.h>
#include <avr/interrupt.h>

ISR(USART0_RX_vect)
{
	UDR0 = UDR0;
}

int main(void)
{
	uart_init();
	fdevopen(uart_putch, uart_getch);
	
	/* Replace with your application code */
	while (1)
	{
		
		
	}
}

