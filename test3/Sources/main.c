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
#include "clock.h"
#include "lcd.h"
#include "sci.h"

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
int button = 1;
int x = 0;
int y = 0;
char *name = "Jeonghoon Lee";
unsigned char data;
unsigned char *pData;
int number;
int seconds =0;
int min =0;
int mili =0;
int namesize = 0;

/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  // Any main local variables must be declared here
  lcd_Init();
  SWL_Init();
  Segs_Init();
  sci0_Init2();
  Clock_Set20MHZ();
  // main entry point
  _DISABLE_COP();
  // EnableInterrupts;

sci0_InitEnum(BAUD_19200_BUS20MHZ);
  /********************************************************************/
  // one-time initializations
  /********************************************************************/

  /********************************************************************/
  // main program loop
  /********************************************************************/
  //lcd_String(name);
 
  number = rand(0,9999);
Segs_16D(number,1);

  for (;;)
  {
 
   
    button = 5;
    RTI_Delay_ms(50);
    
   
    if (SWL_Pushed(SWL_RIGHT) && button != 0)
    {
  
      button = 0;
      if (x == 7))
      {
      }
      else
      {
        lcd_Clear();
        lcd_AddrXY(x += 1, y);
        lcd_String(name);
        
      }
      while(PT1AD1 & SWL_RIGHT);
      counter++;
    }
   
    if (SWL_Pushed(SWL_LEFT) && button != -2)
    {
      
button = -2;
      if (x == 0)
      {
      }
      else
      {
        lcd_Clear();
        lcd_AddrXY(x -= 1, y);
        lcd_String(name);
        
      }
      while(PT1AD1 & SWL_LEFT);
      counter++;
    }
    
    if (SWL_Pushed(SWL_DOWN) && button != 1)
    {
      
      button = 1;
      if (y == 3)
      {
      }
      else
      {
        lcd_Clear();
        lcd_AddrXY(x, y+=1);
        lcd_String("Jeonghoon Lee");
        
      }
      while(PT1AD1 & SWL_DOWN);
      counter++;
    }
    if (SWL_Pushed(SWL_UP) && button != 2)
    {
      
      button = 2;
      if (y == 0)
      {
      }
      else
      {
        lcd_Clear();
        lcd_AddrXY(x, y-=1);
        lcd_String("Jeonghoon Lee");
        
      }
      while(PT1AD1 & SWL_UP);
      counter++;
    }
    Segs_16D(counter,1);
    
  }
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
