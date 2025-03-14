
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "./structs.h"

#include <stdlib.h>

typedef Node* Stack;

// Constructor
void newStack(Stack* _stack);

// Destructor
void destroyStack(Stack* _stack);

// Getters
unsigned char getStackTop(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
);

unsigned char isStackEmpty(const Stack* _stack);

// Methods
unsigned char unshiftStack(
    Stack* _stack,
    void* data,
    const size_t sizeOfData
);

unsigned char shiftStackElement(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
);

#endif // STACK_H_INCLUDED
