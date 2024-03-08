/********************************************************************/
// HC12 Program:  project1
// Processor:     MC9S12XDP512
// Bus Speed:    8 MHz
// Author:       Jeonghoon Lee
// Details:       A more detailed explanation of the program is entered here
// Date:          Date Created
// Revision History :
//  each revision will have a date + desc. of changes

/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
// #include "clock.h"
#include "SW_LED.h"
// #include "rti.c"
// Other system includes or your includes go here
// #include <stdlib.h>
// #include <stdio.h>

/********************************************************************/
// Defines
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
  // Any main local variables must be declared here
 

  // main entry point
  _DISABLE_COP();
  // EnableInterrupts;

  /********************************************************************/
  // one-time initializations
  /********************************************************************/
SWL_Init();
 RTI_Init();
  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {
    if(SWL_Pushed(SWL_UP) && !SWL_Pushed(SWL_DOWN))
    {
      SWL_OFF(SWL_GREEN);
      SWL_TOG(SWL_RED);
 RTI_Delay_ms(8);
    }
    else if(SWL_Pushed(SWL_DOWN)&& !SWL_Pushed(SWL_UP))
    {
      SWL_OFF(SWL_GREEN);
      SWL_TOG(SWL_RED);
      RTI_Delay_ms(12);
    }
    else if (SWL_Pushed(SWL_LEFT))
    {
      SWL_OFF(SWL_GREEN);
      SWL_ON(SWL_RED);
      RTI_Delay_ms(1);
      SWL_OFF(SWL_RED);
      RTI_Delay_ms(9);
    }
    else if (SWL_Pushed(SWL_RIGHT))
    {
      SWL_OFF(SWL_RED);
      SWL_ON(SWL_GREEN);
    }
    else
    {
      SWL_OFF(SWL_GREEN);
      SWL_TOG(SWL_RED);
      RTI_Delay_ms(10);
    }
    
    

      
    
  }
}


  /********************************************************************/
  // Functions
  /********************************************************************/

  /********************************************************************/
  // Interrupt Service Routines
  /********************************************************************/
