#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
unsigned char led[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
int i=0;
void hienthi(unsigned int x){
	int ch,dv;
	ch = x/10;
	dv = x%10;
	PORTD = 0x00;
	PORTD = 0b00000001;
	PORTC = led[ch];
	_delay_ms(1);
	PORTD = 0x00;
	PORTD = 0b00000010;
	PORTC = led[dv];
	_delay_ms(1);
}
int main(void)
{
	DDRA = (0<<PINA0)|(0<<PINA1);
	DDRC = 0xFF;
	PORTC = 0xFF;
	DDRD = (1<<PIND0)|(1<<PIND1);
	PORTD = 0x00;

    while (1) 
    {
		hienthi(i);
		_delay_ms(1);
		if((PINA & (1<<PINA0))==0){
			while((PINA & (1<<PINA0))==0){
				hienthi(i);
				_delay_ms(1);
			}
			i++;
			if(i>99){
				i=0;
				hienthi(i);
				_delay_ms(1);
			}
			hienthi(i);
			_delay_ms(1);
		}
		if((PINA & (1<<PINA1))==0){
			while((PINA & (1<<PINA1))==0){
				hienthi(i);
				_delay_ms(1);
			}
			i--;
			if(i<0){
				i=99;
				hienthi(i);
				_delay_ms(1);
			}
			hienthi(i);
			_delay_ms(1);
		}
	}
		
    
}

