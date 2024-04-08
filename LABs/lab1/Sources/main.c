/********************************************************************/
// HC12 Program:  ICA09
// Processor:     MC9S12XDP512
// Bus Speed:      20 MHz
// Author:        Jeonghoon Lee
// Details:       A more detailed explanation of the program is entered here               
// Date:          April 02nd, 2024
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
signed *char operand = &;
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
  //sci0_Init2();
sci0_InitEnum(BAUD_38400_BUS20MHZ);
/********************************************************************/
  // main program loop
/********************************************************************/
Clock_Set20MHZ();
  for (;;)
  {RTI_Delay_ms(500);
    
sci0_txStr("\x1b[1;1H Jeonghoon Lee");
sci0_txStr("\x1b[2;1H Simple Binary Calculator");
sci0_txStr("\x1b[5;4H OP A: 0x1234 (04660)");
sci0_txStr("\x1b[6;4H OP B: 0xABCD (43981)");
sci0_txStr("\x1b[9;7H" operand);

  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
