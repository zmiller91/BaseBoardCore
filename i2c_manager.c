#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "i2c_manager.h"
#include "mcc_generated_files/i2c_host/mssp1.h"
#include "mcc_generated_files/system/system.h"

void i2c_mgr_init(void) {
    I2C1_Host.Initialize();
    SSP1CON1bits.SSPEN = 1;
    I2C_EN_SetHigh();
}

void i2c_mgr_disable(void) {
    I2C1_Host.Deinitialize();
    SSP1CON1bits.SSPEN = 0;
    I2C_EN_SetLow();
}

void i2c_mgr_wait() {
    while (I2C1_Host.IsBusy()) {}
}

bool i2c_mgr_write_read(uint16_t address, uint8_t *writeData, size_t writeLength, uint8_t *readData, size_t readLength) {
        bool success = I2C1_Host.WriteRead(address, writeData, writeLength, readData, readLength);
        i2c_mgr_wait();
        return success;
}