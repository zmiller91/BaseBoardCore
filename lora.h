/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_RYLR998_H
#define	XC_HEADER_RYLR998_H

#include <xc.h> // include processor files - each processor file is guarded.  


#define RYLR998_OK                                      INT8_C(1)
#define DATA_RECEIVED                                   INT8_C(101)
#define NO_DATA                                         INT8_C(102)


/*! @name RYLR998 Error Codes */
#define RYLR998_NO_ENTER                                INT8_C(-1)
#define RYLR998_NO_AT                                   INT8_C(-2)
#define RYLR998_UNKNOWN_CMD                             INT8_C(-4)
#define RYLR998_LEN_MISMATCH                            INT8_C(-5)
#define RYLR998_TX_OVER_TIMES                           INT8_C(-10)
#define RYLR998_CRC_ERROR                               INT8_C(-12)
#define RYLR998_TX_EXCEEDS_240B                         INT8_C(-13)
#define RYLR998_FLASH_WRITE_FAILED                      INT8_C(-14)
#define RYLR998_UNKNOWN_FAILURE                         INT8_C(-15)
#define RYLR998_LAST_TX_NOT_COMPLETE                    INT8_C(-17)
#define RYLR998_PREAMBLE_VAL_NOT_ALLOWED                INT8_C(-18)
#define RYLR998_RX_FAILED_HEADER_ERROR                  INT8_C(-19)
#define RYLR998_TIME_SETTING_NOT_ALLOWED                INT8_C(-20)

#define LORA_INVALID_DATA                            INT8_C(-97)
#define LORA_TIMEOUT                                 INT8_C(-98)
#define LORA_UNLISTED_FAILURE                        INT8_C(-99)
#define PAYLOAD_TOO_BIG                              INT8_C(-100)
#define LORA_PARSE_ERROR                             INT8_C(-101)


#define LORA_MAX_MSGID     16
#define MAX_PAYLOAD_SIZE   25

typedef struct {
    char msg_id[LORA_MAX_MSGID + 1];           // "a34ac35k"
    const char* payload;
} LoraRcv;


void lora_init(void);

int8_t send_rx_open(uint8_t address, uint16_t duration);
int8_t lora_send(uint8_t address, int32_t metrics[], uint8_t size);
int8_t lora_send_raw(uint8_t address, char* data);
int8_t lora_receive(char* line_buf, uint8_t line_len, LoraRcv* out);
int8_t send_ack(uint8_t address, const char *message_id);
int8_t send_command_complete(uint8_t address, const char *message_id);

bool lora_enable(void);
bool lora_disable(void);

#endif	/* XC_HEADER_TEMPLATE_H */

