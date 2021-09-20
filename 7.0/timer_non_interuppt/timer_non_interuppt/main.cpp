#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRC = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		PORTC = 0xFF;
		_delay_ms(1000);
		PORTC = 0x00;
    }
}

