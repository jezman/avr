#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include <lcd.h>

#define e1    PORTD|=0b00001000 // line E to 1
#define e0    PORTD&=0b11110111 // line E to 0
#define rs1    PORTD|=0b00000100 // line RS in 1 (data)
#define rs0    PORTD&=0b11111011 // line RS in 0 (command)

void LCDInit(void);
void setPosition(uint8_t x, uint8_t y);
void stringLCD (char str1[]);

#endif /* LCD_H_ */