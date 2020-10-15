/****************************************************************/
/*	Author :	Hassan Omar										*/
/*	Date   :	23 April 2018									*/
/*	Version:	1.0												*/
/****************************************************************/

#include "std_types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "SPI_int.h"
#include "SPI_priv.h"
#include "SPI_config.h"
#include "avr/io.h"


void SPI_voidInit (void)
{
	/*	Disable SPI Interrupt */
	SPCR &= ~(1 << SPIE);

	/*	SPI Master or Slave	*/
	SPCR |= (SPI_u8MODE << MSTR);

	/*	Set Order Mode LSB or MSB first	*/
	//SPCR |= (SPI_u8DATA_ORDER << DORD);

	/*	Set Clock Output in idle mode		*/
	SPCR |= (SPI_u8CLK_POLARITY << CPOL);

	/*	Set Sample Time with leading or trailing edge	*/
	SPCR |= (SPI_u8CLK_PHASE << CPHA);

#if SPI_u8MODE == SPI_u8MASTER

	#if SPI_u8PRESCALER == SPI_u8PRESCALER_4
		SPCR |= (SPI_u8PRESCALER << SPR0);
	#elif SPI_u8PRESCALER == SPI_u8PRESCALER_16
		SPCR |= (SPI_u8PRESCALER << SPR0);
	#elif SPI_u8PRESCALER == SPI_u8PRESCALER_64
		SPCR |= (SPI_u8PRESCALER << SPR0);
	#elif SPI_u8PRESCALER == SPI_u8PRESCALER_128
		SPCR |= (SPI_u8PRESCALER << SPR0);
	#elif SPI_u8PRESCALER == SPI_u8PRESCALER_2
		SPSR |= (1 << SPI2X);
	#elif SPI_u8PRESCALER == SPI_u8PRESCALER_8
		SPCR |= 0x01;
		SPSR |= (1 << SPI2X);
	#elif SPI_u8PRESCALER == SPI_u8PRESCALER_32
		SPCR |= 0x02;
		SPSR |= (1 << SPI2X);
	#else
		#error	"Error choosing the Prescaler of SPI"
	#endif
#endif

	/*	Enable SPI	*/
	SPCR |= (1 << SPE);
}

#if SPI_u8MODE == SPI_u8MASTER
void SPI_voidTransmit (u8* Data, u16 Length)
{
	u16 index;
	for (index = 0 ; index < Length ; index++)
	{
		SPDR = Data[index];
		while(! (SPSR & (1 << SPIF)) );
	}
}
#endif


u8 SPI_u8Receive (void)
{
	return SPDR;
}

void SPI_voidSSEnable (void)
{
	DIO_voidSetPinValue(DIO_u8_PIN_12,DIO_u8_LOW);
}

void SPI_voidSSDisable (void)
{
	DIO_voidSetPinValue(DIO_u8_PIN_12,DIO_u8_HIGH);
}

