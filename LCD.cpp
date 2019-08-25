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
	_delay_ms(5);
	PORTB = 0x00;
}

void LCD::write_display(char character){
	PORTB = 0x04;
	PORTD = character;
	PORTB = 0x05;
	_delay_ms(5);
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

int LCD::animate_line(char * word, short row ){
	int size = 0;
	while(*word){size++; word++; }
	word -= size;
	
	if(row == 1){
		set_position(1,1);
		if(line_1_pos > 0){word+=line_1_pos;}
		for(int i = 0; i < 16; i++){
				write_display(' ');
			}
			else{
				write_display(*word++);
			}
		}
		line_1_pos++;
		if(line_1_pos == size)		line_1_pos = -16;
	}
	else if(row == 2){
		set_position(2,1);
		if(line_2_pos > 0){word+=line_2_pos;}
		for(int i = 0; i < 16; i++){
			if(line_2_pos + i < 0 || !*word){
				write_display(' ');
			}
			else{
	 			write_display(*word++);
			}
		}
		line_2_pos++;
		if(line_2_pos == size)		line_2_pos = -16;
	}
	else return -1;
	_delay_ms(500);
	return 0;
}

void LCD::change_char(char character, short row, short col){
	set_position(row, col);
	write_display(character);
}

void LCD::set_position(short row, short col){
	if(row == 1) write_command(0x80);
	else write_command(0xC0);
	for(short i = 0; i < col - 1; i++)	write_command(0x14);
}