#include "timeout.h"
#include "log.h"
#include "mcc_generated_files/timer/tmr6.h"
#include "mcc_generated_files/system/pins.h"

// Timer overflows every 50 milliseconds; 40 overflows = 2 seconds.
#define MAX_OVERFLOWS 90

static volatile uint8_t overflow_count = 0;

void timeout_init() {
    T6CONbits.TMR6ON = 1;     // Enable Timer6
    timeout_reset();
    TMR6_OverflowCallbackRegister(timer_increment);
}

void timeout_disable(void) {
    T6CONbits.TMR6ON = 0;     // Disable Timer6
}

bool timeout_wait(bool (*StatusHandler)(void)) {
    timeout_start();
    while (StatusHandler() && !timeout_timed_out());
    timeout_stop();
    return !timeout_timed_out();
}

void timeout_start(void) {
    timeout_reset(); 
    TMR6_Start();
}

void timeout_stop(void) {
    TMR6_Stop();
}

void timeout_reset(void) {
    PIR2bits.TMR6IF = 0;
    overflow_count = 0;
}

bool timeout_timed_out(void) {
    return overflow_count >= MAX_OVERFLOWS;
}

void timer_increment(void) {
    overflow_count++;
    if (timeout_timed_out()) {
        timeout_stop();
    }
}