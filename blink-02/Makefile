CC=avr-gcc
CFLAGS= -Os -DF_CPU=16000000UL -mmcu=atmega328p
FILENAME=blink

all: $(FILENAME).o

USBPORT:=$(shell ls /dev/ttyACM0)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.h: %.o
	avr-objcopy -O ihex -R .eeprom $< $@

install.%: %.h
	avrdude -F -V -c arduino -p ATMEGA328P -P ${USBPORT} -b 115200 -U flash:w:$<

clean:
	rm -f *.h *.o

install: install.$(FILENAME)