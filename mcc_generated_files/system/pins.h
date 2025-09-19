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
#include <stdbool.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA3 aliases
#define BAT_EN_TRIS                 TRISAbits.TRISA3
#define BAT_EN_LAT                  LATAbits.LATA3
#define BAT_EN_PORT                 PORTAbits.RA3
#define BAT_EN_WPU                  WPUAbits.WPUA3
#define BAT_EN_OD                   ODCONAbits.ODCA3
#define BAT_EN_ANS                  ANSELAbits.ANSA3
#define BAT_EN_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define BAT_EN_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define BAT_EN_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define BAT_EN_GetValue()           PORTAbits.RA3
#define BAT_EN_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define BAT_EN_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define BAT_EN_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define BAT_EN_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define BAT_EN_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define BAT_EN_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define BAT_EN_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define BAT_EN_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)
// get/set IO_RA4 aliases
#define AIN_BAT_TRIS                 TRISAbits.TRISA4
#define AIN_BAT_LAT                  LATAbits.LATA4
#define AIN_BAT_PORT                 PORTAbits.RA4
#define AIN_BAT_WPU                  WPUAbits.WPUA4
#define AIN_BAT_OD                   ODCONAbits.ODCA4
#define AIN_BAT_ANS                  ANSELAbits.ANSA4
#define AIN_BAT_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define AIN_BAT_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define AIN_BAT_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define AIN_BAT_GetValue()           PORTAbits.RA4
#define AIN_BAT_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define AIN_BAT_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define AIN_BAT_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define AIN_BAT_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define AIN_BAT_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define AIN_BAT_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define AIN_BAT_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define AIN_BAT_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)
// get/set IO_RB0 aliases
#define TX1_TRIS                 TRISBbits.TRISB0
#define TX1_LAT                  LATBbits.LATB0
#define TX1_PORT                 PORTBbits.RB0
#define TX1_WPU                  WPUBbits.WPUB0
#define TX1_OD                   ODCONBbits.ODCB0
#define TX1_ANS                  ANSELBbits.ANSB0
#define TX1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define TX1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define TX1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define TX1_GetValue()           PORTBbits.RB0
#define TX1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define TX1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define TX1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define TX1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define TX1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define TX1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define TX1_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define TX1_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)
// get/set IO_RB1 aliases
#define RX1_TRIS                 TRISBbits.TRISB1
#define RX1_LAT                  LATBbits.LATB1
#define RX1_PORT                 PORTBbits.RB1
#define RX1_WPU                  WPUBbits.WPUB1
#define RX1_OD                   ODCONBbits.ODCB1
#define RX1_ANS                  ANSELBbits.ANSB1
#define RX1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RX1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RX1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RX1_GetValue()           PORTBbits.RB1
#define RX1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RX1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RX1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define RX1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define RX1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define RX1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define RX1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define RX1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)
// get/set IO_RB3 aliases
#define LORA_EN_TRIS                 TRISBbits.TRISB3
#define LORA_EN_LAT                  LATBbits.LATB3
#define LORA_EN_PORT                 PORTBbits.RB3
#define LORA_EN_WPU                  WPUBbits.WPUB3
#define LORA_EN_OD                   ODCONBbits.ODCB3
#define LORA_EN_ANS                  ANSELBbits.ANSB3
#define LORA_EN_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define LORA_EN_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define LORA_EN_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define LORA_EN_GetValue()           PORTBbits.RB3
#define LORA_EN_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define LORA_EN_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define LORA_EN_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define LORA_EN_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define LORA_EN_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define LORA_EN_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define LORA_EN_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define LORA_EN_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)
// get/set IO_RB4 aliases
#define TX2_TRIS                 TRISBbits.TRISB4
#define TX2_LAT                  LATBbits.LATB4
#define TX2_PORT                 PORTBbits.RB4
#define TX2_WPU                  WPUBbits.WPUB4
#define TX2_OD                   ODCONBbits.ODCB4
#define TX2_ANS                  ANSELBbits.ANSB4
#define TX2_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define TX2_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define TX2_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define TX2_GetValue()           PORTBbits.RB4
#define TX2_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define TX2_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define TX2_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define TX2_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define TX2_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define TX2_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define TX2_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define TX2_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)
// get/set IO_RB5 aliases
#define RX2_TRIS                 TRISBbits.TRISB5
#define RX2_LAT                  LATBbits.LATB5
#define RX2_PORT                 PORTBbits.RB5
#define RX2_WPU                  WPUBbits.WPUB5
#define RX2_OD                   ODCONBbits.ODCB5
#define RX2_ANS                  ANSELBbits.ANSB5
#define RX2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RX2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RX2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RX2_GetValue()           PORTBbits.RB5
#define RX2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RX2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RX2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define RX2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define RX2_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define RX2_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define RX2_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define RX2_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)
// get/set IO_RC0 aliases
#define I2C_EN_TRIS                 TRISCbits.TRISC0
#define I2C_EN_LAT                  LATCbits.LATC0
#define I2C_EN_PORT                 PORTCbits.RC0
#define I2C_EN_WPU                  WPUCbits.WPUC0
#define I2C_EN_OD                   ODCONCbits.ODCC0
#define I2C_EN_ANS                  ANSELCbits.ANSC0
#define I2C_EN_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define I2C_EN_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define I2C_EN_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define I2C_EN_GetValue()           PORTCbits.RC0
#define I2C_EN_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define I2C_EN_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define I2C_EN_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define I2C_EN_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define I2C_EN_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define I2C_EN_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define I2C_EN_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define I2C_EN_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)
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
// get/set IO_RC4 aliases
#define IO3_TRIS                 TRISCbits.TRISC4
#define IO3_LAT                  LATCbits.LATC4
#define IO3_PORT                 PORTCbits.RC4
#define IO3_WPU                  WPUCbits.WPUC4
#define IO3_OD                   ODCONCbits.ODCC4
#define IO3_ANS                  ANSELCbits.ANSC4
#define IO3_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO3_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO3_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO3_GetValue()           PORTCbits.RC4
#define IO3_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO3_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO3_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO3_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO3_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO3_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO3_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define IO3_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)
// get/set IO_RC5 aliases
#define IO2_TRIS                 TRISCbits.TRISC5
#define IO2_LAT                  LATCbits.LATC5
#define IO2_PORT                 PORTCbits.RC5
#define IO2_WPU                  WPUCbits.WPUC5
#define IO2_OD                   ODCONCbits.ODCC5
#define IO2_ANS                  ANSELCbits.ANSC5
#define IO2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO2_GetValue()           PORTCbits.RC5
#define IO2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO2_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO2_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)
// get/set IO_RC6 aliases
#define IO1_TRIS                 TRISCbits.TRISC6
#define IO1_LAT                  LATCbits.LATC6
#define IO1_PORT                 PORTCbits.RC6
#define IO1_WPU                  WPUCbits.WPUC6
#define IO1_OD                   ODCONCbits.ODCC6
#define IO1_ANS                  ANSELCbits.ANSC6
#define IO1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO1_GetValue()           PORTCbits.RC6
#define IO1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define IO1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define IO1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define IO1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define IO1_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO1_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)
// get/set IO_RD4 aliases
#define AIN1_TRIS                 TRISDbits.TRISD4
#define AIN1_LAT                  LATDbits.LATD4
#define AIN1_PORT                 PORTDbits.RD4
#define AIN1_WPU                  WPUDbits.WPUD4
#define AIN1_OD                   ODCONDbits.ODCD4
#define AIN1_ANS                  ANSELDbits.ANSD4
#define AIN1_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define AIN1_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define AIN1_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define AIN1_GetValue()           PORTDbits.RD4
#define AIN1_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define AIN1_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define AIN1_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define AIN1_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define AIN1_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define AIN1_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define AIN1_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define AIN1_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)
// get/set IO_RD5 aliases
#define AIN2_TRIS                 TRISDbits.TRISD5
#define AIN2_LAT                  LATDbits.LATD5
#define AIN2_PORT                 PORTDbits.RD5
#define AIN2_WPU                  WPUDbits.WPUD5
#define AIN2_OD                   ODCONDbits.ODCD5
#define AIN2_ANS                  ANSELDbits.ANSD5
#define AIN2_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define AIN2_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define AIN2_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define AIN2_GetValue()           PORTDbits.RD5
#define AIN2_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define AIN2_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define AIN2_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define AIN2_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define AIN2_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define AIN2_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define AIN2_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define AIN2_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)
// get/set IO_RD6 aliases
#define AIN3_TRIS                 TRISDbits.TRISD6
#define AIN3_LAT                  LATDbits.LATD6
#define AIN3_PORT                 PORTDbits.RD6
#define AIN3_WPU                  WPUDbits.WPUD6
#define AIN3_OD                   ODCONDbits.ODCD6
#define AIN3_ANS                  ANSELDbits.ANSD6
#define AIN3_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define AIN3_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define AIN3_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define AIN3_GetValue()           PORTDbits.RD6
#define AIN3_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define AIN3_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define AIN3_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define AIN3_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define AIN3_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define AIN3_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define AIN3_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define AIN3_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)
// get/set IO_RE0 aliases
#define LED_EN_TRIS                 TRISEbits.TRISE0
#define LED_EN_LAT                  LATEbits.LATE0
#define LED_EN_PORT                 PORTEbits.RE0
#define LED_EN_WPU                  WPUEbits.WPUE0
#define LED_EN_OD                   ODCONEbits.ODCE0
#define LED_EN_ANS                  ANSELEbits.ANSE0
#define LED_EN_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LED_EN_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LED_EN_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LED_EN_GetValue()           PORTEbits.RE0
#define LED_EN_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LED_EN_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LED_EN_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define LED_EN_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define LED_EN_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define LED_EN_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define LED_EN_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define LED_EN_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

extern volatile bool EXTERNAL_WAKEUP;  

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