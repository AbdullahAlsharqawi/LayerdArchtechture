/***************************************/
/*   NAME    : ABDULLAH ALSHARQAWI     */
/*   DRIVER  : TIM0                    */
/*   DATE    : 19/APRIL/2018           */
/*   VERSION : 2                       */
/***************************************/

#ifndef _TIM0_INIT_H_
#define _TIM0_INIT_H_


void TIM0_voidInitialize(void);

void TIM0_voidEnable(void);

void TIM0_voidDisable(void);

void TIM0_voidSetCallBack(void (*Copy_u8pf)(void));

void TIM0_SetCallBackFunc(void (*ptr)(void));


#endif