#ifndef ERROR_H
#define ERROR_H 

typedef enum errorCode {
    errOK = 0,              // Operation succeeded
    errFileNotOpened = 1,   // File pointer is set to NULL
    errFileEnd = 2,         // File read started at the EOF
    errFileStart = 3,       // File read started before first character
    errFileSeekFailed = 4,  // File seek call returned non-zero
    errBufferOverflow = 5,  // Supplied buffer is too small for data
} errorCode;

#endif
