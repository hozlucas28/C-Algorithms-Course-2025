#ifndef SINGLY_LINKED_LIST_H_INCLUDED
#define SINGLY_LINKED_LIST_H_INCLUDED

#include <stdlib.h>

/* ----------- Node ----------- */

typedef struct Node {
    void* __data;
    size_t __sizeOfData;
    struct Node* __next;
} Node;


/* ---- Singly Linked List ---- */

typedef Node* SList;

// Constructor
void newSList(SList* _list);

// Destructor
void destroySList(SList* _list);

// Getters
unsigned char isSListFull(
    const SList* _list,
    const size_t sizeOfData
);

unsigned char isSListEmpty(const SList* _list);

// Methods
unsigned char insertSListElementInOrder(
    SList* _list,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* data, const void* dataInList)
);

void mapSList(
    SList* _list,
    void (*callback)(void* element)
);

void sortSList(
    SList* _list,
    int (*cmp)(const void* a, const void* b)
);

void reverSList(SList* _list);

#endif // SINGLY_LINKED_LIST_H_INCLUDED
