
#ifndef MAIN_STATIC_LIBRARY_H_INCLUDED
#define MAIN_STATIC_LIBRARY_H_INCLUDED

#include <stdlib.h>

#define MIN(a, b) ((a) > (b) ? (b) : (a));

/* ------------ Queue ------------ */

#define QUEUE_BYTES ((sizeof(size_t) + sizeof(int)) * 6)

typedef struct {
    char __data[QUEUE_BYTES];
    size_t __head;
    size_t __tail;
    size_t __remainingCapacity;
} Queue;

// Constructor
void newQueue(Queue* _queue);

// Destructor
void destroyQueue(Queue* _queue);

// Getters
unsigned char getTopQueueElement(
    const Queue* _queue,
    void* store,
    const size_t sizeOfStore
);

unsigned char isQueueEmpty(const Queue* _queue);

unsigned char isQueueFull(
    const Queue* _queue,
    const size_t sizeOfData
);

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

#endif // MAIN_STATIC_LIBRARY_H_INCLUDED
