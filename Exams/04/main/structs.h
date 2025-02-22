#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdlib.h>

#include "./macros.h"

typedef struct {
    char word[WORD_LENGTH];
    size_t appearances;
} Word;

#endif // STRUCTS_H_INCLUDED
