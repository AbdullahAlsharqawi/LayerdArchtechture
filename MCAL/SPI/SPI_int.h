/****************************************************************/
/*	Author :	Hassan Omar										*/
/*	Date   :	23 April 2018									*/
/*	Version:	1.0												*/
/****************************************************************/

#ifndef SPI_INT_H_
#define SPI_INT_H_

void SPI_voidInit (void);
void SPI_voidTransmit (u8* Data, u16 Length);
void SPI_voidSSEnable (void);
void SPI_voidSSDisable (void);
u8 	 SPI_u8Receive (void);

#endif /* SPI_INT_H_ */
