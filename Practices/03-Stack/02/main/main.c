
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned char error;

    int collection[] = {1, 3, 5, 6, 7, 8, 11, 15};
    const size_t collectionLength = sizeof(collection) / sizeof(*collection);

    Stack* stack;
    size_t stackLength;
    int poppedElement;

    size_t i;

    stack = newStack();
    if (stack == NULL) {
        printf("Error! An error occurred on create dynamic Stack.");
        return 1;
    };

    printf("> After creating the dynamic Stack...\n\n");

    for (i = 0; i < collectionLength; i++) {
        error = push(stack, collection + i, sizeof(*collection));

        if (error) {
            printf(
                "> Error! An error occurred on push(0x%p, %d).\n",
                (void*)stack,
                *(collection + i)
            );

            continue;
        };

        printf(
            "> %d pushed => New Stack length = %d.\n",
            *(collection + i),
            (int)getStackLength(stack)
        );
    };

    printf("\n");
    stackLength = getStackLength(stack);

    for (i = 0; i < stackLength; i++) {
        error = pop(stack, &poppedElement);

        if (error) {
            printf(
                "> Error! An error occurred on pop(0x%p).\n",
                (void*)stack
            );

            continue;
        };

        printf(
            "> %d popped => New Stack length = %d.\n",
            poppedElement,
            (int)getStackLength(stack)
        );
    };

    printf("\n> After popped each element of the dynamic Stack...\n\n");

    error = pop(stack, &poppedElement);

    if (error) {
        printf(
            "> Error! An error occurred on pop(0x%p).",
            (void*)stack
        );
    } else {
        printf(
            "> %d popped => New Stack length = %d.",
            *(collection + i),
            (int)getStackLength(stack)
        );
    };

    destroyStack(stack);

    return 0;
}
