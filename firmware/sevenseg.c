#include "sevenseg.h"
#define _XTAL_FREQ 64000000

#include<xc.h>

void sevseg_init(){
    //set up tristates
    TRISA = 0xC0;
    TRISB = 0x7C;
    TRISC = 0xC3;

}

void sevseg_put_number(int digit, int display, int value){
    PORTA = 0x0;
    PORTB &= 0xF0;
    PORTC = 0x0;
    __delay_us(50);
    display--;
    if(display < 0)
        display = 3;
    char select = 0x0;
    switch(display){
        case 0:
            if(digit == 0)
                select = 0x14;
            else if (digit == 2)
                select = 0x10;
            else if (digit == 1)
                select = 0x04;
            else
                select = 0x0;
            break;
        case 3:
            if(digit == 3)
                select = 0x14;
            else if (digit == 1)
                select = 0x10;
            else if (digit == 2)
                select = 0x04;
            else
                select = 0x0;
            break;
        case 1:
            if(digit == 0)
                select = 0x14;
            else if(digit == 1)
                select = 0x00;
            else if(digit == 2)
                select = 0x10;
            else
                select = 0x4;
            break;
        case 2:
            if(digit == 0)
                select = 0x10;
            else if(digit == 1)
                select = 0x04;
            else if(digit == 2)
                select = 0x14;
            else
                select = 0x00;
            break;
    }
    //put display into select bits 3 and 5
    select |= (((display & 0x1) << 3) | ((display & 0x2) << 4));

    switch(value){
        case 0:
            LATA = 0x1f;
            PORTB |= 0x2;
            break;
        case 1:
            LATA = 0x4;
            PORTB |= 0x2;
            break;
        case 2:
            LATA = 0x1d;
            PORTB |= 0x1;
            break;
        case 3:
            LATA = 0x15;
            PORTB |= 0x3;
            break;
        case 4:
            LATA = 0x6;
            PORTB |= 0x3;
            break;
        case 5:
            LATA = 0x13;
            PORTB |= 0x3;
            break;
        case 6:
            LATA = 0x1b;
            PORTB |= 0x3;
            break;
        case 7:
            LATA = 0x5;
            PORTB |= 0x2;
            break;
        case 8:
            LATA = 0x1f;
            PORTB |= 0x3;
            break;
        case 9:
            LATA = 0x17;
            PORTB |= 0x3;
            break;

        default:
            LATA = 0x3f;
            PORTB |= 0x3;
    }
    LATC = select;
    __delay_us(50);
}
