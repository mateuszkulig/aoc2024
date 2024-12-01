#ifndef ERROR_H
#define ERROR_H 

typedef enum errorCode {
    errOK = 0,              // Operation succeeded
    errFileNotOpened = 1,   // File pointer is set to NULL
    errBufferOverflow = 2   // Supplied buffer is too small for data
} errorCode;

#endif
