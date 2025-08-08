#ifndef RUN_H
#define RUN_H

#include "mcc_generated_files/system/system.h"

#ifdef __cplusplus
extern "C" {
#endif

    
    
    
typedef void (*AppTaskFn)(void);
int run(AppTaskFn);  





#ifdef __cplusplus
}
#endif

#endif // v
