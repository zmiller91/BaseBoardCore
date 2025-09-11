#include <stdio.h>
#include <stdlib.h>

#include "uuid.h"
#include "i2c_manager.h"

#define EEPROM_I2C_ADDRESS      0x50    // 7-bit address of 24AA02UID
#define EEPROM_START_ADDRESS    0xFA    // starting memory address to read from
#define EEPROM_BYTES            6       // number of bytes to read


char g_uuid[9] = {0};

void uuid_init(void) {
    
    uint8_t uuid[6];
    uint8_t start_addr = EEPROM_START_ADDRESS;

    // The I2C outputs need to be powered up. Not doing so may (will?) put the
    // I2C bus in a bad state. This may not be necessary if we move to a high-side
    // P channel mosfet.
    uint8_t original_i2c_state = I2C_EN_LAT;
    I2C_EN_SetHigh();
    
    
    // Send memory address, then read one byte
    i2c_mgr_write_read(
        EEPROM_I2C_ADDRESS,       // 7-bit I2C address
        &start_addr,              // memory address to read from
        1,                        // address length = 1 byte
        uuid,                     // buffer to store read byte
        EEPROM_BYTES              // number of bytes to read
    );
    
    char payload[9];  // 4 bytes * 2 chars + null terminator
    sprintf(g_uuid, "%02X%02X%02X%02X", uuid[2], uuid[3], uuid[4], uuid[5]);
    I2C_EN_LAT = original_i2c_state;
}

const char* uuid_get(void) {
    return g_uuid;
}