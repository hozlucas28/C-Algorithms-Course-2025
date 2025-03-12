
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
unsigned char getStackTop(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
) {
    if (*_stack == NULL) return 1;

    if ((*_stack)->__sizeOfData != sizeOfStore) return 1;

    memcpy(store, (*_stack)->__data, (*_stack)->__sizeOfData);

    return 0;
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

unsigned char isStackEmpty(const Stack* _stack) {
    return *_stack == NULL;
}

// Methods
unsigned char unshiftStack(
    Stack* _stack,
    void* data,
    const size_t sizeOfData
) {
    Node* newNode;
    void* newNodeData;

    newNode = malloc(sizeof(Node));
    newNodeData = malloc(sizeOfData);

    if (newNode == NULL || newNodeData == NULL) return 1;

    memcpy(newNodeData, data, sizeOfData);

    newNode->__data = newNodeData;
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

    memcpy(store, (*_stack)->__data, (*_stack)->__sizeOfData);

    nextNode = (*_stack)->__next;

    free((*_stack)->__data);
    free(*_stack);

    *_stack = nextNode;

    return 0;
}

void flatStack(Stack* _stack) {
    Stack innerStack;

    Node* head = NULL;
    Node* lastTail = NULL;

    Node* nextNode;

    if (*_stack == NULL) return;

    while (*_stack != NULL) {
        innerStack = *(Stack*)(*_stack)->__data;

        if (head == NULL) head = innerStack;
        if (lastTail != NULL) lastTail->__next = innerStack;

        while (innerStack->__next != NULL) {
            innerStack = innerStack->__next;
        };

        lastTail = innerStack;

        nextNode = (*_stack)->__next;
        free(*_stack);

        *_stack = nextNode;
    };

    *_stack = head;
}


unsigned char toFlatStack(
    Stack* _stack,
    Stack* flattedStack
) {
    Stack innerStack;

    Node* newNode;

    Node* nextNode;

    Node* head = NULL;

    if (*_stack == NULL) return *flattedStack != NULL;
    if (*flattedStack != NULL) return 1;

    while (*_stack != NULL) {
        innerStack = *(Stack*)(*_stack)->__data;

        while (innerStack != NULL) {
            newNode = malloc(sizeof(Node));
            if (newNode == NULL) {
                while (*flattedStack != NULL) {
                    nextNode = (*flattedStack)->__next;
                    free((*flattedStack)->__data);
                    free(*flattedStack);
                    *flattedStack = nextNode;
                };

                return 1;
            };

            newNode->__data = malloc(innerStack->__sizeOfData);
            if (newNode->__data == NULL) {
                free(newNode);

                while (*flattedStack != NULL) {
                    nextNode = (*flattedStack)->__next;
                    free((*flattedStack)->__data);
                    free(*flattedStack);
                    *flattedStack = nextNode;
                };

                return 1;
            };

            memcpy(newNode->__data, innerStack->__data, innerStack->__sizeOfData);
            newNode->__sizeOfData = innerStack->__sizeOfData;
            newNode->__next = NULL;

            if (*flattedStack == NULL) {
                head = newNode;
            } else {
                (*flattedStack)->__next = newNode;
            };

            *flattedStack = newNode;
            innerStack = innerStack->__next;
        };

        _stack = &(*_stack)->__next;
    };

    *flattedStack = head;

    return 0;
}
