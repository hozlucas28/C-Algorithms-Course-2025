
#ifndef MAIN_LIBRARY_H_INCLUDED
#define MAIN_LIBRARY_H_INCLUDED

#include <stdlib.h>

/* -------- Array (static array) --------- */

#define MAXIMUM_ARRAY_BYTES 1024

typedef struct {
    char __array[MAXIMUM_ARRAY_BYTES];
    size_t __length;
    size_t __capacity;
    size_t __bytesPerElement;
} Array;

// Constructor
void newArray(
    Array* arr,
    const size_t bytesPerElement
);

// Destroyer
void destroyArray(Array* arr);

// Getters
size_t getArrayLength(Array* arr);

char* getArrayElementAt(
    Array* arr,
    const int index
);

unsigned char isArrayEmpty(Array* arr);
unsigned char isArrayFull(Array* arr);

// Methods
unsigned char deleteArrayElementAt(
    Array* arr,
    const int index
);

unsigned char insertArrayElementInOrder(
    Array* arr,
    char* element,
    int (*cmpElements)(char* key, char* element)
);

void printArray(
    Array* arr,
    void (*printMethod)(char* element, const size_t index)
);


/* -------- Slice (dynamic array) -------- */

typedef struct {
    void* __array;
    size_t __length;
    size_t __capacity;
    size_t __sizeOfDataType;
} Slice;

// Constructor
Slice* newSlice(
    const size_t capacity,
    const size_t sizeOfDataType
);

// Destroyer
void destroySlice(Slice* slice);

// Getters
size_t getSliceLength(Slice* slice);

void* getSliceElementAt(
    Slice* slice,
    const int index
);

unsigned char isSliceEmpty(Slice* slice);
unsigned char isSliceFull(Slice* slice);

// Methods
unsigned char deleteSliceElementAt(
    Slice* slice,
    const int index
);

unsigned char insertSliceElementInOrder(
    Slice* slice,
    void* element,
    int (*cmpElements)(void* key, void* element)
);

void printSlice(
    Slice* slice,
    void (*printMethod)(void* element, const size_t index)
);

#endif  // MAIN_LIBRARY_H_INCLUDED
