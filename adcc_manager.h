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
    ANC5 = channel_ANC5
} adcc_channel;


void adcc_mgr_init(void);
void adcc_mgr_disable(void);
float adcc_mgr_get_single_conversion(adcc_channel channel);

#endif	/* ADCC_MANAGER_H */

