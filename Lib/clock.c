#include <hidef.h>
#include "derivative.h"
#include "clock.h"

#define DEF_BUS_CLOCK 8000000   //default clock speed

unsigned long speed = DEF_BUS_CLOCK;
void Clock_Set8MHZ(void)
{
PLLCTL = 0;
    
}

 void Clock_Set20MHZ(void)
{
  CLKSEL &= ~(CLKSEL_PLLSEL_MASK);
      SYNR = 4;
    REFDV = 3;
  PLLCTL = PLLCTL_PLLON_MASK | PLLCTL_AUTO_MASK;
while(!(CRGFLG & CRGFLG_LOCK_MASK));
 CLKSEL |= CLKSEL_PLLSEL_MASK;
 speed = 20000000;
}
void Clock_Set24MHZ(void)
{

}
void Clock_Set40MHZ(void)
{
    
}