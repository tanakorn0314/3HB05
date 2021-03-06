#include <avr/io.h>
int main(void)
{
	unsigned char TB7SEG[] = {
	0b00111111, 0b00000110, 0b01011011, 0b01001111,
	0b01100110, 0b01101101, 0b01111101, 0b00000111,
	0b01111111, 0b01101111, 0b01110111, 0b01111100,
	0b00111001, 0b01011110, 0b01111001, 0b01110001};
	unsigned char DISPLY;
	unsigned char SWITCH,minus;
	DDRD = 0xFF; //output D
	DDRB = 0x00; //input B
        DDRC = 0xFF; //output C
	while(1)
	{
		SWITCH = PINB;
		SWITCH &= 0b00111100;
                SWITCH = SWITCH >> 2;
                
                minus = 1;
                
                if(SWITCH >= 8)
                {
                  SWITCH = 16 - SWITCH;
                  minus = 0;
                }
                
		DISPLY = TB7SEG[SWITCH];
		PORTD = ~DISPLY;
                PORTC = minus;
	}
}

