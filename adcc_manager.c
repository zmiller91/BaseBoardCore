/* 
 * File:   avr_manager.c
 * Author: zmiller
 *
 * Created on August 12, 2025, 10:58 PM
 */

#include "adcc_manager.h"
#include "timeout.h"
#include "log.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/adcc/adcc.h"
void adcc_mgr_init() {
    ADCC_Initialize();
}

void adcc_mgr_disable() {
    // Stop any ongoing conversions
    ADCC_DisableContinuousConversion();
    ADCC_StopConversion();

    // Turn off ADC core
    ADCON0bits.ADON = 0;
}

uint16_t adcc_mgr_get_raw_conversion(adcc_channel channel) {
    return ADCC_GetSingleConversion((adcc_channel_t) channel);
}

