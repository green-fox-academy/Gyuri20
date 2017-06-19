#include "freq_meas.h"
#include "UART_driver.h"
#include "AC_driver.h"
#include "ADC_driver.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/delay.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

void system_init()
{
	LED_DDR |= 1 << LED_DDR_POS;
	ADC_init();
	TC2_pwm_init();
	AC_driver_init();
	freq_meas_init();
	UART_init();
	sei();
}

void TC2_pwm_init()
{
	// Enable OC0A pin as output
	DDRB |= 1 << DDRB3;

	// Set FAST PWM mode, with comparison of OCRA
	TCCR2A |= 1 << WGM21;
	TCCR2A |= 1 << WGM20;

	// Set OC0A pin to high when compare match occures, clear OC0A when counter overflows
	TCCR2A |= 1 << COM2A1;

	// Set clock speed to minimum, Tcnt will be 16MHz/1024 / 255 ~ 61Hz (1024 prescaler)
	TCCR2B |= 1 << CS20;
	TCCR2B |= 1 << CS22;
}


int main(void)
{

	// Don't forget to call the init function :)
	system_init();

	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM((void *)UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, (void *)UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	// Try printf
	printf("Startup...\r\n");

	// Infinite loop
	while (1) {
		// Generating an about 1Hz signal on the LED pin.
		// The printf call will also take some time, so this won't be exactly 1Hz.
		OCR2A = ADC_read() / 4;
		printf("%f Hz\n", get_freq());
		printf("%f RPM\n", get_rpm());
		_delay_ms(500);
	}
}
