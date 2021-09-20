#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>
#define Vref (1<<REFS0)|(0<<REFS1)|(0<<ADLAR)

unsigned int input_value;

void ADC_init(unsigned char x)
{
	ADMUX = x | Vref;
	ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADIE);
	sei();
}
void PWM_init()
{
	TCCR0 |= (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00)|(1<<CS01);
}

int main(void)
{
	
	DDRB = 0xFF;
    DDRA =0x00;
	ADC_init(4);
	PWM_init();
    while(1)
	{
		PORTB |= (1<<PINB2);
		PORTB ^= (1<<PINB1);
    }
}
ISR(ADC_vect){
	PORTB &= ~(1<<PINB2);
	OCR0 = (int)ADCW;
	ADCSRA |= (1<<ADSC);
}
