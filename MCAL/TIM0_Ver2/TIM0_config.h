/***************************************/
/*   NAME    : ABDULLAH ALSHARQAWI     */
/*   DRIVER  : TIM0                    */
/*   DATE    : 19/APRIL/2018           */
/*   VERSION : 2                       */
/***************************************/

#ifndef _TIM0_CONFIG_H_
#define _TIM0_CONFIG_H_


/******************** Timer0 Mode ******************************/
/*  select any Mode                       TIM0_u8_Normal_MODE 
                                          TIM0_u8_PWM_MODE
                                          TIM0_u8_CTC_MODE 
                                          TIM0_u8_FastPWM_MODE
*/                                        
#define TIM0_u8_MODE                         TIM0_u8_Normal_MODE 

/******************** TIMER0 PRESCALLER ****************/
/*
Select any prescaller                     TIM0_u8_SCLOCK_DIV_1  
							              TIM0_u8_SCLOCK_DIV_8 
							              TIM0_u8_SCLOCK_DIV_64 
                                          TIM0_u8_SCLOCK_DIV_256
                                          TIM0_u8_SCLOCK_DIV_1024     */							
#define TIM0_u8_PRESCALAR                    TIM0_u8_SCLOCK_DIV_1024

							
/*Compare output mode is a function which gives us the ability to get a hardware interrupt through pins
 OC1A and OC1B.for each mode of the timer there is a slight change in the functions of these bits.*/

/***********Compare Output Mode,(PIN  OC1A)***************/
/*
Normal port operation                  :   TIM0_u8_NORMAL_PORT_OPERATION_A
Toggle OC1A on compare match           :   TIM0_u8_TOGGLE_COMPARE_MATCH_A
Clear OC1A on compare match            :   TIM0_u8_CLEAR_COMPARE_MATCH_A
Set OC1A on compare match              :   TIM0_u8_SET_COMPARE_MATCH_A   */
#define  TIM0_u8_PORT_OPERATION_A            TIM0_u8_NORMAL_PORT_OPERATION_A


/***********Compare Output Mode,(PIN  OC1B)***************/
/*
Normal port operation                  :   TIM0_u8_NORMAL_PORT_OPERATION_B
Toggle OC1B on compare match           :   TIM0_u8_TOGGLE_COMPARE_MATCH_B
Clear OC1B on compare match            :   TIM0_u8_CLEAR_COMPARE_MATCH_B
Set OC1B on compare match              :   TIM0_u8_SET_COMPARE_MATCH_B     */
#define  TIM0_u8_PORT_OPERATION_B            TIM0_u8_NORMAL_PORT_OPERATION_B

/*****************INITIAL REG VALUE ************************/
#define  TIM0_u8_REGISTER_INIT_VAL           220

/*****************OOUTPUT COMPARE VALUE ********************/
#define  TIM0_u8_OUTPUT_COMP_VAL             100

/***********




#endif