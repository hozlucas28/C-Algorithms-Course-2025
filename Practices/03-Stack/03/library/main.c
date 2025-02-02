
#include <stdlib.h>
#include <string.h>

#include "./main.h"

/* -------- Node -------- */

// Constructor
Node* newNode(
    void* data,
    const size_t sizeOfDataType
) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) return NULL;

    node->__data = malloc(sizeOfDataType);
    if (node->__data == NULL) {
        free(node);
        return NULL;
    };

    memcpy(node->__data, data, sizeOfDataType);
    node->__sizeOfDataType = sizeOfDataType;
    node->__next = NULL;

    return node;
}

// Destroyer
void destroyNode(Node* node) {
    free(node->__data);
    if (node->__next != NULL) destroyNode(node->__next);
    free(node);
}

// Getters
void* getNodeData(Node* node) {
    return node->__data;
}

size_t getNodeSizeOfDataType(Node* node) {
    return node->__sizeOfDataType;
}

Node* getNodeNext(Node* node) {
    return node->__next;
}

// Setters
unsigned char setNodeData(
    Node* node,
    void* data,
    const size_t sizeOfDataType
) {
    void* newData = malloc(sizeOfDataType);
    if (newData == NULL) return 1;

    free(node->__data);
    node->__data = newData;

    memcpy(node->__data, data, sizeOfDataType);
    node->__sizeOfDataType = sizeOfDataType;

    return 0;
}

Node* setNodeNext(
    Node* node,
    Node* next
) {
    Node* prevNext = node->__next;
    node->__next = next;
    return prevNext;
}


/* ------- Stack -------- */

// Constructor
Stack* newStack() {
    Stack* _stack = malloc(sizeof(Stack));
    if (_stack == NULL) return NULL;

    _stack->__data = NULL;
    _stack->__sizeOfDataType = 0;
    _stack->__next = NULL;

    return _stack;
}

// Destroyer
void destroyStack(Stack* _stack) {
    if (_stack->__data != NULL) free(_stack->__data);
    if (_stack->__next != NULL) destroyStack(_stack->__next);
    free(_stack);
}

// Getters
size_t getStackLength(Stack* _stack) {
    if (_stack == NULL) return 0;
    return (_stack->__data != NULL) + getStackLength(_stack->__next);
}

unsigned char getStackTop(
    Stack* _stack,
    void* data
) {
    if (_stack->__data == NULL) return 1;

    memcpy(data, _stack->__data, _stack->__sizeOfDataType);

    return 0;
}

// Methods
unsigned char pop(
    Stack* _stack,
    void* data
) {
    Node* lastIn;
    Node* prevLastIn;

    if (_stack->__data == NULL) return 1;

    lastIn = _stack->__next == NULL ? _stack : _stack->__next;
    prevLastIn = _stack;

    while (lastIn->__next != NULL) {
        prevLastIn = lastIn;
        lastIn = lastIn->__next;
    };

    memcpy(data, lastIn->__data, lastIn->__sizeOfDataType);

    free(lastIn->__data);

    lastIn->__data = NULL;
    lastIn->__sizeOfDataType = 0;

    if (lastIn != _stack) free(lastIn);

    prevLastIn->__next = NULL;

    return 0;
}

unsigned char push(
    Stack* _stack,
    void* data,
    size_t sizeOfDataType
) {
    Node* lastIn;
    Node* newLastIn;

    newLastIn = newNode(data, sizeOfDataType);
    if (newLastIn == NULL) return 1;

    if (_stack->__data == NULL) {
        _stack->__data = getNodeData(newLastIn);
        _stack->__sizeOfDataType = getNodeSizeOfDataType(newLastIn);
        _stack->__next = getNodeNext(newLastIn);

        free(newLastIn);

        return 0;
    };

    lastIn = _stack->__next == NULL ? _stack : _stack->__next;
    while (lastIn->__next != NULL) lastIn = lastIn->__next;

    lastIn->__next = newLastIn;

    return 0;
}
