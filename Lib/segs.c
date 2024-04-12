#include <hidef.h>
#include "derivative.h"
#include "segs.h"
#define Segs_WLATCH PORTA &= (~0x01);  PORTA |= 0x01;
   
    
#define Segs_ML PORTA &= (~0x02);
#define Segs_MH PORTA |= 0x02;

void Segs_Init(void)
{

    PORTA |= 0x03;
    DDRA |= 0x03;
    DDRB |= 0xff;
    Segs_Clear();
}

void Segs_Normal(unsigned char addr, unsigned char value, Segs_DPOption dp)
{
    addr &= 0x07;
    addr |= 0b1011000;
    if (dp)
    {
        value &= (~0x80);
    }
    else
    {
        value |= 0x80;
    }

    PORTB = addr;
    Segs_MH
        Segs_WLATCH
            PORTB = value;
    Segs_ML Segs_WLATCH
}
void Segs_Custom(unsigned char addr, unsigned char value)
{
    addr &= 0x07;
    addr |= 0b01111000;

    PORTB = addr;
    Segs_MH
        Segs_WLATCH
            PORTB = value;
    Segs_ML Segs_WLATCH
}
void Segs_Clear(void)
{
    Segs_Custom(0, 0b10000000);
    Segs_Custom(1, 0b10000000);
    Segs_Custom(2, 0b10000000);
    Segs_Custom(3, 0b10000000);
    Segs_Custom(4, 0b10000000);
    Segs_Custom(5, 0b10000000);
    Segs_Custom(6, 0b10000000);
    Segs_Custom(7, 0b10000000);
}
void Segs_8H(unsigned char addr, unsigned char value)
{
    addr %=8;
    if(value > 0b1111)
    {
Segs_Normal(addr, value >> 4, Segs_DP_OFF);  
    Segs_Normal((addr + 1) % 8, value & 0b00001111, Segs_DP_OFF);
    }
    else{
        Segs_Normal((addr) % 8, value & 0b00001111, Segs_DP_OFF);
    }
    
}
void Segs_16H (unsigned int value, Segs_LineOption row)
{
    int numbers [] = {0b1111000000000000, 0b0000111100000000, 0b0000000011110000, 0b0000000000001111};
    int addr = 4*row;
    int counter =0;
    Segs_Normal(addr, value >>12, Segs_DP_OFF);
    Segs_Normal(addr+1, (value >> 8), Segs_DP_OFF);
    Segs_Normal(addr+2, (value >> 4), Segs_DP_OFF);
    Segs_Normal(addr+3, value, Segs_DP_OFF);

/*
    for(counter = 0; counter <4; counter++)
    {
        
    Segs_Normal(addr + counter, (value & numbers[counter]) % (16 * (4 - counter)), Segs_DP_OFF);
//Segs_Normal(addr + counter, (value >> (4 * (3 - counter))) % (16 * (4 - counter)), Segs_DP_OFF);

    }
    */

}
