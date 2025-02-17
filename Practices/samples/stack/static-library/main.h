
#ifndef MAIN_STATIC_LIBRARY_H_INCLUDED
#define MAIN_STATIC_LIBRARY_H_INCLUDED

#include <stdlib.h>

#define STACK_BYTES (sizeof(size_t) * 128 + sizeof(char) * 128)

typedef struct {
    char __data[STACK_BYTES];
    size_t __remainingCapacity;
} Stack;

// Constructor
void newStack(Stack* _stack);

// Destructor
void destroyStack(Stack* _stack);

// Getters
unsigned char getStackTopElement(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
);

unsigned char isStackEmpty(Stack* _stack);

unsigned char isStackFull(
    Stack* _stack,
    const size_t sizeOfData
);

// Methods
unsigned char  pushStackElement(
    Stack* _stack,
    void* data,
    const size_t sizeOfData
);

unsigned char  popStackElement(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
);

#endif // MAIN_STATIC_LIBRARY_H_INCLUDED
