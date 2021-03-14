/*
Instructor: Peter Jamieson
Author: Yang Xu

This project is to interface the I2C with an LCD, whose library is from Peter Fleury and Davide Gironi.

References:
  - based on lcd library by Peter Fleury
    http://jump.to/fleury
  - based on I2C library by Davide Gironi
    http://davidegironi.blogspot.com/2013/06/an-avr-atmega-library-for-hd44780-based.html#.YE0ygmhKguV
*/


#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "lib/lcdpcf8574/lcdpcf8574.h"

#define UART_BAUD_RATE 2400
#include "lib/uart/uart.h"


#define PIN(x) (*(&x - 2))    /* address of input register of port x */


int main(void)
{
    DDRC |= _BV(DDC5) | _BV(DDC4);
    PORTC |= _BV(DDC5) | _BV(DDC4);

    //init uart
    uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );

    sei();

    //init lcd
    lcd_init(LCD_DISP_ON_BLINK);

    //lcd go home
    lcd_home();

    lcd_gotoxy(5, 0);
    lcd_puts("Hello");
    lcd_gotoxy(4, 1);
    lcd_puts("I2C ECD");
    _delay_ms(2000);

    uint8_t led = 0;
    lcd_led(led); //set led

    _delay_ms(2000);

    while(1) {
	lcd_clrscr();

    	//test loop
    	int i = 0;
    	int line = 0;
    	for(i=0; i<4; i++) {
		if(i == 0){
			lcd_gotoxy(0, line);
			lcd_clear_line();
			lcd_gotoxy(0, line);
			lcd_puts_int(i+1);
    			lcd_puts(".ECE387");
		}
		if(i == 1){
			lcd_gotoxy(0, line);
			lcd_clear_line();
			lcd_gotoxy(0, line);
			lcd_puts_int(i+1);
    			lcd_puts(".Yang Xu");
		}
		if(i == 2){
			lcd_gotoxy(0, line);
			lcd_clear_line();
			lcd_gotoxy(0, line);
			lcd_puts_int(i+1);
    			lcd_puts(".Presentation I");
		}
		if(i == 3){
			lcd_gotoxy(0, line);
			lcd_clear_line();
			lcd_gotoxy(0, line);
			lcd_puts_int(i+1);
    			lcd_puts(".Thank you");
		}
    		
    		line++;
    		line %= 2;
    		_delay_ms(2000);
    	}
    }
}


