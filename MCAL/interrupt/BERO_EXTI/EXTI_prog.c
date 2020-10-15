/****************************************/
/* Author  : Bero Emile					*/
/* Date    : 24/2/2018					*/
/* Version : V01						*/
/****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_int.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI_reg.h"

/* Define callback variable */
static void (*EXTI_u8Int0Callback) (void);

/* Description : Initialize the EXTI mode	*/
void EXTI_voidInitialize(void)
{
	MCUCR = (MCUCR & EXTI_u8_INT0_MODE_CLEAR) | EXTI_u8_INT0_MODE;     //first clear all the bits then set the last two bits
	/* Initialize the state */
#if EXTI_u8_INT0_INIT_STATE == EXTI_u8_ENABLE_STATE
	SETBIT(GICR,EXTI_u8_INT0_PIE);
#else
	CLRBIT(GICR,EXTI_u8_INT0_PIE);
#endif
	/* Clear flag */
	SETBIT(GIFR,EXTI_u8_INT0_PIF);
}

/* Description : Enable the EXTI 0 ISR		*/
void EXTI_voidEnableInt0(void)
{
	SETBIT(GICR,EXTI_u8_INT0_PIE);
}

/* Description : Disable the EXTI 0 ISR		*/
void EXTI_voidDisableInt0(void)
{
	CLRBIT(GICR,EXTI_u8_INT0_PIE);
}

/* Description : Set call back function		*/
void EXTI_voidSetInt0Callback( void (*Copy_pfCallback) (void) )
{
	EXTI_u8Int0Callback = Copy_pfCallback;
}

/* Description : ISR routine				*/
void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	EXTI_u8Int0Callback();
}


