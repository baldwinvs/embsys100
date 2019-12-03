/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/

    EXTERN delay  // delay() is defined outside this file.

    PUBLIC control_user_led         // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions,
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8.
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)

    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions

/*******************************************************************************
Function Name   : control_user_led
Description     : - Uses Peripheral registers at base 0x4000.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/

GPIOA_BASE EQU 0x40020000       ; constant for the GPIOA base address in SRAM
GPIOA_ODR EQU 0x14              ; constant for the GPIOA_ODR offset from the GPIOA base address

control_user_led
    PUSH {R4, LR}               ; push necessary registers before modifying them
    LDR R2, =GPIOA_BASE         ; load the GPIOA base address into R2
    LDR R3, [R2, #GPIOA_ODR]    ; load the value stored in the GPIOA_ODR hardware register
    LSL R4, R0, #5              ; left shift R0 5 bits
    CMP R0, #0                  ; check if R0 is 0, update PSR
    ITE EQ                      ; if-then-else on EQ condition
    ANDEQ R3, R3, R4            ; EQ: bitwise-and R3 and R4, store in R3
    ORRNE R3, R3, R4            ; NE: bitwise-or R3 and R4, store in R3
    STR R3, [R2, #GPIOA_ODR]    ; store R3 back to the GPIOA_ODR hardware register
    MOV R0, R1                  ; move the duration input R1 to R0 for the input of delay()
    BL delay                    ; branch to delay(), modifies LR
    POP {R4, LR}                ; pop registers
    BX LR                       ; branch back to the calling function
    END
