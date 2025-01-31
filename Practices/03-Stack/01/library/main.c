
#include <string.h>
#include <stdlib.h>

#include "./main.h"

/* -------- Static Stack -------- */

// Constructor
unsigned char newSStack(
    SStack* _stack,
    const size_t bytesPerElement
) {
    const size_t capacity = sizeof(_stack->__data);
    if (bytesPerElement > capacity) return 1;

    _stack->__length = 0;
    _stack->__capacity = capacity;
    _stack->__bytesPerElement = bytesPerElement;

    return 0;
}

// Destroyer
void destroySStack(SStack* _stack) {
    _stack->__length = 0;
    _stack->__capacity = 0;
    _stack->__bytesPerElement = 0;
}

// Getters
size_t getSStackLength(SStack* _stack) {
    return _stack->__length;
}

size_t getSStackCapacity(SStack* _stack) {
    return _stack->__capacity;
}

size_t getSStackBytesPerElement(SStack* _stack) {
    return _stack->__bytesPerElement;
}

unsigned char isSStackFull(SStack* _stack) {
    const size_t usedCapacity = _stack->__length * _stack->__bytesPerElement;
    return usedCapacity == _stack->__capacity;
}

unsigned char isSStackEmpty(SStack* _stack) {
    return _stack->__length ? 0 : 1;
}

// Methods
unsigned char pop(
    SStack* _stack,
    void* data
) {
    void* lastIn;

    if (!_stack->__length) return 1;

    lastIn = _stack->__data + (_stack->__length - 1) * _stack->__bytesPerElement;

    memcpy(
        data,
        lastIn,
        _stack->__bytesPerElement
    );

    _stack->__length--;

    return 0;
}

unsigned char push(
    SStack* _stack,
    void* data
) {
    const size_t usedCapacity = _stack->__length * _stack->__bytesPerElement;
    if (usedCapacity == _stack->__capacity) return 1;

    memcpy(
        _stack->__data + _stack->__length * _stack->__bytesPerElement,
        data,
        _stack->__bytesPerElement
    );

    _stack->__length++;

    return 0;
}
