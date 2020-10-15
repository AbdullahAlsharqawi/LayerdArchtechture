/*******************************/
/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 25-1-2018             */
/*VERSION : V01                */
/*******************************/


#ifndef _EXTI_CONFIG_H
#define _EXTI_CONFIG_H

/*Description:Different Modes of Operation
select one of the following         EXTI_u8_LOW_MODE      
                                    EXTI_u8_LOC_MODE      
                                    EXTI_u8_FAL_MODE      
                                    EXTI_u8_RIS_MODE  */  

#define EXTI_u8_INT0_MODE       	EXTI_u8_LOW_MODE


/*Description:INT0 initial state  MODES
									EXTI_u8_ENABLE_STATE
									EXTI_u8_DISABLE_STATE*/
										
#define EXTI_u8_INT0_INIT_STATE     EXTI_u8_ENABLE_STATE


	

#endif