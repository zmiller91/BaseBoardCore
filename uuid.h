/* 
 * File:   uuid.h
 * Author: zmiller
 *
 * Created on August 8, 2025, 11:10 PM
 */

#ifndef UUID_H
#define	UUID_H 

extern char g_uuid[9]; // 4 bytes, 2 char each, plus null terminator
void uuid_init(void);
const char* uuid_get(void);

#endif	/* UUID_H */

