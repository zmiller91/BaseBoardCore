// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_TIMEOUT_H
#define	XC_TIMEOUT_H


#include <stdbool.h>
#include <xc.h> // include processor files - each processor file is guarded.  

void timeout_init(void);

void timeout_start(void);

void timeout_stop(void);

void timeout_reset(void);

bool timeout_timed_out(void);

void timer_increment(void);

bool timeout_wait(bool (* StatusHandler)(void));

#endif	/* XC_TIMEOUT_H */
