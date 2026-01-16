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
    if (RC1STAbits.OERR) {
        RC1STAbits.CREN = 0;
        RC1STAbits.CREN = 1;
    }
    return !EUSART1_IsRxReady();
}

int8_t uart_read(char* data, uint8_t data_len) {
    
    // Data must have something. Data cannot be null and it must have at least 
    // one element + \0 for a total of 2 elements
    if (data == NULL || data_len < 2) {
        return LORA_INVALID_DATA;
    }

    data[0] = '\0';
    
    if(!timeout_wait(rx_busy)) {
        log_debug("No data.");
        return NO_DATA;
    }
    
    bool carriage_found = false;
    bool newline_found = false;
    
    for(uint8_t i = 0; i < data_len - 1; i++) {
        
        // Clear overrun if present (otherwise RX can get stuck)
        if (RC1STAbits.OERR) { 
            RC1STAbits.CREN = 0; 
            RC1STAbits.CREN = 1; 
        }
        
        // Read the next byte, keep track of new line characters
        uint8_t byte = EUSART1_Read();     
        carriage_found = carriage_found || (byte == '\r');
        newline_found = newline_found || (byte == '\n');
        
        // If the received byte isn't a newline character, then set it and
        // advance the terminal \0 character
        if(!(byte == '\r' || byte == '\n')) {
            data[i] = byte;
            data[i + 1] = '\0';
        }
        
        // Return if a newline has been found
        if(carriage_found || newline_found) {
            data[i] = '\0';
        }
        
        if(carriage_found && newline_found) {
            break;
        }
        
        // Wait for the next byte
        if(!timeout_wait(rx_busy)) {       
            log_debug("Read timed out mid-way");
            data[i] = '\0';
            return LORA_TIMEOUT;
        }
        
    }
    
    log_debug(data);
    return DATA_RECEIVED;
}



int8_t lora_parse_rcv_line(char* line_buf, LoraRcv* out) {
    if (!line_buf || !out) return LORA_INVALID_DATA;
    
    // +RCV=32,20,015042B7::a34ac35k::1001,-86,
    char* current_char = line_buf;
    
    // Basic prefix check
    char prefix[] = "+RCV=";
    for(int i = 0; i < 5; i++) {
        if(*current_char != prefix[i]) {
            return LORA_PARSE_ERROR;
        }
        
        current_char++;
    }
    
    // Advance the current character tot he start of the data bucket. 
    int8_t comma_count = 0;
    while(comma_count < 2 && *current_char != '\0') {
        if(*current_char == ',') {
            comma_count++;
        }    
        current_char++;
    }
    
    if(comma_count != 2) {
        return LORA_PARSE_ERROR;
    }
    
    // Start walking the data block
    char *current_data = current_char;
    
    // The prefix of the data block is the serial number. If they don't match
    // then the message isn't for us. 
    char *id = uuid_get();
    for (int i = 0; i < UUID_SIZE; i++) {
        
        // Premature termination
        if(*current_data == '\0') {
            return LORA_PARSE_ERROR;
        }
        
        if(id[i] != *current_data) {
            return NO_DATA;
        }
        
        current_data++;
    }
    
    // There should be a :: after the serial number.
    if(*current_data != ':' || *(current_data + 1) != ':') {
        return LORA_PARSE_ERROR;
    }
    
    current_data = current_data + 2;
    
    // The next bit of data is the message id
    char message_id[LORA_MAX_MSGID + 1] = {0};
    uint8_t message_id_len = 0;
    for(int i = 0; i < LORA_MAX_MSGID; i++) {
        
        // Premature termination. More data should still exist. 
        if(*current_data == '\0' || *(current_data + 1) == '\0') {
            return LORA_PARSE_ERROR;
        }
        
        // Block ended
        if(*current_data == ':' && *(current_data + 1) == ':') {
            current_data = current_data + 2;
            break;
        }
        
        message_id_len++;
        message_id[i] = *current_data;
        current_data++;
    }
    
    if(message_id_len == 0) {
        return LORA_PARSE_ERROR;
    }
    
    
    // The remainder is the payload
    // Go to the next comma and replace it with a null terminated string
    bool comma_found = false;
    for(int i = 0; i < MAX_PAYLOAD_SIZE; i++) {
       
        if(current_data[i] == '\0') {
            return LORA_PARSE_ERROR;
        }
        
        if(current_data[i] == ',') {
            comma_found = true;
            current_data[i] = '\0';
            break;
        }
    }
    
    if(!comma_found) {
        return LORA_PARSE_ERROR;
    }
    
    memset(out, 0, sizeof(*out));
    memcpy(out -> msg_id, message_id, message_id_len + 1);
    out->msg_id[message_id_len] = '\0';
    out -> payload = current_data;
    
    return DATA_RECEIVED;
}

int8_t lora_receive(char* line_buf, uint8_t line_len, LoraRcv* out){ 
    
    if (line_buf == NULL || out == NULL || line_len < 2) {
        return LORA_INVALID_DATA;
    }

    int8_t response = uart_read(line_buf, line_len);
    if (response != DATA_RECEIVED) {
        return response;
    }

    return lora_parse_rcv_line(line_buf, out);
}

int8_t send_rx_open(uint8_t address, uint16_t duration) {
    

    char buff1[] = "RXOPEN::";
    char buff2[5];
    uint16_to_str(buff2, 5, duration);

    char out[14];
    char *parts[] = { buff1, buff2};
    join_buffers(parts, 2, out, 14);
    
    return lora_send_raw(address, out);
}

int8_t send_ack(uint8_t address, const char *message_id) {
    
    char buf[LORA_MAX_MSGID + 5]; 
    char *parts[] = { "ACK::", message_id };
    
    join_buffers(parts, 2, buf, LORA_MAX_MSGID + 5);
    return lora_send_raw(address, buf);
}

int8_t send_command_complete(uint8_t address, const char *message_id) {
    
    char buf[LORA_MAX_MSGID + 5]; 
    char *parts[] = { "CMDCMPLT::", message_id };
    
    join_buffers(parts, 2, buf, LORA_MAX_MSGID + 5);
    return lora_send_raw(address, buf);
}

int8_t uart_is_rylr_send_success(void){
    char data[60] = {0};

    int8_t response = uart_read(data, sizeof(data));
    if (response != DATA_RECEIVED) {
        return response;
    }

    if (strcmp(data, "+OK") == 0) {
        return RYLR998_OK;
    }

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
    int8_t result = uart_is_rylr_send_success();
    
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
    
    char payload[40];
    uint8_t payload_len = 0;
    
    for (uint8_t i = 0; i < size; i++) {
        
        if(i > 0 && !append_str(payload, &payload_len, sizeof payload, "::")) {
            return PAYLOAD_TOO_BIG;
        }
        char num[12];                            // int32: up to 11 chars incl. sign + NUL
        int32_to_str(num, sizeof num, metrics[i]);
        if (!append_str(payload, &payload_len, sizeof payload, num)) {
            return PAYLOAD_TOO_BIG;
        }
    }
    
    return lora_send_raw(address, payload);
}

int8_t lora_send_raw(uint8_t address, char* data) {
    
    char payload[50];
    uint8_t payload_len = 0;

    // Create the message by adding the uuid along with whatever the device sent
    char *id = uuid_get();
    if (!append_str(payload, &payload_len, sizeof payload, id)  ||
            !append_str(payload, &payload_len, sizeof payload, "::") || 
            !append_str(payload, &payload_len, sizeof payload, data)) {
        
        return PAYLOAD_TOO_BIG;
    }

    // Convert length and address
    char len_str[6];                             // plenty for <50: "49\0"
    uint16_to_str(len_str, sizeof len_str, (uint16_t)payload_len);

    char addr_str[4];                            // 0..255 -> up to "255\0"
    uint16_to_str(addr_str, sizeof addr_str, address);

    // Build full command: "AT+SEND=<addr>,<len>,<payload>\r\n"
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
    return uart_is_rylr_send_success();
}