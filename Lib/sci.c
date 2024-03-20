#include "sci.h"
#include <hidef.h>
#include "derivative.h"

void sci0_Init2(void)
{
SCI0BD = 130;
SCI0CR2 = 0b00001100;


}

unsigned char sci0_bread(unsigned char pData)
{

if(SCI0SR1 & SCI0SR1_RDRF_MASK)
{
    pData = SCI0DRL;
    return 1;

}
else{
    return 0;
}
}

void sci0_txByte (unsigned char data)
{
if(SCI0SR1 & SCI0SR1_TDRE_MASK)
{
SCI0DRL = data;
}
unsigned char sci0_rxByte(unsigned char *pData)
{
    if(SCI0DRL & SCI0SR1_RDRF_MASK)
    {                
        *pData = SCI0DRL;
        return 1;       
    }
    else
    {
        return 0;
    }      

}

}
