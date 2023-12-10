
/*
 * main5.c
 *
 * Created: 2023-12-10 오후 9:37:31
 *  Author: dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include "uart.h"



int main(void)
{
	uart_init();
	
	int8_t ch=0;
	
	/* Replace with your application code */
	while (1)
	{
		ch = uart_getch();
		
		if (ch == 13)
		{
			uart_puts(">> UCSR0B: 0x");
			num2ascii(UCSR0B);
			uart_putch(13);
			ch = 10;
		}
		
		uart_putch(ch);
		
	}
}