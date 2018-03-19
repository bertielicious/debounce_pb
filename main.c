/*
 * File:   main.c
 * Author: philip
 *
 * Created on 11 March 2018, 20:09
 */


#include <xc.h>
#include "config.h"
#include "main.h"
#include "init_ports.h"
#include "debounce_SWIP.h"

void main(void) 
{
    init_ports();
    while(1)
    {
        bounce = debounce_SWIP();
       if (bounce == LED_ON)
        {
            GREEN_LED = 1;
        }
       else
        {
            GREEN_LED = 0;  
        }
    }
        
}
