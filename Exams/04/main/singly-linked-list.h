#ifndef SINGLY_LINKED_LIST_H_INCLUDED
#define SINGLY_LINKED_LIST_H_INCLUDED

#include <stdlib.h>

/* ---------- Node ---------- */

typedef struct Node {
    void* __data;
    size_t __sizeOfData;
    struct Node* __next;
} Node;


/* --- Singly Linked List --- */

typedef Node* SList;

// Constructor
void newSList(SList* _list);

// Destructor
void destroySList(SList* _list);

// Getters
unsigned char getSListHead(
    const SList* _list,
    void* store,
    const size_t sizeOfStore
);

unsigned char getSListTail(
    const SList* _list,
    void* store,
    const size_t sizeOfStore
);

// Methods
unsigned char insertSListElementInOrder(
    SList* _list,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* data, const void* element)
);

void sortSList(
    SList* _list,
    int (*cmp)(const void* a, const void* b)
);

void mapSList(
    const SList* _list,
    void (*callback)(void* element, const size_t index)
);

void reverseMapSList(
    const SList* _list,
    void (*callback)(void* element, const size_t index)
);

#endif // SINGLY_LINKED_LIST_H_INCLUDED
