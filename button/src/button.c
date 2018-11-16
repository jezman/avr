#include <avr/io.h>

int main(void) {
  unsigned char butCount = 0;

  DDRB |= _BV(PB5); // set pin PORTB5 as output
  DDRD &= ~_BV(PD7); // set pin PORTD7 as input
  PORTD |= _BV(PD7); // set pull-up to PORTD7

  while (1) {
    //if button pressed
    if (!(PIND&_BV(PD7)))
      // led on
      (butCount < 5) ? butCount++ : (PORTB |= _BV(PB5));
    else
      // led off
      (butCount > 0) ? butCount-- : (PORTB &= ~_BV(PB5));
  }
}