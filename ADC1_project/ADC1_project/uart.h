
/*
 * uart.h
 *
 * Created: 2023-11-22 오후 8:45:56
 *  Author: dltkd
 */ 

#ifndef UART_H
#define UART_H

// function prototypes

void uart_init(void);
int8_t uart_getch(void);
void uart_putch(int8_t ch);
void uart_puts(int8_t *str);
void num2ascii(int8_t ch);

#endif