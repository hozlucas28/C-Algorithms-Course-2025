
#include "../dynamic-library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    Stack stack;

    int numbers[] = {1, 3, 5, 6, 8, 9, 10};
    const size_t numbersLength = sizeof(numbers) / sizeof(*numbers);

    size_t i;

    newStack(&stack);
    unsigned char stackError;

    int topElement;
    int poppedElement;

    for (i = 0; i < numbersLength; i++) {
        stackError = unshiftStack(&stack, numbers + i, sizeof(*numbers));
        if (stackError) {
            printf(
                "> Error! An error occurred on unshiftStack(%d, %d).\n",
                *(numbers + i),
                (int)sizeof(*numbers)
            );
        } else {
            printf(
                "> unshiftStack(%d, %d).\n",
                *(numbers + i),
                (int)sizeof(*numbers)
            );
        };
    };

    stackError = getStackTop(&stack, &topElement, sizeof(topElement));
    if (stackError) {
        printf(
            "\n> Error! An error occurred on getStackTop(0x%p, %d).\n\n",
            (void*)&topElement,
            (int)sizeof(topElement)
        );
    } else {
        printf(
            "\n> getStackTop(0x%p, %d) = %d.\n\n",
            (void*)&topElement,
            (int)sizeof(topElement),
            topElement
        );
    };


    for (i = 0; i < numbersLength; i++) {
        stackError = shiftStackElement(&stack, &poppedElement, sizeof(poppedElement));
        if (stackError) {
            printf(
                "> Error! An error occurred on shiftStackElement(0x%p, %d).\n",
                (void*)&poppedElement,
                (int)sizeof(poppedElement)
            );
        } else {
            printf(
                "> shiftStackElement(0x%p, %d) = %d.\n",
                (void*)&poppedElement,
                (int)sizeof(poppedElement),
                poppedElement
            );
        };
    };

    destroyStack(&stack);

    return 0;
}
