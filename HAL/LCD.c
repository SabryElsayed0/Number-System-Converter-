/******************************************************************************
 *
 * Module: LCD
 *
 * Description: Source file of KEYPAD driver for AVR
 *
 *******************************************************************************/
#include "LCD.h"

/*****************************************************************************/
/*checking if we use 8 bit with LCD*/
#if LCD_MODE == _8_BIT

/*this function to transmit command to LCD*/
static void LCD_WriteCommand(u8 command)
{
	// to transmit command we should make pin0=0
	DIO_WritePin(RS,LOW);
	
	DIO_WritePORT(LCD_PORT,command);
	
	//trigger rising edge
	DIO_WritePin(EN,HIGH);
	
	//trigger time between rising and falling
	_delay_ms(1);             
	
	//trigger falling edge
	DIO_WritePin(EN,LOW);  
	_delay_ms(1);
	
}
/**************************************************************************/

/*****************************************************************************/
/*to transmit data to LCD */
static void LCD_WriteData(u8 data)
{
	// to transmit data we should make pin0=0
	DIO_WritePin(RS,HIGH); 
	
	DIO_WritePORT(LCD_PORT,data);
	//trigger rising edge
	DIO_WritePin(EN,HIGH);
	
	//trigger time between rising and falling
	_delay_ms(1);     
	
	//trigger falling edge        
	DIO_WritePin(EN,LOW);  
	_delay_ms(1);
	
}
/************************************************************************/

/**********************************************************************/
/*to initialize LCD */
void LCD_Init(void)
{
	_delay_ms(50);
	//2 line 5*7;
	LCD_WriteCommand(0x38); 
	
	//cursor 0x0f, 0x0E ;
	LCD_WriteCommand(0x0c); 
	
	//clear screen; 
	LCD_WriteCommand(0x01); 
	_delay_ms(1);
	
	//increase ddram address,no shift;
	LCD_WriteCommand(0x06); 
	
	
	
}
/*******************************************************************/
/*checking if we use 8 bit with LCD*/
#elif LCD_MODE==_4_BIT

/*this function to transmit command to LCD*/
static void LCD_WriteCommand(u8 command)
{
	// to transmit command we should make pin0=0
	DIO_WritePin(RS,LOW); 
	DIO_WritePin(D7,READ_BIT(command,7));
	DIO_WritePin(D6,READ_BIT(command,6));
	DIO_WritePin(D5,READ_BIT(command,5));
	DIO_WritePin(D4,READ_BIT(command,4));
	//trigger rising edge
	DIO_WritePin(EN,HIGH);
	
	//trigger time between rising and falling
	_delay_ms(1);   
	
	//trigger falling edge          
	DIO_WritePin(EN,LOW);  
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(command,3));
	DIO_WritePin(D6,READ_BIT(command,2));
	DIO_WritePin(D5,READ_BIT(command,1));
	DIO_WritePin(D4,READ_BIT(command,0));
	//trigger rising edge
	DIO_WritePin(EN,HIGH);
	
	//trigger time between rising and falling
	_delay_ms(1);   
	
	//trigger falling edge          
	DIO_WritePin(EN,LOW);  
	_delay_ms(1);
}
/********************************************************************************/

/*******************************************************************************/
/*to transmit data to LCD */
static void LCD_WriteData(u8 data)
{
	 // to transmit data we should make pin0=0
	DIO_WritePin(RS,HIGH); 
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	//trigger rising edge
	DIO_WritePin(EN,HIGH);
	
	//trigger time between rising and falling
	_delay_ms(1);    
	
	//trigger falling edge         
	DIO_WritePin(EN,LOW);  
	
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	
	//trigger rising edge
	DIO_WritePin(EN,HIGH);
	
	//trigger time between rising and falling
	_delay_ms(1);   
	  
	//trigger falling edge        
	DIO_WritePin(EN,LOW);  
	_delay_ms(1);
	
}
/*******************************************************************/

/******************************************************************/
/*to initialize LCD */
void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	//2 line 5*7;
	LCD_WriteCommand(0x28); 
	
	//cursor 0x0f, 0x0E ;
	LCD_WriteCommand(0x0c);  
	
	//clear screen;
	LCD_WriteCommand(0x01); 
	_delay_ms(1);
	
	//increase ddram address,no shift;
	LCD_WriteCommand(0x06); 
	
	
	/*******************************************************************/
}
#endif
/*****************************************************************************/

//to WriteChar on LCD 
void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}

//to Write String on LCD 
void LCD_WriteString(u8*str)
{
	u8 i;
	
	//loop to transmit character by character of string
	for(i=0;str[i];i++)
	{
		LCD_WriteData(str[i]);
		
	}
}

//to Write Number on LCD 
void LCD_WriteNumber(s32 num)//2503
{
	u8 str[20];
	u8 rem,i=0;
	if(num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if(num<0)
	{
		num=num*-1;
		LCD_WriteChar('-');
	}
	
	//to convert each digit in  number  to character and store it in array of character
	while(num>0)
	{
		rem = num % 10;
		str[i] = rem + '0';
		num= num / 10;
		i++;
	}
	
	//loop to transmit each character in array to LCD
	for(s8 j = i - 1 ; j >= 0 ; j--)
	{
		LCD_WriteChar(str[j]);
	}
	
}

//to Write Binary on LCD 
void LCD_WriteBinary(u8 num)//
{
	s8 i,flag = 0;
	
	//Loop to check if each bit in the number is equal to 1 or 0 
	for(i = 7 ; i >= 0 ; i--)
	{
		if(num >> i & 1)
		{
			LCD_WriteChar('1');
			flag = 1;
		}
		else{
			if(flag == 1)
			{
				LCD_WriteChar('0');
			}
			
		}
	}
}

//To set cursor at specific position
void LCD_GoTo(u8 line,u8 cell)
{
	if(line==0)
	{
		LCD_WriteCommand(0x80|cell);
	}
	else if(line==1)
	{
		LCD_WriteCommand(0x80+0x40+cell);

	}
}

//To clear any data on LCD
void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}

//to write Hexadecimal on LCD
void LCD_WriteHex(u8 num)// 0xfe
{
	//u8 HexArray[]={'0','1','2','3'}
		
	//store High nibble of num 	
	u8 Hnibble = num >> 4;//0f
	
	//store LOW nibble of num
	u8 Lnibble = num & 0x0f;//0e
	
	if(Hnibble <= 9)
	{
		LCD_WriteChar(Hnibble+'0');
	}
	else 
	{
		LCD_WriteChar(Hnibble-10+'A');
		
	}
	if(Lnibble <= 9)
	{
		LCD_WriteChar(Lnibble+'0');
	}
	else {
		LCD_WriteChar(Lnibble-10+'A');
		
	}
	
	//LCD_WriteChar(HexArray[Lnibble]);
}
