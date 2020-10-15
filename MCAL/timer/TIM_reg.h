/*******************************/
/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 24-2-2018             */
/*VERSION : V01 1              */
/*******************************/


#ifndef _TIM0_REG_H
#define _TIM0_REG_H

#define  TIMSK       *((volatile u8*)0x59)   /*to enable the overflow interrupt*/
#define  TIFR        *((volatile u8*)0x58)   /*timer flag is set when the intterupt occurs*/
#define  TCCR0       *((volatile u8*)0x53)   /*Controls the mode and the prescalar*/
#define  TCNT0       *((volatile u8*)0x52)   /*to set an initial value in the timer*/



#endif