#include <hidef.h>
#include "derivative.h"
#include "lcd.h"
#define lcd_RWUp DDRH = 0; PORTK |= 2;
#define lcd_RWDown PORTK &= (~2); DDRH = 0xff;
#define lcd_EUp PORTK |= 1;
#define lcd_EDown PORTK &= (~1);
#define lcd_RSUp PORTK |= 4;
#define lcd_RSDown PORTK &= (~4);
#define lcd_MIcroDelay {char __x = 1; while (--__x)};



void lcd_Ins (unsigned char val)
{
lcd_Busy();
lcd_RWDown
lcd_RSDown
PTH = val;
lcd_EUp
lcd_EDown

}
char lcd_Busy (void)
{
    unsigned char inVal = 0;
    lcd_RSDown
    lcd_RWUp

    do
    {
        lcd_EUp
        lcd_MicroDelay
        inVal = PTH;
        lcd_EDown
    }
    while(inVal & 0x80)
}