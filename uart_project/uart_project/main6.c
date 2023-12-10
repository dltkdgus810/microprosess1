
/*
 * main6.c
 *
 * Created: 2023-12-10 오후 9:37:49
 *  Author: dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include "uart.h"
#include <stdio.h>


int main(void)
{
	uart_init();
	fdevopen(uart_putch, uart_getch);
	
	int8_t ch=0;
	
	/* Replace with your application code */
	while (1)
	{
		ch = uart_getch();
		
		if (ch == 13)
		{
			printf(">> UCSR0B: 0x%x\n",UCSR0B);
		}
		
		uart_putch(ch);
		
	}
}