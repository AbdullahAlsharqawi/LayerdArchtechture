/*
 * I2C_prog.c
 *
 *  Created on: May 13, 2018
 *      Author: Ebraam
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_reg.h"
#include "I2C_priv.h"
#include "I2C_config.h"
#include "I2C_int.h"

typedef enum
{
	not_specified=0,
	Read,
	Write
}I2C_operation_t;

static u8 Global_u8Address;
static u8 Global_u8Data;
static bool Global_boolReceiveComplete = FALSE;
static I2C_operation_t Global_Operation;

typedef enum
{
	STA_Transmitted = 0x08,
	REP_STA_Transmitted = 0x10,
	SLA_W_ACK = 0x18,
	SLA_W_NACK = 0x20,
	SLA_R_ACK = 0x40,
	SLA_R_NACK = 0x48,
	DATA_W_ACK = 0x28,
	DATA_W_NACK = 0x30,
	DATA_R_ACK = 0x50,
	DATA_R_NACK = 0x58
}isrState;

static void voidSendStart(void)
{
	/*	Send Start Condition	*/
	SETBIT(TWCR,STA);
}

extern void I2C_voidWrite(u8 Copy_u8Address,u8 Copy_u8_Data)
{
	Global_Operation = Write;
	Global_u8Address = Copy_u8Address;
	Global_u8Data = Copy_u8_Data;
	voidSendStart();
}

extern void I2C_voidRead(u8 Copy_u8Address)
{
	Global_Operation = Read;
	Global_u8Address = Copy_u8Address;
	voidSendStart();
}

extern bool I2C_boolIsDataReady(u8* Copy_u8Data)
{
	if(Global_boolReceiveComplete != TRUE)
		return FALSE;
	else
	{
		*Copy_u8Data = Global_u8Data;
		Global_boolReceiveComplete = FALSE;
		return TRUE;
	}
}

void ISR(void)
{
	switch(Global_Operation)
	{
	case Write:
		switch(TWSR)
		{
		case STA_Transmitted :
		case REP_STA_Transmitted:
			TWDR = (Global_u8Address << 1);
			break;
		case SLA_W_ACK:
			TWDR = Global_u8Data;
			break;
		case SLA_W_NACK:
		case DATA_W_ACK:
		case DATA_W_NACK:
			SETBIT(TWCR,STO);
			Global_Operation = not_specified;
			break;
		default:
			break;
		}
		break;
	case Read:
		switch(TWSR)
		{
		case STA_Transmitted :
		case REP_STA_Transmitted:
			TWDR = (Global_u8Address << 1) | 1;
			break;
		case SLA_R_ACK:
		case SLA_R_NACK:
			break;
		case DATA_R_ACK:
		case DATA_R_NACK:
			Global_u8Data = TWDR;
			Global_boolReceiveComplete = TRUE;
			SETBIT(TWCR,STO);
			Global_Operation = not_specified;
			break;
		}
		break;
	}
}
