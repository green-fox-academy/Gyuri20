/*
 * Dimming a LED in Fast PWM mode.c
 *
 * Created: 2017. 06. 12. 10:36:21
 * Author : Gyuri
 */ 

#include <avr/io.h>
#include "pwmfunction.h"
#define F_CPU 16000000
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
    InitPWM();
	
	uint8_t brightness;
	while (1) {
		for (brightness = 10; brightness < 200; brightness++) {
			duty_cycle (brightness);
			Wait ();
		}
	
		for (brightness = 200; brightness > 10; brightness--) {
			duty_cycle (brightness);
			Wait ();
		}
	}
	
}