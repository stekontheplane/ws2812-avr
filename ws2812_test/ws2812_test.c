/*
 * ws2812_test.c
 *
 * Created: 07.11.2017 19:44:57
 *  Author: Minime
 */ 


#include <avr/io.h>
#include "util/delay.h"

void setLed(void);
#define LedPin 3
#define LedPort PORTD

int main(void)
{
	DDRD |= 1<<LedPin;
	PORTD = 0;
	setLed();
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

/*
1/16000000 = 0,0000000625
0.9 = 14.4
0.35 = 5.6
*/
void sendOne(void)
{
	volatile uint8_t i;
	LedPort |= 1<<LedPin;
	//delay 0.9us
	for(i=0;i<14;i++);
	LedPort &= ~1<<LedPin;
	//delay 0.35us
	for(i=0;i<6;i++);
}
void sendZero(void)
{
	volatile uint8_t i;
	LedPort |= 1<<LedPin;
	//delay 0.35us
	for(i=0;i<6;i++);
	LedPort &= ~1<<LedPin;
	//delay 0.9us
	for(i=0;i<14;i++);
}

void setLed(void)
{
	_delay_us(50);
	for(uint8_t i = 0; i < 8;i++)
	{
		sendZero();
	}
	for(uint8_t i = 0; i < 8;i++)
	{
		sendZero();
	}
	for(uint8_t i = 0; i < 8;i++)
	{
		sendOne();
	}
}