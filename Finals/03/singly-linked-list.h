#ifndef SINGLY_LINKED_LIST_H_INCLUDED
#define SINGLY_LINKED_LIST_H_INCLUDED

#include <stdlib.h>

typedef struct Node {
    void* __data;
    size_t __sizeOfData;
    struct Node* __next;
} Node;

typedef Node* SList;

// Constructor
void newSList(SList* _list);

// Destructor
void destroySList(SList* _list);

// Methods
unsigned char insertSListTop(
    SList* _list,
    void* data,
    const size_t sizeOfData,
    const size_t top,
    int (*cmp)(const void* a, const void* b)
);

void mapSList(
    SList* _list,
    void (*callback)(void* data, const size_t sizeOfData, const size_t index, void* params),
    void* params
);

#endif // SINGLY_LINKED_LIST_H_INCLUDED
