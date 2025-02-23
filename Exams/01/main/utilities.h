#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "./stack.h"

unsigned char createTestFile(const char* filePath);

unsigned char storeData(
    Stack* _stack,
    const char* filePath
);

#endif // UTILITIES_H_INCLUDED
