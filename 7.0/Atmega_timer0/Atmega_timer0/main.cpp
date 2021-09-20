#define F_CPU 8000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
unsigned char led[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
unsigned int dem = 0;
unsigned int countMin = 1;
unsigned int countHour = 1;
void hienthi1(int x){
	int ch,dv;
	ch = x/10;
	dv = x%10;
	PORTB = 0x00;
	PORTB = 0x01;
	PORTA = led[ch];
	_delay_ms(0.1);
	PORTB = 0x00;
	PORTB = (1<<PINB1);
	PORTA = led[dv];
	_delay_ms(0.1);
}
void hienthi2(int x){
	int ch,dv;
	ch = x/10;
	dv = x%10;
	PORTB = 0x00;
	PORTB = 0x04;
	PORTC = led[ch];
	_delay_ms(0.1);
	PORTB = 0x00;
	PORTB = 0x08;
	PORTC = led[dv];
	_delay_ms(0.1);
}
int main(void)
{
	DDRA = 0xFF;
	PORTA = 0x00;
	DDRB = 0x0F;
	PORTB = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;
	TCCR0 = (1<<CS00)|(1<<CS01);
	TCNT0 = 130; 
	TIMSK = (1<<TOIE0);
	sei();
    while (1) 
    {
		hienthi1(countMin);
		hienthi2(countHour);
		if(dem == 60000){
			countMin++;
			if(countMin>60) {
				countMin = 0;
				countHour++;
				if(countHour>24) countHour = 0;
			}
			hienthi1(countMin);
			hienthi2(countHour);
			dem = 0;
		}
		_delay_ms(0.1);
    }
}
ISR(TIMER0_OVF_vect){
	TCNT0 = 130;
	dem++;
}

