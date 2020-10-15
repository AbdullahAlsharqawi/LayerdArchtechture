/***************************************/
/*   NAME    : ABDULLAH ALSHARQAWI     */
/*   DRIVER  : TIM0                    */
/*   DATE    : 19/APRIL/2018           */
/*   VERSION : 2                       */
/***************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIM0_reg.h"
#include "TIM0_priv.h"
#include "TIM0_config.h"
#include "TIM0_init.h"


static void(*TIM0_CallBack)(void);

void TIM0_voidInitialize(void)
{
/********************SELECT MODE*************************/

	#if TIM0_u8_MODE == TIM0_u8_Normal_MODE
		CLRBIT(TCCR0,WGM00);
		CLRBIT(TCCR0,WGM01);
	#elif TIM0_u8_MODE == TIM0_u8_PWM_MODE
		SETBIT(TCCR0,WGM00);
		CLRBIT(TCCR0,WGM01);	
	#elif TIM0_u8_MODE == TIM0_u8_CTC_MODE
		CLRBIT(TCCR0,WGM00);
		SETBIT(TCCR0,WGM01);	
	#elif TIM0_u8_MODE == TIM0_u8_FastPWM_MODE
		SETBIT(TCCR0,WGM00);
		SETBIT(TCCR0,WGM01);	
	#endif

	/*********************COMPARE OUTPUT MODE*****************/
	#if  TIM0_u8_PORT_OPERATION_A == TIM0_u8_NORMAL_PORT_OPERATION_A
		CLRBIT(TCCR0,COM00); 
		CLRBIT(TCCR0,COM01);		
	#elif  TIM0_u8_PORT_OPERATION_A == TIM0_u8_TOGGLE_COMPARE_MATCH_A
		SETBIT(TCCR0,COM00); 
		CLRBIT(TCCR0,COM01);	
	#elif  TIM0_u8_PORT_OPERATION_A == TIM0_u8_CLEAR_COMPARE_MATCH_A
		CLRBIT(TCCR0,COM00); 
		SETBIT(TCCR0,COM01);	
	#elif  TIM0_u8_PORT_OPERATION_A == TIM0_u8_SET_COMPARE_MATCH_A
		SETBIT(TCCR0,COM00); 
		SETBIT(TCCR0,COM01);	
	#endif

/**********************SET PRESCALAR*********************/
	#if TIM0_u8_PRESCALAR == TIM0_u8_SCLOCK_DIV_1
		SETBIT(TCCR0,CS00);
		CLRBIT(TCCR0,CS01);
		CLRBIT(TCCR0,CS02);
	#elif TIM0_u8_PRESCALAR == TIM0_u8_SCLOCK_DIV_8
		CLRBIT(TCCR0,CS00);
		SETBIT(TCCR0,CS01);
		CLRBIT(TCCR0,CS02);
	#elif TIM0_u8_PRESCALAR == TIM0_u8_SCLOCK_DIV_64
		SETBIT(TCCR0,CS00);
		SETBIT(TCCR0,CS01);
		CLRBIT(TCCR0,CS02);	
	#elif TIM0_u8_PRESCALAR == TIM0_u8_SCLOCK_DIV_256
		CLRBIT(TCCR0,CS00);
		CLRBIT(TCCR0,CS01);
		SETBIT(TCCR0,CS02);	
	#elif TIM0_u8_PRESCALAR == TIM0_u8_SCLOCK_DIV_1024
		SETBIT(TCCR0,CS00);
		CLRBIT(TCCR0,CS01);
		SETBIT(TCCR0,CS02);	
	#endif	
	
	CLRBIT(TIMSK,OCIE0);      /*Dissable the interrupts of timer0 overflow and timer0 compare match*/
    CLRBIT(TIMSK,TOIE0);
    SETBIT(TIFR,OCF0);	      /*Clear the timer0 overflow flag and timer0 comparematch flag */
	SETBIT(TIFR,TOV0);

}

void TIM0_voidEnable(void)
{
	#if TIM0_u8_MODE == TIM0_u8_Normal_MODE
	    TCNT0 = TIM0_u8_REGISTER_INIT_VAL ;
		SETBIT(TIMSK,TOIE0);
	#else 
		OCR0 = TIM0_u8_OUTPUT_COMP_VAL ;
		SETBIT(TIMSK,OCIE0);
	#endif	
}

void TIM0_voidDisable(void)
{
	CLRBIT(TIMSK,OCIE0);      /*Dissable the interrupts of timer0 overflow and timer0 compare match*/
    CLRBIT(TIMSK,TOIE0);
}

void TIM0_voidSetRegister(u8 Copy_u8Val)
{
	TCNT0 = copy_u8Val;
}

void TIM0_voidSetCallBack(void (*Copy_u8pf)(void))
{
	TIM0_CallBack=Copy_u8pf;
}

void __vector_11 (void) __attribute__((signal,used));
void __vector_11 (void)
{
	TIM0_CallBack();
}