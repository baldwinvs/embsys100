#include "stm32f401xe.h"

extern uint32_t CSTACK$$Limit;
extern void __iar_program_start(void);

//! Initialize the SysTick registers to trigger the SysTick exception at 1Hz.
void initSysTick(void);

// Local functions
//! Toggle the LD2 LED.
static void SysTick_Handler(void);
static void default_fault_handler(void);
static void default_pass_thru_handler(void);

//! Override the vector table with a custom vector table.
const uint32_t __vector_table[] @ ".intvec" = {
    (uint32_t)&CSTACK$$Limit,               // Initial SP value
    (uint32_t)&__iar_program_start,         // Reset
    (uint32_t)&default_fault_handler,       // NMI
    (uint32_t)&default_fault_handler,       // Hard fault
    (uint32_t)&default_fault_handler,       // Memory management fault
    (uint32_t)&default_fault_handler,       // Bus fault
    (uint32_t)&default_fault_handler,       // Usage fault
    0,                                      // Reserved 7
    0,                                      // Reserved 8
    0,                                      // Reserved 9
    0,                                      // Reserved 10
    (uint32_t)&default_pass_thru_handler,   // SV Call
    (uint32_t)&default_pass_thru_handler,   // Reserved for Debug
    0,                                      // Reserved 13
    (uint32_t)&default_pass_thru_handler,   // PendSV
    (uint32_t)&SysTick_Handler              // Systick
};

void SysTick_Handler(void)
{
    GPIOA->ODR ^= GPIO_ODR_OD5;
}

void initSysTick(void)
{
    volatile uint32_t* SYS_TICK_BASE = (uint32_t*)0xE000E010;
    volatile uint32_t* SYST_CSR = SYS_TICK_BASE;
    volatile uint32_t* SYST_RVR = (SYS_TICK_BASE + 1);
    volatile uint32_t* SYST_CRV = (SYS_TICK_BASE + 2);

    // The correct initialization sequence for the SysTick counter is:
    // 1: Program reload value (reload value = 0xF423FF).
    // 2: Clear current value (write to clear to 0).
    // 3: Program Control and Status Register (set bits [2:0]).

    //SYST_RVR: 0xE000E014 [SysTick Reload Value Register]
    // Set RELOAD to the frequency of the processor clock [16 MHz] (0xF42400 - 1)
    *SYST_RVR = 0xF423FF;

    //SYST_CVR: 0xE000E018 [SysTick Current Value Register]
    // DO NOT WRITE TO THIS REGISTER unless it needs to be cleared. Write clears to 0.
    *SYST_CRV = 0x0;

    //SYST_CSR: 0xE000E010 [SysTick Control and Status Register]
    // Set CLKSOURCE to processor clock (0x4)
    // Set TICKINT to assert the exception when the counter reaches zero(0x2)
    // Set ENABLE to counter enabled (0x1)
    *SYST_CSR |= 0x7;
}

void default_fault_handler(void)
{
    while(1) {}
}

void default_pass_thru_handler(void)
{
    // do nothing, pass through
}