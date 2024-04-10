#include <hidef.h>
#include "derivative.h"
#include "segs.h"
#define Segs_WLATCH PORTA &= (~0x01); PORTA |= 0x01;
#define Segs_ML PORTA &= (~0x02);
#define Segs_MH PORTA |= 0x02;


void Segs_Init (void)
{
   Segs_Clear();
    PORTA |= 0x03;
    DDRA |= 0x03;
    DDRB |= 0xff;
}

void Segs_Normal (unsigned char addr, unsigned char value, Segs_DPOption dp)
{
    addr &= 0x07;
    addr |= 0b1011000;
    if(dp)
    {
        value &= (~0x80);
    }
    else{
        value |= 0x80;
    }

    PORTB = addr;
    Segs_MH
    Segs_WLATCH
    PORTB = value;
    Segs_ML
    Segs_WLATCH
}
void Segs_Custom (unsigned char addr, unsigned char command)
{
addr &= 0x07;
addr |= 0b1011000;
 if(command && 0b10000000)
    {
        command &= (~0x80);
    }
    else{
        command |= 0x80;
    }

 PORTB = addr;
    Segs_MH
    Segs_WLATCH
    PORTB = command;
    Segs_ML
    Segs_WLATCH
}
void Segs_Clear(void)
{
    Segs_Custom(1,0b00000000);
    


}

