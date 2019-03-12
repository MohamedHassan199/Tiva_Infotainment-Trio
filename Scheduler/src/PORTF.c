#include "../inc/PORTF.h"
#include "../inc/bitwise_operation.h"


/*********************************************************************************
 *
 * Function: PORTF_Init
 *
 * @param: void
 *
 * @return: void
 *
 * Description: function to initialize PORTF that has the Red LED
 *
 *
 ********************************************************************************/
void PORTF_Init(void){

		Set_Bit(SYSCTL_RCGCGPIO_R,PORTF_CLK_INIT_PIN);
        while((SYSCTL_PRGPIO_R & PORTF_PERIPH_READY_MASK) == ZERO);

        Set_Bit(GPIO_PORTF_DIR_R,REDLEDPIN);
        Set_Bit(GPIO_PORTF_PUR_R,REDLEDPIN);
        Set_Bit(GPIO_PORTF_DEN_R,REDLEDPIN);

}
