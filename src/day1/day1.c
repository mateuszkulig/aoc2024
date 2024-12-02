#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "utils/load_file.h"


// There are 2 rows each consisting of 1000 numbers in file
#define inputRows 1000
#define inputColumns 2
    

/**
 * @brief Custom comparator for qsort() function
 *        Taken from https://www.geeksforgeeks.org/c-program-to-sort-an-array-in-ascending-order/
 * 
 * @param n1 First number 
 * @param n2 Second number
 * @return int Postive value if n1 is smaller, otherwise negative
 */
int sortComparator(const void *n1, const void *n2) {
    return (*(int*)n1 - *(int*)n2);
}


int main(int argc, char **argv) {
    FILE        *file = NULL;
    int         buffer;
    int         counter;
    // Swap columns and rows to be able to pass column as regular array 
    int         inputNumbers[inputColumns][inputRows];
    int         totalDistance = 0;
    int         tempDistance;
    int         totalSimilarity = 0;
    int         tempSimilarComparator;
    errorCode   returnCode;
    

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

    for (int row=0; row<inputRows; ++row) {
        for (int column=0; column<inputColumns; ++column) {
            returnCode = readInt32(file, &inputNumbers[column][row]);
        }
    }

    fclose(file);

    for (int column=0; column<inputColumns; ++column) {
        qsort(inputNumbers[column], inputRows, sizeof(int), sortComparator);
    }
    
    for (int row=0; row<inputRows; ++row) {
        tempDistance = inputNumbers[0][row] - inputNumbers[1][row];
        if (tempDistance < 0) {
            tempDistance = -tempDistance;
        }
        totalDistance += tempDistance;
    }

    for (int row=0; row<inputRows; ++row) {
        counter = 0;
        tempSimilarComparator = inputNumbers[0][row];
        for (int row2=0; row2<inputRows; ++row2) {
            if (tempSimilarComparator == inputNumbers[1][row2]) {
                counter++;
            } else if (tempSimilarComparator < inputNumbers[1][row2]) {
                // Little negligible optimization
                break;
            }
        }
        totalSimilarity += counter * tempSimilarComparator;
    }
    
    printf("Part 1: %d\n", totalDistance);
    printf("Part 2: %d\n", totalSimilarity);

    return 0;
}
