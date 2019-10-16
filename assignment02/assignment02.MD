# Assignment 02

#### 1. Inject 0x1FFFFFFF for the ***counter*** value in the variable window, then step thru the program only once to increment ***counter***.

###### a) What is the value of the ***counter*** from the ***Locals*** window?

    536870912

###### b) What is the value of the "counter" in the "Register" window?

    0x20000000

###### c) Which flags are set in the APSR register? Explain why?

    None.
    -  **N**: The resulting operation did not yield a negative value.
    -  **Z**: The resulting operation did not yield zero.
    -  **C**: No carry operations occurred.
    -  **V**: No overflow occurred.
    -  **Q**: As far as I know, saturation arithmetic isn't being used.

#### 2. If you write all Fs (0xFFFFFFFF) in the Register value for ***counter*** then step step thru the program once to increment ***counter***:

###### a) What happens to the value of ***counter*** in the ***Locals*** window?

    It becomes zero.

###### b) What flags, if any, are set in the APSR?

    The **[Z]**ero and **[C]**arry flags.

#### 3. Change the "counter" variable type in your code to **unsigned**. Inject the value **0x1FFFFFFF** then step thru the program to increment the ***counter*** once:

###### a) What is the value of ***counter*** in the **Locals** window after incrementing for each value?

    536870912

###### b) What flags, if any, are set in the APSR?  Explain why.

    None; see 1c.

#### 4. Change the ***counter*** variable type in your code to **unsigned**. Inject the value **0xFFFFFFFF** then step thru the program to increment the ***counter*** once:

###### a) What is the value of "counter" in the "Locals" window after incrementing for each value?

    0

###### b) What flags, if any, are set in the APSR? Explain why.

    -  **[Z]** is set because the resulting value is 0.
    -  **[C]** is set because the resulting value of the addition is greater than or equal to 2^32.

#### 5. Move the ***counter*** variable outside of main (at the top of the file):

###### a) What is the scope of the variable "counter"?

    Global

###### b) Is it still visible in the "Locals" view?

    No

###### c) In which window view can we track "counter" now?

    The **Watch** view.

###### d) What is the address of the "counter" variable in memory?

    0x20000000

#### 6. Change the source code as described in Assignment_02.pdf, then run the program in the simulator:

###### a) What is the value of ***counter*** at the end of the program (halting at the **return 0** statement)?

    4

###### b) Explain why the counter value has changed.

    ***counter*** is residing at the beginning of the SRAM (0x20000000) according to the **Watch** view.  ***p_int*** is then pointing to the same memory location as ***counter***.  Then the pre-increment operator is being applied to the dereferenced value of ***p_int***, which is counter, 3 times followed by a single post-increment of ***counter***; resulting in the final value of **4**.

#### 7. Change the setting of IAR to run the same program on the **evaluation board**.

###### a) What is the address where ***counter*** is stored?

    0x20000000

###### b) Is the ***counter*** variable stored in RAM or ROM?

    RAM

###### c) What is the value of ***counter*** at the end of the program (halting at the **return 0** statement)?

    4
