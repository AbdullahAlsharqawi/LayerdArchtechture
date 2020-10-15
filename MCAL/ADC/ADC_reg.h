/*************************************/
/*   Author:Abdullah Alsharqawi      */
/*   Driver:ADC                      */
/*   Version:1                       */
/*   DATE:12/4/2018                  */
/*************************************/


#ifndef  _ADC_REG_H
#define  _ADC_REG_H

#define ADMUX           *((volatile u8 *) 0x27)
#define ADCSRA          *((volatile u8 *) 0x26)
#define SFIOR           *((volatile u8 *) 0x50)
#define ADCL            *((volatile u8 *) 0x24)    //The ADC Data Register –ADCL and ADCH
#define ADCH            *((volatile u8 *) 0x25)


#endif