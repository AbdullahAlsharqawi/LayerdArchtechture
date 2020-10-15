/*************************************************/
/* Author : Esther Shokry                        */
/* Date   : 6/3/2018                        	 */
/* Version: V01                     		     */
/*************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "TIM0_reg.h"
#include "TIM0_priv.h"
#include "TIM0_config.h"
#include "TIM0_int.h"


static void(*TIM0_CallBack)(void);

void TIM0_voidInitialize(void)
{
	/*Disable Timer Interrupt*/
	CLRBIT(TIMSK,TOIE0);
	
	/*Clear Flag*/
	SETBIT(TIFR,TOV0);
	
	/*Set Mode and Prescaler*/
#if TIM0_u16_PRESCALER==TIM0_u16_DIV_1
	TCCR0=0b00000001;
#elif TIM0_u16_PRESCALER==TIM0_u16_DIV_8
	TCCR0=0b00000010;
#elif TIM0_u16_PRESCALER==TIM0_u16_DIV_64
	TCCR0=0b00000011;
#elif TIM0_u16_PRESCALER==TIM0_u16_DIV_256
	TCCR0=0b00000100;
#elif TIM0_u16_PRESCALER==TIM0_u16_DIV_1024
	TCCR0=0b00000101;
#endif
//TCCR0 =(TCCR0&INT0_u8_TIM0_MODE_CLEAR)|TIM0_u8_PRESCALER;
}

void TIM0_voidEnableInt(void)
{
	SETBIT(TIMSK,0);
}

void TIM0_voidDisableInt(void)
{
	CLRBIT(TIMSK,0);
}

void TIM0_voidSetRegister(u8 Copy_u8Value)
{
	TCNT0=Copy_u8Value;
}


void TIM0_voidSetCallBack(void (*Copy_ptr) (void))
{
	TIM0_CallBack=	Copy_ptr;
}

void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	TIM0_CallBack();
}