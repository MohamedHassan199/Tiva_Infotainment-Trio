#include "../inc/Systick.h"
#include "../inc/tm4c123gh6pm.h"
#include "../inc/types.h"


/* A set of global variables used by the Scheduler	*/
 uint16_t volatile SysTicks = INITIALIZE_TO_ZERO;
 uint16_t volatile OsTicks = INITIALIZE_TO_ZERO;
 uint8_t  volatile Task_Counter = INITIALIZE_TO_ZERO;
 uint8_t  volatile flag = INITIALIZE_TO_ZERO;
 
 /*********************************************************************************
 *
 * Function: Systick_init
 *
 * @param: void
 *
 * @return: void
 *
 * Description: function initialize the Systick timer that controls the OS
 *
 *
 ********************************************************************************/
void Systick_init()
{
	NVIC_ST_CTRL_R |= (ONE << INTENABLE);
	NVIC_ST_CTRL_R |= (ONE << CLK_SRC);
	NVIC_ST_RELOAD_R = TIMERVALUEFORONEMS;
	NVIC_ST_CTRL_R |= (ONE << ENABLE);
}


/*********************************************************************************
 *
 * Function: Systick_IntHandler
 *
 * @param: void
 *
 * @return: void
 *
 * Description: The ISR of the Systick Timer
 *
 *
 ********************************************************************************/
Systick_IntHandler()
{
SysTicks++;

	if ( NULL_CHARACTER != General_Ptr )
	{
		(*General_Ptr)();
	} 

}
 /*********************************************************************************
 *
 * Function: Set_CallBack
 *
 * @param: void(*ptr[])(void), Pointers to a function in the OS 
 * @return: void
 *
 * Description: function to Set the address of a function in the OS
 *		to a pointer as a way to tell the timer this is the address of the 
 *		function you have to call whenever a tick occurs
 *
 ********************************************************************************/
void Set_CallBack(void (*ptr)(void)){
	
	General_Ptr = ptr;
		
}
