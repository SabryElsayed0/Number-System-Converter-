/**************************************************************************************************
 * Author      : Sabry Elsayed
/
 * Description : Main file for Number System Converter
/ 
 ************************************************************************/

/***********************************************************************/
#define F_CPU 8000000
#include <util/delay.h>
#include "DIO_interface.h"
#include  "LCD.h"
#include   "KeyPad.h"
/************************************************************************/

/************************** Functions Prototypes**********************************/

/*To covert from Decimal to Binary*/
void decimal_to_binary(void);

/*To covert from Decimal to Decimal*/
void decimal_to_decimal(void);

/*To covert from Decimal to Hexadecimal*/
void decimal_to_HEX(void);

/*To covert from Binary to Decimal*/
void binary_to_decimal(void);

/*To covert from Binary to Binary*/
void binary_to_binary(void);

/*To covert from Binary to Hexadecimal*/
void binary_to_HEX(void);

/*To covert from Hexadecimal to Decimal*/
void HEX_to_decimal(void);

/*To covert from Hexadecimal to Binary*/
void HEX_to_binary(void);

/*To covert from Hexadecimal to Hexadecimal*/
void HEX_to_HEX(void);
/******************************************************************************/
 /********************************Global Variables **********************************/
 /*
	 * 
	 * flag_stage : to move from a stage to another based on user selection for converting between different  Number Systems  
	 * x    : to store the type of Number System  that convert from it
	 * y    : to store the type of  Number System  that convert to it
	 * flag_stat :to move from the first use of specific converting function to the second
	 * key  :  for storing keypad value as character
	 * num  :  for storing keypad value as decimal
	 */
 

static u8 flag_stage = 0;
static u8 x = 0;
static u8 y = 0;
static u8 flag_stat = 0;
static u8 key = NO_KEY; 
s32 num = 0;

/**************************************************************************************/

int main(void)
{
   DIO_Init();//Initializing DIO
   LCD_Init();//Initializing LCD  
   LCD_GoTo(0,6);
   LCD_WriteString("Hello");
   _delay_ms(1000);
   LCD_Clear();
    while (1) 
    {
		/*****************************************************************/
		/*Checking of the first selection type of Number System for converting from it */
		if(flag_stage == 0)
		{
			LCD_GoTo(0,0);
			LCD_WriteString("convert from");
			LCD_WriteString("     ");
			LCD_GoTo(1,0);
			
			/*Display on LCD the selections 
			1 for Decimal
			2 for Binary 
			3 for Hexadecimal
			*/
			LCD_WriteString("1D  2B   3H");
			
			/* Getting the current pressed key */
			key = KEYPAD_GetKey();
			
			if(key != NO_KEY)
			{
				/* Checking the value of keypad if from 1 to 3*/
				if(key >= '1' && key <= '3')
				{
					/*Store the first selection*/
					x = key - '0';
					
					/*To move to the second selection type of Number System for converting to it */
					flag_stage = 1;
				}
				
				/*If the user enter wrong value */
				else
				{
					LCD_Clear();
					LCD_GoTo(0,0);
					LCD_WriteString("wrong number !!");
					_delay_ms(1500);
					LCD_Clear();
					flag_stage = 0;
				}
				
			}
			
		}
		
		
		/*****************************************************************/
	   /*Checking of the second selection type of Number System  for converting to it */
		if(flag_stage == 1)
		{
			LCD_GoTo(0,0);
			LCD_WriteString("convert to");
			LCD_WriteString("     ");
			LCD_GoTo(1,0);
			
			/*Display on LCD the selections 
			1 for Decimal
			2 for Binary 
			3 for Hexadecimal
			*/
			LCD_WriteString("1D  2B   3H");
			LCD_WriteString("     ");
			
			/* Getting the current pressed key */
			key = KEYPAD_GetKey();
			if(key != NO_KEY)
			{
				/* Checking the value of keypad if from 1 to 3*/
				if(key >= '1' && key <= '3')
				{
			    	/*Store the second selection*/
					y = key - '0';
					
				/*To move to the third stage that contain the different
				Converting Functions of number systems
				and Execution one of them*/
					flag_stage = 2;
				}
				
				/*If the user enter wrong value */
				else
				{
					LCD_Clear();
					LCD_GoTo(0,0);
					LCD_WriteString("wrong number !!");
					_delay_ms(1500);
					LCD_Clear();
					flag_stage = 0;
				}
				
			}	
		}
/***********************************************************************/

/***********************************************************************/
  /*Checking of the third stage
   that contain Converting Functions of number systems
   and Execution one of them
   */ 
		if(flag_stage == 2)
		{
			
			switch(x)
			{
				case 1:
				switch(y)
				{
					/*Covert from Decimal_to_Decimal*/
					case 1:
					decimal_to_decimal();
					break;
					
					/*Covert from Decimal_to_Binary*/
					case 2:
					decimal_to_binary();
					break;
					
					/*Covert from Decimal_to_Hexadecimal*/
					case 3:
					decimal_to_HEX();
					break;
				}
				break;
				
				case 2:
				switch(y)
				{
					/*Covert from Binary_to_Decimal*/
					case 1:
					binary_to_decimal();
					break;
					
					/*Covert from Binary_to_Binary*/
					case 2:
					binary_to_binary();
					break;
					
					/*Covert from Binary_to_Hexadecimal*/
					case 3:
					binary_to_HEX();
					break;
				}
				break;
				
				case 3:
				{
					switch(y)
					{
						/*Covert from Hexadecimal_to_Decimal*/
						case 1:
						HEX_to_decimal();
						break;
						
						/*Covert from Hexadecimal_to_Binary*/
						case 2:
						HEX_to_binary();
						break;
						
						/*Covert from Hexadecimal_to_Hexadecimal*/
						case 3:
						HEX_to_HEX();
						break;
					}
				}
				break;
				
			}
		}
			
    }
}
/*****************************************************************/


/******************Defintions of converting functions**************/

/*****************************Covert from Decimal_to_Binary**********/
void decimal_to_binary(void)
{
	/*checking the first execution  of the converting function*/
	if(flag_stat == 0)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("D:");
		LCD_WriteString("           ");
		LCD_GoTo(1,0);
		LCD_WriteString("B:");
		LCD_WriteString("             ");
		LCD_GoTo(0,2);
		flag_stat = 1;
	}
	
	/* Getting the current pressed key */
	key = KEYPAD_GetKey();
	if(key != NO_KEY)
	{
		//checking for clearing any values in this location on LCD
		if(flag_stat == 1)
		{
			LCD_GoTo(0,2);
			
			//To clear any values in this location on LCD
			LCD_WriteString("              ");
			LCD_GoTo(0,2);
			
			/*To make the upcoming execution of function is not first one*/
			flag_stat = 2;
		}
		
		//checking if the character between 0 to 9
		if(key >= '0' && key <= '9')
		{
			///display the character on LCD
			LCD_WriteChar(key);
			
			//to store the successive characters as decimal
			num= num * 10 + (key-'0');
		}
		
		//checking if the current pressed key is '=' to convert the value of num
		else if(key == '=')
		{
			LCD_GoTo(1,2);
			
			//convert number to binary and display it on LCD
			LCD_WriteBinary(num);
			
			LCD_WriteString("      ");
			LCD_GoTo(0,2);
			flag_stat = 1;
			num = 0;
			
		}
		//checking if the user wants to select another type of conversion
		else if(key == 'C')
		{
			//to return to selection list
			flag_stage = 0;
			
			//to return to the first use
			flag_stat = 0;
		}
		
		/*If the user enter wrong value */
		else
		{
			LCD_Clear();
			LCD_GoTo(0,0);
			LCD_WriteString("wrong number!!");
			_delay_ms(1500);
			flag_stage = 0;
			flag_stat = 0;
			num = 0;
		}
		
	}
}
/*****************************************************************************/

/****************************Covert from Decimal_to_Decimal**************/
void decimal_to_decimal(void)
{
	/*checking the first execution  of the converting function*/
	if(flag_stat == 0)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("D:");
		LCD_WriteString("           ");
		LCD_GoTo(1,0);
		LCD_WriteString("D:");
		LCD_WriteString("           ");
		LCD_GoTo(0,2);
		flag_stat = 1;
	}
	
	/* Getting the current pressed key */
	key = KEYPAD_GetKey();
	if(key != NO_KEY)
	{
		//checking for clearing any values in this location on LCD 
		if(flag_stat == 1)
		{
			LCD_GoTo(0,2);
			
			//To clear any values in this location on LCD
			LCD_WriteString("              ");
			
			LCD_GoTo(0,2);
			/*To make the upcoming execution of function is not first one*/
			flag_stat = 2;
		}
		//checking if the character between 0 to 9
		if(key >='0' && key <= '9')
		{
			//display the character on LCD
			LCD_WriteChar(key);
			
			//to store the successive characters as decimal
			num = num * 10 + (key-'0');	
		}
		
		//checking if the current pressed key is '=' to convert the value of num
		else if(key == '=')
		{
			LCD_GoTo(1,2);
			
			//convert number to decimal and display it on LCD
			LCD_WriteNumber(num);
			
			LCD_WriteString("      ");
			flag_stat = 1;
			num = 0;
			
		}
		//checking if the user wants to select another type of conversion
		else if(key == 'C')
		{
			//to return to selection list
			flag_stage = 0;
			
			//here return to the first use
			flag_stat = 0;
		}
		
		/*If the user enter wrong value */
		else
		{
			LCD_Clear();
			LCD_GoTo(0,0);
			LCD_WriteString("wrong number!!");
			_delay_ms(1500);
			flag_stage = 0;
			flag_stat = 0;
			num = 0;
		}
	}
}
/********************************************************************************/

/********************************Covert from Decimal_to_HEX*******************/
void decimal_to_HEX(void)
{
	/*checking the first execution  of the converting function*/
	if(flag_stat == 0)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("D:");
		LCD_WriteString("           ");
		LCD_GoTo(1,0);
		LCD_WriteString("H:");
		LCD_WriteString("           ");
		LCD_GoTo(0,2);
		flag_stat = 1;
	}

	/* Getting the current pressed key */
	key = KEYPAD_GetKey();
	if(key != NO_KEY)
	{
		//checking for clearing any values in this location on LCD
		if(flag_stat == 1)
		{
			LCD_GoTo(0,2);
			//To clear any values in this location on LCD
			LCD_WriteString("              ");
			
			LCD_GoTo(0,2);
			/*To make the upcoming execution of function is not first one*/
			flag_stat = 2;
		}
		
		//checking if the character between 0 to 9
		if(key >='0' && key <= '9')
		{
			//display the character on LCD
			LCD_WriteChar(key);
			
			//to store the successive characters as decimal
			num = num * 10 + (key-'0');
		}
		//checking if the current pressed key is '=' to convert the value of num
		else if(key == '=')
		{
			
			LCD_GoTo(1,2);
			//convert number to Hexadecimal and display it on LCD
			LCD_WriteHex(num);
			
			LCD_WriteString("      ");
			flag_stat = 1;
			num = 0;
			
		}
		//checking if the user wants to select another type of conversion
		else if(key == 'C')
		{
			//to return to selection list
			flag_stage = 0;
				
			//here return to the first use
			flag_stat = 0;
		}
		else
		{
			LCD_Clear();
			LCD_GoTo(0,0);
			LCD_WriteString("wrong number!!");
			_delay_ms(1500);
			flag_stage = 0;
			flag_stat = 0;
		}
	}
}
/*****************************************************************************/

/***************************Convert from Binary to Binary*********************************/

void binary_to_binary(void)
{
	/*checking the first execution  of the converting function*/
	if(flag_stat == 0)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("B:");
		LCD_WriteString("           ");
		LCD_GoTo(1,0);
		LCD_WriteString("B:");
		LCD_WriteString("           ");
		LCD_GoTo(0,2);
		flag_stat = 1;
	}
	
    /* Getting the current pressed key */
	key = KEYPAD_GetKey();
	if(key != NO_KEY)
	{
		//checking for clearing any values in this location on LCD
		if(flag_stat == 1)
		{
			LCD_GoTo(0,2);
			//To clear any values in this location on LCD
			LCD_WriteString("              ");
			
			LCD_GoTo(0,2);
			/*To make the upcoming execution of function is not first one*/
			flag_stat = 2;
		}
		
		//checking if the character  0 or 1
		if(key >= '0' && key <= '1')
		{
			//display the character on LCD
			LCD_WriteChar(key);
			
			//to store the successive characters as decimal
			num = num * 2 + (key-'0');
		}
		
		//checking if the current pressed key is '=' to convert the value of num
		else if(key == '=')
		{
			LCD_GoTo(1,2);
			
			//convert number to Binary and display it on LCD
			LCD_WriteBinary(num);
			
			LCD_WriteString("         ");
			flag_stat = 1;
			num = 0;
			
			
		}
		
		//checking if the user wants to select another type of conversion
		else if(key == 'C')
		{
			//to return to selection list
			flag_stage = 0;
			
			//here return to the first use
			flag_stat = 0;
		}
		
		/*If the user enter wrong value */
		else{
			LCD_Clear();
			LCD_GoTo(0,0);
			LCD_WriteString("wrong number!!");
			_delay_ms(1500);
			flag_stage = 0;
			flag_stat = 0;
			num = 0;
		}
	}
}
/***************************************************************************/

/********************************Convert from Binary to Decimal***********/
void binary_to_decimal(void)
{
	/*checking the first execution  of the converting function*/
	if(flag_stat == 0)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("B:");
		LCD_WriteString("           ");
		LCD_GoTo(1,0);
		LCD_WriteString("D:");
		LCD_WriteString("           ");
		LCD_GoTo(0,2);
		flag_stat = 1;
	}
	
    /* Getting the current pressed key */
	key = KEYPAD_GetKey();
	if(key != NO_KEY)
	{
		//checking for clearing any values in this location on LCD
		if(flag_stat == 1)
		{
			LCD_GoTo(0,2);
			//To clear any values in this location on LCD
			LCD_WriteString("              ");
			
			LCD_GoTo(0,2);
			/*To make the upcoming execution of function is not first one*/
			flag_stat = 2;
		}
		
		//checking if the character  0 or 1
		if(key >= '0' && key <= '1')
		{
			//display the character on LCD
			LCD_WriteChar(key);
			
			//to store the successive characters as decimal
			num = num * 2 + (key-'0');
		}
		
		//checking if the current pressed key is '=' to convert the value of num
		else if(key == '=')
		{	
			LCD_GoTo(1,2);
			
			//convert number to Decimal and display it on LCD
			LCD_WriteNumber(num);
			
			LCD_WriteString("         ");
			flag_stat = 1;
			num = 0;
		}
		
		//checking if the user wants to select another type of conversion
		else if(key == 'C')
		{
			//to return to selection list
			flag_stage = 0;
			
			//here return to the first use
			flag_stat = 0;
		}
		
		/*If the user enter wrong value */
		else{
			LCD_Clear();
			LCD_GoTo(0,0);
			LCD_WriteString("wrong number!!");
			_delay_ms(1500);
			flag_stage = 0;
			flag_stat = 0;
			num = 0;
		}
	}
}
/*******************************************************************/

/*************************Convert from Binary to Hexadecimal*********/
void binary_to_HEX(void)
{
	/*checking the first execution  of the converting function*/
	if(flag_stat == 0)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("B:");
		LCD_WriteString("           ");
		LCD_GoTo(1,0);
		LCD_WriteString("H:");
		LCD_WriteString("           ");
		LCD_GoTo(0,2);
		flag_stat = 1;
	}
	
      /* Getting the current pressed key */
	key = KEYPAD_GetKey();
	if(key != NO_KEY)
	{
	   //checking for clearing any values in this location on LCD
	   if(flag_stat == 1)
	   {
		   LCD_GoTo(0,2);
		   //To clear any values in this location on LCD
		  LCD_WriteString("              ");
		
		  LCD_GoTo(0,2);
		  /*To make the upcoming execution of function is not first one*/
		   flag_stat = 2;
	   }
	
	   //checking if the character  0 or 1
		if(key >= '0' && key <= '1')
		{
			//display the character on LCD
			LCD_WriteChar(key);
			
			//to store the successive characters as decimal
			num = num * 2 + (key-'0');
		}
		
		//checking if the current pressed key is '=' to convert the value of num
		else if(key == '=')
		{
			LCD_GoTo(1,2);
			
			//convert number to Hexadecimal and display it on LCD
			LCD_WriteHex(num);
			
			LCD_WriteString("         ");
			flag_stat = 1;
			num = 0;
		}
		
		//checking if the user wants to select another type of conversion
		else if(key == 'C')
		{
			//to return to selection list
			flag_stage = 0;
			
			//here return to the first use
			flag_stat = 0;
		}
		
		/*If the user enter wrong value */
		else{
			LCD_Clear();
			LCD_GoTo(0,0);
			LCD_WriteString("wrong number!!");
			_delay_ms(1500);
			flag_stage = 0;
			flag_stat = 0;
			num = 0;
		}
	}
}
/********************************************************************************/

/*************************Convert from Hexadecimal to Decimal*********/
void HEX_to_decimal(void)
{
	/*checking the first execution  of the converting function*/
	if(flag_stat == 0)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("H:");
		LCD_WriteString("           ");
		LCD_GoTo(1,0);
		LCD_WriteString("D:");
		LCD_WriteString("           ");
		LCD_GoTo(0,2);
		flag_stat = 1;
	}
	
    /* Getting the current pressed key */
	key = KEYPAD_GetKey();
	if(key != NO_KEY)
	{
		//checking for clearing any values in this location on LCD
		if(flag_stat == 1)
		{
			LCD_GoTo(0,2);
			//To clear any values in this location on LCD
			LCD_WriteString("              ");
			
			LCD_GoTo(0,2);
			/*To make the upcoming execution of function is not first one*/
			flag_stat = 2;
		}
		
		//checking if the character  0 to 9 or a to f
		if(key >= '0' && key <= '9' || key >= 'a' && key <= 'f')
		{
			//display the character on LCD
			LCD_WriteChar(key);
			
			if( key >= '0' && key <= '9')
			{
				//to store the successive characters as decimal
				num = num * 16 + (key-'0');
			}
			if (key >= 'a' && key <= 'f')
			{
				//to store the successive characters as decimal
				num = num * 16 + ((key-97) + 10);
			}
		}
		
		//checking if the current pressed key is '=' to convert the value of num
		else if(key == '=')
		{
			LCD_GoTo(1,2);
			
			//convert number to decimal and display it on LCD
			LCD_WriteNumber(num);
			
			LCD_WriteString("         ");
			flag_stat = 1;
			num = 0;
			
		}
		
		//checking if the user wants to select another type of conversion
		else if(key == 'C')
		{
			//to return to selection list
			flag_stage = 0;
			
			//here return to the first use
			flag_stat = 0;
		}
		
		/*If the user enter wrong value */
		else
		{
			LCD_Clear();
			LCD_GoTo(0,0);
			LCD_WriteString("wrong number!!");
			_delay_ms(1500);
			flag_stage = 0;
			flag_stat = 0;
			num = 0;
		}
	}
	
}
/********************************************************************************/

/*************************Convert from Hexadecimal to Binary*********/

void HEX_to_binary(void)
{
	/*checking the first execution  of the converting function*/
	if(flag_stat == 0)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("H:");
		LCD_WriteString("           ");
		LCD_GoTo(1,0);
		LCD_WriteString("B:");
		LCD_WriteString("           ");
		LCD_GoTo(0,2);
		flag_stat = 1;
	}
	
    /* Getting the current pressed key */
	key = KEYPAD_GetKey();
	if(key != NO_KEY)
	{
		//checking for clearing any values in this location on LCD
		if(flag_stat == 1)
		{
			LCD_GoTo(0,2);
			//To clear any values in this location on LCD
			LCD_WriteString("              ");
			
			LCD_GoTo(0,2);
			/*To make the upcoming execution of function is not first one*/
			flag_stat = 2;
		}
		
		//checking if the character  0 to 9 or a to f
		if(key >= '0' && key <= '9' || key >= 'a' && key <= 'f')
		{
			//display the character on LCD
			LCD_WriteChar(key);
			
		   if( key >= '0' && key <= '9')
		   {
			    //to store the successive characters as decimal
			    num = num * 16 + (key-'0');
		   }
		   if (key >= 'a' && key <= 'f')
		   {
			   //to store the successive characters as decimal
		 	   num = num * 16 + ((key-97) + 10);
		   }
		}
		
		//checking if the current pressed key is '=' to convert the value of num
		else if(key == '=')
		{
			LCD_GoTo(1,2);
			
			//convert number to Binary and display it on LCD
			LCD_WriteBinary(num);
			
			LCD_WriteString("         ");
			flag_stat = 1;
			num = 0;
		}
		
		//checking if the user wants to select another type of conversion
		else if(key == 'C')
		{
			//to return to selection list
			flag_stage = 0;
			
			//here return to the first use
			flag_stat = 0;
		}
		
		/*If the user enter wrong value */
		else
		{
			LCD_Clear();
			LCD_GoTo(0,0);
			LCD_WriteString("wrong number!!");
			_delay_ms(1500);
			flag_stage = 0;
			flag_stat = 0;
			num = 0;
		}
	}
	
}
/********************************************************************************/

/*************************Convert from Hexadecimal to  Hexadecimal*********/

void HEX_to_HEX(void)
{
	/*checking the first execution  of the converting function*/
	if(flag_stat == 0)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("H:");
		LCD_WriteString("           ");
		LCD_GoTo(1,0);
		LCD_WriteString("H:");
		LCD_WriteString("           ");
		LCD_GoTo(0,2);
		flag_stat = 1;
	}
	
   /* Getting the current pressed key */
	key = KEYPAD_GetKey();
	if(key != NO_KEY)
	{
		//checking for clearing any values in this location on LCD
		if(flag_stat == 1)
		{
			LCD_GoTo(0,2);
			//To clear any values in this location on LCD
			LCD_WriteString("              ");
			
			LCD_GoTo(0,2);
			/*To make the upcoming execution of function is not first one*/
			flag_stat = 2;
		}
		
		//checking if the character  0 to 9 or a to f
		if(key >= '0' && key <= '9' || key >= 'a' && key <= 'f')
		{
			//display the character on LCD
			LCD_WriteChar(key);
			
			if(key >= '0' && key <= '9')
			{
				//to store the successive characters as decimal
				num = num * 16 + (key-'0');
			}
			if (key >= 'a' && key <= 'f')
			{
				//to store the successive characters as decimal
				num = num * 16 +((key-97) + 10);
			}
		}
		
		//checking if the current pressed key is '=' to convert the value of num
		else if(key == '=')
		{
			LCD_GoTo(1,2);
			//convert number to Hexadecimal and display it on LCD
			LCD_WriteHex(num);
			
			LCD_WriteString("         ");
			flag_stat = 1;
			num = 0;	
		}
		
		//checking if the user wants to select another type of conversion
		else if(key == 'C')
		{
			//to return to selection list
			flag_stage = 0;
			
			//here return to the first use
			flag_stat = 0;
		}
		
		/*If the user enter wrong value */
		else{
			LCD_Clear();
			LCD_GoTo(0,0);
			LCD_WriteString("wrong number!!");
			_delay_ms(1500);
			flag_stage = 0;
			flag_stat = 0;
			num = 0;
		}
	}
	
}