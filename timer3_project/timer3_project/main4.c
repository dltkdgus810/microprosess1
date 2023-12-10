
/*
 * main4.c
 *
 * Created: 2023-12-10 오후 9:31:35
 *  Author: dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include <util/delay.h>
#include "fnd.h"
#include <avr/interrupt.h>
#include "signal_table.h"

void ioport_init(void);
void timer_init(void);
void interrupt_init(void);
void set_timer3_dutycycle(uint8_t dutycycle);

static uint8_t i = 255;
static uint16_t fnd_num = 0;
static uint8_t a = 0;

ISR(INT7_vect)
{
	if (a<100)
	{
		a = a + 10;
	}
	else
	{
		a = 100;
	}
	fnd_write_numbers(a);
	set_timer3_dutycycle(a);
}

ISR(INT3_vect)
{
	if(a>0)
	{
		a = a - 10;
	}
	else
	{
		a = 0;
	}
	
	fnd_write_numbers(a);
	set_timer3_dutycycle(a);
}

ISR(TIMER5_COMPA_vect)
{
	i++;
	OCR2A = signal_table[i];
}

int main(void)
{
	ioport_init();
	timer_init();
	interrupt_init();
	fnd_init();
	
	fnd_write_numbers(fnd_num);
	
	uint8_t led_pattern[8] = {0x81, 0xC3, 0xE7, 0xFF, 0x7E, 0x3C, 0x18, 0x00};
	
	/* Replace with your application code */
	while (1)
	{
		led_write(led_pattern[i++%8]);
		_delay_ms(250);
	}
}

void ioport_init(void)
{
	//DDRC의 하위 4bit을 출력하는 단자로 만든다.
	DDRC = _BV(LED1) | _BV(LED2) | _BV(LED3) | _BV(LED4);
	//MCU의 LED보드 4개의 불을 끈다.
	PORTC = 0xff;
	PORTE = _BV(SW2);
	PORTD = _BV(SW3);
	DDRE = _BV(SOUND_OUT);
	DDRB = _BV(LED_COLOR);
}

void interrupt_init(void)
{
	// 하강 모서리 (falling edge)에서 INT3이발생하도록 EICRA를설정한다.
	EICRA = _BV(ISC31);
	// 하강 모서리 (falling edge)에서 INT7이발생하도록 EICRB를설정한다.
	EICRB = _BV(ISC71);
	// INT7와 INT3을 enable시킨다.
	EIMSK = _BV(INT7) | _BV(INT3);
	//timer5번의 compare match interrupt enable.
	TIMSK5 = _BV(OCIE5A);
	// global interrupt flag을 set시킨다.
	sei();
}
void timer_init(void)
{
	// Timer2를 Fast PWM 모드로 동작시키고 PWM 신호는 OC2A 핀으로출력하려고한다.
	TCCR2A |= _BV(WGM21) | _BV(WGM20);
	// 이 때 prescaler는 1로 설정하고
	TCCR2B |= _BV(CS20);
	//COM2A1 비트와 COM2A0 비트는각각 1과 0으로설정한다.
	TCCR2A |= _BV(COM2A1);
	// 출력 PWM의 duty cycle이 50 %가 되도록 OCR2A 레지스터값을설정한다.
	OCR2A = 50*(2*255)/(2*100);
	
	// Timer3을 Phase Correct PWM 모드로 동작시키고 PWM 신호는 OC3A 핀으로출력하려고한다
	TCCR3A |= _BV(WGM31);
	TCCR3B |= _BV(WGM33);
	// prescaler를 8로 설정하고
	TCCR3B |= _BV(CS31);
	//COM3A1 비트와 COM3A0 비트는각각 1과 0으로설정한다.
	TCCR3A |= _BV(COM3A1);
	// PWM 주파수가 1 KHz가 되도록 하려면 ICR3 레지스터에값을저장한다.
	ICR3 = F_CPU/(2*8*1000);
	// 출력 PWM의 duty cycle이 50 %가 되도록 OCR3A 레지스터값을설정한다.
	OCR3A = 0;
	
	// Timer5을 CTC 모드로 설정
	TCCR5B |= _BV(WGM52);
	// 이 때 prescaler는 8로 설정한다
	prescaler_set5(8);
	// 256×4 Hz의주파수로 compare match interrupt가발생하도록설정한다.
	OCR5A = (F_CPU/(8*256*4))-1;
}

void set_timer3_dutycycle(uint8_t dutycycle)
{
	OCR3A = 10 * dutycycle;
}