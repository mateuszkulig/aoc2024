#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"
#include "load_file.h"
#include "error.h"
#include "std_bindings.h"


errorCode readWord(FILE *file, char *buffer, uint32_t bufferSize) {
    char        oneByteBuffer;
    uint32_t    currentIndex = 0;
    bool        firstSpaceCheck = true;

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
            } else if (oneByteBuffer == EOF && currentIndex == 0) {
                return errFileEnd;
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


errorCode readInt32(FILE *file, int32_t *buffer) {
    char        conversionBuffer[maxInt32InCharacters];
    errorCode   returnCode;

    returnCode = readWord(file, conversionBuffer, maxInt32InCharacters);
    if (returnCode) {
        return returnCode;
    }
    *buffer = convertStringToInt(conversionBuffer);

    return errOK;
}


errorCode readLastChar(FILE *file, char *buffer) {
    int64_t position;

    position = getPositionFromFile(file);
    // File stream is at its first character
    if (position == 0) {
        return errFileStart;
    }

    // Previous character is at current position - 1 character
    if (setPositionInFile(file, position-1, SEEK_SET)) {
        return errFileSeekFailed;
    }

    *buffer = getCharFromFile(file);

    return errOK;
}
