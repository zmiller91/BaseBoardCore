/* 
 * File:   string_utils.h
 * Author: zmiller
 *
 * Created on September 11, 2025, 9:58 PM
 */

#ifndef STRING_UTILS_H
#define	STRING_UTILS_H


#include <stdint.h>

/* ---------- unsigned 16-bit -> decimal ---------- */
uint8_t uint16_to_str(char *, uint8_t, uint16_t);

/* ---------- signed 16-bit -> decimal ---------- */
uint8_t int16_to_str(char *, uint8_t, int16_t);

/* ---------- unsigned 32-bit -> decimal ---------- */
uint8_t uint32_to_str(char *, uint8_t, uint32_t);

/* ---------- signed 32-bit -> decimal ---------- */
uint8_t int32_to_str(char *, uint8_t, int32_t);

void join_buffers(char *[], uint8_t , char *, uint8_t);
uint8_t byte_to_hex2(uint8_t, char *);
#endif	/* STRING_UTILS_H */

