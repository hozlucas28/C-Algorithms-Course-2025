
#ifndef MAIN_LIBRARY_H_INCLUDED
#define MAIN_LIBRARY_H_INCLUDED

#include <stdlib.h>

/* -------- Static Stack -------- */

#define MAXIMUM_SSTACK_BYTES 1024

typedef struct {
    char __data[MAXIMUM_SSTACK_BYTES];
    size_t __length;
    size_t __capacity;
    size_t __bytesPerElement;
} SStack;

// Constructor
unsigned char newSStack(
    SStack* _stack,
    const size_t bytesPerElement
);

// Destroyer
void destroySStack(SStack* _stack);

// Getters
size_t getSStackLength(SStack* _stack);
size_t getSStackCapacity(SStack* _stack);
size_t getSStackBytesPerElement(SStack* _stack);

unsigned char isSStackFull(SStack* _stack);
unsigned char isSStackEmpty(SStack* _stack);

// Methods
unsigned char pop(
    SStack* _stack,
    void* data
);

unsigned char push(
    SStack* _stack,
    void* data
);

#endif // MAIN_LIBRARY_H_INCLUDED
