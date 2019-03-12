#ifndef TASKS_H_
#define TASKS_H_

#include "Systick.h"
#include "bitwise_operation.h"
#include "types.h"

typedef void(*tasktype)(void);
#define NUM_OF_TASKS 2

#define PRIORITY_7 7
#define PRIORITY_6 6
#define PRIORITY_5 5
#define PRIORITY_4 4
#define PRIORITY_3 3
#define PRIORITY_2 2
#define PRIORITY_1 1

#define FALSE 0

#define ONE_SECOND 1000
#define ONE_AND_HALF_SECONDS 1500
#define TWO_SECONDS 2000
#define HALF_SECOND 500
#define FIVE_MILLISECOND 5

#define RED_LED 1

typedef struct {
	tasktype address;
	uint16_t periodicity;
	uint16_t RemainingTicksBeforeExcution;
	uint8_t Priority;
} vTASK;



void TASK1_Toggle_LED1(void);

tasktype extern ReadyQueue[NUM_OF_TASKS];
 
#endif /* TASKS_H_ */
