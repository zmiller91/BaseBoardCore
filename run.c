#include "mcc_generated_files/system/system.h"
#include <stdio.h>
#include <string.h>
#include "run.h"
#include "log.h"
#include "lora.h"
#include "uuid.h"

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
    lora_init();
    log_device_id();
    
    while(1)
    {
 
        if(task != NULL) {
            task();
        }
        __delay_ms(2000);
       
    }    
}