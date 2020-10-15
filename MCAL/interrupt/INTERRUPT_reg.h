/*******************************/
/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 24-2-2018             */
/*VERSION : V01 1              */
/*******************************/


#ifndef _EXTI_REG_H
#define _EXTI_REG_H

#define MCUCR           *((volatile u8 *)0x55)                 /*REGISTER used for mode selection*/
#define GICR            *((volatile u8 *)0x5B)                 /*General Interrupt Control Register  used to eneble or disable the particular intterrupt*/
#define GIFR            *((volatile u8 *)0x5A)                 /*General Interrupt Flag Register, Raises the flag when there is an interrupt call*/

#endif