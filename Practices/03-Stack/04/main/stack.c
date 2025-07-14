
#include <stdlib.h>
#include <string.h>

#include "./stack.h"

// Constructor
void newStack(Stack* _stack) {
    *_stack = NULL;
}

// Destructor
void destroyStack(Stack* _stack) {
    Node* nextNode;

    while (*_stack != NULL) {
        nextNode = (*_stack)->__next;

        free((*_stack)->__data);
        free(*_stack);

        *_stack = nextNode;
    };
}

// Methods
unsigned char unshiftStackElement(
    Stack* _stack,
    void* data,
    const size_t sizeOfData
) {
    Node* newNode;

    newNode = malloc(sizeof(Node));
    if (newNode == NULL) return 1;

    newNode->__data = malloc(sizeOfData);
    if (newNode->__data == NULL) {
        free(newNode);
        return 1;
    };

    memcpy(newNode->__data, data, sizeOfData);
    newNode->__sizeOfData = sizeOfData;
    newNode->__next = *_stack;

    *_stack = newNode;

    return 0;
}

unsigned char shiftStackElement(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
) {
    Node* nextNode;

    if (*_stack == NULL) return 1;
    if ((*_stack)->__sizeOfData != sizeOfStore) return 1;

    nextNode = (*_stack)->__next;

    memcpy(store, (*_stack)->__data, (*_stack)->__sizeOfData);

    free((*_stack)->__data);
    free(*_stack);

    *_stack = nextNode;

    return 0;
}
