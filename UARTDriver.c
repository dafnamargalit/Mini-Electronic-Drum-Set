/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/******************************************************************************
 * MSP432 UART - PC Echo with 12MHz BRCLK
 *
 * Description: This demo echoes back characters received via a PC serial port.
 * SMCLK/DCO is used as a clock source and the device is put in LPM0
 * The auto-clock enable feature is used by the eUSCI and SMCLK is turned off
 * when the UART is idle and turned on when a receive edge is detected.
 * Note that level shifter hardware is needed to shift between RS232 and MSP
 * voltage levels.
 *
 *               MSP432P4111
 *             -----------------
 *            |                 |
 *            |                 |
 *            |                 |
 *       RST -|     P1.3/UCA0TXD|----> PC (echo)
 *            |                 |
 *            |                 |
 *            |     P1.2/UCA0RXD|<---- PC
 *            |                 |
 *
 *******************************************************************************/
/* DriverLib Includes */
#include <driverlib/driverlib.h>
#include "msp.h"
/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

//![Simple UART Config]
/* UART Configuration Parameter. These are the configuration parameters to
 * make the eUSCI A UART module to operate with a 9600 baud rate. These
 * values were calculated using the online calculator that TI provides
 * at:
 *http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
 */
struct  _eUSCI_eUSCI_UART_Config uartConfig =
{
        EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        78,                                     // BRDIV = 78
        2,                                       // UCxBRF = 2
        0,                                       // UCxBRS = 0
        EUSCI_A_UART_NO_PARITY,                  // No Parity
        EUSCI_A_UART_LSB_FIRST,                  // LSB First
        EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
        EUSCI_A_UART_MODE,                       // UART mode
        EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION,  // Oversampling
};
//![Simple UART Config]

void UART_Config(void)
{
    /* Halting WDT  */
    MAP_WDT_A_holdTimer();

    EUSCI_A1->CTLW0 |= EUSCI_A_CTLW0_SWRST;

    /* Selecting P2.2 and P2.3 in UART mode */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P2,
           GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
//             GPIO_PIN3, GPIO_SECONDARY_MODULE_FUNCTION);
//    P2->SEL0 |= BIT3;


    /* Setting DCO to 12MHz */
    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_12);

    //![Simple UART Example]
    /* Configuring UART Module */
    MAP_UART_initModule(EUSCI_A1_BASE, &uartConfig);

    /* Enable UART module */
    MAP_UART_enableModule(EUSCI_A1_BASE);


    /* Enabling interrupts */
    MAP_UART_enableInterrupt(EUSCI_A1_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
    MAP_Interrupt_enableInterrupt(INT_EUSCIA1);
    MAP_Interrupt_enableSleepOnIsrExit();
    MAP_Interrupt_enableMaster();
    //![Simple UART Example]

}

/* EUSCI A0 UART ISR - Echoes data back to PC host */
void EUSCIA0_IRQHandler(uint8_t data)
{
    uint32_t status = MAP_UART_getEnabledInterruptStatus(EUSCI_A1_BASE);

    MAP_UART_clearInterruptFlag(EUSCI_A1_BASE, status);

    if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
    {
        MAP_UART_transmitData(EUSCI_A1_BASE, data);
    }

}


//#include "msp.h"
//#include "UARTDriver.h"
//#include <stdint.h>
// #include <string.h>
//
///**
// * UART Driver
// */
//
//
//void UART_config(void){
//    /* Configures ports for UART communication */
//    /* Uses EUSCI modules for configuration */
//    EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SWRST;  // UCSWRST = 1
//
//    // configure UART
//    EUSCI_A0->CTLW0 |= (EUSCI_A_CTLW0_MODE_0    |   // select UART mode
//                            EUSCI_A_CTLW0_MST   // select master mode
//                          );
//
////    EUSCI_A0->CTLW1 |= (EUSCI_A_CTLW0_MODE_0    |   // select UART mode
////                                EUSCI_A_CTLW0_MST   // select master mode
////                              );
////        EUSCI_A0->BRW = 8;  // set prescaler to have 375kHz SCL line
//
//        // Configure port
//        P2->SEL0 |= BIT3;
//        P2->SEL1 &= ~BIT3;
//
//
//        EUSCI_A0->CTLW0 &= ~(EUSCI_A_CTLW0_SWRST);  // clear UCSWRST
//
//        EUSCI_A0->IE |= (EUSCI_A_IE_TXIE | EUSCI_A_IE_RXIE);
//
//}
//
//void UART_transmitData(uint8_t value){
//    /* Transmits data */
//    UCTXADDR
//    EUSCI_A0->TXBUF = value;  // send value being written to
//    while(!(EUSCI_A0->IFG  & EUSCI_A_IFG_TXIFG));
//
//}
//
//void UART_transmitBytes(uint8_t * string, uint8_t value) {
//    uint8_t i;
//   for(i = 0; i < strlen(string); i++){
//       UART_transmitData(value);
//   }
//}
//
//void sendStop(void){
//    /* Stops communication */
//    EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SPB ;  // send stop
//    while(EUSCI_A0->CTLW0 & EUSCI_A_CTLW0_SPB);  // wait until stop is sent
//}
