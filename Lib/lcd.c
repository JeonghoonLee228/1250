
#include <hidef.h>      
#include "derivative.h" 
#include "lcd.h"
#define lcd_RWUp DDRH = 0; PORTK |= 2;
#define lcd_RWDown PORTK &= (~2); DDRH = 0xFF;
#define lcd_EUp PORTK |= 1;
#define lcd_EDown PORTK &= (~1);
#define lcd_RSUp PORTK |= 4;
#define lcd_RSDown PORTK &= (~4);


void lcd_Init (void) {
    PTH = 0b00000000;                        
      DDRH = 0b11111111;    
    PORTK &= 0b11111000;    
    DDRK |= 0b00000111;   
    asm LDD #0;                                 
    asm DBNE D,*;                              
    asm DBNE D,*;                            
       PTH = 0b00111000;   
    PORTK |= 0b00000001;    
    PORTK &= 0b11111000;    
    asm LDD #11000;     
    asm DBNE D,*;    
    PORTK |= 0b00000001;
    PORTK &= 0b11111000;   
    asm LDD #267;
    asm DBNE D,*;  
        PORTK |= 0b00000001;   
    PORTK &= 0b11111000;    
    asm LDD #267;
    asm DBNE D,*;    
    lcd_Ctrl(0b00111000);    
    lcd_Ctrl(0b00001110);   
    lcd_Ctrl(0b00000001);   
    lcd_Ctrl(0b00000110);
}

void lcd_Ctrl(unsigned char cCommand) {
    
    while(lcd_Busy() != 0);

    PTH = cCommand;    
    PORTK |= 0b00000001;  
    PORTK &= 0b11111000;
}

unsigned char lcd_Busy (void) {
    unsigned char cBusy;    
    DDRH = 0b00000000;  
       PORTK |= 0b00000011;   
    PORTK &= 0b11111000;    
    cBusy = PTH & 0b10000000;    
    DDRH = 0b11111111;
        return cBusy;
}

void lcd_Data (unsigned char val) {
  
    while(lcd_Busy() != 0);   
    lcd_RWDown  
    lcd_RSUp
    PTH = val;    
    PORTK |= 0b0000001;  
    PORTK &= 0b11111000;
}

void lcd_Clear (void) {

    lcd_Ctrl(0b00000001);
}

void lcd_AddrXY (unsigned char ix, unsigned char iy) 
{
    if(iy == 0)
    {
        lcd_Addr(ix);
    }
     if(iy == 1)
    {
        lcd_Addr(ix+64);
    }
     if(iy == 2)
    {
        lcd_Addr(ix+20);
    }
    if(iy == 3)
    {
        lcd_Addr(ix+84);
    }
}



void lcd_String (char const * straddr) {
  
    while(*straddr != 0)      
    lcd_Data(*straddr++);
}

void lcd_Addr (unsigned char addr) {
  
    addr |= 0b10000000;
    lcd_Ctrl(addr);
}
