#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "utils/load_file.h"


/**
 * @brief Looking at the input it seems that every line has no more than 8 numbers, and there
 *        are total of 1000 lines
 * 
 */
#define inputMaxLineNumbers 8
#define inputLines 1000


/**
 * @brief Compare if second value increased over first value
 * 
 * @param value1 First value
 * @param value2 Second value
 * @return true Second value increased
 * @return false First value increased or stayed the same
 */
bool hasIncreased(int value1, int value2) {
    return value1 - value2 < 0 ? true : false;
}


int main(int argc, char **argv) {
    FILE        *file = NULL;
    int         puzzleLevels[inputMaxLineNumbers];
    int         puzzleReportSize;
    int         safeCount = 0;
    int         difference;
    int         isSafe;
    bool        increasing;
    errorCode   returnCode;
    char        newlineBuffer;

    if (argc < 2) {
        printf("Missing argument: filename\n");
        printf("Usage: %s <path>\n", argv[0]);
        return -1;
    }
    for (int i=2; i<argc; ++i) {
        printf("Ignoring extra argument: %s\n", argv[i]);
    }

    // Read input file
    file = fopen(argv[1], "r");

    for (int i=0; i<inputLines; ++i) {
        // Load data into array
        puzzleReportSize = 0;
        for (int current=0; current<inputMaxLineNumbers; ++current) {
            returnCode = readInt32(file, &puzzleLevels[puzzleReportSize]);
            if (returnCode == errFileEnd) {
                // Happens when last line has less than maximum characters
                break;
            } else if (returnCode) {
                printf("readInt32 error: %d\n", returnCode);
                return returnCode;
            }

            puzzleReportSize++;

            readLastChar(file, &newlineBuffer);
            if (returnCode) {
                printf("readLastChar error: %d\n", returnCode);
                return returnCode;
            }

            if (newlineBuffer == '\n') {
                break;
            }
        }

        // Process data: Part 1
        increasing = hasIncreased(puzzleLevels[0], puzzleLevels[1]);
        isSafe = 1;
        for (int current=1; current<puzzleReportSize; ++current) {
            if (hasIncreased(puzzleLevels[current-1], puzzleLevels[current]) != increasing) {
                isSafe = 0;
                break;
            }

            // Kinda weird reverse logic
            difference = puzzleLevels[current-1] - puzzleLevels[current];
            if (increasing) {
                difference = -difference;
            }

            if (difference < 1 || difference > 3) {
                isSafe = 0;
                break;
            }
        }

        safeCount += isSafe;
    }

    fclose(file);

    printf("Part 1: %d\n", safeCount);

    return 0;
}