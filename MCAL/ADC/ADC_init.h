/*************************************/
/*   Author:Abdullah Alsharqawi      */
/*   Driver:ADC                      */
/*   Version:1                       */
/*   DATE:12/4/2018                  */
/*************************************/


#ifndef  _ADC_INIT_H
#define  _ADC_INIT_H

#define ADC_u8_PIN_0     0
#define ADC_u8_PIN_1     1
#define ADC_u8_PIN_2     2
#define ADC_u8_PIN_3     3
#define ADC_u8_PIN_4     4
#define ADC_u8_PIN_5     5
#define ADC_u8_PIN_6     6
#define ADC_u8_PIN_7     7

void ADC_voidInitialise(void);


void ADC_voidStartConversion(u8 channel_Number);  

#if ADC_u8_RESOLUTION==8BIT_RESOLUTION 
u8 ADC_u8GetResult(void);
#elif ADC_u8_RESOLUTION==16BIT_RESOLUTION
u16 ADC_u16GetResult(void);
#endif

void ADC_voidSetCallBack(void (*Copy_ptr) (void));


#endif