
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "./stack.h"

/* ----------- Stack ------------ */

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
    Stack* _stack,
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

    free(newNode->__data);
    free(newNode);

    return 0;
}

unsigned char isStackEmpty(Stack* _stack) {
    return *_stack == NULL;
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
