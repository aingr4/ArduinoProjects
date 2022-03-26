#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#define DELAY_S 200
#define DELAY_O 500

void morse(char letter);

int main() {

    DDRB |= _BV(PORTB1);

    while (true) {
        morse('s');
        morse('o');
        morse('s');
        _delay_ms(1000);
    }
}

void morse(char letter) {
    
    if (letter == 's') {
        for (int i = 0; i < 3; i++) {
            PORTB |= _BV(PORTB1);
            _delay_ms(DELAY_S);

            PORTB &= ~_BV(PORTB1);
            _delay_ms(DELAY_S);
        }
    } else {
        for (int i = 0; i < 3; i++) {
            PORTB |= _BV(PORTB1);
            _delay_ms(DELAY_O);

            PORTB &= ~_BV(PORTB1);
            _delay_ms(DELAY_O);
        }
    }
}