// Simple program to test blinking PortG0 of an AVR 
// based on the code found in https://www.pololu.com/docs/0J61/6.3
// Author: Henrique

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRG |= (1<<DDG0); 		//Make pin PG0 be an output.
	while(1){
		PORTG |=(1 <<PORTG0); 	//Turn the LED on.
		_delay_ms(500);
		PORTG &= ~(1 <<PORTG0); //Turn the LED off.
		_delay_ms(500);
	}
}
