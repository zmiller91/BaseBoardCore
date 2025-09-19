#ifndef RUN_H
#define RUN_H

#include "mcc_generated_files/system/system.h"

#ifdef __cplusplus
extern "C" {
#endif

    
// Timer1 overflows every 15 seconds. Run 120 overflow cycles to sleep for
// a total of 30 minutes
typedef enum {
    FIFTEEN_SECONDS = 1,
    ONE_MINUTE = 4,
    FIVE_MINUTES = 20,
    FIFTEEN_MINUTES = 60,
    THIRTY_MINUTES = 120,
    FOURTY_FIVE_MINUTES = 180,
    ONE_HOUR = 240        
} sleep_period;
      
    
typedef void (*AppTaskFn)(void);
int run(AppTaskFn);  
void set_sleep_period(sleep_period);




#ifdef __cplusplus
}
#endif

#endif // v
