#ifndef LOAD_FILE_H
#define LOAD_FILE_H

#include "stdio.h"
#include "stdint.h"
#include "error.h"

/**
 * @brief Total number of characters in longest 4-byte int value (-2147483647) plus 1 extra
 *        for null byte 
 * 
 */
#define maxInt32InCharacters 11 + 1

/**
 * @brief Read characters from opened file until encoutering space, newline of end of file
 *        Ignores spaces etc. until reaching first character, adds null byte at the end of
 *        buffer.
 * 
 * @param file Pointer to file
 * @param buffer Buffer to store the characters in
 * @param bufferSize Size of supplied buffer
 * @return errorCode One of codes from error.h
 */
errorCode readWord(FILE *file, char *buffer, uint32_t bufferSize);

/**
 * @brief Read signed integer value from opened file, integer is considered ended when
 *        the next character is space, newline, EOF instead of number. Ignores spaces etc.
 *        until reaching first character       
 * 
 * @param file Poiter to file
 * @param buffer Buffer for read integer
 * @return errorCode 
 */
errorCode readInt32(FILE *file, int32_t *buffer);

#endif
