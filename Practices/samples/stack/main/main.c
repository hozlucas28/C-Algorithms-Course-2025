
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
        stackError = pushStackElement(&stack, numbers + i, sizeof(*numbers));
        if (stackError) {
            printf(
                "> Error! An error occurred on pushStackElement(%d, %d).\n",
                *(numbers + i),
                (int)sizeof(*numbers)
            );
        } else {
            printf(
                "> pushStackElement(%d, %d).\n",
                *(numbers + i),
                (int)sizeof(*numbers)
            );
        };
    };

    stackError = getStackTopElement(&stack, &topElement, sizeof(topElement));
    if (stackError) {
        printf(
            "\n> Error! An error occurred on getStackTopElement(0x%p, %d).\n\n",
            (void*)&topElement,
            (int)sizeof(topElement)
        );
    } else {
        printf(
            "\n> getStackTopElement(0x%p, %d) = %d.\n\n",
            (void*)&topElement,
            (int)sizeof(topElement),
            topElement
        );
    };


    for (i = 0; i < numbersLength; i++) {
        stackError = popStackElement(&stack, &poppedElement, sizeof(poppedElement));
        if (stackError) {
            printf(
                "> Error! An error occurred on popStackElement(0x%p, %d).\n",
                (void*)&poppedElement,
                (int)sizeof(poppedElement)
            );
        } else {
            printf(
                "> popStackElement(0x%p, %d) = %d.\n",
                (void*)&poppedElement,
                (int)sizeof(poppedElement),
                poppedElement
            );
        };
    };

    destroyStack(&stack);

    return 0;
}
