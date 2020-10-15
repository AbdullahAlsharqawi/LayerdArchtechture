/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 6-2-2018             */
/*VERSION : V01                */
/*******************************/


#include "STD_TYPES"
#include "DIO_int.h"
#include "BIT_MATH.h"

#include "Delay.h"

#include "LCD_config.h"
#include "LCD_priv.h"
#include "LCD_int.h"


extern void LCD_voidInitialize(void){
	/*wait more thn 30 ms*/
	delay(35);
	/*write function set command*/
	LCD_voidWriteCmd(0b00111000);
	/*wait for 1 ms*/
     delay(1);
	/*write display on/off command*/
     LCD_voidWriteCmd(0b00001100);
     /*wait for 1 ms*/
     delay(1);
	/*write display clear command*/
     LCD_voidWriteCmd(0b00000001);
     delay(2);
}


extern void LCD_voidWriteData(u8 Copy_u8Data){   /*i want it to be seen out of this file*/
	/*RS = 1*/
	DIO_voidSetPinValue(LCD_u8_RS_PIN,DIO_u8_HIGH);
   /*execute the Data*/
    voidExecute(u8 Copy_u8Value);
}

extern void LCD_voidWriteCmd(u8 Copy_u8Cmd){
	/*RS = 0*/
	DIO_voidSetPinValue(LCD_u8_RS_PIN,DIO_u8_LOW);
    /*execute the command*/
    voidExecute(u8 Copy_u8Value);
}

static void voidExecute(u8 Copy_u8Value){  /*i want this function to be unseen out of its file*/
	/*RW = 0*/
DIO_voidSetPinValue(LCD_u8_RW_PIN,DIO_u8_LOW);
	/*Data bus of LCD = Copy_u8Cmd*/
 if (GETBIT(Copy_u8Value,0))
 {
 	DIO_voidSetPinValue(LCD_u8_DATA_P0,DIO_u8_HIGH);
 }
 else {
 	DIO_voidSetPinValue(LCD_u8_DATA_P0,DIO_u8_LOW);
 }

  if (GETBIT(Copy_u8Value,1))
 {
 	DIO_voidSetPinValue(LCD_u8_DATA_P1,DIO_u8_HIGH);
 }
 else {
 	DIO_voidSetPinValue(LCD_u8_DATA_P1,DIO_u8_LOW);
 }

  if (GETBIT(Copy_u8Value,2))
 {
 	DIO_voidSetPinValue(LCD_u8_DATA_P2,DIO_u8_HIGH);
 }
 else {
 	DIO_voidSetPinValue(LCD_u8_DATA_P2,DIO_u8_LOW);
 }

  if (GETBIT(Copy_u8Value,3))
 {
 	DIO_voidSetPinValue(LCD_u8_DATA_P3,DIO_u8_HIGH);
 }
 else {
 	DIO_voidSetPinValue(LCD_u8_DATA_P3,DIO_u8_LOW);
 }

  if (GETBIT(Copy_u8Value,4))
 {
 	DIO_voidSetPinValue(LCD_u8_DATA_P4,DIO_u8_HIGH);
 }
 else {
 	DIO_voidSetPinValue(LCD_u8_DATA_P4,DIO_u8_LOW);
 }

  if (GETBIT(Copy_u8Value,5))
 {
 	DIO_voidSetPinValue(LCD_u8_DATA_P5,DIO_u8_HIGH);
 }
 else {
 	DIO_voidSetPinValue(LCD_u8_DATA_P5,DIO_u8_LOW);
 }

  if (GETBIT(Copy_u8Value,6))
 {
 	DIO_voidSetPinValue(LCD_u8_DATA_P6,DIO_u8_HIGH);
 }
 else {
 	DIO_voidSetPinValue(LCD_u8_DATA_P6,DIO_u8_LOW);

 }


  if (GETBIT(Copy_u8Value,7))
 {
 	DIO_voidSetPinValue(LCD_u8_DATA_P7,DIO_u8_HIGH);
 }
 else {
 	DIO_voidSetPinValue(LCD_u8_DATA_P7,DIO_u8_LOW);
 }

	/*E = 1*/
 	DIO_voidSetPinValue(LCD_u8_E_PIN,DIO_u8_HIGH);
	/*delay 1 ms */
 		delay();

	/*E = 0*/
 		DIO_voidSetPinValue(LCD_u8_E_PIN,DIO_u8_LOW);

	/*delay 1 ms */
 		delay();
}