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
bool i2c_mgr_write_read(uint16_t address, uint8_t *write_data, size_t write_length, uint8_t *read_data, size_t read_length);
bool i2c_mgr_write(uint8_t address, uint8_t *write_data, size_t write_length);;

#endif	/* UUID_H */

