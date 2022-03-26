#include <avr/io.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lib/ioCommon.h"

#define delay 500

void clear_all_TC(void);
void blink (short int times);
void off_led ();
int analogWrite(short int apin, short int cycle);

int main() {

    clear_all_TC();

    short int ard, duty_cycle, direction;

    ard = 9;
    duty_cycle = 0; // 63 = 25%


    while(true) {
        analogWrite(ard, duty_cycle);
        
        if (duty_cycle == 0) {
            direction = 1;
        } else if (duty_cycle == 255){
            direction = 0;
        }

        if (direction == 1) {
            duty_cycle++;
        } else {
            duty_cycle--;
        }

        _delay_ms(4);
    }
}

void clear_all_TC(void) {
    // reset both timer/counter registers
    TCCR0A = 0;
    TCCR0B = 0;
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR2A = 0;
    TCCR2B = 0;
}

void blink (short int times)
{
    // Set the built-in LED PB5 to be an output
    DDRB |= _BV(DDB5);
    // Enter an infinite loop
    for (int i=0;i<times;i++) {
        PORTB |= _BV(PORTB5);
        _delay_ms(delay);
        PORTB &= ~(_BV(PORTB5));
        _delay_ms(delay);
    }
}

void off_led ()
{
    // Set the built-in LED PB5 to be an output
    DDRB |= _BV(DDB5);
    PORTB &= ~(_BV(PORTB5));
}