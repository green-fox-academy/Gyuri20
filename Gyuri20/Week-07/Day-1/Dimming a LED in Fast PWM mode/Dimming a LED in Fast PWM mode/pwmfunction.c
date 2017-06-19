#include <avr/io.h>
#include <util/delay.h>

void InitPWM ()
{
	TCCR0A |= 1 << WGM01 | 1 << WGM00 | 1 << COM0A1;
	TCCR0B |= 1 <<  CS02 |  1 <<  CS00;
	DDRD = 1 << DDRD6;
}

void duty_cycle (uint8_t duty)
{	
	OCR0A = duty;
}

void Wait ()
{
	_delay_ms (100);
}