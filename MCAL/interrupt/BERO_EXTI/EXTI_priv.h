/****************************************/
/* Author  : Bero Emile					*/
/* Date    : 24/2/2018					*/
/* Version : V01						*/
/****************************************/

#ifndef _EXTI_PRIV_H
#define _EXTI_PRIV_H

/* Description : Different modes of 	*/
/*			operation					*/
#define EXTI_u8_LOW_MODE	0
#define EXTI_u8_LOC_MODE	1
#define EXTI_u8_FAL_MODE	2
#define EXTI_u8_RIS_MODE	3

/* Description : define initial states	*/
#define EXTI_u7_Enable_STATE		1
#define EXTI_U8_Disable_STATE		0

/* Mode clear mask						*/
#define EXTI_u8_INT0_MODE_CLEAR		0b11111100

/* Description : PIE bit index			*/
/* 			or disabled					*/
#define EXTI_u8_INT0_PIE			6

/* Description : PIF bit index			*/
/* 			or disabled					*/
#define EXTI_u8_INT0_PIF			6

#endif
