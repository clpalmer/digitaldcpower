/*********************************************
* vim: set sw=8 ts=8 si :
* Author: Guido Socher, Copyright: GPL 
* This is a test program which will write "LCD works"
* on the LCD display.
* 
* See http://www.tuxgraphics.org/electronics/
* 
* Chip type           : ATMEGA8
* Clock frequency     : Internal clock 4 Mhz 
*********************************************/
#include <avr/io.h>
#include <inttypes.h>
#define F_CPU 4000000UL  // 4 MHz
#include <util/delay.h>
#include "lcd.h"
#include <stdlib.h> // atoi
#include <string.h> 


void delay_ms(unsigned int ms)
/* delay for a minimum of <ms> */
{
        // we use a calibrated macro. This is more
        // accurate and not so much compiler dependent
        // as self made code.
        while(ms){
                _delay_ms(0.96);
                ms--;
        }
}


int main(void)
{
	lcd_init();
	while (1) {
		lcd_clrscr();
		lcd_puts("LCD works");
		delay_ms(500);
	}
	return(0);
}

