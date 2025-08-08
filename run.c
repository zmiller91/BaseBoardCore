 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
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
#include "mcc_generated_files/system/system.h"
#include <stdio.h>
#include "run.h"

#define EEPROM_I2C_ADDRESS  0x50  // 7-bit address of 24AA02UID

/*
    Main application
*/

void read_uuid_from_eeprom(void) {
    uint8_t uuid[6];
    uint8_t start_addr = 0xFA;
    
    // Initialize I2C host
    I2C1_Host.Initialize();

    // Read UUID from EEPROM using WriteRead (random read)
    for (uint8_t i = 0; i < 6; i++) {
        uint8_t mem_addr = start_addr + i;

        // Send memory address, then read one byte
        bool success = I2C1_Host.WriteRead(
            EEPROM_I2C_ADDRESS,     // 7-bit I2C address
            &mem_addr,              // memory address to read from
            1,                      // address length = 1 byte
            &uuid[i],               // buffer to store read byte
            1                       // number of bytes to read
        );

        while (I2C1_Host.IsBusy()) {}
        
        if (!success) {
            __delay_ms(1);
            return;
        }
    }
    
    __delay_ms(1);
    
    
    char payload[9];  // 4 bytes * 2 chars + null terminator
    sprintf(payload, "%02X%02X%02X%02X", uuid[2], uuid[3], uuid[4], uuid[5]);

    // Send over LoRa to address 32 (change as needed)
    printf("AT+SEND=32,8,%s\r\n", payload);
}

int run(AppTaskFn task) {
    
    
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable(); 
    INTERRUPT_PeripheralInterruptEnable(); 
    
    printf("Hello from run method");
    
    __delay_ms(2000);
    read_uuid_from_eeprom();
    while(1)
    {
        
        read_uuid_from_eeprom();
        if(task != NULL) {
            task();
        }
        __delay_ms(2000);
       
    }    
}