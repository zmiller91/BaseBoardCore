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


//float get_fvr_voltage(void) {
//    switch (FVRCONbits.ADFVR) {
//        case 1: return 1.024f;  // 1x
//        case 2: return 2.048f;  // 2x
//        case 3: return 4.096f;  // 4x
//        default: return 0.0f;   // invalid / reserved
//    }
//}

uint16_t adcc_mgr_get_raw_conversion(adcc_channel channel) {
    return ADCC_GetSingleConversion((adcc_channel_t) channel);
}

//float adcc_mgr_get_voltage_conversion(adcc_channel channel) {
//    adc_result_t adcVal = ADCC_GetSingleConversion((adcc_channel_t) channel);
//    
//    char buf[50];
//    sprintf(buf, "ADC Result: %u", adcVal);
//    log_debug(buf);
//    return adcVal * get_fvr_voltage() / 1023.0f;
//}

