/* 
 * File:   avr_manager.c
 * Author: zmiller
 *
 * Created on August 12, 2025, 10:58 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "adcc_manager.h"
#include "timeout.h"
#include "log.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/adcc/adcc.h"
#include "mcc_generated_files/fvr/fvr.h"

void adcc_mgr_init() {
    FVR_Initialize();
    timeout_wait(FVR_IsOutputReady);
    ADCC_Initialize();
}

void adcc_mgr_disable() {
    // Stop any ongoing conversions
    ADCC_DisableContinuousConversion();
    ADCC_StopConversion();

    // Turn off ADC core
    ADCON0bits.ADON = 0;

    // Turn off FVR
    FVRCONbits.FVREN = 0;
}


float get_fvr_voltage(void) {
    switch (FVRCONbits.ADFVR) {
        case 1: return 1.024f;  // 1x
        case 2: return 2.048f;  // 2x
        case 4: return 4.096f;  // 4x
        default: return 0.0f;   // invalid / reserved
    }
}

float adcc_mgr_get_single_conversion(adcc_channel channel) {
    adc_result_t adcVal = ADCC_GetSingleConversion((adcc_channel_t) channel);
    
    char buf[50];
//    sprintf(buf, "ADC Result: %u", adcVal);
//    log_debug(buf);
    
    buf[0] = '\0';
//    sprintf(buf, "FVR Voltage: %.3f", get_fvr_voltage());
//    log_debug(buf);
    return adcVal * 4.65f / 1023.0f;
}

