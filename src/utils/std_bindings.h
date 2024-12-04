#ifndef STD_BINGINGS_H
#define STD_BINGINGS_H

#include "stdlib.h"

/**
 * @brief Defininions of std libc functions to use, change if in need to use custom funcitons
 *        instead of standard ones
 * 
 */
#define getCharFromFile(filePointer) fgetc(filePointer)
#define getPositionFromFile(filePointer) ftell(filePointer)
#define setPositionInFile(filePointer, newPosition, relativeTo) fseek(filePointer, newPosition, relativeTo)
#define convertStringToInt(str) atoi(str)

#endif
