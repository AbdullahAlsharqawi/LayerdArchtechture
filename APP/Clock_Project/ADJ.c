/********************************************************************/
/*	Name: Ahmed El-Shinnawi											*/
/*	Date: 13 March 2018												*/
/*	Version: V01													*/
/********************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include"KEYPAD.h"
#include"SEG.h"
#include"Clock.h"

/* Comment: This variable shall hold the number that will be displayed on the 7-segment	*/
static u8 Local_u8ValueKP=0;
/* Comment: This variable shall hold the readings of the keypad							*/
static u16 KP_Readings = 0;
/* Comment: This flag shall determine what is on display								*/
static bool PositionFlag=0;
/* Comment: This Flag shall take reading from clock for "ADJ" application				*/
static CLK_time_t Local_Time;


/********************************************/
/*Description: This task shall Initialize 	*/
/*			   "ADJ" application			*/
/********************************************/
extern void ADJ_voidInitialize(void)
{

}

/********************************************/
/*Description: This task shall select the 	*/
/*			   "hh/mm/ss" to be displayed	*/
/********************************************/
extern void ADJ_voidTimeDispTASK(void)
{
	/* Comment : Read the keypad value and store it in					*/
	/* 			 Global Variable										*/
	KP_Readings=KEYPAD_u16GetKpStatus();

	/* Comment : Read the keypad value and store it in					*/
	/* 			 Global Variable										*/
	KP_Readings=KEYPAD_u16GetKpStatus();

	/* Comment : Read the time at the current moment and 				*/
	/*			 store it in Global variable							*/
	Clk_voidGetTime(&Local_Time);
	/* Comment : If 'A' is pressed take Hours reading and present it	*/
	if(GETBIT(KP_Readings,11) || 6==PositionFlag)
	{
		PositionFlag=6;
		Local_u8ValueKP=Local_Time.u8Hours;
	}
	/* Comment : If 'B' is pressed take Minutes reading and present it	*/
	else if(GETBIT(KP_Readings,7) || 5==PositionFlag)
	{
		PositionFlag=5;
		Local_u8ValueKP=Local_Time.u8Minutes;
	}
	/* Comment : If 'C' is pressed take Seconds reading and present it	*/
	else if(GETBIT(KP_Readings,3) || 4==PositionFlag)
	{
		PositionFlag=4;
		Local_u8ValueKP=Local_Time.u8Seconds;
	}
	else
	{}
}

/********************************************/
/*Description: This task shall clear the 	*/
/*			   hh/mm/ss						*/
/********************************************/
extern void ADJ_voidClrDispTASK(void)
{
	/* Comment : Read the keypad value and store it in					*/
	/* 			 Global Variable										*/
	KP_Readings=KEYPAD_u16GetKpStatus();

	/* Reset the HH/MM/SS to zero			*/
	if(GETBIT(KP_Readings,15))
	{
		CLK_voidSetHr(0);
		CLK_voidSetMin(0);
		CLK_voidSetSec(0);
	}
}

/********************************************/
/*Description: This task shall display the 	*/
/*			   the pressed number on keypad	*/
/********************************************/
extern void ADJ_voidNumbersTASK(void)
{
	if(GETBIT(KP_Readings,0))
	{
		PositionFlag=1;
		Local_u8ValueKP=1;
	}
	else if(GETBIT(KP_Readings,1))
	{
		PositionFlag=1;
		Local_u8ValueKP=2;
	}
	else if(GETBIT(KP_Readings,2))
	{
		PositionFlag=1;
		Local_u8ValueKP=3;
	}
	else if(GETBIT(KP_Readings,4))
	{
		PositionFlag=1;
		Local_u8ValueKP=4;
	}
	else if(GETBIT(KP_Readings,5))
	{
		PositionFlag=1;
		Local_u8ValueKP=5;
	}
	else if(GETBIT(KP_Readings,6))
	{
		PositionFlag=1;
		Local_u8ValueKP=6;
	}
	else if(GETBIT(KP_Readings,8))
	{
		PositionFlag=1;
		Local_u8ValueKP=7;
	}
	else if(GETBIT(KP_Readings,9))
	{
		PositionFlag=1;
		Local_u8ValueKP=8;
	}
	else if(GETBIT(KP_Readings,10))
	{
		PositionFlag=1;
		Local_u8ValueKP=9;
	}
	else if(GETBIT(KP_Readings,13))
	{
		PositionFlag=1;
		Local_u8ValueKP=0;
	}
	else
	{}
}

/********************************************/
/*Description: This task shall increment 	*/
/* 			   the time on display			*/
/********************************************/
extern void ADJ_voidIncTASK(void)
{
	/* Comment : Read the keypad value and store it in					*/
	/* 			 Global Variable										*/
	KP_Readings=KEYPAD_u16GetKpStatus();

	/* Comment : If 'D' is pressed, check the dispaly and increment it		*/
	if(GETBIT(KP_Readings,14))
	{
		/* Comment : Check if Hours is on display, if so increment Hours	*/
		if(6 == PositionFlag)
		{
			CLK_voidSetHr((Local_Time.u8Hours + 1));
		}
		/* Comment : Check if Minutes is on display, if so increment Minutes*/
		else if(5 == PositionFlag)
		{
			CLK_voidSetMin((Local_Time.u8Minutes + 1));
		}
		/* Comment : Check if Seconds is on display, if so increment Seconds*/
		else if(4 == PositionFlag)
		{
			CLK_voidSetSec((Local_Time.u8Seconds + 1));
		}
		else
		{}
	}
}

/********************************************/
/*Description: This task shall display the 	*/
/*			   selected number or time on	*/
/*			   the 7-segment display		*/
/********************************************/
extern void ADJ_voidDisplayTASK(void)
{
	static bool SelectFlag=0;
	if(SelectFlag==0)
	{
		SelectFlag=1;
		DIO_voidSetPinValue(DIO_u8_PIN_20,DIO_u8_LOW);
		SEG_voidPrintNumber(Local_u8ValueKP/10);
		DIO_voidSetPinValue(DIO_u8_PIN_19,DIO_u8_HIGH);
	}
	else
	{
		SelectFlag=0;
		DIO_voidSetPinValue(DIO_u8_PIN_19,DIO_u8_LOW);
		SEG_voidPrintNumber(Local_u8ValueKP%10);
		DIO_voidSetPinValue(DIO_u8_PIN_20,DIO_u8_HIGH);
	}
}
