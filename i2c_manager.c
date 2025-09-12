
#include <stdbool.h>

#include "i2c_manager.h"
#include "timeout.h"
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

bool i2c_mgr_wait() {
    return timeout_wait(I2C1_Host.IsBusy);
}

bool i2c_mgr_write_read(uint16_t address, uint8_t *write_data, size_t write_length, uint8_t *read_data, size_t read_length) {
        if(!I2C1_Host.WriteRead(address, write_data, write_length, read_data, read_length)) {
            return false;
        }
        
        return i2c_mgr_wait();
}

bool i2c_mgr_write(uint8_t address, uint8_t *write_data, size_t write_length) {
    if(!I2C1_Host.Write(address, write_data, write_length + 1)) {
        return false;
    }
    
    return i2c_mgr_wait();
}