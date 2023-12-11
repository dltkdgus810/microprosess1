/*
 * 20191064.c
 *
 * Created: 2023-12-11 오후 3:06:25
 * Author : dltkd
 */ 

#include "board.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include "uart.h"
#include "fnd.h"
#include "sound.h"
#include "music_data.h"

void ioport_init(void);
void interrupt_init(void);
uint8_t switch_hit(void);

uint8_t fnd_num = 255;
uint8_t led_num = 0;
volatile uint16_t notes_num = 0;
volatile uint8_t song_num = 0;

ISR(INT7_vect)
{
	if (fnd_num == 255)
	{
		fnd_write_numbers(fnd_num);
	}	
}

ISR(USART0_RX_vect)
{
	if (UDR0 == 's' || UDR0 == 'S')
	{
		song_num++;
		UDR0 = UDR0;	
	}
	if (UDR0 == '1' || UDR0 == '2'|| UDR0 == '3' || UDR0 == '4'|| UDR0 == '5' || UDR0 == '6'|| UDR0 == '7' || UDR0 == '8'|| UDR0 == '9' || UDR0 == '0')
	{
		UDR0 = UDR0;
	}
	if (UDR0 == 'o' || UDR0 == 'O')
	{
		led_num++;
	}
	if (UDR0 == 13)
	{
		UDR0 = 10;
	}
}
int main(void)
{
	ioport_init();
	interrupt_init();
	fnd_init();
	uart_init();
	led_write(0xCC);
	uint8_t a = 0;
	uint16_t m_notes_size = sizeof(m_notes) / sizeof(uint16_t);
	uint16_t m_duration_size = sizeof(m_duration) / sizeof(uint8_t);
	
	
	uint16_t m_duration_real = 0;
	
    /* Replace with your application code */
    while (1) 
    {
		a += switch_hit();
		
		if (a%2)
		{
			fnd_num--;
			fnd_write_numbers(fnd_num);
			_delay_ms(200);
		}
		if (led_num%2)
		{
			led_write(0);
		}
		else
		{
			led_write(0xCC);
		}
		if (song_num%2)
		{
			if (!m_notes[notes_num%m_notes_size])
			{
				sound_mute();
			}
			else
			{
				sound_set_frequency(m_notes[notes_num%m_notes_size]);
			}
			
			m_duration_real = (m_duration[notes_num%m_duration_size] * music_tempo);
			
			_delay_ms(m_duration_real);

			notes_num++;
		}
		else
		{
			sound_mute();
		}
		
    }
}

void ioport_init()
{
	//DDRC의 하위 4bit을 출력하는 단자로 만든다.
	DDRC = _BV(LED1) | _BV(LED2) | _BV(LED3) | _BV(LED4);
	//MCU의 LED보드 4개의 불을 끈다.
	PORTC = 0xff;
	//MCU 보드의 SW2의 내부 pull-up저항을 활성화 한다.
	PORTE = _BV(SW2);
	
	DDRE = _BV(SOUND_OUT);
	DDRB = _BV(PB4);
}

void interrupt_init(void)
{
	//falling 엣지가 일어날 때 INT7가 발생하게한다.
	EICRB = _BV(ISC71);
	//INT7을 활성화한다.
	EIMSK = _BV(INT7);
	// global interrupt flag을 set시킨다.
	sei();
}

uint8_t switch_hit(void)
{
	static uint8_t prev_state = _BV(SW2);
	uint8_t cur_state;
	
	cur_state = PINE & _BV(SW2);
	if(prev_state != cur_state)
	{
		prev_state = cur_state;
		if(!cur_state) return 1;
		else return 0;
	}
	else
	return 0;
}

