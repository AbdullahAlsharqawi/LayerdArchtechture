/*******************************/
/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 25-1-2018             */
/*VERSION : V01                */
/*******************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_reg.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "DIO_int.h"


/* Enable Global Interrupt*/
void GIE_voidEnable(void){
	SET_BIT(SREG,GIE_u8_BIT_INDEX);
}



/* Disable Global Interrupt*/
void GIE_voidDisable(void){
	CLR_BIT(SREG,GIE_u8_BIT_INDEX);
	
}