#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include <lcd.h>

#define F_CPU 16000000UL

void portInit(void) {
	PORTD=0x00;
	DDRD=0xFF;
}

int main(void) {
	portInit(); 
	LCDInit();

	setPosition(0,0);
	stringLCD("HELLO FROM");
	setPosition(0,1);
	stringLCD("ATMEGA328P");
	while(1) {}
}