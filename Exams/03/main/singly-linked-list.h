#ifndef SINGLY_LINKED_LIST_H_INCLUDED
#define SINGLY_LINKED_LIST_H_INCLUDED

#include <stdlib.h>

/* ----------------- Node ----------------- */

typedef struct Node {
    void* __data;
    size_t __sizeOfData;
    struct Node* __next;
} Node;


/* ---------- Singly Linked List ---------- */

typedef Node* SList;

// Constructor
void newSList(SList* _list);

// Destructor
void destroySList(SList* _list);

// Getters
unsigned char getSListHead(
    SList* _list,
    void* store,
    const size_t sizeOfStore
);

unsigned char isSListFull(
    SList* _list,
    const size_t sizeOfData
);

unsigned char isSListEmpty(SList* _list);

// Methods
unsigned char shiftSListElement(
    SList* _list,
    void* store,
    const size_t sizeOfStore
);

unsigned char insertSListElementTop(
    SList* _list,
    void* data,
    const size_t sizeOfData,
    const size_t maximumTop,
    int (*cmp)(const void* data, const void* element)
);

void sortSList(
    SList* _list,
    int (*cmp)(const void* a, const void* b)
);

void mapSList(
    SList* _list,
    void (*callback)(void* data, const size_t index, const void* params),
    const void* params
);

#endif // SINGLY_LINKED_LIST_H_INCLUDED
