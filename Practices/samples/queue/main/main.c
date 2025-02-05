
#include "../dynamic-library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    Queue queue;

    int numbers[] = {1, 3, 5, 7, 8, 9, 10};
    const size_t numbersLength = sizeof(numbers) / sizeof(*numbers);

    newQueue(&queue);
    int poppedElement;

    size_t i;
    unsigned char error;

    printf("> Push elements...\n\n");

    for (i = 0; i < numbersLength; i++) {
        error = push(&queue, numbers + i, sizeof(*(numbers + i)));
        if (error) {
            printf(
                "> Error! An error occurred on push(0x%p, 0x%p, %d).\n",
                (void*)&queue,
                (void*)(numbers + i),
                (int)sizeof(*(numbers + i))
            );

            continue;
        };

        printf(
            "> push(0x%p, 0x%p, %d).\n",
            (void*)&queue,
            (void*)(numbers + i),
            (int)sizeof(*(numbers + i))
        );
    };

    printf("\n> Shift elements...\n\n");

    while (!isEmpty(&queue)) {
        error = shift(&queue, &poppedElement, sizeof(poppedElement));
        if (error) {
            printf(
                "> Error! An error occurred on shift(0x%p, 0x%p, %d).\n",
                (void*)&queue,
                (void*)&poppedElement,
                (int)sizeof(poppedElement)
            );

            continue;
        };

        printf(
            "> shift(0x%p, 0x%p, %d) => %d.\n",
            (void*)&queue,
            (void*)&poppedElement,
            (int)sizeof(poppedElement),
            poppedElement
        );
    };

    destroyQueue(&queue);

    return 0;
}
