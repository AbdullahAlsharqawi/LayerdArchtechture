/***************************************/
/*    Author:Abdullah Alsharqawy       */
/*    Date:23/Mar/2018                 */
/*    RTO Version: 1                   */
/***************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_reg.h"

#include "RTO_config.h"
#include "RTO_int.h"
#include "RTO_priv.h"


static u8 currentTick=0;
static u8 OV_Counter=0;

typedef struct
{
	u8 periodicity;
	void (*taskHandler) (void);
	
}task;

/************Application*******************************/
void led1()
{
	
}
void led2()
{
	
}
void led3()
{
	
}

/*******************************************************/
task sysTasks[RTO_u8_TASKS_NUM]={
	{1,led1},
	{1,led2},
	{3,led3}	
};

void RTO_voidInitialize(void)
{
	currentTick=0;
	OV_Counter=0;
	TIM0_voidSetRegister(RTO_u8_SET_REGISTER);
	TIM0_voidSetCallBack(kernel);
}	

static void kernel (void)
{
	OV_Counter++;
	if(OV_Counter==RTO_u16_MAX_OVERFLOW)
	{
		OV_Counter=0;
		TIM0_voidSetRegister(RTO_u8_SET_REGISTER);
		currentTick++;
		scheduler();
	}
}


static void scheduler(void)
{
	static u8 i;
	for(i=0;i<RTO_u8_TASKS_NUM;i++)
	{
		if(currentTick%sysTasks[i].periodicity==0)
		{
			sysTasks[i].taskHandler();
		}
	}
}




