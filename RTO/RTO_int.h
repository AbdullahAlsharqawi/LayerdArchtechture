/*************************************************/
/* Author : Abdullah Muhammad                    */
/* Date   : 14/3/2018                        	 */
/* Version: V01 2                    		     */
/*************************************************/

#ifndef _RTO_INT_H
#define _RTO_INT_H

#define RTO_u8_RUNNING          22
#define RTO_u8_SUSPENDED        9


typedef struct
{
	u8 Periodicity;
	void (*TaskHandler)(void);
	u8 FirstDelay;
	u8 State;
}Task;


void RTO_voidInitialize(void);
void RTO_voidCreatTask(Task* Copy_u8Task,u8 Copy_u8Priority);
void RTO_voidDeleteTask(u8 Copy_u8Priority);
void RTO_voidSuspendTask(u8 Copy_u8Priority);
void RTO_voidContinueTask(u8 Copy_u8Priority);

#endif

