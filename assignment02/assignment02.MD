# Assignment 02

### 1. Inject 0x7FFFFFFF for the ***counter*** value in the variable window, then step thru the program only once to increment ***counter***.

##### a) What is the value of the *counter* from the *Locals* window?

-2147483648

##### b) What is the value of the *counter* in the *Register* window?

0x80000000

##### c) Please note if the N and/or V flags are set in the APSR register? Explain why.

- **[N]**: *SET* - The resulting value is negative.
- **[V]**: *SET* - The maximum signed integer is 0x7FFFFFFF because of 2's complement; adding 1 to counter yielded 0x80000000 which is the minimum signed integer value in 2's complement. Going from one value to the other will result in this flag being set.

### 2. If you write all Fs (0xFFFFFFFF) in the Register value for ***counter*** then step step thru the program once to increment ***counter***:

##### a) What happens to the value of *counter* in the *Locals* window?

It becomes zero.

##### b) Please note if the N and/or V flags are set in the APSR register? Explain why.

- **[N]**: *NOT SET* - The resulting value is not negative.
- **[V]**: *NOT SET* - There was no signed integer overflow; the counter began at -1 and incremented to 0.

### 3. Change the ***counter*** variable type in your code to **unsigned**. Inject the value **0x7FFFFFFF** then step thru the program to increment the ***counter*** once:

##### a) What is the value of *counter* in the *Locals* window after incrementing for each value?

2147483648

##### b) Please note if the N and/or V flags are set in the APSR register? Explain why.

- **[N]**: *SET* - The resulting operation did not yield a negative value, but the most significant bit in counter is set which causes this flag to be set.
- **[V]**: *SET* - No overflow occurred in the unsigned value but in terms of a signed value, an overflow did occur.

### 4. Change the ***counter*** variable type in your code to **unsigned**. Inject the value **0xFFFFFFFF** then step thru the program to increment the ***counter*** once:

##### a) What is the value of *counter* in the *Locals* window after incrementing for each value?

0

##### b) What flags, if any, are set in the APSR? Explain why.

- **[N]**: *NOT SET* - The resulting value is not negative.
- **[V]**: *NOT SET* - There was no signed integer overflow; the counter began at UINT_MAX and incremented (rolled over) to 0.

### 5. Move the ***counter*** variable outside of main (at the top of the file):

##### a) What is the scope of the variable *counter*?

Global

##### b) Is it still visible in the *Locals* view?

No

##### c) In which window view can we track *counter* now?

The **Watch** view.

##### d) What is the address of the *counter* variable in memory?

0x20000000

### 6. Change the source code as described in Assignment_02.pdf, then run the program in the simulator:

##### a) What is the value of *counter* at the end of the program (halting at the *return 0* statement)?

4

##### b) Explain why the counter value has changed.

***counter*** is residing at the beginning of the SRAM (0x20000000) according to the **Watch** view. ***p_int*** is then pointing to the same memory location as ***counter***. The pre-increment operator is applied to the dereferenced value of ***p_int*** (which is ***counter***) 3 times followed by a single post-increment of ***counter***; resulting in the final value of **4**.

### 7. Change the setting of IAR to run the same program on the **evaluation board**.

##### a) What is the address where *counter* is stored?

0x20000000

##### b) Is the *counter* variable stored in RAM or ROM?

RAM

##### c) What is the value of *counter* at the end of the program (halting at the *return 0* statement)?

4
