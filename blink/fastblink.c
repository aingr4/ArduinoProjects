#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main() {

    DDRB |= _BV(PORTB5);

    while (true) {
        PORTB ^= _BV(PORTB5);
        _delay_ms(20);
    }
}