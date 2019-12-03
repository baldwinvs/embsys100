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

; The bit-band address is defined as:
; bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number x 4)

GPIOA_BASE EQU 0x40020000           ; constant for the GPIOA base address in SRAM
GPIOA_ODR EQU 0x14                  ; constant for the GPIOA_ODR offset from the GPIOA base address
GPIOA_ODR_PA5 EQU 0x5               ; bit number for LD2 for the GPIOA_ODR

PERIPH_ALIAS_BASE EQU 0x40000000    ; the peripheral bit-band alias base address
PERIPH_BIT_BAND_BASE EQU 0x42000000 ; the peripheral bit-band region base address

control_user_led
    PUSH {R4-R7, LR}                ; push necessary registers before modifying them
    LDR R4, =PERIPH_BIT_BAND_BASE   ; load PERIPH_BIT_BAND_BASE
    LDR R5, =GPIOA_BASE             ; load GPIOA_BASE
    LDR R6, =PERIPH_ALIAS_BASE      ; load PERIPH_ALIAS_BASE
    SUB R7, R5, R6                  ; calculate the byte offset
    LDR R6, =GPIOA_ODR              ; load the GPIOA ODR offset
    ADD R7, R7, R6                  ; add the GPIOA_ODR byte offset
    MOV R5, #32                     ; set R5 to the byte offset multiplier
    MUL R7, R7, R5                  ; calculate byte offset x 32
    LDR R6, =GPIOA_ODR_PA5          ; load GPIOA_ODR_PA5
    MOV R5, #4                      ; set R5 to the bit number multiplier
    MUL R6, R6, R5                  ; calculate bit number x 4
    ADD R7, R7, R6                  ; add the 2 calculations together to get the bit_word_offset
    ADD R4, R4, R7                  ; add the bit_word_offset to the bit_band_base to get the bit_word_addr
    STR R0, [R4]                    ; write to the bit_word_addr
    MOV R0, R1                      ; move the duration input R1 to R0 for the input of delay()
    BL delay                        ; branch to delay(), modifies LR
    POP {R4-R7, LR}                 ; pop registers
    BX LR                           ; branch back to the calling function
    END
