
/*
 * main2.c
 *
 * Created: 2023-12-10 오후 9:36:45
 *  Author: dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include "uart.h"



int main(void)
{
	uart_init();
	
	uint8_t ch=0;
	
	/* Replace with your application code */
	while (1)
	{
		ch = uart_getch();
		uart_putch(ch+1);
	}
}