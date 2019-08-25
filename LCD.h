/* 
* LCD.h
*
* Created: 14.08.2019 20:19:21
* Author: Gabriel
*/


#ifndef __LCD_H__
#define __LCD_H__
#define F_CPU 16000000L
#include <util/delay.h>
#include <avr/io.h>
#include <string.h>

class LCD{
	int * RS, * RW, * E;
	short line_1_pos = 0;
	short line_2_pos = 0;
	
	void write_command(char character);
	void write_display(char character);
	void set_position(short row, short col);
public:
	LCD();
	int write_line(char * word, short row);	
	int animate_line(char * word, short row );
	int animate_col(char **word, short speed);
	void change_char(char character, short row, short col);

};

#endif //__LCD_H__
