/***************************************/
/*   NAME    : ABDULLAH ALSHARQAWI     */
/*   DRIVER  : TIM0                    */
/*   DATE    : 19/APRIL/2018           */
/*   VERSION : 2                       */
/***************************************/

#ifndef _TIM0_PRIV_H_
#define _TIM0_PRIV_H_

/*Timer/Counter Control
Register – TCCR0*/
#define CS00                  0
#define CS01                  1
#define CS02                  2
#define WGM01                 3
#define COM00                 4
#define COM01                 5
#define WGM00                 6
#define FOC0                  7

/*Timer/Counter Interrupt Mask
Register – TIMSK*/
#define TOIE0                 0
#define OCIE0                 1

/*Timer/Counter Interrupt Flag
Register – TIFR*/
#define TOV0                  0
#define OCF0                  1
/************* OUTPUT COMPARE MODE PIN-A **********/
#define TIM0_u8_NORMAL_PORT_OPERATION_A                 1
#define TIM0_u8_TOGGLE_COMPARE_MATCH_A                  2
#define TIM0_u8_CLEAR_COMPARE_MATCH_A                   3
#define TIM0_u8_SET_COMPARE_MATCH_A                     4

/************* OUTPUT COMPARE MODE PIN-B **********/
#define TIM0_u8_NORMAL_PORT_OPERATION_B                 1
#define TIM0_u8_TOGGLE_COMPARE_MATCH_B                  2
#define TIM0_u8_CLEAR_COMPARE_MATCH_B                   3
#define TIM0_u8_SET_COMPARE_MATCH_B                     4

/****************MODE************************/
#define TIM0_u8_Normal_MODE                             1
#define TIM0_u8_PWM_MODE                                2
#define TIM0_u8_CTC_MODE                                3
#define TIM0_u8_FastPWM_MODE                            4

/***************PRESCALAR********************/
#define TIM0_u8_SCLOCK_DIV_1                            1
#define TIM0_u8_SCLOCK_DIV_8                            2
#define TIM0_u8_SCLOCK_DIV_64                           3
#define TIM0_u8_SCLOCK_DIV_256                          4
#define TIM0_u8_SCLOCK_DIV_1024                         5

#endif