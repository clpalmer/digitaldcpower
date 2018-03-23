/*********************************************
* vim: set sw=8 ts=8 si :
* Author: Guido Socher, Copyright: GPL 
* This is a program to test I2C communication over RS232 to the PC
* 
* See http://www.tuxgraphics.org/electronics/
* 
* Chip type           : ATMEGA8
* Clock frequency     : Internal clock 4 Mhz 
*********************************************/
#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#define F_CPU 4000000UL  // 4 MHz
#include <util/delay.h>
#include "i2c_avr.h"
#include "lcd.h"
#include <stdlib.h> // atoi
#include <string.h> 


static char i2c_buf[MAX_BUF_LEN+1];
// the set values but converted to ADC steps

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
	// I2C also called TWI, slave address=3
	i2c_init(3,1,0);
	sei();
	i2c_send_data("on");
	while (1) {
		if (i2c_get_received_data(i2c_buf)){
			if (i2c_buf[0]=='i'){
				i2c_send_data("got i");
			}else if (i2c_buf[0]=='u'){
				i2c_send_data("got i");
			}else{
				i2c_send_data("Hi!");
			}
		}
		delay_ms(100);
	}
	return(0);
}

