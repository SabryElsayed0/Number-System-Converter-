/******************************************************************************
 *
 * Module: DIO
 *
 * Description: Source file of DIO driver for AVR
 *
 *******************************************************************************/

 #include "DIO_interface.h"
 #include "DIO_private.h"
 

/*************************Functions Definitions***********************************/

 //initialize the direction (output or input or input pull)
 static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status )
 {
	 //To calculate the number of PORT
     DOI_Port_type port = pin / 8;
	 
	 //To calculate the number of PIN
     u8 pin_num = pin % 8;
	
	switch(status)
	{
	/**first check the desired direction of pin 
	   second check the port of pin 
	   third adjust DDR and PORT Registers 
	    by value that match with the desired direction*/
	                                                                                                                                                               
			case OUTPUT:
			switch(port)
			{
				case PA:
				SET_BIT(DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				SET_BIT(DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
				SET_BIT(DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:
				SET_BIT(DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
			}
			break;
			case INFREE:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				CLR_BIT(DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
				CLR_BIT(DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:
				CLR_BIT(DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
			}
			break;
			case INPULL:
			
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				SET_BIT(PORTA,pin_num);
				break;
				case PB:
				CLR_BIT(DDRB,pin_num);
				SET_BIT(PORTB,pin_num);
				break;
				case PC:
				CLR_BIT(DDRC,pin_num);
				SET_BIT(PORTC,pin_num);
				break;
				case PD:
				CLR_BIT(DDRD,pin_num);
				SET_BIT(PORTD,pin_num);
				break;
			}
			break;
	}
		
	}
    
/*************************************************************************/	
  //DIO write (write HIGH or LOW)
	void DIO_WritePin(DIO_Pin_type pin, DIO_PinVoltage_type Volt )
	{
		 //To calculate the number of PORT
           DOI_Port_type port = pin / 8;
	 
	    //To calculate the number of PIN
           u8 pin_num = pin % 8;
	 
	 
		
		if(Volt == HIGH)
		{
		/**first check the desired volt  
           second check the port of pin 
	       third adjust  PORT Registers 
	       by value that match with the desired volt*/
			switch(port)
			{
				case PA:
				SET_BIT(PORTA,pin_num);
				break;
				case PB:
				SET_BIT(PORTB,pin_num);
				break;
				case PC:
				SET_BIT(PORTC,pin_num);
				break;
				case PD:
				SET_BIT(PORTD,pin_num);
				break;
			}
		}
		else if(Volt == LOW)
		{
			switch(port)
			{
				case PA:
			
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
			
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:
			
				CLR_BIT(PORTD,pin_num);
				break;
			}
			}
		}
/*********************************************************************/		
 /*To initialize all PINS based on the desired direction 
 value on PinsStatusArray Array that in "DIO_interface.h"*/ 
 
	void DIO_Init(void)
	{
		DIO_Pin_type i;
		for(i=PINA0 ; i < TOTAL_PINS ; i++)
		{
			DIO_InitPin(i,PinsStatusArray[i]);
		}
	}
	
/*************************************************************************/	
	//DIO write (write HIGH or LOW) for all desired Port
	void DIO_WritePORT(DOI_Port_type port, u8 value )
	{
		/**first check the desired PORT    
	       second out the desired volt on PORT 
	       third adjust  PORT Registers 
	        by value that match with the desired volt*/
		
		switch(port)
		{
			case PA:
			PORTA=value;
			break;
			case PB:
			PORTB=value;
			break;
			case PC:
            PORTC=value;		 
			break;
			case PD:
			PORTD=value;
			break;
		}
	}
/*************************************************************************/		
// To read the status of any Pin in any Port
 DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin )
 {
	 
	      //To calculate the number of PORT
           DOI_Port_type port = pin / 8;
	 
	      //To calculate the number of PIN
           u8 pin_num = pin % 8;
		   
		  //local variable to return the value of volt on a pin 
	     DIO_PinVoltage_type  volt = LOW;
		 
	 switch(port)
	 {
		  /**first check the desired pin  
	         second check the port of pin 
	         third Read the status of pin in PIN Register  
	         **/
		  
		 case PA:
		 volt=READ_BIT(PINA,pin_num);
		 break;
		 case PB:
		 
		 volt=READ_BIT(PINB,pin_num);
		 break;
		 case PC:
		 
		 volt=READ_BIT(PINC,pin_num);
		 break;
		 case PD:
		 
		 volt=READ_BIT(PIND,pin_num);
		 break;
	 }
	 return volt;
 }
                                                                 