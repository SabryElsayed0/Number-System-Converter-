/******************************************************************************
 *
 * Module: KEYPAD
 *
 * Description: Header file of KEYPAD driver for AVR
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO_interface.h"

/****************************config*****************/
#define FIRST_OUTPUT    PINB4
#define FIRST_INPUT     PIND2
#define ROWS             4
#define COLS             4
#define NO_KEY           'N'

//2D array that contains the different values for each button in KeyPad
static u8 kayarrarr[ROWS][COLS]={
	                            {'7' , '8' , '9' , 'a'},
	                            {'4' , '5' , '6' , 'b'},
	                            {'1' , '2' , '3' , 'e'},
	                             {'C' , '0' ,'=' , 'f'},
                                 };
                               
/***************************************************************************/

//prototype of function that detect the desired pressed key on KeyPad
u8 KEYPAD_GetKey(void);




#endif /* KEYPAD_H_ */