
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
unsigned char getStackTopElement(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
);

unsigned char isStackEmpty(const Stack* _stack);

unsigned char isStackFull(
    const Stack* _stack,
    const size_t sizeOfData
);

// Methods
unsigned char pushStackElement(
    Stack* _stack,
    void* data,
    const size_t sizeOfData
);

unsigned char popStackElement(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
);

#endif // MAIN_DYNAMIC_LIBRARY_H_INCLUDED
