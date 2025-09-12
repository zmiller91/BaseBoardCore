
#include "uuid.h"
#include "i2c_manager.h"
#include "string_utils.h"

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
    
    char p1[3];
    char p2[3];
    char p3[3];
    char p4[3];
    
    byte_to_hex2(uuid[2], p1);
    byte_to_hex2(uuid[3], p2);
    byte_to_hex2(uuid[4], p3);      
    byte_to_hex2(uuid[5], p4);
    
    char *parts[] = {p1, p2, p3, p4};
    join_buffers(parts, 4, g_uuid, 9);
    
    I2C_EN_LAT = original_i2c_state;
}

char* uuid_get(void) {
    return g_uuid;
}