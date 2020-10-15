/*************************************/
/*   Author:Abdullah Alsharqawi      */
/*   Driver:ADC                      */
/*   Version:1                       */
/*   DATE:12/4/2018                  */
/*************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_init.h"
#include "ADC_reg.h"
#include "ADC_priv.h"
#include "ADC_config.h"
#include "ADC_init.h"


static void(*ADC_CallBack)(void);


void ADC_voidInitialise(void)
{
	/**************SET VOLTAGE ****************/
	#if  ADC_u8_REF_VOLTAGE == ADC_AREF_VOLTAGE
		CLRBIT(ADMUX,REFS0);
		CLRBIT(ADMUX,REFS1);
		
	#elif ADC_u8_REF_VOLTAGE == ADC_AVCC_VOLTAGE
		SETBIT(ADMUX,REFS0);
		CLRBIT(ADMUX,REFS1);
	
	#elif ADC_u8_REF_VOLTAGE == ADC_INTERNAL_VOLTAGE
		SETBIT(ADMUX,REFS0);
		SETBIT(ADMUX,REFS1);
	#endif
	
	
	/*******************Bit MODE ********************/
	#if ADC_u8_RESOLUTION == 8BIT_RESOLUTION
	    SETBIT(ADCSRA,ADLAR);
	#elif ADC_u8_RESOLUTION == 16BIT_RESOLUTION
        CLRBIT(ADCSRA,ADLAR);

	/******************SET PRESCALAR  **************/
	#if ADC_u8_PRESCALER == ADC_u8_PRESCALER_2
		SETBIT(ADCSRA,ADPS0);
		CLRBIT(ADCSRA,ADPS1);
		CLRBIT(ADCSRA,ADPS2);		
	#elif ADC_u8_PRESCALER == ADC_u8_PRESCALER_4
		CLRBIT(ADCSRA,ADPS0);
		SETBIT(ADCSRA,ADPS1);
		CLRBIT(ADCSRA,ADPS2);	
	#elif ADC_u8_PRESCALER == ADC_u8_PRESCALER_8
		SETBIT(ADCSRA,ADPS0);
		SETBIT(ADCSRA,ADPS1);
		CLRBIT(ADCSRA,ADPS2);	
	#elif ADC_u8_PRESCALER == ADC_u8_PRESCALER_16
		CLRBIT(ADCSRA,ADPS0);
		CLRBIT(ADCSRA,ADPS1);
		SETBIT(ADCSRA,ADPS2);	
	#elif ADC_u8_PRESCALER == ADC_u8_PRESCALER_32
		SETBIT(ADCSRA,ADPS0);
		CLRBIT(ADCSRA,ADPS1);
		SETBIT(ADCSRA,ADPS2);	
	#elif ADC_u8_PRESCALER == ADC_u8_PRESCALER_64
		CLRBIT(ADCSRA,ADPS0);
		SETBIT(ADCSRA,ADPS1);
		SETBIT(ADCSRA,ADPS2);	
	#elif ADC_u8_PRESCALER == ADC_u8_PRESCALER_128
		SETBIT(ADCSRA,ADPS0);
		SETBIT(ADCSRA,ADPS1);
		SETBIT(ADCSRA,ADPS2);
	#endif
	
	/******************SET MODE***********/
	
    #if ADC_u8_MODE ==  ADC_u8_SINGLE_CONVERSION_MODE
		CLRBIT(ADCSRA,ADATE);
	#elif ADC_u8_MODE == ADC_u8_AUTO_FREE_RUNNING
	    SETBIT(ADCSRA,ADATE);       //ADC Auto Trigger Enable
		CLRBIT(SFIOR,ADTS0);		 /*Bits to select the mode*/
		CLRBIT(SFIOR,ADTS1); 
		CLRBIT(SFIOR,ADTS2);
	#elif ADC_u8_MODE == ADC_u8_AUTO_ANALOG_COMPARATOR
		SETBIT(ADCSRA,ADATE);		//ADC Auto Trigger Enable
		SETBIT(SFIOR,ADTS0);		 /*Bits to select the mode*/
		CLRBIT(SFIOR,ADTS1); 
		CLRBIT(SFIOR,ADTS2);
	#elif ADC_u8_MODE == ADC_u8_AUTO_EXT_INTERRUPT
		SETBIT(ADCSRA,ADATE);       //ADC Auto Trigger Enable
		CLRBIT(SFIOR,ADTS0);		 /*Bits to select the mode*/
		SETBIT(SFIOR,ADTS1); 
		CLRBIT(SFIOR,ADTS2);
	#elif ADC_u8_MODE == ADC_u8_AUTO_TIM0_COMP_MATCH
		SETBIT(ADCSRA,ADATE);       //ADC Auto Trigger Enable
		SETBIT(SFIOR,ADTS0);		 /*Bits to select the mode*/
		SETBIT(SFIOR,ADTS1); 
		CLRBIT(SFIOR,ADTS2);
	#elif ADC_u8_MODE == ADC_u8_AUTO_TIM0_OVERFLOW
		SETBIT(ADCSRA,ADATE);       //ADC Auto Trigger Enable
		CLRBIT(SFIOR,ADTS0);		 /*Bits to select the mode*/
		CLRBIT(SFIOR,ADTS1); 
		SETBIT(SFIOR,ADTS2);
	#elif ADC_u8_MODE == ADC_u8_AUTO_TIM1_COMP_MATCH
		SETBIT(ADCSRA,ADATE);       //ADC Auto Trigger Enable
		SETBIT(SFIOR,ADTS0);		 /*Bits to select the mode*/
		CLRBIT(SFIOR,ADTS1); 
		SETBIT(SFIOR,ADTS2);
	#elif ADC_u8_MODE == ADC_u8_AUTO_TIM1_OVERFLOW
		SETBIT(ADCSRA,ADATE);       //ADC Auto Trigger Enable
		CLRBIT(SFIOR,ADTS0);		 /*Bits to select the mode*/
		SETBIT(SFIOR,ADTS1); 
		SETBIT(SFIOR,ADTS2);
	#elif ADC_u8_MODE == ADC_u8_AUTO_TIM1_CAPTURE_EVENT	
		SETBIT(ADCSRA,ADATE);       //ADC Auto Trigger Enable
		SETBIT(SFIOR,ADTS0);        /*Bits to select the mode*/
		SETBIT(SFIOR,ADTS1); 
		SETBIT(SFIOR,ADTS2);
	#endif
	/*****************ADC Enable**********/
	SETBIT(ADCSRA,ADEN);    /*Writing this bit to one enables the ADC. By writing it to zero, the ADC is turned off. 
							  Turning the ADC off while a conversion is in progress, will terminate this conversion.*/
	SETBIT(ADCSRA,ADIF);    //ADC Interrupt Flag clear by writing 1 to it
	SETBIT(ADCSRA,ADIE);    //ADC Interrupt Enable
	
}

/*****************************************************************/
/*A single conversion is started by writing a logical one to the */
/*ADC Start Conversion bit,ADSC. This bit stays high as long as  */
/*the conversion is in progress and will be cleared by hardware  */
/*when the conversion is completed                               */
/*****************************************************************/
void ADC_voidStartConversion(u8 channel_Number)
{
	SETBIT(ADCSRA,ADSC);
}


#if ADC_u8_RESOLUTION==8BIT_RESOLUTION 
u8 ADC_GetResult(void)                   //right shifted and take only the low register
{
	static u8 u8_DigitalVal;
	u8_DigitalVal = ADCH;                //The ADC Data Register –ADCL and ADCH
	return u8_DigitalVal;
}
#elif ADC_u8_RESOLUTION==16BIT_RESOLUTION     
u16 ADC_GetResult(void)                  //right shifted and or the low register with the 8 left shifted high register 
{
	static u16 u16_DigitalVal;
	u16_DigitalVal = ADCL | (ADCH<<8);   //The ADC Data Register –ADCL and ADCH
	return u16_DigitalVal;
}
#endif




void ADC_voidSetCallBack(void (*Copy_ptr) (void))
{
	ADC_CallBack =	Copy_ptr;
}

void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{
	ADC_CallBack();
}