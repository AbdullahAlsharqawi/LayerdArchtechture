/********************************************/
/* Author  : Bero Emile			    		*/
/* Date    : 24/2/2018				    	*/
/* Version : V01						    */
/********************************************/

#ifndef _EXTI_INT_H
#define _EXTI_INT_H

/* Description : Initialize the EXTI mode	*/
void EXTI_voidInitialize(void);

/* Description : Enable the EXTI 0 ISR		*/
void EXTI_voidEnableInt0(void);

/* Description : Disable the EXTI 0 ISR		*/
void EXTI_voidDisableInt0(void);

/* Description : Set call back function		*/
void EXTI_voidSetInt0Callback( void (*Copy_pfCallback) (void) );

#endif
