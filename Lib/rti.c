#include "rti.h"
#include <hidef.h>
#include "derivative.h"
unsigned int i = 0;
void RTI_Init(void)
{
    CRGINT |= CRGINT_RTIE_MASK;
}
void RTI_Delay_ms(unsigned int ms)
{
    RTICTL = 0;
    if (CRGFLG_RTIF)
    {
        CRGFLG = CRGFLG_RTIF_MASK;
    }

    RTICTL = 0b10010111;
    for (i = 0; i < ms; i++)
    {

        while(!CRGFLG_RTIF)
        {
            
        }
        CRGFLG = CRGFLG_RTIF_MASK;
    }
    RTICTL = 0;
}
