#include <hidef.h>
#include "derivative.h"
#include"SW_LED.h"


void SWL_ON (SWL_LEDColour led)
{
    PT1AD1 |= (unsigned char)led;
}
void SWL_OFF (SWL_LEDColour led)
{
    PT1AD1 &= ~(unsigned char)led;
}
int SWL_Pushed (SWL_SwitchPos pos)
{
    return PT1AD1 & pos;
}