#include "mcc_generated_files/system/system.h"
#include <stdio.h>
#include <string.h>
#include "run.h"
#include "log.h"
#include "lora.h"
#include "uuid.h"
#include "timeout.h"
#include "adcc_manager.h"
#include "i2c_manager.h"

void low_power_mode(void){

    // Timer1 overflows every 15 seconds. Run 120 overflow cycles to sleep for
    // a total of 30 minutes
    TMR1_Start();
    uint16_t overflowCount = 0;
    while (overflowCount < 1) {
        SLEEP();  
        overflowCount++;
    }

    TMR1_Stop();
}

void init(void) {
    log_init();
    timeout_init();
    lora_init();
    i2c_mgr_init();
    adcc_mgr_init();
    __delay_ms(2000);
}

void deinit(void) {
    lora_disable();
    i2c_mgr_disable();
    adcc_mgr_disable();
    timeout_disable();
//    log_disable();
}

void log_device_id(void) {
    char buf[32]; 
    sprintf(buf, "Device ID: %s", uuid_get());
    log_debug(buf);
}

int run(AppTaskFn task) {
    
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable(); 
    INTERRUPT_PeripheralInterruptEnable(); 
    
    __delay_ms(2000);
    
    uuid_init();
    log_device_id();
    
    while(1)
    {
 
        init();
        if(task != NULL) {
            task();
        }
        
        deinit();
        low_power_mode();
       
    }    
}