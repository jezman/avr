#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL

uint8_t i;

void setChar (uint8_t seg) {
	switch(seg) {
	case 1: PORTD = 0b11111001; break;
	case 2: PORTD = 0b10100100; break;
	case 3: PORTD = 0b10110000; break;
	case 4: PORTD = 0b10011001; break;
	case 5: PORTD = 0b10010010; break;
	case 6: PORTD = 0b10000010; break;
	case 7: PORTD = 0b11111000; break;
	case 8: PORTD = 0b10000000; break;
	case 9: PORTD = 0b10010000; break;
	case 0: PORTD = 0b11000000; break;
	}
}

int main(void) {
  OCR1A = 0x30D3; 
  TCCR1B |= (1 << WGM12); // Mode 4, CTC on OCR1A
  TIMSK1 |= (1 << OCIE1A); //Set interrupt on compare match
  TCCR1B |= (1 << CS12) | (1 << CS10); // set prescaler to 1024 and start the timer
  sei();         //enable interrupts

  DDRD = 0xFF;
  PORTD = 0b11111111;

  while (1) {}
}

ISR (TIMER1_COMPA_vect) {
  if (i > 9) i = 0;
  setChar(i);
  i++;
}