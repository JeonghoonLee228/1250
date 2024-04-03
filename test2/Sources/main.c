/********************************************************************/
// HC12 Program:  test2
// Processor:     MC9S12XDP512
// Bus Speed:      20 MHz
// Author:        Jeonghoon Lee
// Details:       A more detailed explanation of the program is entered here               
// Date:         april 03rd, 2024
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "SW_LED.h"
#include "MISC.h"
#include "rti.h"
#include "clock.h"
#include "sci.h"
// Other system includes or your includes go here
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
long counter;
char str;
int g;
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
SWL_Init();
  RTI_Init();
  sci0_Init2();
sci0_InitEnum(BAUD_38400_BUS20MHZ);
Clock_Set20MHZ();
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
   /* RTI_Delay_ms(10);
SWL_TOG(SWL_RED);
sci0_txByte2('L');
*/

if(counter == 57160)
{
  
  
  if(SWL_Pushed(SWL_UP))
  {
    sprintf(str, "\x1b[3;0H",g%80)
     sci0_txByte2(str);
  }
  if(SWL_Pushed(SWL_DOWN))
  {
    sprintf(str, "\x1b[3;0H",g%80)
    sci0_txByte2(str);
  }
  else{
    sprintf(str, "\x1b[3;0H",g%80)
   sci0_txByte2(str);
  }
  SWL_TOG(SWL_GREEN);
  counter = 0;
  
}
counter++;

  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
