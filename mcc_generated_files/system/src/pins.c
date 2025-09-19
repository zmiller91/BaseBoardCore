/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.0.0
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

#include "../pins.h"

volatile bool EXTERNAL_WAKEUP = false;

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0xC;
    LATD = 0x0;
    LATE = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0xF7;
    TRISB = 0xE6;
    TRISC = 0x8E;
    TRISD = 0xFF;
    TRISE = 0xE;

    /**
    ANSELx registers
    */
    ANSELA = 0xF7;
    ANSELB = 0xD4;
    ANSELC = 0x82;
    ANSELD = 0xFF;
    ANSELE = 0x6;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUB = 0x0;
    WPUC = 0x0;
    WPUD = 0x0;
    WPUE = 0x0;
  
    /**
    ODx registers
    */
   
    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x0;
    ODCOND = 0x0;
    ODCONE = 0x0;
    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x7;
    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0xF;

    /**
    PPS registers
    */
    RX2PPS = 0xD; //RB5->EUSART2:RX2;
    RX1PPS = 0x9; //RB1->EUSART1:RX1;
    RB4PPS = 0x11;  //RB4->EUSART2:TX2;
    RB0PPS = 0x0E;  //RB0->EUSART1:TX1;
    SSP1CLKPPS = 0x13;  //RC3->MSSP1:SCL1;
    RC3PPS = 0x15;  //RC3->MSSP1:SCL1;
    SSP1DATPPS = 0x12;  //RC2->MSSP1:SDA1;
    RC2PPS = 0x16;  //RC2->MSSP1:SDA1;

    /**
    APFCON registers
    */

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;


}
  
void PIN_MANAGER_IOC(void)
{
    // This method handles the interrupt on change event when a pin changes 
    // state. As written, it handles all state changes the same and won't 
    // differentiate between pins. If you want to know which pin is toggled
    // you will have to add that logic here -- either calling a delegate method
    // or exposing a variable. 
    
    // Flag to indicate that the IOC triggered
    EXTERNAL_WAKEUP = true;

    // Read all the flag registers so the PIC recognizes the state change
    uint8_t port_a_flags = IOCAF;
    uint8_t port_b_flags = IOCBF;
    uint8_t port_c_flags = IOCCF;
    uint8_t port_e_flags = IOCEF;

    // Clear all the ports flags
    if (port_a_flags) { (void)PORTA; IOCAF = 0; }
    if (port_b_flags) { (void)PORTB; IOCBF = 0; }
    if (port_c_flags) { (void)PORTC; IOCCF = 0; }
    if (port_e_flags) { (void)PORTE; IOCEF = 0; }
    
    // Clear the master flag
    PIR0bits.IOCIF   = 0;
}
/**
 End of File
*/