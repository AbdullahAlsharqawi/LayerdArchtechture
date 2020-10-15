/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 26-1-2018             */
/*VERSION : V01                */
/*******************************/
#include "STD_TYPES"
#include "DIO_int.h"
#include "LED_priv_TYPES"
#include "c_TYPES"
#include "i_TYPES"
#include "i_TYPES"



/****************************************/
/*This function shall set LED on        */
/****************************************/
void LED_voidSetLedOn(void){
	if(LED_u8_MODE == LED_u8_NORMAL)
	{
		DIO_voidSetPinValue(LED_u8_DIO_PIN,DIO_u8_HIGH);
	}
	else{
		DIO_voidSetPinValue(LED_u8_DIO_PIN,DIO_u8_LOW);
	}
}

/****************************************/
/*This function shall set LED off       */
/****************************************/
void LED_voidSetLedOff(void){
	if(LED_u8_MODE == LED_u8_NORMAL)
	{
		DIO_voidSetPinValue(LED_u8_DIO_PIN,DIO_u8_LOW);
	}
	else{
		DIO_voidSetPinValue(LED_u8_DIO_PIN,DIO_u8_HIGH);
	}
}

