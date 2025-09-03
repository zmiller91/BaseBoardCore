/* 
 * File:   uuid.h
 * Author: zmiller
 *
 * Created on August 8, 2025, 11:10 PM
 */

#ifndef I2C_MANAGER_H
#define	I2C_MANAGER_H 


#include "mcc_generated_files/system/system.h"


void i2c_mgr_init(void);
void i2c_mgr_disable(void);
bool i2c_mgr_write_read(uint16_t address, uint8_t *writeData, size_t writeLength, uint8_t *readData, size_t readLength);
void i2c_mgr_wait(void);

#endif	/* UUID_H */

