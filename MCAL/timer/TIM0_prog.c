/*********************************************/
/* Author  : Hussein Elmasry		         */
/* Date    : 6/3/2018				         */
/* Version : V01						     */
/*********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_reg.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI_int.h"


static (*TIM0_CallBack)(void)

void TIM0_voidInitialize(void)
{
	/* Disable Timer Interrupt */
	CLR_BIT(TIMSK,0);	
	
	/* Clear Flag              */
	set_BIT(TIFR,0);	
	
	/* set Mode and Prescaller */
	#if TIM0_u16_RESCALLER == TIM0_u16_DIV_1
		TCCR0 =0b00000001;
	#elif TIM0_u16_RESCALLER == TIM0_u16_DIV_8
		TCCR0 =0b00000010;
	#elif TIM0_u16_RESCALLER == TIM0_u16_DIV_64
		TCCR0 =0b00000011;
	#elif TIM0_u16_RESCALLER == TIM0_u16_DIV_256
		TCCR0 =0b00000100;	
	#elif TIM0_u16_RESCALLER == TIM0_u16_DIV_1024
		TCCR0 =0b00000101;	

    #endif		
}

void TIM0_voidEnableInt(void)
{
	SET_BIT(TIMSK,0);
}

void TIM0_voidDisableInt(void)
{
	CLR_BIT(TIMSK,0);	
}

void TIM0_voidSetRegister(u8 copy_u8Value)
{
	TCNT0 = copy_u8Value;
}

void TIM0_voidSetCallBack(void (*Copy_ptr) (void))
{
	TIM0_CallBack = Copy_ptr;
}

void __vector_11 (void) __attribute__((signal,used));
void __vector_11 (void)
{
	(*TIM0_CallBack);
}