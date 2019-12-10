#include "msp.h"
#include <stdint.h>
#include "UARTDriver.h"
#include <driverlib/driverlib.h>
void  pinConfig(void)
{

    P1->OUT &= ~BIT0;                       // Clear LED to start
    P1->DIR |= BIT0;                        // Set P1.0/LED to output

    P2->OUT &= ~BIT0;                       // Clear LED to start
    P2->DIR |= BIT0;                        // Set P2.0/LED to output


    // Configure GPIO
    P5->SEL1 |= BIT5 | BIT4 | BIT3 | BIT2;   // Enable A/D channel A0, A1, A3
    P5->SEL0 |= BIT5 | BIT4 | BIT3 | BIT2;

    // Enable global interrupt
    __enable_irq();

    NVIC->ISER[0] = 1 << ((ADC14_IRQn) & 31);// Enable ADC interrupt in NVIC module

    // Turn on ADC14, extend sampling time to avoid overflow of results
    ADC14->CTL0 = ADC14_CTL0_ON |
            ADC14_CTL0_MSC |
            ADC14_CTL0_SHT0__192 |
            ADC14_CTL0_SHP |
            ADC14_CTL0_CONSEQ_3;

    ADC14->MCTL[0] = ADC14_MCTLN_INCH_0;    // ref+=AVcc, channel = A0
    ADC14->MCTL[1] = ADC14_MCTLN_INCH_1;    // ref+=AVcc, channel = A1
    ADC14->MCTL[2] = ADC14_MCTLN_INCH_2;    // ref+=AVcc, channel = A1
    ADC14->MCTL[3] = ADC14_MCTLN_INCH_3| ADC14_MCTLN_EOS;

    ADC14->IER0 = ADC14_IER0_IE3;           // Enable ADC14IFG.3

    SCB->SCR &= ~SCB_SCR_SLEEPONEXIT_Msk;   // Wake up on exit from ISR

    // Ensures SLEEPONEXIT takes effect immediately
    __DSB();

//    while(1)
//    {
        // Start conversion-software trigger
        ADC14->CTL0 |= ADC14_CTL0_ENC |
                ADC14_CTL0_SC;
//        __sleep();
//        __no_operation();                   // For debugger
 }

// ADC14 interrupt service routine
void ADC14_IRQHandler(void)
{
    if (ADC14->IFGR0 & ADC14_IFGR0_IFG3)
    {
        int kick, snare, hihat;
        while(ADC14->MEM[0] > 0x7FF){
            kick = 1;
        }
        while(ADC14->MEM[1] > 0x7FF){
            snare = 1;
        }
        while(ADC14->MEM[3] > 0x7FF){
            hihat = 1;
        }
       if (kick == 1){             // ADC12MEM0 = A0 > 0.5AVcc? 3E8
             P2->OUT |= BIT0;                      // P1.0 = 1
             MAP_UART_transmitData(EUSCI_A1_BASE, 'k');
             ADC14->MEM[0] = 0;
             kick = 0;
        }
        else if (snare == 1) {       // ADC12MEM0 = A1 > 0.5AVcc? 3A98
            P2->OUT |= BIT0;                      // P1.0 = 1
            MAP_UART_transmitData(EUSCI_A1_BASE, 's');
            ADC14->MEM[1] = 0;
            snare = 0 ;
        }

        else if (hihat == 1){        // ADC12MEM0 = A3 > 0.5AVcc? 3A98
            P2->OUT |= BIT0;                      // P1.0 = 1
            MAP_UART_transmitData(EUSCI_A1_BASE, 'h');
            ADC14->MEM[3] = 0;
            hihat = 0;
        }
        else{
            P2->OUT &= ~BIT0;
        }
    }
 }
