/******************************************************************************
 *
 * Module: DIO
 *
 * Description: Header file of DIO driver for AVR
 *
 *******************************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "MeMmap.h"
#include "STDTYPES.h"
#include "UTILS.h"

/*******************************enum for port_number******************************/
typedef enum{
	PA=0,
	PB,
	PC,
	PD
}DOI_Port_type;
/***********************************************************************************/

/*******************************enum for direction of pin***************************/
typedef enum{
	OUTPUT,
	INFREE,
	INPULL,
}DIO_PinStatus_type;
/**********************************************************************************/

/****************************enum for volt*************************************************/
typedef enum{
	LOW,
	HIGH
}DIO_PinVoltage_type;
/***********************************************************************************/

/**********************************enum for all pins in different port*********************/

typedef enum
{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_type;

//initialize the direction (output or input or input pull)
extern void DIO_Init(void) ;

// Give a value for pins as HIGH or LOW
extern void DIO_WritePin(DIO_Pin_type pin, DIO_PinVoltage_type Volt );
// to read pin if HIGH or LOW
extern   DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin );

 // to toggle pin
void DIO_WritePORT(DOI_Port_type port, u8 value );














#endif /* DIO_INTERFACE_H_ */