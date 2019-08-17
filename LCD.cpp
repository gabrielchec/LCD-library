/* 
* LCD.cpp
*
* Created: 14.08.2019 20:19:21
* Author: Gabriel
*/
#include "LCD.h"

LCD::LCD(){
	DDRD = 0xff;
	DDRB |= 0x07;
	write_command(0x38);
	write_command(0x0C);
	write_command(0x01);
	write_command(0x80);
	write_command(0x06);
}

void LCD::write_command(char character){
	PORTB = 0x00;
	PORTD = character;
	PORTB = 0x01;
	_delay_ms(4.5);
	PORTB = 0x00;
}

void LCD::write_display(char character){
	PORTB = 0x04;
	PORTD = character;
	PORTB = 0x05;
	_delay_ms(4.5);
	PORTB &= 0x04;
}

int LCD::write_line(char *word, short row){
	short i = 16;
	
	if(row == 1) write_command(0x80);
	else if(row == 2) write_command(0xC0);
	else return -1;
	
	while( *word && i ){ write_display(*word++);i--;}
	return 0;
}

int LCD::animate_line(char * word, short row, short ms_per_move ){
	short i = 16;
	
	if(row == 1){
		write_command( 0x80 );
		word += line_1_pos;
		while( *word && i ){ write_display( *word++ ); i--; }
		if(i == 1)		line_1_pos = 0;	
		line_1_pos++;
	}
	else if(row == 2){
		write_command( 0xC0 );
		word += line_2_pos;
		while( *word && i ){ write_display( *word++ ); i--; }
		if(i == 1)		line_1_pos = 0;
		line_2_pos++;
	}
	else return -1;
	_delay_ms(500);
	return 0;
}