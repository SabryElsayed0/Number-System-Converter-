 /******************************************************************************
 *
 * Module: LCD
 *
 * Description: header file of KEYPAD driver for AVR
 *
 *******************************************************************************/
 
#ifndef LCD_H_
#define LCD_H_
#define F_CPU 8000000
#include <util/delay.h>
#include "DIO_interface.h"

#define  _4_BIT    1
#define  _8_BIT    2
/**********************pin configuration********/
#define LCD_MODE      _4_BIT

#define RS           PINA1
#define EN           PINA2
#define D7           PINA6
#define D6           PINA5
#define D5           PINA4
#define D4           PINA3



#define LCD_PORT     PA
/****************************************************/

/*to initialize LCD */
void LCD_Init();

//To clear any data on LCD
void LCD_Clear(void);

//to Write String on LCD 
void LCD_WriteString(u8*str);

//to Write Number on LCD 
void LCD_WriteNumber(s32 num);

//to WriteChar on LCD 
void LCD_WriteChar(u8 ch);

//to Write Binary on LCD 
void LCD_WriteBinary(u8 num);

//To set cursor at specific position
void LCD_GoTo(u8 line,u8 cell);

//to write Hexadecimal on LCD
void LCD_WriteHex(u8 num);





#endif /* LCD_H_ */