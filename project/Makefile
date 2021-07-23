# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blink-c.elf blink-s.elf

#additional rules for files
blink-c.elf: ${COMMON_OBJECTS} blinkMain.o state_advance-c.c red_control-c.c led_off-c.o stateMachines.o buzzer.o led.o wdInterruptHandler.o p1_interrupt_handler.o switches.o lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

blink-s.elf: ${COMMON_OBJECTS} blinkMain.o state_advance-s.s red_control-s.s led_off-s.o stateMachines.o buzzer.o led.o wdInterruptHandler.o p1_interrupt_handler.o switches.o lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load-c: blink-c.elf
	msp430loader.sh blink-c.elf

load-s: blink-s.elf
	msp430loader.sh blink-s.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h led.h switches.h

stateMachines.o: led.h stateMachines.h switches.h buzzer.h
