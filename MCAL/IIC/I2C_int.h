/*
 * I2C_int.h
 *
 *  Created on: May 13, 2018
 *      Author: Ebraam
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_

extern void I2C_voidWrite(u8 Copy_u8Address,u8 Copy_u8_Data);

extern void I2C_voidRead(u8 Copy_u8Address);

extern bool I2C_boolIsDataReady(u8* Copy_u8Data);

#endif /* I2C_INT_H_ */
