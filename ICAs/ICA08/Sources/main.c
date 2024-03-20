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
#include "MISC.h"
#include "rti.h"
#include "clock.h"
#include "sci.h"
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
unsigned char data;
unsigned char pData;
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

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    
   Clock_Set20MHZ();
RTI_Delay_ms(50);
SWL_TOG(SWL_RED); 

//data = rand() % 26 + 'A';


// sci0_txByte (data);
 
    if(sci0_rxByte(&pData))
    {     
             sci0_txByte (pData);    
      if(pData == 'a'|| pData == 'e'|| pData == 'i'|| pData == 'u'|| pData == 'o'|| pData == 'y' )
       { 
        SWL_ON(SWL_GREEN);
        SWL_OFF(SWL_YELLOW);
       }
       else
       {
        SWL_OFF(SWL_GREEN);
        SWL_ON(SWL_YELLOW);
       }
    }
    else{
      SWL_OFF(SWL_GREEN);
      SWL_OFF(SWL_YELLOW);
    }
  }      
              
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
