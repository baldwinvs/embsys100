# Assignment 06

### 1. Use the CMSIS to implement code that blinks the user LED on the STM32 board.
|   | Description |
|:-:|:------------|
| 1 | Create a new project. |
| 2 |Create a main.c file and add it to the project. |
| 3 |Add the files <b>stm32f401xe.h</b> & <b>system_stm32f4xx.h</b> to the folder where <b>main.c</b> is saved. <i>You should be able to get these files thru STM32CubeMX. You could also get them by downloading the zip file <b>CMSIS_STM32_Device_Specific_Files.zip</b> from canvas site under the link [Assignment\A06 folder](https://canvas.uw.edu/courses/1325909/files/folder/EMBSYS%20100%2019/Assignments/A06)</i> |
| 4 |Enable use of CMSIS in project options settings. |
| 5 |Implement toggling of the LED using the CMSIS data structures. |


> Code:
>  - [main.c](problem01/main.c)

### 2. Convert the blinking led program into assembly code.
|   | Description |
|:-:|:------------|
| 1 | Go to the link [Assignment\A06 folder](https://canvas.uw.edu/courses/1325909/files/folder/EMBSYS%20100%2019/Assignments/A06) and download the zip file <b><i>Module07_Assignment06_Starter_Code.zip</i></b>. Use the skeleton files (<b>main.c</b>, <b>user_led.s</b>, and <b>delay.s</b>) inside that zip file. |
| 2 | Create a new project and add the skeleton files to that project. |
| 3 | Make sure to setup the project to connect to your board (follow instructions form <b>Module_02</b> if you forgot how to do that). |
| 4 | Implement the function <b>control_user_led</b> in assembly.<br>&bull; The function takes as input the led requested state (0 == OFF, 1 == ON) and the duration for holding the state.<br>&bull; The function returns void. |
| 5 | Implement the function <b>delay</b> in assembly.<br>&bull; The function takes as input an integer value.<br>&bull; The function will decrement the value until it reaches 0.<br>&bull; Then returns void.<br>&bull; Call the <b>control_user_led</b> function from a while loop in main.<br>&bull; For any C code, use only data types defined in the “stdint.h” file</ul> |

<pre>
<b><i>Hints:</b>
a. Implement delay in assembly first. Once it works, implement <b>control_user_led</b> function.

b. Use your simple LED code that made use of the peripheral registers (<b>not</b> the bit-banding registers).

c. It is ok to use a hard code value of the ODR (Output Data Register) address for GPIOA and store it into one of the CPU scratch registers.</i>
</pre>

> Code:
>  - [main.c](problem02/main.c)
>  - [user_led.s](problem02/user_led.s)
>  - [delay.s](problem02/delay.s)

### 3. Generate the map file for your program and provide details on:

##### a. How much total ROM your program is occupying?

//stuff

##### b. How much total RAM your program is using?

//stuff

##### c. What part of your program is using the most ROM?

//stuff

##### d. What part of your program is using the most RAM?

//stuff

### 4. BONUS: Anything that can be done to optimize the usage of ROM or RAM resources? Explain any options.

//stuff

### 5. BONUS: Re-implement the control_user_led to use the bit-band region for accessing the Output Data Register (ODR) for GPIOA in order to toggle the LED ON/OFF.
<pre>
<b><i>Hint:</b>
It is ok to use a hard code value of the ODR bit-band address for GPIOA and store it into one of the CPU scratch registers.</i>
</pre>

> Code:
>  - [main.c](problem05/main.c)
>  - [user_led.s](problem05/user_led.s)
>  - [delay.s](problem05/delay.s)