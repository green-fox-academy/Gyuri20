#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "freq_meas.h"

// TODO:
// Write the interrupt handlers
volatile uint16_t timer_overflow = 0;
volatile uint16_t prev = 0;
volatile uint16_t last = 0;
volatile uint16_t stock_overflow = 0;

ISR (TIMER1_COMPA_vect)
{
	prev = last;
	last = ICR1;
	stock_overflow = timer_overflow;
	timer_overflow = 0;
}

ISR(TIMER1_OVF_vect)
{
	timer_overflow++;
}

void freq_meas_init()
{
	/**************
	 * TC1 CONFIG *
	 **************/
	// TODO:
	// Configure the TC1 timer properly :)
	TIMSK1 |= 1 << ICIE1; // Input Capture Interrupt Enable
	TIMSK1 |= 1 << TOIE1; // Enable the TC0 overflow interrupt
	TCCR1B |= 1 << CS12; // Set the prescaler to 256 division
}

// TODO:
// Write this function. It returns the measured frequency in Hz
float get_freq()
{
	uint32_t steps = 0;
	steps = timer_overflow * 65535 + last - prev;
	float T = (1/16000000) * steps;
	
	return T;
}