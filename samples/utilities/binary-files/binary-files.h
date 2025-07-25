#ifndef BINARY_FILES_H_INCLUDED
#define BINARY_FILES_H_INCLUDED

#include <stdio.h>

// Getters
size_t getAmountOfData(
    FILE* file,
    const size_t sizeOfData
);

unsigned char getDataAt(
    FILE* file,
    const size_t sizeOfData,
    void* store,
    const size_t storeLength,
    const size_t index
);

// Methods
unsigned char writeDataAt(
    FILE* file,
    const size_t sizeOfData,
    const void* data,
    const size_t dataLength,
    const size_t index
);

#endif // BINARY_FILES_H_INCLUDED
