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
#include <assert.h>

char clr_scrn[] = { 27, 91, 50, 74, 0 };              // esc[2J
/* Public variables ----------------------------------------------------------*/
__IO uint32_t timer;
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */
/* Private prototype ---------------------------------------------------------*/
void delay(uint32_t time);

//import the sqrAsm function
extern int sqrAsm(int);

// this has to be global so that sqrAsm.s is able to import
char* myCstr;
/*******************************************************************************
Function Name   : main
Description     :
Parameters      :
Return value    :               */
void main() {
  Hw_init();

  PrintString(clr_scrn);

  const int input = 10;
  myCstr = "value to square: 10\n";
  const int output = sqrAsm(input);

  assert(output == (input * input));

  char str[32];
  sprintf(str, "\t%d^2 = %d\n", input, output);
  PrintString(str);

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
