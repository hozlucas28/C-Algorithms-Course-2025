
#include <stdio.h>
#include <stdlib.h>

#include "./macros.h"
#include "./stack.h"
#include "./utilities.h"

int main() {
    Stack stack;

    Stack innerStack;
    int counter;
    int integer;

    if (createTestFile(TEST_FILE_PATH)) {
        printf("> Error! An error occurred on create the test file.");
        return 1;
    };

    newStack(&stack);

    if (storeData(&stack, TEST_FILE_PATH)) {
        printf("> Error! An error occurred on store data.");
        destroyStack(&stack);
        return 1;
    };

    counter = 1;

    while (!isStackEmpty(&stack)) {
        if (shiftStackElement(&stack, &innerStack, sizeof(innerStack))) continue;

        printf("> Inner stack %02d:", counter);

        while (!isStackEmpty(&innerStack)) {
            if (shiftStackElement(&innerStack, &integer, sizeof(integer))) continue;
            printf(" %d", integer);
        };

        puts(".");

        destroyStack(&innerStack);

        counter++;
    };

    destroyStack(&stack);

    newStack(&stack);

    if (storeData(&stack, TEST_FILE_PATH)) {
        printf("> Error! An error occurred on store data.");
        destroyStack(&stack);
        return 1;
    };

    flatStack(&stack);

    printf("\n> Flattened stack:");

    while (!isStackEmpty(&stack)) {
        if (shiftStackElement(&stack, &integer, sizeof(integer))) continue;
        printf(" %d", integer);
    };

    putchar('.');

    destroyStack(&stack);

    return 0;
}
