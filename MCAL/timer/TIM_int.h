/*******************************/
/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 6-3-2018              */
/*VERSION : V0l 1              */
/*******************************/


#ifndef _TIM0_INT_H
#define _TIM0_INT_H

void TIM0_voidInitialize();
void TIM0_voidEnable();
void TIM0_voidDisable();
void TIM0_voidSetRegister(u8 Copy_u8Value);
void TIM0_voidSetCallBack(void (*Copy_ptr)(void));

#endif