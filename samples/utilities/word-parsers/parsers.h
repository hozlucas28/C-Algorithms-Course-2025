#ifndef PARSERS_H_INCLUDED
#define PARSERS_H_INCLUDED

#include "../../singly-linked-list/library/main.h"

#ifndef WORD_LENGTH
    #define WORD_LENGTH 64 + 1
#endif

#ifndef LINE_LENGTH
    #define LINE_LENGTH WORD_LENGTH * 25 + 1
#endif

size_t parseWordsBySeps(
    char* line,
    const char* separators,
    unsigned char (*onGetWord)(const char* word, const void* params),
    const void* params
);

int parseBrakedWordsFromFile(
    const char* filePath,
    const char* wordSeparators,
    unsigned char (*onGetWord)(const char* word, const void* params),
    const void* params
);

int parseBrakedWordsFromFileUnknownSeps(
    const char* filePath,
    unsigned char (*isWordChar)(const char _char),
    unsigned char (*onGetWord)(const char* word, const void* params),
    const void* params
);

#endif // PARSERS_H_INCLUDED
