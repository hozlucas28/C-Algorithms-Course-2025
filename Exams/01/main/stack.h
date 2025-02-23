#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>

/* ------------ Node ------------ */

typedef struct Node {
    void* __data;
    size_t __sizeOfData;
    struct Node* __next;
} Node;


/* ----------- Stack ------------ */

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

unsigned char isStackFull(
    Stack* _stack,
    const size_t sizeOfData
);

unsigned char isStackEmpty(Stack* _stack);

// Methods
unsigned char unshiftStackElement(
    Stack* _stack,
    void* data,
    const size_t sizeOfData
);

unsigned char shiftStackElement(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
);

void flatStack(Stack* _stack);

#endif // STACK_H_INCLUDED
