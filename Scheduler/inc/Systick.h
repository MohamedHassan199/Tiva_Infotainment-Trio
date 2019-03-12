#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include "tm4c123gh6pm.h"
#include "types.h"

uint16_t extern volatile SysTicks;
uint16_t extern volatile OsTicks;
uint8_t extern volatile Task_Counter;
uint8_t extern volatile flag;

void (*General_Ptr)(void);

void timer0_init();
void Systick_init();

/*void timer_delay(uint32 n);*/
#define TIMERVALUEFORONEMS ( 16000-1 )

#define NULL_CHARACTER '\0'

#define ONE 1

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

#define  ENABLE 0
#define  INTENABLE 1
#define  CLK_SRC 2

#define START_COUNT_FROM_250 250
#define COMPARE_VALUE_124 124
#define COMPARE_VALUE_248 248
#define INITIALIZE_TO_ZERO 0x00

#define NUM_OF_OVERFLOWS 1000

#define INITIAL_STATE 0
#define MAX_NUM_OF_STATES 2

#define GIE 7

#endif /* INC_SYSTICK_H_ */
