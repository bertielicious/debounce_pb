/*
 * File:   debounce_SWIP.c
 * Author: philip
 *
 * Created on 28 February 2018, 18:54
 */
/*INPUT = SWIP && previous_state && current_state 
  OUTPUT = LED_OFF or LED_ON*/

#include <xc.h>
#include "config.h"
#include <stdbool.h>
#include "debounce_SWIP.h"

bool debounce_SWIP(void) 
{
    static uchar current_state = OFF;
    
    if(SWIP == NOT_PUSHED && current_state == OFF) //a
    {
        current_state = OFF; 
        return LED_OFF;
    }
    
    if(SWIP == PUSHED && current_state == OFF)  //b
    {
        current_state = BOUNCING_ON;
        return  LED_OFF;
    }
    
    if(SWIP == NOT_PUSHED  && current_state == BOUNCING_ON) //c
    {
        current_state = OFF;
        return LED_OFF;
    }
    
    if(SWIP == PUSHED && current_state == BOUNCING_ON) //d
    {
        current_state = ON;
        return LED_ON;
    }
    
    if(SWIP == PUSHED && current_state == ON) //x
    {
        current_state = ON;
        return LED_ON;
    }
    
    if(SWIP == NOT_PUSHED  && current_state == ON) //e
    {
        current_state = BOUNCING_OFF;
        return LED_OFF;
    }
    
    if(SWIP == PUSHED && current_state == BOUNCING_OFF)       // f
    {
        current_state = ON;
        return LED_OFF;
    }
    
    if(SWIP == NOT_PUSHED  && current_state == BOUNCING_OFF) //g
    {
        current_state = OFF;
        return LED_OFF;
    }
}