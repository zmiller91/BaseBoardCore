#ifndef LOG_H
#define LOG_H

#ifdef LOG_CONFIG_HEADER
  #include LOG_CONFIG_HEADER
#endif

#ifndef ENABLE_DEBUG
  #define ENABLE_DEBUG 1
#endif

#ifndef ENABLE_INFO
  #define ENABLE_INFO 1
#endif

#ifndef ENABLE_ERROR
  #define ENABLE_ERROR 1
#endif

typedef enum {
    LOG_LEVEL_DEBUG = 0,
    LOG_LEVEL_INFO  = 1,
    LOG_LEVEL_ERROR = 2,
    LOG_LEVEL_NONE  = 3
} LogLevel;

void log_init(void);
void log_disable(void);
void log_debug(const char* message);
void log_info(const char* message);
void log_error(const char* message);
void set_log_level(LogLevel level);

#endif