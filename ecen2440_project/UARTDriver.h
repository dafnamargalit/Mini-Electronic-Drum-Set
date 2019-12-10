#include "msp.h"


/**
 * UART Driver
 */

/* Configures ports for UART communication */
/* Uses EUSCI modules for configuration */

void UART_Config(void);

void EUSCIA0_IRQHandler(uint8_t data);
/* Transmits data to Arduino*/
//void UART_transmitData(uint8_t value);
//
//void UART_transmitBytes(uint8_t * string, uint8_t value);
//
///* Stop Communication */
//void sendStop(void);


///* Enables Interrupts */
//void UART_enableInterrupt(void);
//
///* Disables Interrupts */
//void UART_disableInterrupt(void);
