/*******************************/
/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 24-2-2018             */
/*VERSION : V01 1              */
/*******************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "EXTI_reg.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI_int.h"

/*Define Callback variable*/
static void (*EXTI_u8Int0Callback)(void);

/*Description : Initialize interrupt INT0 */
void EXTI_voidInitialize(void)
{
	MCUCR = (MCUCR & EXTI_u8_INT0_MODE_CLEAR) | EXTI_u8_INT0_MODE;
	
	/*INITIALIZE the state*/
	#if EXTI_u8_INT0_INIT_STATE == EXTI_u8_ENABLE_STATE
	  SETBIT(GICR,EXTI_u8_INT0_PIE);
	#else
	  CLRBIT(GICR,EXTI_u8_INT0_PIE);	
	#endif
	
	/*CLEAR the INT0 flag (may be raised due to previous interrupt) by setting 1 to it*/
	
	SETBIT(GIFR,EXTI_u8_INT0_PIF);
	
}


/*Description : Enable interrupt INT0 */
void EXTI_voidEnableInt0(void)
{
	/*enable the INT0 by setting its bit*/
	SETBIT(GICR,EXTI_u8_INT0_PIE);	
}


/*Description : Disable interrupt INT0 */
void EXTI_voidDisableInt0(void)
{
	/*disable the INT0 by clearing its bit*/
	CLRBIT(GICR,EXTI_u8_INT0_PIE);
	
}


/*Description:Set callback function*/
void EXTI_voidSetInt0CallBack(void (*Copy_pfCallback) (void)  )
{
	EXTI_u8Int0Callback = Copy_pfCallback;
}


/*Description:ISR routine*/
void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	EXTI_u8Int0Callback();
}



