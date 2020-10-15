/*******************************/
/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 24-2-2018             */
/*VERSION : V01 1              */
/*******************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "TIM_reg.h"
#include "TIM_priv.h"
#include "TIM_config.h"
#include "TIM_int.h"

static void(*TIM0_CallBack)(void);

void TIM0_voidInitialize(void)  
{
	/*Disable timer interrupt*/
    CLRBIT(TIMSK,TOIE0);	
	/*Clear flag*/
	SETBIT(TIFR,TOV0);
	/*SetMode and prescale*/
	#if TIM0_u16_PRESCALLAR == TIM0_u16_DIV_1
	TCNT0=0b00000001;
	#elif TIM0_u16_PRESCALLAR == TIM0_u16_DIV_8
	TCNT0=0b00000010;
	#elif TIM0_u16_PRESCALLAR == TIM0_u16_DIV_64
	TCNT0=0b00000011;
	#elif TIM0_u16_PRESCALLAR == TIM0_u16_DIV_256
	TCNT0=0b00000100;
	#elif TIM0_u16_PRESCALLAR == TIM0_u16_DIV_1024
	TCNT0=0b00000101;
	#endif
		
}
void TIM0_voidEnable(void)
{
	SETBIT(TIMSK,TOIE0);
	
}

void TIM0_voidDisable(void)
{
	CLRBIT(TIMSK,TOIE0);
}

void TIM0_voidSetRegister(u8 Copy_u8value)
{
	TCNT0=Copy_u8value;
}

void TIM0_voidSetCallBack(void (*Copy_u8pf)(void))
{
	TIM0_CallBack=Copy_u8pf;
}

void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	TIM0_CallBack();
}