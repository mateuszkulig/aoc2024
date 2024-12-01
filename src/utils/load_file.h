#ifndef LOAD_FILE_H
#define LOAD_FILE_H

#include "stdio.h"
#include "error.h"

/**
 * @brief Read characters from opened file until encoutering space, newline of end of file
 *        Ignores spaces etc. until reaching first character 
 * 
 * @param file Pointer to opened file
 * @param buffer Buffer to store the characters in
 * @param bufferSize Size of supplied buffer
 * @return errorCode One of codes from error.h
 */
errorCode readWord(FILE *file, char *buffer, int bufferSize);

#endif
