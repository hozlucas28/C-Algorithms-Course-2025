#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "./macros.h"

unsigned char createTestFile(
    const char* filePath,
    const char lines[][LINE_LENGTH],
    const size_t linesLength
);

#endif // TEST_H_INCLUDED
