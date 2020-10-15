/****************************************************************/
/*	Author :	Hassan Omar										*/
/*	Date   :	23 April 2018									*/
/*	Version:	1.0												*/
/****************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/**************************/
/*	Options: SPI_u8Master */
/*			 SPI_u8Slave  */
/**************************/
#define SPI_u8MODE				SPI_u8MASTER

/********************************/
/*	Options: SPI_u8FirstLSB    */
/*			 SPI_u8FirstMSB    */
/********************************/
#define SPI_u8DATA_ORDER		SPI_u8FIRST_MSB

/********************************/
/*	Options: SPI_u8High	  	    */
/*			 SPI_u8Low		    */
/********************************/
#define SPI_u8CLK_POLARITY		SPI_u8CLK_IDLE_LOW


/*********************************/
/*	Options: SPI_u8Leading_Edge  */
/*			 SPI_u8Trailing_Edge */
/*********************************/
#define SPI_u8CLK_PHASE			SPI_u8LEADING_EDGE

/************************************/
/*	Options: SPI_u8Prescaler_4	    */
/*			 SPI_u8Prescaler_16     */
/*           SPI_u8Prescaler_64     */
/*           SPI_u8Prescaler_128    */
/*           SPI_u8Prescaler_2      */
/*           SPI_u8Prescaler_8      */
/*           SPI_u8Prescaler_32     */
/*                               	*/
/************************************/
#define SPI_u8PRESCALER			SPI_u8PRESCALER_128

#endif /* SPI_CONFIG_H_ */
