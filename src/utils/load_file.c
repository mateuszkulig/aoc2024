#include "stdio.h"
#include "stdbool.h"
#include "load_file.h"
#include "error.h"
#include "std_bindings.h"


errorCode readWord(FILE *file, char *buffer, int bufferSize) {
    char    oneByteBuffer;
    int     currentIndex = 0;
    bool    firstSpaceCheck = true;

    if (!file) {
        return errFileNotOpened;
    }

    while (true) {
        if (currentIndex >= bufferSize) {
            return errBufferOverflow;
        }

        oneByteBuffer = getCharFromFile(file);

        if (oneByteBuffer == EOF || oneByteBuffer == ' ' || oneByteBuffer == '\n') {
            if (firstSpaceCheck && oneByteBuffer != EOF) {
                continue;
            }

            break;
        }

        firstSpaceCheck = false;

        buffer[currentIndex] = oneByteBuffer;
        currentIndex++;
    }

    // End string with null character
    buffer[currentIndex] = '\0';

    return errOK;
}
