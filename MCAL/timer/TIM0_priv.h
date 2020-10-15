/*********************************************/
/* Author  : Hussein Elmasry		         */
/* Date    : 6/3/2018				         */
/* Version : V01						     */
/*********************************************/

#ifndef _TIM0_PRIV_H
#define _TIM0_PRIV_H



#define TIM0_u16_DIV_1	            1
#define TIM0_u16_DIV_8	            8
#define TIM0_u16_DIV_64	            64
#define TIM0_u16_DIV_256	        256
#define TIM0_u16_DIV_1024           1024 


/********************************************/
/* Description : Enable/Disable state   	*/
/********************************************/
#define EXTI_u8_ENABLE_STATE	            1
#define EXTI_u8_DISABLE_STATE	            0

/********************************************/
/* Description : mode clear mask   	        */
/********************************************/
#define EXTI_u8_INT0_MODE_CLEAR	             0b11111100


/********************************************/
/* Description : PIE bit index   	        */
/********************************************/
#define EXTI_u8_INT0_PIE	                 6


/********************************************/
/* Description : PIF bit index   	        */
/********************************************/
#define EXTI_u8_INT0_PIF	                 6

#endif
