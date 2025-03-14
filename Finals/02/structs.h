#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdlib.h>

typedef struct Node {
    void* __data;
    size_t __sizeOfData;
    struct Node* __next;
} Node;

#endif // STRUCTS_H_INCLUDED
