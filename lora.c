#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include <xc.h>
#include "mcc_generated_files/system/system.h"

#include "lora.h"
#include "timeout.h"
#include "log.h"
#include "uuid.h"
#include "string_utils.h"

void lora_init(void) {
    
    // Set the TX and RX pins and input and output
    RX1_SetDigitalInput();
    TX1_SetDigitalOutput();
    
    EUSART1_Enable();
    EUSART1_TransmitEnable();
    EUSART1_ReceiveEnable();
}

void eusart1_rx_clear(void) {
    // Clear overrun if present
    if (RC1STAbits.OERR) {
        RC1STAbits.CREN = 0;
        RC1STAbits.CREN = 1;
    }

    // Flush any unread data
    while (PIR3bits.RC1IF) {
        volatile uint8_t dummy = RC1REG;
    }
}

bool tx_busy(void) {
    return !EUSART1_IsTxDone();
}

int8_t uart_write(char *data) {
    
    bool carriage_found = false;
    bool newline_found = false;
    
    log_info(data);
    for(uint8_t i = 0; i < strlen(data); i++) {
        
        char c = data[i];
        EUSART1_Write(c);
        
        if(!timeout_wait(tx_busy)) {
            return LORA_TIMEOUT;
        }
        
        carriage_found = carriage_found || (data[i] == '\r');
        newline_found = newline_found || (data[i] == '\n');
        if(carriage_found && newline_found) {
            break;
        }
    }
    
    if(!carriage_found || !newline_found) {
        return LORA_INVALID_DATA;
    }
    
    return RYLR998_OK;
}

bool rx_busy(void) {
    return !EUSART1_IsRxReady();
}

int8_t uart_read(void) {
    
    if(!timeout_wait(rx_busy)) {
        log_debug("Read timed out begin");
        return LORA_TIMEOUT;
    }
    
    bool carriage_found = false;
    bool newline_found = false;
    
    char data[60] = {0};
    for(uint8_t i = 0; i < sizeof(data); i++) {
        
        if (RC1STAbits.OERR) { RC1STAbits.CREN = 0; RC1STAbits.CREN = 1; }
        uint8_t byte = EUSART1_Read();
        carriage_found = carriage_found || (byte == '\r');
        newline_found = newline_found || (byte == '\n');
        
        if(!(byte == '\r' || byte == '\n')) {
            data[i] = byte;
        }
        
        if(carriage_found && newline_found) {
            break;
        }
        
        if(!timeout_wait(rx_busy)) {
            log_debug("Read timed out mid-way");
            return LORA_TIMEOUT;
        }
        
    }
    
    log_debug(data);
    bool success = strcmp("+OK", data) == 0;
    if(success) {
        return RYLR998_OK;
    }
    
    // TODO: return more appropriate error code
    return LORA_UNLISTED_FAILURE;
}

bool lora_disable(void) {
    log_debug("Disabling RYLR");
    LORA_EN_SetLow();
    EUSART1_Disable();
    EUSART1_TransmitDisable();
    EUSART1_ReceiveDisable();
    return true;
}

bool lora_enable(void) {
    
    log_debug("Enabling RYLR");
    LORA_EN_SetHigh();
    log_debug("RYLR_EN high");
    
    __delay_ms(2000);
    
    // Clear the rx queue and submit an AT command and check for OK status
    eusart1_rx_clear();
    uart_write("AT\r\n");
    int8_t result = uart_read();
    
    if (result != RYLR998_OK) {
        log_debug("Failed to enable RYLR");
        return false;
    }

    log_debug("RYLR response found, comparing");
    return true;
}

uint8_t payload_size(char *parts[], uint8_t part_size) {
    
    uint8_t count = 0;
    for (uint8_t i = 0; i < part_size; i++) {
    
        uint8_t j = 0;
        while(parts[i][j] != '\0') {
            count++;
            j++;
        }
    }
    
    return count;
}

static bool append_str(char *dst, uint8_t *len, uint8_t cap, const char *src) {
    while (*src) {
        if (*len + 1 >= cap) {      // keep room for '\0'
            dst[*len] = '\0';
            return false;
        }
        dst[(*len)++] = *src++;
    }
    dst[*len] = '\0';
    return true;
}

int8_t lora_send(uint8_t address, int32_t metrics[], uint8_t size) {
    // 1) Build payload: "<UUID>::<m0>::<m1>..."
    char payload[50];
    uint8_t payload_len = 0;

    char *id = uuid_get();
    if (!append_str(payload, &payload_len, sizeof payload, id))
        return -1;

    for (uint8_t i = 0; i < size; i++) {
        if (!append_str(payload, &payload_len, sizeof payload, "::"))
            return -1;

        char num[12];                            // int32: up to 11 chars incl. sign + NUL
        int32_to_str(num, sizeof num, metrics[i]);
        if (!append_str(payload, &payload_len, sizeof payload, num))
            return -1;
    }

    // 2) Convert length and address
    char len_str[6];                             // plenty for <50: "49\0"
    uint16_to_str(len_str, sizeof len_str, (uint16_t)payload_len);

    char addr_str[4];                            // 0..255 -> up to "255\0"
    uint16_to_str(addr_str, sizeof addr_str, address);

    // 3) Build full command: "AT+SEND=<addr>,<len>,<payload>\r\n"
    char cmd[64];
    uint8_t cmd_len = 0;

    if (!append_str(cmd, &cmd_len, sizeof cmd, "AT+SEND=")) return -1;
    if (!append_str(cmd, &cmd_len, sizeof cmd, addr_str))   return -1;
    if (!append_str(cmd, &cmd_len, sizeof cmd, ","))        return -1;
    if (!append_str(cmd, &cmd_len, sizeof cmd, len_str))    return -1;
    if (!append_str(cmd, &cmd_len, sizeof cmd, ","))        return -1;
    if (!append_str(cmd, &cmd_len, sizeof cmd, payload))    return -1;
    if (!append_str(cmd, &cmd_len, sizeof cmd, "\r\n"))     return -1;

    int8_t rc = uart_write(cmd);
    if (rc < 0) return rc;
    return uart_read();
}