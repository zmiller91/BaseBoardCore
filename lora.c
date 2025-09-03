#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include <xc.h>
#include "mcc_generated_files/system/system.h"

#include "lora.h"
#include "timeout.h"
#include "log.h"
#include "uuid.h"

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
    RYLR_EN_SetLow();
    EUSART1_Disable();
    EUSART1_TransmitDisable();
    EUSART1_ReceiveDisable();
    return true;
}

bool lora_enable(void) {
    
    log_debug("Enabling RYLR");
    RYLR_EN_SetHigh();
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

int8_t lora_send(uint8_t address, double metrics[], uint8_t size) {
    
    char metricResult[60] = {0};
    for(uint8_t idx = 0; idx < size; idx++) {
        
        // There shouldn't be more than 10 characters in the metric, including
        // decimals and negative signs.
        char data[10];
        sprintf(data, "%.2f", metrics[idx]);
        
        strcat(metricResult, "::");
        strcat(metricResult, data);
    }
       
    // Calculate the payload size, since any null values won't be written
    // to the final buffer.
    int payload_size = snprintf(NULL, 0, "%s%s", uuid_get(), metricResult);
    char buffer[60] = {0};
    sprintf(buffer, "AT+SEND=%i,%i,%s%s\r\n", address, payload_size, uuid_get(), metricResult);
    
    log_debug(buffer);
    int8_t response_code = uart_write(buffer);
    if(response_code < 0) {
        return response_code;
    }
    
    return uart_read();
}