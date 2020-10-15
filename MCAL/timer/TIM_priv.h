/*******************************/
/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 24-2-2018             */
/*VERSION : V01 1              */
/*******************************/


#ifndef _EXTI_priv_H
#define _EXTI_priv_H


/*Description:Mask for clear mode*/
#define  EXTI_u8_INT0_MODE_CLEAR    0b11111100


/*Description:Different Modes of Operation*/
#define EXTI_u8_LOW_MODE              0
#define EXTI_u8_LOC_MODE              1
#define EXTI_u8_FAL_MODE              2
#define EXTI_u8_RIS_MODE              3

/*Description:PIE bit index in GICR*/
#define EXTI_u8_INT0_PIE              6


/*Description:PIF bit index in the GIFR*/
#define EXTI_u8_INT0_PIF              6

/*Description:Enable and dissable mode*/
#define EXTI_u8_ENABLE_STATE          1
#define EXTI_u8_DISABLE_STATE         0


#endif
