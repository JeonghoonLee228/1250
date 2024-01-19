/********************************************************************/
// HC12 Program:  template_main_2023.c
// Processor:     MC9S12XDP512
// Bus Speed:     40 MHz
// Author:        Jeonghoon Lee
// Details:       toggling the red and green LED               
// Date:          January 19th, 2024
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
 
/********************************************************************/
// Local Prototypes
/********************************************************************/
void RED(int LC); // declearing the method and defining the variable that goes in
void GREEN(int LC);
/********************************************************************/
// Global Variables
/********************************************************************/
unsigned int uiMainLoopCount; //counter for the whole cycle
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
uiMainLoopCount = 0; 

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
   ++uiMainLoopCount;  //infinite loop with the counter going up and putting that value into the RED and GREEN method
  RED(uiMainLoopCount);
  GREEN(uiMainLoopCount);
  }                   

}
/********************************************************************/
// Functions
/********************************************************************/
 void RED (LC)
        {
            if (LC < 0x1000)  //if the given value (counter) is less than 0x1000, change the PT1AD1
                PT1AD1 |= 1 << 7;
            else  // else, leave it the same
            {
                PT1AD1 &= 0x7F;
            }

        }
         void GREEN(LC)
        {
            if (LC >= 0x1000)  // if the given value ( counter) is more than or equal to 0x1000, change PT1AD1
            {
                PT1AD1 |= 0x20;
            }
            else
            {
                PT1AD1 &= 0b11011111;
            }
                            
        }

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
