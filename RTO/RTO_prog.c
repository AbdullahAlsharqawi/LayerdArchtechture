/*************************************************/
/* Author : Abdullah Muhammad                    */
/* Date   : 14/3/2018                        	 */
/* Version: V01 2                    		     */
/*************************************************/


                                                          /******************************************************/
static Task* RTO_SysTasks [RTO_u8_TASKS_NUM]={(Task*)0};  /*this is the 0 address in the ram .there is noting   */
                                                          /*called null as it is a #define and it can have any  */
														  /*possible value i wil initialize all the tasks with 0*/
														  /*and when i found 0 it means this task is not present*/
														  /*and the zero addres is the first global variable    */
														  /*adrress.                                            */
                                                          /******************************************************/
void RTO_voidInitialize(void)
{
	
}

void RTO_voidCreatTask(Task* Copy_u8Task,u8 Copy_u8Priority)
{
	RTO_SystTasks[Copy_u8Priority]=Copy_u8Task
}

void RTO_voidDeleteTask(u8 Copy_u8Priority)
{
	RTO_SystTasks[Copy_u8Priority]=(TASK*)0;
}

void RTO_voidSuspendTask(u8 Copy_u8Priority)
{
	RTO_SystTasks[Copy_u8Priority] -> state =RTO_u8_SUSPENDED;
}

void RTO_voidContinueTask(u8 Copy_u8Priority)
{
	RTO_SystTasks[Copy_u8Priority] -> state =RTO_u8_RUNNING;
}

static void RTO_voidScheduler(void)
{
	for (i=0;i<RTO_u8_TASKS_NUM;i++)      //
	{
		if(RTO_SysTasks[i] !=(Task*)0)
		{
			if(RTO_SysTasks[i] -> State != RTO_u8_SUSPENDED)    /*cyclometic complexity :is the number of nested */
                                                              	/*loop or if,and it is not a good thing as every */
																/*scope opens a new stack                        */
			{
				if (RTO_SystTasks[i] -> FirstDelay) == 0)  //run the task
				{
					Run Task();           //run the task
					RTO_SysTasks[i] -> FirstDelay = RTO_SysTasks[i] -> Periodicity;      //  periodicty -1
				}
				else
				{
					(RTO_SysTasks[i] -> FirstDelay) -- ;
				}
			}
		}
	    else
	    {
		/*No task to do*/
	    }
	}	
}

