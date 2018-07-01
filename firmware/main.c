/*
 * File:   main.c
 * Author: aaronmorrison
 *
 * Created on March 16, 2018, 5:22 PM
 */
#define _XTAL_FREQ 64000000
#include <stdio.h>
#include <stdlib.h>
#include "sevenseg.h"
#include "configuration.h"
#include "date_and_time.h"


/*
 *
 */
volatile int outputs[16] = {
0,0,0,0,
0,0,0,0,
0,0,0,0,
0,0,0,0 };

static enum {
    COUNTUP,
    COUNTDOWN,
    FROZEN,
    EDITING
} fsm_state;

int main(int argc, char** argv) {
    sevseg_init();

    //why do I need to set this here? No idea man
    fsm_state = COUNTUP;

    PIE0 = 0b00100000;

    INTCON= 0b11000000;

    //enable timer 0
    T0CON0 = 0b10010000;
    //timer 0 read from LFINTOSC
    T0CON1 = 0b10000000;

    while(1){
        PORTB |= 0x80;

        sevseg_put_number(0,0,outputs[ 0]);
        sevseg_put_number(1,0,outputs[ 1]);
        sevseg_put_number(2,0,outputs[ 2]);
        sevseg_put_number(3,0,outputs[ 3]);
        sevseg_put_number(0,1,outputs[ 4]);
        sevseg_put_number(1,1,outputs[ 5]);
        sevseg_put_number(2,1,outputs[ 6]);
        sevseg_put_number(3,1,outputs[ 7]);
        sevseg_put_number(0,2,outputs[ 8]);
        sevseg_put_number(1,2,outputs[ 9]);
        sevseg_put_number(2,2,outputs[10]);
        sevseg_put_number(3,2,outputs[11]);
        sevseg_put_number(0,3,outputs[12]);
        sevseg_put_number(1,3,outputs[13]);
        sevseg_put_number(2,3,outputs[14]);
        sevseg_put_number(3,3,outputs[15]);
    }
    return (EXIT_SUCCESS);
}

void interrupt isr (void)
{
    //interrupt was generated by timer 0 module
    if(TMR0IF){
        TMR0IF = 0;
        TMR0H = 0xFE;
        TMR0L = 0xC9;
        if(fsm_state == COUNTDOWN) {
            decrement_and_rollover(outputs, 0);
        }
        else if(fsm_state == COUNTUP) {
            increment_and_rollover(outputs, 0);
        }
    }
    //we don't know what caused interrupt, so block
    else{
        while(1) {}
    }
}

