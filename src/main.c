#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000L

int main(void) {
  unsigned char i;

  DDRD |= 0xFF;
  PORTD |= _BV(PD1);

  while (1) {
    for (i = 0; i <= 7; i++) {
      PORTD = (1<<i);
      _delay_ms(50);
    }
  }
}