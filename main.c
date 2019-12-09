#include "msp.h"
#include "voltageToAudio.h"
#include <driverlib/driverlib.h>
#include "UARTDriver.h"

/**
 * main.c
 */
void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW |             // Stop WDT
                 WDT_A_CTL_HOLD;
    pinConfig();
    UART_Config();

    while(1){
        MAP_PCM_gotoLPM0();
    }
}
