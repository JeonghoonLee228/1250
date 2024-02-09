/********************************************************************/
// HC12 Program:  YourProg - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        This B. You
// Details:       A more detailed explanation of the program is entered here               
// Date:          Date Created
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "SW_LED.h"
//Other system includes or your includes go here
#include <stdlib.h>
#include <stdio.h>


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
  //Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
  
/********************************************************************/
  // one-time initializations
/********************************************************************/
PT1AD1 &= 0x1F;
DDR1AD1 = 0xE0;
ATD1DIEN1 |= 0b00011111;

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    if(SWL_Pushed(SWL_LEFT))
    
    {
      SWL_ON(SWL_RED);

    }
    else
     {
     SWL_OFF(SWL_RED);
     }
      if(SWL_Pushed(SWL_CTR))
      {
        SWL_ON(SWL_YELLOW);
      } 
       
      else{
        SWL_OFF(SWL_YELLOW);
      }
      if(SWL_Pushed(SWL_RIGHT))
      {
        SWL_ON(SWL_GREEN);
      }
      else{
        SWL_OFF(SWL_GREEN);
      }
     // if(SWL_Pushed(SWL_UP))
     // {
      //  SWL_OFF(SWL_ALL);
      //}
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
