
#ifndef MAIN_DYNAMIC_LIBRARY_H_INCLUDED
#define MAIN_DYNAMIC_LIBRARY_H_INCLUDED

#include <stdlib.h>

/* -------- Node --------- */

typedef struct Node {
    void* __data;
    size_t __sizeOfData;
    struct Node* __next;
} Node;


/* -------- Queue -------- */

typedef struct {
    Node* __head;
    Node* __tail;
} Queue;

// Constructor
void newQueue(Queue* _queue);

// Destroyer
void destroyQueue(Queue* _queue);

// Getters
unsigned char getHead(
    const Queue* _queue,
    void* store,
    const size_t sizeOfStore
);

unsigned char isEmpty(const Queue* _queue);

unsigned char isFull(
    const Queue* _queue,
    const void* data,
    const size_t sizeOfData
);

// Methods
unsigned char shift(
    Queue* _queue,
    void* store,
    const size_t sizeOfStore
);

unsigned char push(
    Queue* _queue,
    void* data,
    const size_t sizeOfData
);

#endif // MAIN_DYNAMIC_LIBRARY_H_INCLUDED
