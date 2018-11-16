#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main (void) {
	DDRB |= _BV(PB1);

	TCCR1A |= _BV(COM1A1) | _BV(WGM10);
	TCCR1B |= _BV(CS10) | _BV(WGM12);

	uint8_t PWM = 0x00;
	uint8_t UP = 1;

	while(1) {
		OCR1A = PWM;

		PWM += UP ? 1 : -1;

		if (PWM == 0xff) UP = 0;
		else if (PWM == 0x00) UP = 1;

		_delay_ms(2);
	}
}