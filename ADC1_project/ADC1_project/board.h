/*
 * board.h
 *
 * Created: 2023-10-11 오후 8:13:25
 *  Author: dltkd
 */ 


#ifndef BOARD_H_
#define BOARD_H_

#define F_CPU 16000000L
#include <avr/io.h>

// PORTC
#define LED1 PC0
#define LED2 PC1
#define LED3 PC2
#define LED4 PC3
// PORTB
#define LED_COLOR PB4
// PORTD
#define SW3 PD3
#define SW4 PD4
#define SW5 PD5
// PORTE
#define SW2 PE7
#define SOUND_OUT PE3

void prescaler_set1(uint8_t num);
void prescaler_set2(uint8_t num);
void prescaler_set3(uint8_t num);
void prescaler_set4(uint8_t num);
void prescaler_set5(uint8_t num);


#endif /* BOARD_H_ */