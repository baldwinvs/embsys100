
#include "stm32f401xe.h"
#include "system_stm32f4xx.h"
#include <stdint.h>

// Helper function for waiting a short period of time.
void wait(void) {
    volatile uint32_t count = 500000;
    while(count > 0) {
        --count;
    }
}

int main()
{
    //enable the clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    //set the mode for GPIOA to general purpose output mode
    GPIOA->MODER |= GPIO_MODER_MODER5_0;

    while(1) {
        //toggle LD2, then wait for a short period of time
        GPIOA->ODR ^= GPIO_ODR_OD5;
        wait();
    }
    return 0;
}
