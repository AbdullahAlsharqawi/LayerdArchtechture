/*************************************/
/*   Author:Abdullah Alsharqawi      */
/*   Driver:ADC                      */
/*   Version:1                       */
/*   DATE:12/4/2018                  */
/*************************************/

#ifndef  _ADC_CONFIG_H
#define  _ADC_CONFIG_H

/**************RANGE***************/            /*(ADLAR)ADMUX: ADC Left Adjust Result*/
/*      8bit  = 8BIT_RESOLUTION   */
/*      16bit = 16BIT_RESOLUTION  */
/**********************************/
#define ADC_u8_RESOLUTION        8BIT_RESOLUTION


/*************  REF VOLTAGE  ************/      /*(REFS1 REFS0)ADMUX: Voltage Reference Selection*/
/*             ADC_AREF_VOLTAGE         */
/*             ADC_AVCC_VOLTAGE         */
/*             ADC_INTERNAL_VOLTAGE     */  
/****************************************/
#define  ADC_u8_REF_VOLTAGE      ADC_AREF_VOLTAGE


/***************  Prescalar **************/     /*(ADPS2 ADPS1 ADPS0)ADCSRA:ADC Prescaler Select Bits*/
/*            ADC_u8_PRESCALER_2         */
/*            ADC_u8_PRESCALER_4         */
/*            ADC_u8_PRESCALER_8         */
/*            ADC_u8_PRESCALER_16        */
/*            ADC_u8_PRESCALER_32        */
/*            ADC_u8_PRESCALER_64        */
/*            ADC_u8_PRESCALER_128       */
/*****************************************/
#define ADC_u8_PRESCALER      ADC_u8_PRESCALER_2

/***************** MODE ************************/            
/*       ADC_u8_SINGLE_CONVERSION_MODE         */
/*		 ADC_u8_AUTO_FREE_RUNNING              */
/* 		 ADC_u8_AUTO_ANALOG_COMPARATOR         */
/* 		 ADC_u8_AUTO_EXT_INTERRUPT             */
/* 		 ADC_u8_AUTO_TIM0_COMP_MATCH           */
/* 		 ADC_u8_AUTO_TIM0_OVERFLOW             */
/* 		 ADC_u8_AUTO_TIM1_COMP_MATCH           */
/* 		 ADC_u8_AUTO_TIM1_OVERFLOW             */
/* 		 ADC_u8_AUTO_TIM1_CAPTURE_EVENT        */
/***********************************************/
#define  ADC_u8_MODE    ADC_u8_SINGLE_CONVERSION_MODE     		 
	  
#endif	  