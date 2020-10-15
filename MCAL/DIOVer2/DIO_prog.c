/*******************************/
/*AUTHOR : ABDULLAH MUHAMMAD   */
/*DATE : 25-1-2018             */
/*VERSION : V01                */
/*******************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_reg.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "DIO_int.h"

/******PORT DIRECTIONS*************/
#define DIO_GROUPA_DIRECTIONS    CONCBIT(DIO_u8_PIN_DIR_7 , DIO_u8_PIN_DIR_6,DIO_u8_PIN_DIR_5,DIO_u8_PIN_DIR_4,DIO_u8_PIN_DIR_3,DIO_u8_PIN_DIR_2,DIO_u8_PIN_DIR_1,DIO_u8_PIN_DIR_0)
#define DIO_GROUPB_DIRECTIONS    CONCBIT(DIO_u8_PIN_DIR_15 ,DIO_u8_PIN_DIR_14,DIO_u8_PIN_DIR_13,DIO_u8_PIN_DIR_12,DIO_u8_PIN_DIR_11,DIO_u8_PIN_DIR_10,DIO_u8_PIN_DIR_9,DIO_u8_PIN_DIR_8)
#define DIO_GROUPC_DIRECTIONS    CONCBIT(DIO_u8_PIN_DIR_23 ,DIO_u8_PIN_DIR_22,DIO_u8_PIN_DIR_21,DIO_u8_PIN_DIR_20,DIO_u8_PIN_DIR_19,DIO_u8_PIN_DIR_18,DIO_u8_PIN_DIR_17,DIO_u8_PIN_DIR_16)
#define DIO_GROUPD_DIRECTIONS    CONCBIT(DIO_u8_PIN_DIR_31 ,DIO_u8_PIN_DIR_30,DIO_u8_PIN_DIR_29,DIO_u8_PIN_DIR_28,DIO_u8_PIN_DIR_27,DIO_u8_PIN_DIR_26,DIO_u8_PIN_DIR_25,DIO_u8_PIN_DIR_24)


/***************************************/
/*Description:This function shall set  */
/*            directions for 10 pins   */ 
/***************************************/
void DIO_voidInitialize(void){
DDRA = DIO_GROUPA_DIRECTIONS;
DDRB = DIO_GROUPB_DIRECTIONS;
DDRC = DIO_GROUPC_DIRECTIONS;
DDRD = DIO_GROUPD_DIRECTIONS;
}

/******************************************/
/*Description:This function shall set a   */
/*            digital value for 10 pins   */ 
/******************************************/

void DIO_voidSetPinValue(u8 Copy_u8PinIdx, u8 Copy_u8PinVal)
{

    /*IF the user chooses a pin in port A*/
	if ((Copy_u8PinIdx >= DIO_u8_PORTA_START ) && (Copy_u8PinIdx <=DIO_u8_PORTA_END ))
	{
		if(Copy_u8PinVal == DIO_u8_HIGH)             /*DIO_u8_HIGH is defined in the config.h*/
		{
		SETBIT(PORTA,Copy_u8PinIdx);	
		}
		else
		{
		CLRBIT(PORTA,Copy_u8PinIdx);	
		}
       
	}
	/*IF the user chooses a pin in port B*/
	else if ((Copy_u8PinIdx >= DIO_u8_PORTB_START) && (Copy_u8PinIdx <= DIO_u8_PORTB_END))
	{
		Copy_u8PinIdx -= DIO_u8_PORTA_SIZE;

		if(Copy_u8PinVal == DIO_u8_HIGH)
		{
		SETBIT(PORTB,Copy_u8PinIdx);	
		}
		else
		{
		CLRBIT(PORTB,Copy_u8PinIdx);	
		}
	}
    /*IF the user chooses a pin in port C*/
	else if ((Copy_u8PinIdx >= DIO_u8_PORTC_START) && (Copy_u8PinIdx <= DIO_u8_PORTC_END))
	{   
		/*In order to reduce the number entered by the user to the number of PINS in the code*/
		Copy_u8PinIdx -= (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE);
        /*If the user wants the PIN to be HIGH*/
		if(Copy_u8PinVal == DIO_u8_HIGH)
		{
		SETBIT(PORTC,Copy_u8PinIdx);	
		}
		/*If the user wants the PIN to be LOW*/
		else
		{
		CLRBIT(PORTC,Copy_u8PinIdx);	
		}
	}
    /*IF the user chooses a pin in port D*/
	else if ((Copy_u8PinIdx >= DIO_u8_PORTD_START) && (Copy_u8PinIdx <= DIO_u8_PORTD_END))
	{
		/*In order to reduce the number entered by the user to the number of PINS in the code*/
		Copy_u8PinIdx -= (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE);
        /*If the user wants the PIN to be HIGH*/
		if(Copy_u8PinVal == DIO_u8_HIGH)
		{
		SETBIT(PORTD,Copy_u8PinIdx);	
		}
		/*If the user wants the PIN to be LOW*/
		else
		{
		CLRBIT(PORTD,Copy_u8PinIdx);	
		}
	}

}



/******************************************/
/*Description:This function shall Get the   */
/*            digital value for  pins   */ 
/******************************************/
void DIO_voidGetPinValue(u8 Copy_u8PinIdx)
{
    u8 Local_u8Result;
    /*IF the user chooses a pin in port A*/
	if ((Copy_u8PinIdx >= DIO_u8_PORTA_START ) && (Copy_u8PinIdx <=DIO_u8_PORTA_END ))
	{
		
		if(GET_BIT(PINA,Copy_u8PinIdx)             /*DIO_u8_HIGH is defined in the config.h*/
		{
		 Local_u8Result = DIO_u8_HIGH;	
		}
		else
		{
		 Local_u8Result = DIO_u8_LOW;	
		}
       
	}
	 /*IF the user chooses a pin in port B*/
	else if ((Copy_u8PinIdx >= DIO_u8_PORTB_START ) && (Copy_u8PinIdx <=DIO_u8_PORTB_END ))
	{
		Copy_u8PinIdx -= DIO_u8_PORTA_SIZE;
		if(GET_BIT(PINB,Copy_u8PinIdx)             /*DIO_u8_HIGH is defined in the config.h*/
		{
		 Local_u8Result = DIO_u8_HIGH;	
		}
		else
		{
		 Local_u8Result = DIO_u8_LOW;	
		}
       
	}
	
		 /*IF the user chooses a pin in port C*/
	else if ((Copy_u8PinIdx >= DIO_u8_PORTC_START ) && (Copy_u8PinIdx <=DIO_u8_PORTC_END ))
	{
		Copy_u8PinIdx -= (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE);
		if(GET_BIT(PINC,Copy_u8PinIdx)             /*DIO_u8_HIGH is defined in the config.h*/
		{
		 Local_u8Result = DIO_u8_HIGH;	
		}
		else
		{
		 Local_u8Result = DIO_u8_LOW;	
		}
       
	}
	
			 /*IF the user chooses a pin in port D*/
	else if ((Copy_u8PinIdx >= DIO_u8_PORTD_START ) && (Copy_u8PinIdx <=DIO_u8_PORTD_END ))
	{
		Copy_u8PinIdx -= (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE);
		if(GET_BIT(PINC,Copy_u8PinIdx)             /*DIO_u8_HIGH is defined in the config.h*/
		{
		 Local_u8Result = DIO_u8_HIGH;	
		}
		else
		{
		 Local_u8Result = DIO_u8_LOW;	
		}
       
	}
	return Local_u8Result;
}