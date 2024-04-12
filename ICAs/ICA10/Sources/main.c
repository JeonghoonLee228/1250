/********************************************************************/
// HC12 Program:  YourProg - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Jeonghoon Lee
// Details:       A more detailed explanation of the program is entered here               
// Date:          Date Created
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "segs.h"
#include "SW_LED.h"
#include "rti.h"
//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
 unsigned counter =  0;
/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  //Any main local variables must be declared here
Segs_Init();
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
    
Segs_8H(0,0b0100);
Segs_Normal(4,'3',Segs_DP_OFF);
Segs_Custom(1,0b01001010);
Segs_Custom(2,0b11110000);
Segs_8H(7,0b1110);
Segs_Custom(5,0b10001011);
Segs_Custom(6,0b10110001);
if(SWL_Pushed(SWL_CTR))
{
  for(;;)
  {
    RTI_Delay_ms(100);
Segs_16H(counter,0);
counter++;
  }
}
   /* 

Segs_Normal(3,13,Segs_DP_ON);
Segs_Normal(6,0x0f,Segs_DP_OFF);
*/

//Segs_16H(9999,0);
}

}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
