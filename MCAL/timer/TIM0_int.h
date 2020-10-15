/*********************************************/
/* Author  : Hussein Elmasry		         */
/* Date    : 6/3/2018				         */
/* Version : V01						     */
/*********************************************/

#ifndef _TIM0_INT_H
#define _TIM0_INT_H


void TIM0_voidInitialize(void);

void TIM0_voidEnableInt(void);

void TIM0_voidDisableInt(void);

void TIM0_voidSetRegister(u8 copy_u8Value);

void TIM0_voidSetCallBack(void (*Copy_ptr) (void));

#endif
