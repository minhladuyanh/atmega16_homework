/*
 * USART_Atmega16.cpp
 *
 * Created: 8/5/2021 2:16:24 PM
 * Author : Zbook 15 G2
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

void USART_init()
{
	UBRRH = 0;     //Set baud rate 9600
	UBRRL = 51;
	UCSRA = 0x00;
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UCSRB = (1<<RXEN)|(1<<RXCIE)|(1<<TXEN);
	sei();
}
void usart_getchar(char data)
{
	while((UCSRA&(1<<UDRE))==0);
	UDR = data;
	_delay_ms(1);
}
void usart_transmit(char *str)
{
	int i=0;
	while(str[i]!= 0)
	{
		usart_getchar(str[i]);
		i++;
	}
}
void usart_recived()
{
	while((UCSRA&(1<<RXC))==0);
}
int main(void)
{
	USART_init();
	DDRB = 0xFF;
	PORTB = 0x00;
    while (1) 
    {
		
    }
}
ISR(USART_RXC_vect)
{
	char pc = UDR;
	switch(pc)
	{
		case '0': PORTB = 0b00000001;break;
		case '1': PORTB = 0b00000010;break;
		case '2': PORTB = 0b00000100;break;
		case '3': PORTB = 0b00001000;break;
		case '4': PORTB = 0b00010000;break;
		case '5': PORTB = 0b00100000;break;
		case '6': PORTB = 0b01000000;break;
		case '7': PORTB = 0b10000000;break;
		case '8': PORTB = 0b11111111;break;
		default:PORTB = 0b00000000;break;
	}
}