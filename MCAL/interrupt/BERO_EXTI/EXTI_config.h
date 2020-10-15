/****************************************/
/* Author  : Bero Emile					*/
/* Date    : 24/2/2018					*/
/* Version : V01						*/
/****************************************/

#ifndef _EXTI_CONFIG_H
#define _EXTI_CONFIG_H

/* Description : External INT0 mode		*/
/* Options 	   :	EXTI_u8_LOW_MODE	*/
/*					EXTI_u8_LOC_MODE	*/
/*					EXTI_u8_FAL_MODE	*/
/*					EXTI_u8_RIS_MODE	*/

#define EXTI_u8_INT0_MODE			EXTI_u8_LOC_MODE

/* Description : Interrupt 0 state		*/
/* Options	   : EXTI_u7_Enable_STATE	*/
/*				 EXTI_U8_Disable_STATE	*/
#define EXTI_u8_INT0_INIT_STATE		 EXTI_U8_Disable_STATE

#endif
