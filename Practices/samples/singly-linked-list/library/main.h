
#ifndef MAIN_LIBRARY_H_INCLUDED
#define MAIN_LIBRARY_H_INCLUDED

#include <stdlib.h>

/* --------------- Node --------------- */

typedef struct Node {
    void* __data;
    size_t __sizeOfData;
    struct Node* __next;
} Node;


/* -------- Singly Linked List -------- */

typedef Node* SList;

// Constructor
void newSList(SList* _list);

// Destroyer
void destroySList(SList* _list);

// Getters
unsigned char getSListHead(
    SList* _list,
    void* store,
    const size_t sizeOfStore
);

unsigned char getSListTail(
    SList* _list,
    void* store,
    const size_t sizeOfStore
);

unsigned char isSListFull(
    const SList* _list,
    const size_t sizeOfData
);

unsigned char isSListEmpty(const SList* _list);

// Methods
unsigned char unshiftSListElement(
    SList* _list,
    void* data,
    const size_t sizeOfData
);

unsigned char pushSListElement(
    SList* _list,
    void* data,
    const size_t sizeOfData
);

unsigned char insertSListElementAt(
    SList* _list,
    void* data,
    const size_t sizeOfData,
    const size_t index
);

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
    SList* _list,
    void (*callback)(const void* element)
);

void reverseMapSList(
    const SList* _list,
    void (*callback)(void* element, const size_t index)
);

void reverSList(SList* _list);

#endif // MAIN_LIBRARY_H_INCLUDED