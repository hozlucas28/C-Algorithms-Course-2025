
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./main.h"

/* -------- Array (static array) --------- */

// Constructor
void newArray(
    Array* arr,
    const size_t bytesPerElement
) {
    arr->__length = 0;
    arr->__capacity = sizeof(arr->__array) / bytesPerElement;
    arr->__bytesPerElement = bytesPerElement;
}

// Destroyer
void destroyArray(Array* arr) {
    arr->__length = 0;
}

// Getters
size_t getArrayLength(Array* arr) {
    return arr->__length;
}

char* getArrayElementAt(
    Array* arr,
    const int index
) {
    size_t _index;

    if (!arr->__length) return NULL;

    _index = ((index % arr->__length) + arr->__length) % arr->__length;
    return arr->__array + _index * arr->__bytesPerElement;
}

unsigned char isArrayEmpty(Array* arr) {
    return !arr->__length ? 1 : 0;
}

unsigned char isArrayFull(Array* arr) {
    return arr->__length == arr->__capacity ? 1 : 0;
}

// Methods
unsigned char deleteArrayElementAt(
    Array* arr,
    const int index
) {
    size_t i;
    size_t _index;

    if (!arr->__length) return 1;

    _index = ((index % arr->__length) + arr->__length) % arr->__length;

    for (i = _index + 1; i < arr->__length; i++) {
        memcpy(
            arr->__array + (i - 1) * arr->__bytesPerElement,
            arr->__array + i * arr->__bytesPerElement,
            arr->__bytesPerElement
        );
    };

    arr->__length--;

    return 0;
}

unsigned char insertArrayElementInOrder(
    Array* arr,
    char* element,
    int (*cmpElements)(char* key, char* element)
) {
    size_t i;
    int cmpValue;

    size_t j;
    size_t jStart;

    if (!arr->__length) {
        memcpy(
            arr->__array,
            element,
            arr->__bytesPerElement
        );

        arr->__length++;
        return 0;
    };

    for (i = 0; i < arr->__length; i++) {
        cmpValue = cmpElements(
            element,
            arr->__array + i * arr->__bytesPerElement
        );
        if (cmpValue > 0) continue;

        jStart = arr->__length - (arr->__length == arr->__capacity);

        for (j = jStart; j > i; j--) {
            memcpy(
                arr->__array + j * arr->__bytesPerElement,
                arr->__array + (j - 1) * arr->__bytesPerElement,
                arr->__bytesPerElement
            );
        };

        memcpy(
            arr->__array + i * arr->__bytesPerElement,
            element,
            arr->__bytesPerElement
        );
        break;
    };

    if (i >= arr->__length && arr->__length + 1 <= arr->__capacity) {
        memcpy(
            arr->__array + arr->__length * arr->__bytesPerElement,
            element,
            arr->__bytesPerElement
        );
    };

    arr->__length++;

    return 0;
}

void printArray(
    Array* arr,
    void (*printMethod)(char* element, const size_t index)
) {
    size_t i;

    printf("Array %p {\n", (void*)arr);

    printf("  __array = [");
    for (i = 0; i < arr->__length; i++) {
        printMethod(
            (char*)arr->__array + i * arr->__bytesPerElement,
            i
        );
    };
    printf("],\n");

    printf("  __length = %d,\n", (int)arr->__length);
    printf("  __capacity = %d,\n", (int)arr->__capacity);
    printf("  __bytesPerElement = %d,\n", (int)arr->__bytesPerElement);
    printf("};");
}


/* -------- Slice (dynamic array) -------- */

// Constructor
Slice* newSlice(
    const size_t capacity,
    const size_t sizeOfDataType
) {
    Slice* slice = malloc(sizeof(Slice));
    if (slice == NULL) return NULL;

    slice->__array = malloc(sizeOfDataType * capacity);
    if (slice->__array == NULL) {
        free(slice);
        return NULL;
    };

    slice->__length = 0;
    slice->__capacity = capacity;
    slice->__sizeOfDataType = sizeOfDataType;

    return slice;
}

// Destroyer
void destroySlice(Slice* slice) {
    free(slice->__array);
    free(slice);
}

// Getters
size_t getSliceLength(Slice* slice) {
    return slice->__length;
}

void* getSliceElementAt(
    Slice* slice,
    const int index
) {
    size_t _index;

    if (!slice->__length) return NULL;

    _index = ((index % slice->__length) + slice->__length) % slice->__length;
    return (char*)slice->__array + _index * slice->__sizeOfDataType;
}

unsigned char isSliceEmpty(Slice* slice) {
    return !slice->__length ? 1 : 0;
}

unsigned char isSliceFull(Slice* slice) {
    return slice->__length == slice->__capacity ? 1 : 0;
}

// Methods
unsigned char deleteSliceElementAt(
    Slice* slice,
    const int index
) {
    size_t i;
    size_t _index;

    if (!slice->__length) return 1;

    _index = ((index % slice->__length) + slice->__length) % slice->__length;

    for (i = _index + 1; i < slice->__length; i++) {
        memcpy(
            (char*)slice->__array + (i - 1) * slice->__sizeOfDataType,
            (char*)slice->__array + i * slice->__sizeOfDataType,
            slice->__sizeOfDataType
        );
    };

    slice->__length--;

    return 0;
}

unsigned char insertSliceElementInOrder(
    Slice* slice,
    void* element,
    int (*cmpElements)(void* key, void* element)
) {
    size_t i;
    int cmpValue;

    size_t j;
    size_t jStart;

    if (!slice->__length) {
        memcpy(
            slice->__array,
            element,
            slice->__sizeOfDataType
        );

        slice->__length++;
        return 0;
    };

    for (i = 0; i < slice->__length; i++) {
        cmpValue = cmpElements(
            element,
            (char*)slice->__array + i * slice->__sizeOfDataType
        );
        if (cmpValue > 0) continue;

        jStart = slice->__length - (slice->__length == slice->__capacity);

        for (j = jStart; j > i; j--) {
            memcpy(
                (char*)slice->__array + j * slice->__sizeOfDataType,
                (char*)slice->__array + (j - 1) * slice->__sizeOfDataType,
                slice->__sizeOfDataType
            );
        };

        memcpy(
            (char*)slice->__array + i * slice->__sizeOfDataType,
            element,
            slice->__sizeOfDataType
        );
        break;
    };

    if (i >= slice->__length && slice->__length + 1 <= slice->__capacity) {
        memcpy(
            (char*)slice->__array + slice->__length * slice->__sizeOfDataType,
            element,
            slice->__sizeOfDataType
        );
    };

    slice->__length++;

    return 0;
}

void printSlice(
    Slice* slice,
    void (*printMethod)(void* element, const size_t index)
) {
    size_t i;

    printf("Slice 0x%p {\n", (void*)slice);

    printf("  __array = [");
    for (i = 0; i < slice->__length; i++) {
        printMethod(
            (char*)slice->__array + i * slice->__sizeOfDataType,
            i
        );
    };
    printf("],\n");

    printf("  __length = %d,\n", (int)slice->__length);
    printf("  __capacity = %d,\n", (int)slice->__capacity);
    printf("  __sizeOfDataType = %d,\n", (int)slice->__sizeOfDataType);
    printf("};");
}
