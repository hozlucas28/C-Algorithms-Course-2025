
#ifndef MAIN_LIBRARY_H_INCLUDED
#define MAIN_LIBRARY_H_INCLUDED

#include <stdlib.h>

/* -------- Node -------- */

typedef struct Node {
    void* __data;
    size_t __sizeOfDataType;
    struct Node* __next;
} Node;

// Constructor
Node* newNode(
    void* data,
    const size_t sizeOfDataType
);

// Destroyer
void destroyNode(Node* node);

// Getters
void* getNodeData(Node* node);
size_t getNodeSizeOfDataType(Node* node);
Node* getNodeNext(Node* node);

// Setters
unsigned char setNodeData(
    Node* node,
    void* data,
    const size_t sizeOfDataType
);

Node* setNodeNext(
    Node* node,
    Node* next
);


/* ------- Stack -------- */

typedef Node Stack;

// Constructor
Stack* newStack();

// Destroyer
void destroyStack(Stack* _stack);

// Getters
size_t getStackLength(Stack* _stack);

unsigned char getStackTop(
    Stack* _stack,
    void* data
);

// Methods
unsigned char pop(
    Stack* _stack,
    void* data
);

unsigned char push(
    Stack* _stack,
    void* data,
    size_t sizeOfDataType
);

#endif // MAIN_LIBRARY_H_INCLUDED
