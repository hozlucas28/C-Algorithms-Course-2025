#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <stdlib.h>

#include "./structs.h"
#include "./singly-linked-list.h"

unsigned char processRunners(
    const char* filePath,
    SList* runners,
    const size_t top
);

void printRunner(
    void* runner,
    const size_t sizeOfRunner,
    const size_t index,
    void* params
);

#endif // UTILITIES_H_INCLUDED
