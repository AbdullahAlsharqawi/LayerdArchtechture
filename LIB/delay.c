#include "STD_TYPES.h"

#define Z 9200
#define M 5300

void Delay_ms(u32 DelayValue)
{
	u32 i = 0;
	u32 count = (DelayValue*1000000 - Z)/(M+125);
	for(;i < count ; i++)
		asm("NOP");
}
