/*******************************************************************************
FILE NAME   : main.c
DESCRIPTION : Where all the magic begins.


Copyright   : David Allegre
            : 2015
	    : All Rights Reserved
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "nucleoboard.h"
#include "hw_init.h"
#include "print.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

char clr_scrn[] = { 27, 91, 50, 74, 0 };              // esc[2J
/* Public variables ----------------------------------------------------------*/
__IO uint32_t timer;
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */
/* Private prototype ---------------------------------------------------------*/
void delay(uint32_t time);

//import the div2Asm function
extern int div2Asm(int);

// this has to be global so that div2Asm.s is able to import
char* myCstr;
#define STR_SIZE (32)
/*******************************************************************************
Function Name   : main
Description     :
Parameters      :
Return value    :               */
void main() {
  Hw_init();

  PrintString(clr_scrn);

  char str[STR_SIZE];
  memset(str, 0, STR_SIZE);
  myCstr = str;

  // positive value
  {
      const int input = INT_MAX;
      sprintf(str, "value to divide by 2: %d\n", input);
      const int output = div2Asm(input);

      assert(output == (input / 2));

      sprintf(str, "\t%d / 2 = %d\n", input, output);
      PrintString(str);
  }
  //negative value
  {
      const int input = INT_MIN;
      sprintf(str, "value to divide by 2: %d\n", input);
      const int output = div2Asm(input);

      assert(output == (input / 2));

      sprintf(str, "\t%d / 2 = %d\n", input, output);
      PrintString(str);
  }
  //zero value
  {
      const int input = 0;
      sprintf(str, "value to divide by 2: %d\n", input);
      const int output = div2Asm(input);

      assert(output == (input / 2));

      sprintf(str, "\t%d / 2 = %d\n", input, output);
      PrintString(str);
  }

  while (1) {
    // loop forever
    asm("nop");
  }
}


void delay(uint32_t time) {

  timer = time;
  while(timer) {}
}
void SystemInit(void) {
  // System init is called from the assembly .s file
  // We will configure the clocks in hw_init
  asm("nop");
}
