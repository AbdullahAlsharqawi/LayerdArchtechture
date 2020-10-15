/*
 * I2C_reg.h
 *
 *  Created on: May 13, 2018
 *      Author: Ebraam
 */

#ifndef I2C_REG_H_
#define I2C_REG_H_

#define TWSR	*((volatile u8*) 0x21)
#define TWDR	*((volatile u8*) 0x23)
#define TWCR	*((volatile u8*) 0x56)

#endif /* I2C_REG_H_ */
