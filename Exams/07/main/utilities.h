#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <stdlib.h>

#include "./binary-tree.h"

#define LINE_LENGTH (sizeof(char) * (512 + 1))
#define TAG_LINE_LENGTH (sizeof(char) * (2 + 1))

unsigned char loadTagsOnBTree(
    BTree* tree,
    const char* filePath
);

unsigned char validateFile(
    const char* filePath,
    const char* tagsFilePath,
    void (*onValidLine)(const char* line, const size_t lineIndex, void* params),
    void (*onInvalidLine)(const char* line, const size_t lineIndex, void* params),
    void* params
);

#endif // UTILITIES_H_INCLUDED
