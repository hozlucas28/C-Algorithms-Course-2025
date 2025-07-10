#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdlib.h>

typedef struct {
    void* __data;
    size_t __sizeOfData;
    void* __next;
} Node;

typedef struct {
    Node* __head;
    Node* __tail;
} Queue;

// Constructor
void newQueue(Queue* _queue);

// Destructor
void destroyQueue(Queue* _queue);

// Getters
unsigned char isQueueFull(
    Queue* _queue,
    const size_t sizeOfData
);

unsigned char isQueueEmpty(Queue* _queue);

// Methods
unsigned char shiftQueueElement(
    Queue* _queue,
    void* store,
    const size_t sizeOfStore
);

unsigned char pushQueueElement(
    Queue* _queue,
    void* data,
    const size_t sizeOfData
);

#endif // QUEUE_H_INCLUDED
