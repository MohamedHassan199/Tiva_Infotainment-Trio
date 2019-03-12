#include "../inc/tasks.h"
#include "../inc/Scheduler.h"
#include "../inc/PORTF.h"


 /*********************************************************************************
 *
 * Function: TASK1_Toggle_LED1
 *
 * @param: void
 *		
 * @return: void
 *
 * Description: Task created to toggle the Red LED on PORTF pin 1
 *
 *
 ********************************************************************************/
void TASK1_Toggle_LED1(void)
{
	Toggle_Bit(GPIO_PORTF_DATA_R,RED_LED);
}

/************************************************************************
*			CREATE THE TASK POINTER ARRAY							    *																		*
************************************************************************/
tasktype ReadyQueue[NUM_OF_TASKS];

//vTASK Task_Array[NUM_OF_TASKS] = {};
