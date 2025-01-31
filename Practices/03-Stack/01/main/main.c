
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned char error;

    int numbers[] = {1, 3, 5, 6, 8, 10};
    const size_t numbersLength = sizeof(numbers) / sizeof(int);

    SStack stack;
    int poppedElement;
    size_t stackLength;
    const size_t bytesPerElement = sizeof(int);

    size_t i;

    error = newSStack(&stack, bytesPerElement);
    if (error) {
        printf("> Error! An error occurred on create a static Stack.");
        return 1;
    };

    printf("> After creating the static stack...\n\n");

    for (i = 0; i < numbersLength; i++) {
        error = push(&stack, numbers + i);
        if (!error) continue;

        printf(
            "> Error! An error occurred on push(0x%p, %d).\n",
            (void*)&stack,
            *(numbers + i)
        );
    };

    stackLength = getSStackLength(&stack);

    for (i = 0; i < stackLength; i++) {
        error = pop(&stack, &poppedElement);
        if (!error) {
            printf("> %d popped.\n", poppedElement);
            continue;
        };

        printf(
            "> Error! An error occurred on pop(0x%p).\n",
            (void*)&stack
        );
    };

    error = pop(&stack, &poppedElement);
    if (error) {
        printf(
            "\n> Error! An error occurred on pop(0x%p).\n",
            (void*)&stack
        );
    } else {
        printf("\n> %d popped.\n", poppedElement);
    };

    destroySStack(&stack);

    printf("\n> After destroying the static stack...\n\n");

    for (i = 0; i < numbersLength; i++) {
        error = push(&stack, numbers + i);
        if (!error) continue;

        printf(
            "> Error! An error occurred on push(0x%p, %d).\n",
            (void*)&stack,
            *(numbers + i)
        );
    };

    stackLength = getSStackLength(&stack);

    for (i = 0; i < stackLength; i++) {
        error = pop(&stack, &poppedElement);
        if (!error) {
            printf("> %d popped.\n", poppedElement);
            continue;
        };

        printf(
            "> Error! An error occurred on pop(0x%p).\n",
            (void*)&stack
        );
    };

    error = pop(&stack, &poppedElement);
    if (error) {
        printf(
            "\n> Error! An error occurred on pop(0x%p).",
            (void*)&stack
        );
    } else {
        printf("\n> %d popped.", poppedElement);
    };

    return 0;
}
