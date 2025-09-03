/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RB0 aliases
#define RX1_TRIS                 TRISBbits.TRISB0
#define RX1_LAT                  LATBbits.LATB0
#define RX1_PORT                 PORTBbits.RB0
#define RX1_WPU                  WPUBbits.WPUB0
#define RX1_OD                   ODCONBbits.ODCB0
#define RX1_ANS                  ANSELBbits.ANSB0
#define RX1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RX1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RX1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RX1_GetValue()           PORTBbits.RB0
#define RX1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RX1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RX1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define RX1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define RX1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define RX1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define RX1_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define RX1_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)
// get/set IO_RB1 aliases
#define TX1_TRIS                 TRISBbits.TRISB1
#define TX1_LAT                  LATBbits.LATB1
#define TX1_PORT                 PORTBbits.RB1
#define TX1_WPU                  WPUBbits.WPUB1
#define TX1_OD                   ODCONBbits.ODCB1
#define TX1_ANS                  ANSELBbits.ANSB1
#define TX1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define TX1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define TX1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define TX1_GetValue()           PORTBbits.RB1
#define TX1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define TX1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define TX1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define TX1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define TX1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define TX1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define TX1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define TX1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)
// get/set IO_RC2 aliases
#define SCL1_TRIS                 TRISCbits.TRISC2
#define SCL1_LAT                  LATCbits.LATC2
#define SCL1_PORT                 PORTCbits.RC2
#define SCL1_WPU                  WPUCbits.WPUC2
#define SCL1_OD                   ODCONCbits.ODCC2
#define SCL1_ANS                  ANSELCbits.ANSC2
#define SCL1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SCL1_GetValue()           PORTCbits.RC2
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define SDA1_TRIS                 TRISCbits.TRISC3
#define SDA1_LAT                  LATCbits.LATC3
#define SDA1_PORT                 PORTCbits.RC3
#define SDA1_WPU                  WPUCbits.WPUC3
#define SDA1_OD                   ODCONCbits.ODCC3
#define SDA1_ANS                  ANSELCbits.ANSC3
#define SDA1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SDA1_GetValue()           PORTCbits.RC3
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
// get/set IO_RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)
// get/set IO_RC6 aliases
#define IO_RC6_TRIS                 TRISCbits.TRISC6
#define IO_RC6_LAT                  LATCbits.LATC6
#define IO_RC6_PORT                 PORTCbits.RC6
#define IO_RC6_WPU                  WPUCbits.WPUC6
#define IO_RC6_OD                   ODCONCbits.ODCC6
#define IO_RC6_ANS                  ANSELCbits.ANSC6
#define IO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_RC6_GetValue()           PORTCbits.RC6
#define IO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_RC6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define IO_RC6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define IO_RC6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define IO_RC6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define IO_RC6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO_RC6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)
// get/set IO_RD0 aliases
#define I2C_EN_TRIS                 TRISDbits.TRISD0
#define I2C_EN_LAT                  LATDbits.LATD0
#define I2C_EN_PORT                 PORTDbits.RD0
#define I2C_EN_WPU                  WPUDbits.WPUD0
#define I2C_EN_OD                   ODCONDbits.ODCD0
#define I2C_EN_ANS                  ANSELDbits.ANSD0
#define I2C_EN_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define I2C_EN_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define I2C_EN_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define I2C_EN_GetValue()           PORTDbits.RD0
#define I2C_EN_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define I2C_EN_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define I2C_EN_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define I2C_EN_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define I2C_EN_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define I2C_EN_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define I2C_EN_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define I2C_EN_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)
// get/set IO_RD1 aliases
#define LED_TRIS                 TRISDbits.TRISD1
#define LED_LAT                  LATDbits.LATD1
#define LED_PORT                 PORTDbits.RD1
#define LED_WPU                  WPUDbits.WPUD1
#define LED_OD                   ODCONDbits.ODCD1
#define LED_ANS                  ANSELDbits.ANSD1
#define LED_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LED_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LED_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LED_GetValue()           PORTDbits.RD1
#define LED_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LED_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define LED_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)
// get/set IO_RD6 aliases
#define TX2_TRIS                 TRISDbits.TRISD6
#define TX2_LAT                  LATDbits.LATD6
#define TX2_PORT                 PORTDbits.RD6
#define TX2_WPU                  WPUDbits.WPUD6
#define TX2_OD                   ODCONDbits.ODCD6
#define TX2_ANS                  ANSELDbits.ANSD6
#define TX2_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define TX2_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define TX2_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define TX2_GetValue()           PORTDbits.RD6
#define TX2_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define TX2_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define TX2_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define TX2_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define TX2_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define TX2_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define TX2_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define TX2_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)
// get/set IO_RD7 aliases
#define RYLR_EN_TRIS                 TRISDbits.TRISD7
#define RYLR_EN_LAT                  LATDbits.LATD7
#define RYLR_EN_PORT                 PORTDbits.RD7
#define RYLR_EN_WPU                  WPUDbits.WPUD7
#define RYLR_EN_OD                   ODCONDbits.ODCD7
#define RYLR_EN_ANS                  ANSELDbits.ANSD7
#define RYLR_EN_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define RYLR_EN_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define RYLR_EN_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define RYLR_EN_GetValue()           PORTDbits.RD7
#define RYLR_EN_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define RYLR_EN_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define RYLR_EN_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define RYLR_EN_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define RYLR_EN_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define RYLR_EN_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define RYLR_EN_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define RYLR_EN_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/