
#include "./binary-files.h"

#include <stdio.h>

// Getters
size_t getAmountOfData(
    FILE* file,
    const size_t sizeOfData
) {
    long bytes;

    rewind(file);
    bytes = ftell(file);
    if (bytes < 0) return 0;

    fseek(file, 0, SEEK_END);
    bytes = ftell(file) - bytes;

    return bytes / sizeOfData;
}

unsigned char getDataAt(
    FILE* file,
    const size_t sizeOfData,
    void* store,
    const size_t storeLength,
    const size_t index
) {
    if (!fseek(file, sizeOfData * index, SEEK_SET)) {
        fread(store, sizeOfData, storeLength, file);

        rewind(file);

        return 0;
    };

    rewind(file);

    return 1;
}

// Methods
unsigned char writeDataAt(
    FILE* file,
    const size_t sizeOfData,
    const void* data,
    const size_t dataLength,
    const size_t index
) {
    if (!fseek(file, sizeOfData * index, SEEK_SET)) {
        fwrite(data, sizeOfData, dataLength, file);
        fflush(file);

        rewind(file);

        return 0;
    };

    rewind(file);

    return 1;
}
