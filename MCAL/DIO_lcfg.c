/******************************************************************************
 *
 * Module: DIO_interface
 *
 * Description: Header file of DIO driver for AVR
 *
 *******************************************************************************/

#include "DIO_interface.h"

/********************************************************************************/
//array by Const values to each pin for adjust the desired direction 
const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS]={
	INFREE,    /*Port A Pin 0 ADC0*/
	OUTPUT,    /*Port A Pin 1 ADC1*/
	OUTPUT,    /*Port A Pin 2 */
	OUTPUT,     /*Port A Pin 3*/
	OUTPUT,    /*Port A Pin 4*/
	OUTPUT,    /*Port A Pin 5*/
	OUTPUT,    /*Port A Pin 6*/
	INFREE,    /*Port A Pin 7 ADC7*/
	OUTPUT,    /*Port B Pin 0 */
	OUTPUT,    /*Port B Pin 1 */
	OUTPUT,    /*Port B Pin 2 /INIT2 */
	OUTPUT ,     /*Port B Pin 3 */
	OUTPUT,     /*Port B Pin 4/ss* */
	OUTPUT ,     /*Port B Pin 5//mosi */
	OUTPUT,     /*Port B Pin 6 */
	OUTPUT,     /*Port B Pin 7 */
	OUTPUT,     /*Port c Pin 0 */
	OUTPUT,     /*Port c Pin 1 */
	OUTPUT,     /*Port c Pin 2 */
	OUTPUT ,     /*Port c Pin 3 */
	OUTPUT,     /*Port c Pin 4 */
	OUTPUT,     /*Port c Pin 5 */
	OUTPUT,     /*Port c Pin 6 */
	OUTPUT,     /*Port c Pin 7 */
	INPULL,     /*Port D Pin 0 */
	INPULL,     /*Port D Pin 1 */
	INPULL,     /*Port D Pin 2/INIT0 */
	INPULL ,      /*Port D Pin 3/INT1 */
	INPULL,       /*Port D Pin 4 OC1B */
	INPULL,      /*Port D Pin 5 OC1A */
	OUTPUT,      /*Port D Pin 6/ICP */
	OUTPUT,      /*Port D Pin 7 */
	
	
	
};