
#include <stdlib.h>
#include <string.h>

#include "./main.h"

// Constructor
void newStack(Stack* _stack) {
    _stack->__remainingCapacity = STACK_BYTES;
}

// Destructor
void destroyStack(Stack* _stack) {
    _stack->__remainingCapacity = STACK_BYTES;
}

// Getters
unsigned char getStackTopElement(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
) {
    size_t sizeOfTopElement;

    if (_stack->__remainingCapacity == STACK_BYTES) return 1;

    memcpy(
        &sizeOfTopElement,
        _stack->__data + _stack->__remainingCapacity,
        sizeof(size_t)
    );

    if (sizeOfTopElement != sizeOfStore) return 1;

    memcpy(
        store,
        _stack->__data + _stack->__remainingCapacity + sizeof(size_t),
        sizeOfStore
    );

    return 0;
}

unsigned char isStackEmpty(Stack* _stack) {
    return _stack->__remainingCapacity == STACK_BYTES;
}

unsigned char isStackFull(
    Stack* _stack,
    const size_t sizeOfData
) {
    return _stack->__remainingCapacity < 1;
}

// Methods
unsigned char pushStackElement(
    Stack* _stack,
    void* data,
    const size_t sizeOfData
) {
    const size_t spaceRequired = sizeof(size_t) + sizeOfData;

    if (spaceRequired > _stack->__remainingCapacity) return 1;

    _stack->__remainingCapacity -= sizeOfData;

    memcpy(
        _stack->__data + _stack->__remainingCapacity,
        data,
        sizeOfData
    );

    _stack->__remainingCapacity -= sizeof(size_t);

    memcpy(
        _stack->__data + _stack->__remainingCapacity,
        &sizeOfData,
        sizeof(size_t)
    );

    return 0;
}

unsigned char popStackElement(
    Stack* _stack,
    void* store,
    const size_t sizeOfStore
) {
    size_t sizeOfData;

    if (_stack->__remainingCapacity == STACK_BYTES) return 1;

    memcpy(
        &sizeOfData,
        _stack->__data + _stack->__remainingCapacity,
        sizeof(size_t)
    );

    if (sizeOfData != sizeOfStore) return 1;

    _stack->__remainingCapacity += sizeof(size_t);

    memcpy(
        store,
        _stack->__data + _stack->__remainingCapacity,
        sizeOfStore
    );

    _stack->__remainingCapacity += sizeOfData;

    return 0;
}
