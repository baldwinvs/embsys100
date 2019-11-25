/*******************************************************************************
File name       : swapPointersAsm.s
Description     : Assembly language function for swapping 2 characters
*******************************************************************************/

    PUBLIC swapPointersAsm  // Exports symbols to other modules
                            // Making swapPointersAsm available to other modules.

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
Function Name   : swapPointersAsm
Description     : swaps the content stored at addresses of R0 and R1.
C Prototype     : void swapPointersAsm(int** x, int** y)
                : Where x and y are double pointers to an integer.
Parameters      : R0: Address of pointer to x.
                : R1: Address of pointer to y.
Return value    : N/A
*******************************************************************************/

swapPointersAsm
    LDR R2, [R0]    ; load [R0] (int*) into R2, R2 == &x
    LDR R3, [R1]    ; load [R1] (int*) into R3, R3 == &y
    STR R3, [R0]    ; store R3 into [R0]
    STR R2, [R1]    ; store R2 into [R1]
    BX LR           ; return from function

    END
