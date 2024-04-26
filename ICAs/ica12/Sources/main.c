/********************************************************************/
// HC12 Program:  ica10 - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Jeonghoon Lee
// Details:       A more detailed explanation of the program is entered here               
// Date:          april 11th, 2024
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "lcd.h"
#include "clock.h"
//Other system includes or your includes go here
#include <stdlib.h>
#include <stdio.h>
#include "SW_LED.h"

/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
 
/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  

  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
SWL_Init();
/********************************************************************/
  // one-time initializations
/********************************************************************/
Clock_Set20MHZ();
lcd_Init();


/********************************************************************/
  // main program loop
/********************************************************************/
//lcd_Addr(3);//set cusor pos at 3 (0,1,2,3,etc...)
//lcd_String("hello"); //
//lcd_Data('Q');
//lcd_Clear();

lcd_AddrXY(0,3);
lcd_String("hello");
lcd_AddrXY(0,0);
lcd_String("hello");
lcd_AddrXY(0,1);
lcd_String("hello");
lcd_AddrXY(0,2);
lcd_String("hello");



  for (;;)
  { 

}




}



/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
