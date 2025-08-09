#include <stdio.h>
#include "log.h"


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