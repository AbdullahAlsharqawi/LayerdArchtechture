/********************************************************************/
/*	Name: Ahmed El-Shinnawi											*/
/*	Date: 13 March 2018												*/
/*	Version: V01													*/
/********************************************************************/


#ifndef _ADJ_H
#define _ADJ_H


/********************************************/
/*Description: This task shall Initialize 	*/
/*			   "ADJ" application			*/
/********************************************/
extern void ADJ_voidInitialize(void);

/********************************************/
/*Description: This task shall select the 	*/
/*			   "hh/mm/ss" to be displayed	*/
/********************************************/
extern void ADJ_voidTimeDispTASK(void);

/********************************************/
/*Description: This task shall clear the 	*/
/*			   hh/mm/ss						*/
/********************************************/
extern void ADJ_voidClrDispTASK(void);

/********************************************/
/*Description: This task shall display the 	*/
/*			   the pressed number on keypad	*/
/********************************************/
extern void ADJ_voidNumbersTASK(void);

/********************************************/
/*Description: This task shall increment 	*/
/* 			   the time on display			*/
/********************************************/
extern void ADJ_voidIncTASK(void);

/********************************************/
/*Description: This task shall display the 	*/
/*			   selected number or time on	*/
/*			   the 7-segment display		*/
/********************************************/
extern void ADJ_voidDisplayTASK(void);

#endif
