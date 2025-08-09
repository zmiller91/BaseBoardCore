#include <stdio.h>
#include <stdlib.h>

#include "uuid.h"
#include "mcc_generated_files/i2c_host/mssp1.h"
#include "mcc_generated_files/system/system.h"

#define EEPROM_I2C_ADDRESS      0x50    // 7-bit address of 24AA02UID
#define EEPROM_START_ADDRESS    0xFA    // starting memory address to read from
#define EEPROM_BYTES            6       // number of bytes to read


char g_uuid[9] = {0};

void uuid_init(void) {
    
    uint8_t uuid[6];
    uint8_t start_addr = EEPROM_START_ADDRESS;
    
    // Initialize I2C host
    I2C1_Host.Initialize();

    // Send memory address, then read one byte
    bool success = I2C1_Host.WriteRead(
        EEPROM_I2C_ADDRESS,       // 7-bit I2C address
        &start_addr,              // memory address to read from
        1,                        // address length = 1 byte
        uuid,                     // buffer to store read byte
        EEPROM_BYTES              // number of bytes to read
    );

    while (I2C1_Host.IsBusy()) {}
    
    char payload[9];  // 4 bytes * 2 chars + null terminator
    sprintf(g_uuid, "%02X%02X%02X%02X", uuid[2], uuid[3], uuid[4], uuid[5]);
}

const char* uuid_get(void) {
    return g_uuid;
}