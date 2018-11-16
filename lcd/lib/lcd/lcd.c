#include <lcd.h>

void sendHalfByte(uint8_t c) {
	c<<=4;
	e1; // line E on
	_delay_us(50);
	PORTD &= 0b00001111; // clear data from DB4-DB7
	PORTD |= c;
	e0;  // line E off
	_delay_us(50);
}

void sendByte(uint8_t c, uint8_t mode) {
    !mode ? (rs0) : (rs1);
	uint8_t highChar = 0;
	highChar = c >> 4;
	sendHalfByte(highChar);
    sendHalfByte(c);
}

void sendChar(uint8_t c) {
	sendByte(c,1);
}

void setPosition(uint8_t x, uint8_t y) {
	char address = (0x40*y + x) | 0b10000000;
	sendByte(address, 0);
}

void LCDInit(void) {
	_delay_ms(15);
	sendHalfByte(0b00000011);
	_delay_ms(4);
	sendHalfByte(0b00000011);
	_delay_us(100);
	sendHalfByte(0b00000011);
	_delay_ms(1);
	sendHalfByte(0b00000010);
	_delay_ms(1);
	sendByte(0b00101000, 0);
	_delay_ms(1);
	sendByte(0b00001100, 0);
	_delay_ms(1);
	sendByte(0b00000110, 0);
	_delay_ms(1);
}

void clearLcd() {
	sendByte(0b00000001, 0);
	_delay_us(1500);
}

void stringLCD (char str1[]) {  
	wchar_t n;
	for(n = 0; str1[n] != '\0'; n++)
    	sendChar(str1[n]);
}