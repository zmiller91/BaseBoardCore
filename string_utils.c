
#include "string_utils.h"
/* ---------- unsigned 16-bit -> decimal ---------- */
uint8_t uint16_to_str(char *out, uint8_t out_capacity, uint16_t value) {
    if (out_capacity == 0) return 0;

    // maximum 16 bit digit is 65535
    char digit_string[5];
    uint8_t num_digits = 0;

    // get the right most digit and then shift all digits to the right 
    // (mod, divide by 10), effectively turning the digit into a reversed string
    do {
        digit_string[num_digits] = (char)('0' + (uint8_t)(value % 10u));
        value /= 10u;
        num_digits++;
    } while (value);

    // reverse the reversed string, clamping it to the the input size 
    // adding 1 to num_digits in order to account for the necessary string terminator '\0'
    uint8_t digits_to_copy = (num_digits  + 1 > out_capacity ) ? out_capacity - 1 : num_digits;
    for (uint8_t i = 0; i < digits_to_copy; ++i)
        out[i] = digit_string[num_digits - 1 - i];

    out[digits_to_copy] = '\0';
    return digits_to_copy;
}

/* ---------- signed 16-bit -> decimal ---------- */
uint8_t int16_to_str(char *out, uint8_t out_capacity, int16_t number) {
    if (out_capacity == 0) return 0;
    if (number < 0) {
        if (out_capacity < 2) { out[0] = '\0'; return 0; }
        out[0] = '-';
        return (uint8_t)(1 + uint16_to_str(out + 1, (uint8_t)(out_capacity - 1), (uint16_t)(-number)));
    }
    return uint16_to_str(out, out_capacity, (uint16_t)number);
}






/* ---------- unsigned 16-bit -> decimal ---------- */
uint8_t uint32_to_str(char *out, uint8_t out_capacity, uint32_t value) {
    if (out_capacity == 0) return 0;

    // maximum 32 bit digit is 4294967295
    char digit_string[10];
    uint8_t num_digits = 0;

    // get the right most digit and then shift all digits to the right 
    // (mod, divide by 10), effectively turning the digit into a reversed string
    do {
        digit_string[num_digits] = (char)('0' + (uint8_t)(value % 10u));
        value /= 10u;
        num_digits++;
    } while (value);

    // reverse the reversed string, clamping it to the the input size 
    // adding 1 to num_digits in order to account for the necessary string terminator '\0'
    uint8_t digits_to_copy = (num_digits  + 1 > out_capacity ) ? out_capacity - 1 : num_digits;
    for (uint8_t i = 0; i < digits_to_copy; ++i)
        out[i] = digit_string[num_digits - 1 - i];

    out[digits_to_copy] = '\0';
    return digits_to_copy;
}

/* ---------- signed 16-bit -> decimal ---------- */
uint8_t int32_to_str(char *out, uint8_t out_capacity, int32_t number) {
    if (out_capacity == 0) return 0;
    if (number < 0) {
        if (out_capacity < 2) { out[0] = '\0'; return 0; }
        out[0] = '-';
        return (uint8_t)(1 + uint32_to_str(out + 1, (uint8_t)(out_capacity - 1), (uint32_t)(-number)));
    }
    
    return uint32_to_str(out, out_capacity, (uint32_t)number);
}











void join_buffers(char *parts[], uint8_t part_size, char *buffer, uint8_t buffer_size) {

    uint8_t position_idx = 0;
    for (uint8_t i = 0; i < part_size; i++) {
        
        uint8_t j = 0;
        while(position_idx < buffer_size - 1 && parts[i][j] != '\0') {
            buffer[position_idx] = parts[i][j];
            j++;
            position_idx++;
        }
    }
    
    buffer[position_idx] = '\0';
}

char hex_digit(uint8_t v) {
    // Mask v down to its lowest 4 bits. 0xAB would become 0X0B
    v &= 0x0Fu;
    return (v < 10u) ? (char)('0' + v) : (char)('A' + (v - 10u));
}


uint8_t byte_to_hex2(uint8_t value, char out[3]) {
    out[0] = hex_digit(value >> 4); // convert the first four bits)
    out[1] = hex_digit(value); // Convert the second four bits
    out[2] = '\0';
    return 2;
}