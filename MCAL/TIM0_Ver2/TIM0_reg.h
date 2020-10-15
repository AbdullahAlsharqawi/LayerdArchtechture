/***************************************/
/*   NAME    : ABDULLAH ALSHARQAWI     */
/*   DRIVER  : TIM0                    */
/*   DATE    : 19/APRIL/2018           */
/*   VERSION : 2                       */
/***************************************/

#ifndef _TIM0_REG_H_
#define _TIM0_REG_H_

#define TCCR0            *((volatile u8*) 0x53 )
#define TCNT0            *((volatile u8*) 0x52 )
#define OCR0             *((volatile u8*) 0x5C )
#define TIMSK            *((volatile u8*) 0x59 )
#define TIFR             *((volatile u8*) 0x58 )




#endif