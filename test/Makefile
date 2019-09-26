# Simple makefile to compile and program an AVR chip, in this case AT90CAN64
# base on the makefile found at https://www.pololu.com/docs/0J61/6.3 adjusted for my personal needs
# Author: Henrique

PORT=usb
MCU=at90can64
CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) -Os
LDFLAGS=-Wl,-gc-sections -Wl,-relax
CC=avr-gcc
TARGET=main
OBJECT_FILES=main.o

all: $(TARGET).hex

clean:
	rm -f *.o *.hex *.obj *.hex

%.hex: %.obj
	avr-objcopy -R .eeprom -O ihex $< $@

%.obj: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@

program: $(TARGET).hex
	avrdude -p $(MCU) -c atmelice_isp -U flash:w:$(TARGET).hex

readeeprom:
	avrdude -p $(MCU) -c atmelice_isp -P usb -U eeprom:r:eepromdump.hex:i

readflash:
	avrdude -p $(MCU) -c atmelice_isp -P usb -U flash:r:flashdump.hex:i
