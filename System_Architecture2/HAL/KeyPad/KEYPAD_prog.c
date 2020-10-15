/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 26-1-2018             */
/*VERSION : V01                */
/*******************************/
#include "STD_TYPES"
#include "DIO_int.h"






/****************************************/
/*    Return the status of the keypad   */
/*      in a variable of 16 bit length  */
/****************************************/

extern u16 KEYPAD_u16GetKpStatus(void){
	
	u16 Local_u16Result = 0;
	
	DIO_u8SetPinValue(KEYPAD_u8_OUTPUT_5,DIO_u8_LOW);
	DIO_u8SetPinValue(KEYPAD_u8_OUTPUT_6,DIO_u8_HIGH);
	DIO_u8SetPinValue(KEYPAD_u8_OUTPUT_7,DIO_u8_HIGH);
	DIO_u8SetPinValue(KEYPAD_u8_OUTPUT_8,DIO_u8_HIGH);

	if(DIO_u8GetPinValue(KEYPAD_u8_INPUT_1)==DIO_u8_LOW){
		SET_BIT(Local_u16Result,0);
	
	}
	else{
	CLR_BIT(Local_u16Result,0);	
	}