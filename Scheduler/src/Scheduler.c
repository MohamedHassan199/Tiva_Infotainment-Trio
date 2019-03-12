#include "../inc/Scheduler.h"
#include "../inc/tasks.h"
#include "../inc/Systick.h"


void(*SetFlag_Ptr)(void) = &SetFlag;
vTASK Task_Array[NUM_OF_TASKS] = {NULL_CHARACTER};


/*********************************************************************************
 *
 * Function: SchedulerStart
 *
 * @param: void
 *		
 * @return: void
 *
 * Description: function to start the OS Scheduler
 *
 *
 ********************************************************************************/
void SchedulerStart(void)
{		
		/*	Timer0 initialization	*/
			Systick_init();

		/*	Enable global interrupt	*/
		//	Set_Bit(GICR,INT2);
		//	Set_Bit(MCUCSR,ISC2);
		
		/*	TO ENABLE THE PRIORITY FEATURE	*/
		Task_Arranger();
	
	while (TRUE)
	{
		if (flag == HIGH)
		{
			flag = LOW;
			Os_Schedule(ReadyQueue,NUM_OF_TASKS);			
		}
	}
}


/*********************************************************************************
 *
 * Function: SchedulerInit
 *
 * @param: void
 *		
 * @return: void
 *
 * Description: function to initialize the OS Scheduler
 *
 *
 ********************************************************************************/
void SchedulerInit(void)
{
	Set_CallBack(SetFlag_Ptr);		
}


 /*********************************************************************************
 *
 * Function: Os_Schedule
 *
 * @param: void(*ptr[])(void), Array of pointers to functions that have the tasks
 *		   uint8 arr_size, The size of the array of pointers 
 * @return: void
 *
 * Description: function to call the 3 tasks at the same time each OS tick
 *
 *
 ********************************************************************************/
void Os_Schedule(void(*ptr[])(void), uint8_t arr_size )
{uint8_t i;
for (i = ZERO ; i < arr_size ; i++)
{
	if (NULL_CHARACTER != ptr[i])
	{
		Task_Array[i].RemainingTicksBeforeExcution--;
		if (Task_Array[i].RemainingTicksBeforeExcution == ZERO)
		{
			ptr[i]();
			Task_Array[i].RemainingTicksBeforeExcution = Task_Array[i].periodicity;
		}
	}
}
}

 /*********************************************************************************
 *
 * Function: SetFlag
 *
 * @param: void 
 * @return: void
 *
 * Description: function to set a flag that an OS tick occurred
 *
 *
 ********************************************************************************/
void SetFlag(void)
{
flag = HIGH;	
}

 /*********************************************************************************
 *
 * Function: scheduler_Add_Task
 *
 * @param: void(*ptr[])(void), Array of structures that have the tasks
 *		   uint8 Periodicity, The period of each task
 *			uint8 Priority, The Priority of each task 
 * @return: void
 *
 * Description: function to add tasks during runtime
 *
 *
 ********************************************************************************/
void scheduler_Add_Task(tasktype Task_Name,uint16_t Periodicity,uint8_t Priority)
{
	static uint8_t TaskCtr = 0;
			Task_Array[TaskCtr].address = Task_Name;
			Task_Array[TaskCtr].periodicity = Periodicity;
			Task_Array[TaskCtr].RemainingTicksBeforeExcution = Periodicity;
			Task_Array[TaskCtr].Priority = Priority;
  ReadyQueue[TaskCtr] = Task_Array[TaskCtr].address;	
  TaskCtr++;
}

 /*********************************************************************************
 *
 * Function: scheduler_Remove_Task
 *
 * @param: void(*ptr[])(void), Array of structures that have the tasks
 * @return: void
 *
 * Description: function to remove a tasks at runtime
 *
 *
 ********************************************************************************/
void scheduler_Remove_Task(tasktype Task_Name)
{	uint8_t index;
	for (index = 0; index < NUM_OF_TASKS; index++ )
	{
		if (Task_Name == Task_Array[index].address)
		{
			ReadyQueue[index] = NULL_CHARACTER;
		}
	}
}

/*********************************************************************************
 *
 * Function: swap
 *
 * @param: void 
 * @return: void
 *
 * Description: function to swap two variables
 *
 *
 ********************************************************************************/
void swap(vTASK* T1,vTASK* T2)
{
	vTASK temp;
	temp = *T1;
	*T1 = *T2;
	*T2 = temp;
}

 /*********************************************************************************
 *
 * Function: Task_Arranger
 *
 * @param: void 
 * @return: void
 *
 * Description: function to set a flag that an OS tick occurred
 *
 *
 ********************************************************************************/
void Task_Arranger()
{	uint8_t i,j;
	for(i = ZERO; i < NUM_OF_TASKS-1 ; i++ )
	{
		for(j = i; j < NUM_OF_TASKS ; j++ )
		{
			if (Task_Array[i].Priority > Task_Array[j].Priority )
			{
				swap(&Task_Array[i],&Task_Array[j]);
			}
		}
	}
	for (i = ZERO; i < NUM_OF_TASKS; i++)
	{
		ReadyQueue[i] = Task_Array[i].address;
	}	
}

/*********************************************************************************
 *
 * Function: scheduler_Rerun_Removed_Task
 *
 * @param: void(*ptr[])(void), Array of structures that have the tasks
 * @return: void
 *
 * Description: function to remove a tasks at runtime
 *
 *
 ********************************************************************************/
void scheduler_Rerun_Removed_Task(tasktype Task_Name)
{
	uint8_t index;
	for (index = ZERO; index < NUM_OF_TASKS; index++ )
	{
		if (Task_Name == Task_Array[index].address)
		{
			ReadyQueue[index] = Task_Array[index].address;
		}
	}
}
