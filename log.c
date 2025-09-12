#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include "log.h"
#include "timeout.h"
#include "string_utils.h"
#include "mcc_generated_files/system/system.h"


static LogLevel current_log_level = LOG_LEVEL_DEBUG;


bool tx2_busy(void) {
    return !EUSART2_IsTxDone();
}

bool uart2_write(char *data) {
    
    for(uint8_t i = 0; i < strlen(data); i++) {
        EUSART2_Write(data[i]);
        if(!timeout_wait(tx2_busy)) {
            return false;
        }
    }
    
    return true;
}


void format_log_level(const char* log_level, char buffer[9]) {
    size_t n = strlen(log_level);
    for(uint8_t i = 0; i < n; i++) {
        buffer[i] = log_level[i];
    }
    
    for(size_t i = n; i < 8; i++) {
        buffer[i] = ' ';
    }
    
    buffer[9] = '\0';
}

bool has_cr_or_lf(const char *text) {
    while (*text) {
        char ch = *text++;
        if (ch == '\r' || ch == '\n') {
            return true;
        }
    }
    return false;
}


void log(LogLevel level, const char* level_name, const char* message) {
    if (level < current_log_level) return;    
    
    size_t n = strlen(message);
    bool has_crlf = (n >= 2 && message[n-2] == '\r' && message[n-1] == '\n');
    char* format = has_crlf ? "%-8s %s" : "%-8s %s\r\n";
    
    char buffer[50];
    char log_level[9];
    format_log_level(level_name, log_level);
    char *parts[] = {log_level, message, has_cr_or_lf(message) ? "" : "\r\n"};
    join_buffers(parts, 3, buffer, 50);
    uart2_write(buffer);
    
    
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