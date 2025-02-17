
#include <stdlib.h>
#include <string.h>

#include "./main.h"

/* ------- Stack -------- */

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

// Getters
unsigned char getStackTopElement(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
) {
    if (*_stack == NULL) return 1;
    if ((*_stack)->__sizeOfData != sizeOfStore) return 1;

    memcpy(store, (*_stack)->__data, sizeOfStore);

    return 0;
}

unsigned char isStackEmpty(const Stack* _stack) {
    return *_stack == NULL;
}

unsigned char isStackFull(
    const Stack* _stack,
    const size_t sizeOfData
) {
    Node* node;
    void* nodeData;

    node = malloc(sizeof(Node));
    nodeData = malloc(sizeOfData);

    free(node);
    free(nodeData);

    return node == NULL || nodeData == NULL;
}

// Methods
unsigned char pushStackElement(
    Stack* _stack,
    void* data,
    const size_t sizeOfData
) {
    Node* newNode;
    void* newNodeData;

    while (*_stack != NULL) {
        _stack = &(*_stack)->__next;
    };

    newNode = malloc(sizeof(Node));
    newNodeData = malloc(sizeOfData);

    if (newNode == NULL || newNodeData == NULL) return 1;

    memcpy(newNodeData, data, sizeOfData);

    newNode->__data = newNodeData;
    newNode->__sizeOfData = sizeOfData;
    newNode->__next = NULL;

    *_stack = newNode;

    return 0;
}

unsigned char popStackElement(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
) {
    if (*_stack == NULL) return 1;

    while ((*_stack)->__next != NULL) {
        _stack = &(*_stack)->__next;
    };

    if ((*_stack)->__sizeOfData != sizeOfStore) return 1;

    memcpy(store, (*_stack)->__data, sizeOfStore);

    free((*_stack)->__data);
    free(*_stack);

    *_stack = NULL;

    return 0;
}
