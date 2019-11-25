/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swapping 2 characters
*******************************************************************************/

    PUBLIC swapCharsAsm // Exports symbols to other modules
                        // Making swapCharsAsm available to other modules.

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
Function Name   : swapCharsAsm
Description     : swaps the content stored at addresses of R0 and R1.
C Prototype     : int swapCharsAsm(char* x, char* y)
                : Where x and y are pointers to characters.
Parameters      : R0: Address of first character
                : R1: Address of second character
Return value    : R0: 0 if the characters being pointed at by x and y are the same
                :     otherwise return 1
*******************************************************************************/

swapCharsAsm
    PUSH {R4}       ; push R4 before use in function
    MOVS R2, R1     ; move R1 into R2
    MOVS R1, R0     ; move R0 into R1
    MOVS R0, #0     ; set the default return value to 0
    LDRB R3, [R1]   ; load [R1] into R3, R3 == x
    LDRB R4, [R2]   ; load [R2] into R4, R4 == y
    CMP R3, R4      ; compare R3 to R4, modifies APSR
    BEQ finish      ; branch to finish label if Z == 1
    STRB R4, [R1]   ; store R4 (y) into [R1] (&x)
    STRB R3, [R2]   ; store R3 (x) into [R2] (&y)
    MOVS R0, #1     ; set the return value to 1
    B finish        ; branch to finish
finish:             ; local label for restoring R4 and setting the return value to 0
    POP {R4}        ; restore R4
    BX LR           ; return from function with result in R0

    END
