/*******************************/
/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 24-2-2018             */
/*VERSION : V0l 1              */
/*******************************/


#ifndef _INTERRUPT_INT_H
#define _INTERRUPT_INT_H

/*Description : Initialize interrupt INT0 */
void EXTI_voidInitialize(void);

/*Description : Enable interrupt INT0 */
void EXTI_voidEnableInt0(void);

/*Description : Disable interrupt INT0 */
void EXTI_voidDisableInt0(void);


/*Description : CallBack Function for INT0 */
void EXTI_voidSetInt0CallBack(void (*Copy_pfCallback) (void) );


#endif