#include "mcc_generated_files/system/system.h"
#include "run.h"
#include "log.h"
#include "lora.h"
#include "uuid.h"
#include "timeout.h"
#include "adcc_manager.h"
#include "i2c_manager.h"
#include "string_utils.h"
#include <stdbool.h>


sleep_period sleep_period_count = FIFTEEN_MINUTES;

void set_sleep_period(sleep_period period) {
    sleep_period_count = period;
}

void low_power_mode(void){
    
    // Reset the external wakup flag to false
    EXTERNAL_WAKEUP = false;
    
    // Timer1 overflows every 15 seconds. Run 120 overflow cycles to sleep for
    // a total of 30 minutes
    TMR1_Start();
    uint16_t overflow_count = 0;
    while (overflow_count < (uint16_t) sleep_period_count) {
        SLEEP();  
        if(EXTERNAL_WAKEUP) {
            return;
        }
        overflow_count++;
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
    char label[] = "Device ID: ";
    char *uuid = uuid_get();
    char *parts[] = { label, uuid};
    
    join_buffers(parts, 2, buf, 32);
    
    
    log_info(buf);
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