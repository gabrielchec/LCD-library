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


int main(void)
{
	LCD example;
	example.write_line((char*)"Hi there",1);
	example.change_char(' ', 1, 4);
	while(1){
		example.animate_line((char*)"This is little example of using animate_line function",2);
	}

}

