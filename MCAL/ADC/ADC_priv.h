/*************************************/
/*   Author:Abdullah Alsharqawi      */
/*   Driver:ADC                      */
/*   Version:1                       */
/*   DATE:12/4/2018                  */
/*************************************/

#ifndef  _ADC_PRIV_H
#define  _ADC_PRIV_H

/***************ADMUX***************/
#define MUX0      0
#define MUX1      1
#define MUX2      2
#define MUX3      3
#define MUX4      4
#define ADLAR     5
#define REFS0     6
#define REFS1     7 

       
/**************ADCSRA***************/
#define ADPS0     0
#define ADPS1     1
#define ADPS2     2
#define ADIE      3
#define ADIF      4
#define ADATE     5
#define ADSC      6
#define ADEN      7 


/***************SFIOR***************/     
#define PSR10     0
#define PSR2      1
#define PUD       2
#define ACME      3
#define ADTS0     5
#define ADTS1     6
#define ADTS2     7 
  
#endif