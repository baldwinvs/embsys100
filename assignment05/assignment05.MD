# Assignment 05

### 1. Create a function that allows swapping of two pointers.

> Code: [main.c](problem1/main.c)<br>

##### a. Explain what the “main” function does to the CSTACK in order setup the input arguments prior to calling the swap_pointer() function?

- Five registers are pushed to the CSTACK:
   ```c
   {R3-R7, LR}
   ```
- For the two integer values, the values are set in registers and then those registers are stored in their respective position in the CSTACK.
- For the two pointer values, the stack pointers (for the respective variable) are set in registers and then those registers are stored in their respective position in the CSTACK.

##### b. And what are the values in R0 & R1 when swap_pointer() is called?

The values stored in <b>R0</b> and <b>R1</b> are the addresses in the CSTACK of the respective pointers.

##### c. Share a screen shot of the local variables inside of “main” after the function swap_pointer() returns.

> [Local variables screen shot](problem1/output.png)

### 2. Run sqrAsm code from the class demo:<br>
- Copy HelloWorld from Assignment 1.
- Download the file sqrAsm.s and copy it to the project directory.
- In IAR, add sqrAsm.s file to your project. Now you should be able to see the file from the Workspace Window.
- Modify main.c to call sqrAsm function.
- Run your program on the board, and capture the output from TeraTerm.

> Code: [main.c](problem2/main.c)<br>
> [TeraTerm output](problem2/output.png)

### 3. Create a new file div2Asm.s and add the file to the same HelloWorld project above.
- Write the assembly code to take an input argument, divide it by 2, and return the result.
- Invoke the function “PrintString” from within divAsm before doing the division computation.
- Add a comment for every statement in your assembly function code.
- In the main.c, invoke dev2Asm(foo) and capture the screen output from TeraTerm.

> Code:
>  - [main.c](problem3/main.c)
>  - [div2Asm.s](problem3/div2Asm.s)

> [TeraTerm output](problem3/output.png)

### 4. Implement a swap function in assembly and call it “swapCharsAsm”:
- It takes as input two variables of char data type and swaps the two chars
- Add a comment for every statement in your assembly function code.
- <b>Bonus:</b> Returns 0 if the two chars are identical; otherwise, return 1.

> Code:
>  - [main.c](problem4/main.c)
>  - [swapCharsAsm.s](problem4/swapCharsAsm.s)

### 5. Bonus: Implement the swap_pointer() function from #1 above in assembly and call it swapPointersAsm().
- Add a comment for every statement in your assembly function code.
- Take a snap shot of the output after invoking the swapPointerAsm() subroutine.

> Code:
>  - [main.c](problem5/main.c)
>  - [swapPointersAsm.s](problem5/swapPointersAsm.s)

> [Local variables screen shot](problem5/output.png)