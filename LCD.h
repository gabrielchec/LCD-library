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


class LCD{
	int * RS, * RW, * E;
	void write_command(char character);
	void write_display(char character);
	short line_1_pos = 0;
	short line_2_pos = 0;
public:
	LCD();
	int write_line(char * word, short row);	
	int animate_line(char * word, short row, short ms_per_move );
	int animate_col(char **word, short speed);
	int change_char(char character, short col, short row);

};

#endif //__LCD_H__
