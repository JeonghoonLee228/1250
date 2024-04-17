/********************************************************************/
// HC12 Program:  lab2 - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Jeonghoon Lee
// Details:       A more detailed explanation of the program is entered here
// Date:         Apr 17th, 2024
// Revision History :
//  each revision will have a date + desc. of changes

/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "rti.h"
#include "SW_LED.h"
#include "segs.h"

// Other system includes or your includes go here

/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned counter = 0;
unsigned segcounter = 0;
unsigned dotcounter = 3;
int button = 0;

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
  RTI_Init();
  SWL_Init();
  Segs_Init();

  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {
    RTI_Delay_ms(50);
//running everytime the counter is at 4 or at multiples of 4 up to 20, since the counter gets reset at 20;
    if ((counter % 4) == 0)
    {
      if (dotcounter == 8)
      {
        dotcounter = 3;
        Segs_ClearLine(1);
      }
      if (dotcounter != 3)
      {
        Segs_Custom(dotcounter, 0b00000000);
      }

      dotcounter++;//the position
    }

    //every 20 iterations, toggle the green led and set the counter to 0
    if (counter == 20)
    {
      segcounter++;   
      counter = 0;
      SWL_TOG(SWL_GREEN);
    }

    // button logic!!
   if(SWL_Pushed(SWL_UP))
   {
button = 1;
   }
   else if (SWL_Pushed(SWL_DOWN))
{
  button = 0;
}    
if(button ==1)
{
  Segs_16H(segcounter,0);
}
else if(button == 0)
{
  Segs_16D(segcounter,0);
}
if(segcounter == 9999)
{
  segcounter =0;
}
if(SWL_Pushed(SWL_CTR))
{
  segcounter =0;
}
    SWL_TOG(SWL_RED);
    counter++;
  }
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
