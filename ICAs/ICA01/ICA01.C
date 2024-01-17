/********************************************************************/
// HC12 Program:  Jeonghoon Lee ICA01 
// Processor:     MC9S12XDP512
// Bus Speed:      16.00 MHz
// Author:        Jeonghoon Lee
// Details:                
// Date:         Jan 12, 2024
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/
#define RED_LED 0b10000000
#define INDEX_MAX 10
/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned int counter, index;
/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  

  
  _DISABLE_COP();
  
  
/********************************************************************/
  // one-time initializations
/********************************************************************/

PT1AD1 |= RED_LED;
DDR1AD1 |= RED_LED;
counter = 0;
index = 0;
/********************************************************************/
  // main program loop
/********************************************************************/

 for (;;) // run whatever is inside forever
{
if(++counter == 0) // increment counter by 1, (up until 4.2 billion) and when the value in counter goes over it's limit, it overflows and goes to 0. then, run whatever is inside
{
   if(++index >= INDEX_MAX)   //increments index, checks the indx >= INDEX_MAX, if false, dont run whatever is inside and continue ( forloop)
    {
      index = 0;
      PT1AD1 ^= RED_LED;
    }
}
}                  
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/