/* 
 * File:   adcc_manager.h
 * Author: zmiller
 *
 * Created on August 12, 2025, 11:12 PM
 */

#ifndef ADCC_MANAGER_H
#define	ADCC_MANAGER_H


#include "mcc_generated_files/adcc/adcc.h"

typedef enum {
    ADCC_1 = AIN1,
    ADCC_2 = AIN2,
    ADCC_3 = AIN3,
    ADCC_BAT = AIN_BAT
} adcc_channel;


void adcc_mgr_init(void);
void adcc_mgr_disable(void);
adc_result_t adcc_mgr_get_raw_conversion(adcc_channel channel);
float adcc_mgr_get_voltage_conversion(adcc_channel channel);

#endif	/* ADCC_MANAGER_H */

