/******************************************************************************
 *
 * Module: KEYPAD
 *
 * Description: Source file of KEYPAD driver for AVR
 *
 *******************************************************************************/

#include "KEYPAD.h"
#define F_CPU 8000000
#include <util/delay.h>

/***************************************************************************/

//to detect the desired pressed key on KeyPad
u8 KEYPAD_GetKey(void)
{
	//Local variable to store the value of the pressed key
	u8 Key=NO_KEY;
	
	//local variable is used inside for loop to detect the desired row 
	u8 r;
	
	//local variable is used inside for loop to detect the desired column
	u8 c;
	
	/**out on all buttons in rows HIGH*/ 
	DIO_WritePin(FIRST_OUTPUT,HIGH);
	DIO_WritePin(FIRST_OUTPUT+1,HIGH);
	DIO_WritePin(FIRST_OUTPUT+2,HIGH);
	DIO_WritePin(FIRST_OUTPUT+3,HIGH);
	
	/**loop on all each row and detect any button in columns is pressed*/ 
	for(r=0;r<ROWS;r++)
	{
		DIO_WritePin(FIRST_OUTPUT+r,LOW);
		for(c=0;c<COLS;c++)
		{
			
			if(DIO_ReadPin(FIRST_INPUT+c)==LOW)
			{
				
				Key=kayarrarr[r][c];
				while(DIO_ReadPin(FIRST_INPUT+c)==LOW);
			}
		}
		DIO_WritePin(FIRST_OUTPUT+r,HIGH);

	}
	
	return Key ;
}

