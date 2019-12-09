#include "stm32f401xe.h"
#include "system_stm32f4xx.h"
#include <stdint.h>

void initLD2(void);
extern void initSysTick(void); // defined in stm32f401xe.c

int main()
{
    initLD2();
    initSysTick();

    while(1) {}
    return 0;
}

void initLD2(void)
{
    //enable the clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    //set the mode for GPIOA to general purpose output mode
    GPIOA->MODER |= GPIO_MODER_MODER5_0;
}