#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "./macros.h"
#include "./singly-linked-list.h"

unsigned char storeWords(
    SList* words,
    const char* filePath
);

void toLower(char* str);

void printWord(void* word, const size_t index);

int cmpWords(const void* word, const void* wordInList);

int cmpWordsAppearances(const void* word01, const void* word02);

#endif // UTILITIES_H_INCLUDED
