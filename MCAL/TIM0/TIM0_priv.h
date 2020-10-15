/*************************************************/
/* Author : Esther Shokry                        */
/* Date   : 6/3/2018                        	 */
/* Version: V01                     		     */
/*************************************************/

#ifndef _TIM0_PRIV_H
#define _TIM0_PRIV_H



#define TIM0_u16_DIV_1			1
#define TIM0_u8_DIV_8			8
#define TIM0_u8_DIV_64			64
#define TIM0_u8_DIV_256			256
#define TIM0_u8_DIV_1024		1064


/*Description : Mode Clear Mask	*/
#define INT0_u8_TIM0_MODE_CLEAR		0b11111000

/* for TCCR0*/
/*FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00*/

#define CS00 		0
#define CS01		1
#define WGM00		5
#define	WGM01		3

/*TIMSK*/
/*OCIE0 TOIE0*/

#define TOIE0 		0
#define OCIE0		1

/*TIFR*/
/*OCF0 TOV0*/

#define TOV0 		0
#define OCF0		1


#endif