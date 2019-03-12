#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Systick.h"
#include "tasks.h"
#include "types.h"

#define OS_TICK_INTERVAL_MSEC 2000
#define MAX_NUM_OF_TASKS 4
#define ZERO 0
#define EXTRA_ONE_SLOT_FOR_THE_ARRANGMENT 1
#define TRUE 1
#define HIGH 1
#define LOW 0


//void SchedulerInit_AndStart(void); 
void SchedulerStart(void);
void SchedulerInit(void);
void Set_CallBack(tasktype pointer);
void Os_Schedule(void(*ptr[])(void), uint8_t arr_size );
void SetFlag(void);
void scheduler_Add_Task(tasktype Task_Name,uint16_t Periodicity,uint8_t Priority);
void Task_Arranger(void);
void swap(vTASK *T1,vTASK *T2);
void scheduler_Remove_Task(tasktype Task_Name);
void scheduler_Rerun_Removed_Task(tasktype Task_Name);

#endif /* SCHEDULER_H_ */
