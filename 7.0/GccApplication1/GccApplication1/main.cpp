/*
 * GccApplication1.cpp
 *
 * Created: 6/10/2021 1:14:42 AM
 * Author : Zbook 15 G2
 */ 
#define F_CPU 1600000
#include <avr/io.h>
#include <util/delay.h>

int main()
{
    /* Replace with your application code */
	DDRA = 0b11111111;//set chân A là output
	PORTA = 0b00000000;//set chan A la 0V
	DDRB = 0x00;//set chân b là input
	PORTB = 0x01;//set chan b la 5v
	int button =0;
	while(1){
		if((PINB & (1<<PINB0))==0){
		    while((PINB & (1<<PINB0))==0){
		    }
			button++;
			if(button>8){
				button=0;
			}
		}
		switch(button){
			case 0:PORTA = 0b00000000;break;
			case 1:PORTA = PORTA | (1<<0);break;
			case 2:PORTA = PORTA | (1<<1);break;
			case 3:PORTA = PORTA | (1<<2);break;
			case 4:PORTA = PORTA | (1<<3);break;
			case 5:PORTA = PORTA | (1<<4);break;
			case 6:PORTA = PORTA | (1<<5);break;
			case 7:PORTA = PORTA | (1<<6);break;
			case 8:PORTA = PORTA | (1<<7);break;
		}
	}
}

