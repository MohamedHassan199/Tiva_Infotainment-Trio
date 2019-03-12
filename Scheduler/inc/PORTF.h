#ifndef PORTF_H
#define PORTF_H

#include "types.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"


#define RED 	(1U << 1) // 0000 0010
#define BLUE  	(1U << 2) // 0000 0100
#define GREEN 	(1U << 3) // 0000 1000
#define WHITE 	(1U << 1)|(1U << 2)|(1U << 3)
#define PORTF_CLK_INIT_PIN 5
#define PORTF_PERIPH_READY_MASK 0x00000020
#define ZERO 0

#define REDLEDPIN 1

void PORTF_Init(void);

#endif
