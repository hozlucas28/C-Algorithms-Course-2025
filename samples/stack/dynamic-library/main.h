
#ifndef MAIN_DYNAMIC_LIBRARY_H_INCLUDED
#define MAIN_DYNAMIC_LIBRARY_H_INCLUDED

#include <stdlib.h>

/* -------- Node -------- */

typedef struct Node {
    void* __data;
    size_t __sizeOfData;
    struct Node* __next;
} Node;


/* ------- Stack -------- */

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
    const Stack* _stack,
    const size_t sizeOfData
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

void flatStack(Stack* _stack);

unsigned char toFlatStack(
    Stack* _stack,
    Stack* flattedStack
);

#endif // MAIN_DYNAMIC_LIBRARY_H_INCLUDED
