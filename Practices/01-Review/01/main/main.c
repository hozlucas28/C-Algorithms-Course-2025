#include <stdio.h>
#include <stdlib.h>

#include "../library/main.h"

#include "./functions.h"

int main() {
    Array arr;
    Slice* slice;

    int numbers[] = {1, 3, 5, 7, 9, 11, 13, 15};
    const size_t numbersLength = sizeof(numbers) / sizeof(int);

    int newElement = 8;

    size_t i;

    newArray(&arr, sizeof(int));

    slice = newSlice(256, sizeof(int));
    if (slice == NULL) {
        destroyArray(&arr);
        printf("Error! An error occurred on create a new slice.");
        return 1;
    };

    printf("> On start...\n\n");
    printArray(&arr, &printInt01);
    printf("\n\n");
    printSlice(slice, &printInt02);

    for (i = 0; i < numbersLength; i++) {
        insertArrayElementInOrder(
            &arr,
            (char*)(numbers + i),
            &cmpInts01
        );
    };

    for (i = 0; i < numbersLength; i++) {
        insertSliceElementInOrder(
            slice,
            numbers + i,
            &cmpInts02
        );
    };

    printf("\n\n> After insert in order...\n\n");
    printArray(&arr, &printInt01);
    printf("\n\n");
    printSlice(slice, &printInt02);

    insertArrayElementInOrder(
        &arr,
        (char*)(&newElement),
        &cmpInts01
    );

    insertSliceElementInOrder(
        slice,
        &newElement,
        &cmpInts02
    );

    printf("\n\n> After insert one element in order:\n\n");
    printArray(&arr, &printInt01);
    printf("\n\n");
    printSlice(slice, &printInt02);

    deleteArrayElementAt(&arr, 2);
    deleteSliceElementAt(slice, 2);

    printf("\n\n> After delete one element...\n\n");
    printArray(&arr, &printInt01);
    printf("\n\n");
    printSlice(slice, &printInt02);

    destroyArray(&arr);
    destroySlice(slice);

    return 0;
}
