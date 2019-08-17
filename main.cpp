/*
 * LCD.cpp
 *
 * Created: 14.08.2019 20:07:28
 * Author : Gabriel
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include <string.h>

#define rs PB2			//0x04
#define rw PB1			//0x02
#define e PB0			//0x01
#define data PD


int main(void)
{
	LCD a;
	while(1){
		a.animate_line("This is short example.",2,500);
	}

}

