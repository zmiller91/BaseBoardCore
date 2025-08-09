#ifndef LOG_H
#define LOG_H

typedef enum {
    LOG_LEVEL_DEBUG = 0,
    LOG_LEVEL_INFO  = 1,
    LOG_LEVEL_ERROR = 2,
    LOG_LEVEL_NONE  = 3
} LogLevel;

void log_debug(const char* message);
void log_info(const char* message);
void log_error(const char* message);
void set_log_level(LogLevel level);

#endif