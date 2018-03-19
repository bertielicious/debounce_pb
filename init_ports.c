/*
 * File:   init_ports.c
 * Author: philip
 *
 * Created on 02 February 2018, 18:05
 */


#include <xc.h>

void init_ports(void) 
{
    /* turn off adc module and comparators*/
    ANSEL = 0x00;
    ANSELH = 0x00;  // ADC module off
    CM1CON0 = 0x00;
    CM2CON0 = 0x00; // comparators off
    
    /* internal clock setup*/
    OSCCONbits.IRCF2 = 1;           // 8 MHz clock configuration
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF0 = 1;
    
    TRISCbits.TRISC0 = 1;           // GREEN led output pin 16
    
    TRISCbits.TRISC1 = 0;           // PUSH BUTTON input
    
}
