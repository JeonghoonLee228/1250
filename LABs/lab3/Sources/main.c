/********************************************************************/
// HC12 Program:  lab2 - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Jeonghoon Lee
// Details:       A more detailed explanation of the program is entered here
// Date:         Apr 22nd, 2024
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
signed place = 0;
int values[] = {0, 0, 0, 0};
int i2 = 0;
// int buttonPressed = -1;  
unsigned thousand =0;
unsigned hundred =0;
unsigned ten =0;
unsigned one = 0;
unsigned sum =0;
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
  Segs_Normal(0, values[0], Segs_DP_OFF);
  Segs_Normal(1, values[1], Segs_DP_OFF);
  Segs_Normal(2, values[2], Segs_DP_OFF);
  Segs_Normal(3, values[3], Segs_DP_OFF);
  for (;;)
  {
    RTI_Delay_ms(80);

    Segs_Normal(place, values[place], Segs_DP_ON);

    if (SWL_Pushed(SWL_RIGHT))
    {
      place += 1;
      if (place > 3)
      {
        place = 0;
        Segs_Normal(3, values[3], Segs_DP_OFF);
      }
      else
      {
        Segs_Normal(place - 1, values[place - 1], Segs_DP_OFF);
      }
    }
    if (SWL_Pushed(SWL_LEFT))
    {
      place -= 1;
      if (place < 0)
      {
        place = 3;
        Segs_Normal(0, values[0], Segs_DP_OFF);
      }
      else
      {

        Segs_Normal(place + 1, values[place + 1], Segs_DP_OFF);
      }
    }
    if(SWL_Pushed(SWL_UP))
    {
      if(values[place] > 8)
      {
        values[place] =0;
      }
      else{
 Segs_Normal(place, values[place]+=1,Segs_DP_ON);
      }
     
    }
    if(SWL_Pushed(SWL_DOWN))
    {
      if(values[place] < 1)
      {
        values[place] = 9;
      }
      else{
         Segs_Normal(place, values[place]-=1,Segs_DP_ON);
      }
    }
thousand = values[0]*1000;
hundred = values[1]*100;
ten = values[2]*10;
one = values[3];
sum = thousand+hundred+ten+one;
    Segs_16H(sum,1);
  }
 
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/

/*
if (SWL_Pushed(SWL_UP) && buttonPressed != 0) {
      buttonPressed = 0;
      valueArr[edittingIndex]++;
      if (valueArr[edittingIndex] == 10) valueArr[edittingIndex] = 0;
    }
    else if (!SWL_Pushed(SWL_UP) && buttonPressed == 0) buttonPressed = -1;
    */
