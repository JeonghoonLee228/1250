#include "sci.h"
#include <hidef.h>
#include "derivative.h"

void sci0_Init2(void)
{
    SCI0BD = 130;
    SCI0CR2 = 0b00001100;
}
unsigned int iz =0;
unsigned char sci0_bread(unsigned char pData)
{

    if (SCI0SR1 & SCI0SR1_RDRF_MASK)
    {
        pData = SCI0DRL;
        return 1;
    }
    else
    {
        return 0;
    }
}

void sci0_txByte (unsigned char data)
{
while (!SCI0SR1_TDRE); //Blocking
//if(SCI0SR1_TDRE) // non blocking
SCI0DRL = data;
}

unsigned char sci0_rxByte(unsigned char *pData)
{
    if (SCI0DRL & SCI0SR1_RDRF_MASK)
    {
        *pData = SCI0DRL;
        return 1;
    }
    else
    {
        return 0;
    }
}
void sci0_txStr(char const *straddr)
{ /*while(*straddr)
{sci0_txByte (*straddr);
    ++straddr;
};
*/
    
    for (; *straddr; ++straddr)
sci0_txByte (*straddr);

}
void sci0_InitEnum (BaudRate br)
{
SCI0BD = br;
SCI0CR2 = 0b00001100;
// other initialization elements here...
}
unsigned long sci0_InitMath (unsigned long ulBusClock, unsigned long ulBaudRate)
{
    
}
