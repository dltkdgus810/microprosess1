/*
 * LED_project.c
 *
 * Created: 2023-12-10 오후 8:36:53
 * Author : dltkd
 */ 

#include <avr/io.h>


int main(void)
{
	DDRC = 0x0f;
	PORTE = 0x80;

	/* Replace with your application code */
	while (1)
	{
		if(PINE&0x80){
			PORTC &= 0x06;
			PORTC |= 0x06;
		}
		else{
			PORTC |= 0x09;
			PORTC ^= 0x06;
		}
	}
}

