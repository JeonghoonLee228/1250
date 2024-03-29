






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
#include "clock.h"
#include "clock.c"
//Other system includes or your includes go here


/********************************************************************/
//Defines
/********************************************************************/
PLLCTL = PLLCTL_PLLON_MASK | PLLCTL_AUTO_MASK;
ECLKCTL &= ~ECLKCTL_NECLK_MASK;
CLKSEL |= CLKSEL_PLLSEL_MASK;
/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/

/********************************************************************/
// Constants
/********************************************************************/
PLLCTL = 0b01100000;
SYNR = 6; 
REFDV = 5;
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


/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
while(!(CRGFLG & CRGFLG_LOCK_MASK));
CLKSEL |= 0b10000000;
ECLKCTL &= ~ECLKCTL_NECLK_MASK;
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/

