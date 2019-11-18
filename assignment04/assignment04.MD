# Assignment 04

### 1. Using bit-band region for peripherals:

> Code:
>   - [main.c](problem1/main.c)

##### b. What instructions does the compiler produce in assembly for the "writing" to the GPIO bit when using bit-band address?

```c
MOV     R4, #1
STR     R4, [R1]
```

##### c. What were the instructions produced when writing to the GPIOx_ODR bit[5] directly?

```c
LDR     R4, [R0]
EOR.W   R4, R4, #32
STR     R4, [R0]
```

### 2. Create a function with multiple arguments (5 arguments for example) and call that function from within another function.  Trace through the assembler and note:

> Code:
>   - [main.c](problem2/main.c)

##### a. How does the calling function pass the values to the called function?

The calling function stores the first 4 values in registers R0-R3. Remaining values get stored into values on the stack.

##### b. What extra code did the compiler generate before calling the function with the multiple arguments?

```
STR.W   Rt, [SP {, #offset}]
MOV     Rd, Rn
```
Where:
- <b>Rt</b> is the register that is to be stored
- <b>#offset</b> is the offset from the SP (not all stores used an offset)
- <b>Rd</b> is the destination register in the move operation.

##### c. What extra code did the compiler generate inside the called function with the multiple list of arguments?

For the intermediate values that were stored on the stack and not passed through registers R0-R3:

```
MOVS.W  LR, #imm12
STR.W   LR, [SP, #offset]
```

<i><b>NOTE:</b></i> my code was only setting the values and not doing anything with them.  I assume that if they were being used then the `STR.W` might change into a `LDR`.

##### d. Any other observations?

- when moving data from R4-R7 into R0-R3 `MOVS` was used
- when moving data from R8+ into R0-R3 `MOV` was used
- before leaving my second to last function, `function_5()`, it looks like there was more data on the stack than was needed so before popping values from the stack the following operation occurred:
```c
ADD     SP, SP, #0x1c
```

### 3. Following the queue data structure approach, design, implement and test a stack data structure.

> Code:
>   - [main.c](problem3/main.c)
>   - [stack.h](problem3/stack.h)
>   - [stack.c](problem3/stack.c)

     
### 4. [BONUS] Using the power of pointers and type casting, create a function that can determine if a computer is big-endian or little-endian. Test your function in the simulator and modify the Project Options against:
<ol type="a">
  <li>Device STM32F401RE
  <li>Cortex M4 (Little Endian option)
  <li>Cortex M4 (Big Endian option)
</ol>

> Code:
>   - [main.c](problem4/main.c)