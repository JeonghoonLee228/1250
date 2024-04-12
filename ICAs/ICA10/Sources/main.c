/********************************************************************/
// HC12 Program:  ica10 - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Jeonghoon Lee
// Details:       A more detailed explanation of the program is entered here               
// Date:          april 11th, 2024
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
 unsigned counter =0;
 unsigned hugecounter = 0;
 unsigned shifter =0;
 unsigned placement = 0;
 unsigned righter =0;
 unsigned lefter =0;
 int caret [] = {0b11000000,0b10100000,0b10010000,0b10000001,0b10001000,0b10000010};
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
SWL_Init();
RTI_Init();
  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;

/********************************************************************/
  // one-time initializations
/********************************************************************/
/*
Segs_8H(0,0b0100);
Segs_Normal(4,'3',Segs_DP_OFF);
Segs_Custom(1,0b01001010);
Segs_Custom(2,0b11110000);
Segs_8H(7,0b1110);
Segs_Custom(5,0b10001011);
Segs_Custom(6,0b10110001);
*/
/********************************************************************/
  // main program loop
/********************************************************************/
/* tier 1
  for (;;)
  {   

if(SWL_Pushed(SWL_CTR))
{   
RTI_Delay_ms(100);
Segs_16H(counter,0);
Segs_16H(0xFFFF-counter,1);
counter++;  
}
}
*/



//tier 2
/*
for(;;)
{
  if(counter >= 6)
  {
    counter = -1;
 
  }
  else
  {
    RTI_Delay_ms(100);
Segs_Custom(placement,caret[counter]);
Segs_Custom(placement-1,0b10000000);
Segs_Custom(placement+1,0b10000000);
Segs_Custom(placement-2,0b10000000);
Segs_Custom(placement+2,0b10000000);

Segs_Normal(7,shifter,Segs_DP_OFF);
if(placement !=3)
{
  Segs_Custom(3,0b10000000);
}

  }

counter++;
hugecounter++;
if(hugecounter = 10)
{
  if(SWL_Pushed(SWL_RIGHT))
  {
    hugecounter =0;
    if(placement !=3)   
    {
 placement+=1;
    shifter++;
    } 
                 
  }
  if(SWL_Pushed(SWL_LEFT))
  {
    hugecounter =0;
    if(placement !=0)   
    {
 placement-=1;
    shifter++;
    }    
    

  }
  
}

}
*/



//tier 3
for(;;)
{
  if(counter >= 6)
  {
    counter = -1;
 
  }
  else
  {
    RTI_Delay_ms(100);
Segs_Custom(placement,caret[counter]);
Segs_Custom(placement-1,0b10000000);
Segs_Custom(placement+1,0b10000000);
Segs_Custom(placement-2,0b10000000);
Segs_Custom(placement+2,0b10000000);
Segs_Normal(7,shifter,Segs_DP_OFF);
Segs_Normal(5,righter,Segs_DP_OFF);
Segs_Normal(6,lefter,Segs_DP_OFF);

  }
counter++;
if(SWL_Pushed(SWL_RIGHT))
{
righter++;
if(righter >=10)
{
  if(placement !=3)   
    {
 placement+=1;
    shifter++;
    righter = 0;
    } 
}
}
if(SWL_Pushed(SWL_LEFT))
{
  lefter++;
  if(lefter >=10)
  {
    if(placement !=0)   
    {
 placement-=1;
    shifter++;
    lefter =0;
    }
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
