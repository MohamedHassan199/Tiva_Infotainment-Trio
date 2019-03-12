#include "inc/types.h"
#include "inc/scheduler.h"
#include "inc/tasks.h"
#include "inc/PORTF.h"

#define F_CPU 16000000


int main(void)
{
	/*	Initialize PORTF */
	PORTF_Init();

	/*	Initialize the Scheduler	*/
	SchedulerInit();
/*The Scheduler uses the Systick Timer -> See Systick.h for timer configuration	*/

/*	Tasks Created by the user	*/

/* A task that toggles RED LED every one second 	*/
scheduler_Add_Task(TASK1_Toggle_LED1,ONE_SECOND,PRIORITY_1);


/*	Start the Scheduler	 */
	SchedulerStart();

}

