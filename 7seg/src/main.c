#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000L

void setChar(unsigned char seg)
{
  switch (seg)
  {
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

int main(void)
{
  unsigned char i;
  unsigned char buttonCount = 0;
  unsigned char buttonState = 0;

  DDRB &= ~_BV(PB5); // set button pin input
  PORTB |= _BV(PD5); // set pull-up
  DDRD |= 0xFF; // set 7segment led port output

  while (1) {
    for (i = 0; i <= 9; i++) {
      // check button
      while (1) {
        if (!(PIND & _BV(PD5))) {
          if (buttonCount < 5) {
            buttonCount++;
          } else {
            i = 0;
            buttonState = 1;
          }
        } else
          (buttonCount > 0) ? buttonCount-- : (buttonState = 1);
      }

      setChar(i);
      _delay_ms(500);

      buttonState = 0;
    }
  }
}