#include <stdio.h>
#include <stdarg.h>
#include "log.h"
#include "mcc_generated_files/system/system.h"


static LogLevel current_log_level = LOG_LEVEL_DEBUG;

void log(LogLevel level, const char* level_name, const char* message) {
    if (level < current_log_level) return;
    printf("%-8s %s\r\n", level_name, message);
}

void log_debug(const char* message) {
    log(LOG_LEVEL_DEBUG, "DEBUG", message);
}

void log_info(const char* message) {
    log(LOG_LEVEL_INFO, "INFO", message);
}

void log_error(const char* message) {
    log(LOG_LEVEL_ERROR, "ERROR", message);
}

void set_log_level(LogLevel level) {
    current_log_level = level;
}

void log_init() {
    EUSART2_Enable();
    EUSART2_TransmitEnable();
    EUSART2_ReceiveEnable();
}

void log_disable() {
    EUSART2_Disable();
    EUSART2_TransmitDisable();
    EUSART2_ReceiveDisable();
}