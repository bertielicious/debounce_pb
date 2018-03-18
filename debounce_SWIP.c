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
    
    if(SWIP == NOT_PUSHED && current_state == OFF) //a
    {
        current_state = OFF; 
        return LED_OFF;
    }
    if(SWIP == PUSHED && current_state == OFF)  //b
    {
        previous_state = OFF;
        current_state = BOUNCING_ON;
        return  LED_OFF;
    }
    if(SWIP == NOT_PUSHED && previous_state == OFF && current_state == BOUNCING_ON) //c
    {
        previous_state = BOUNCING_ON;
        current_state = OFF;
        return LED_OFF;
    }
    if(SWIP == PUSHED && previous_state == OFF && current_state == BOUNCING_ON) //d
    {
        previous_state = BOUNCING_ON;
        current_state = ON;
        return LED_ON;
    }
    if(SWIP == PUSHED && previous_state == BOUNCING_ON && current_state == ON) //x
    {
        previous_state = ON;
        current_state = ON;
        return LED_ON;
    }
    
    
    if(SWIP == NOT_PUSHED && previous_state == ON && current_state == ON) //e
    {
        previous_state = ON;
        current_state = BOUNCING_OFF;
        return LED_OFF;
    }
    
    if(SWIP == PUSHED && previous_state == ON && current_state == BOUNCING_OFF)       // f
    {
        previous_state = BOUNCING_OFF;
        current_state = ON;
        return LED_OFF;
    }
    
    if(SWIP == NOT_PUSHED && previous_state == ON && current_state == BOUNCING_OFF) //g
    {
        previous_state = BOUNCING_OFF;
        current_state = OFF;
        return LED_OFF;
    }
    
}