/******************************************************************************
 *
 * Module: DIO_PRIVATE
 *
 * Description: Header file of DIO driver for AVR
 *
 *******************************************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

//array by Const values to each pin for adjust the desired direction
extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];

 //initialize the direction (output or input or input pull)
static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status );



#endif /* DIO_PRIVATE_H_ */