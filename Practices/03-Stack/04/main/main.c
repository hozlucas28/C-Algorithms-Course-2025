
#include <stdio.h>
#include <stdlib.h>

#include "./stack.h"

int main() {
    Stack stack;

    char line[] = "Hello world!";
    const size_t lineLength = (sizeof(line) / sizeof(*line)) - 1;

    int i;
    char _char;

    newStack(&stack);

    printf("> Original line: \"%s\".\n", line);

    for (i = 0; i < lineLength; i++) {
        unshiftStackElement(&stack, line + i, sizeof(*(line + i)));
    };

    printf("> Reversed line: \"");
    while (!shiftStackElement(&stack, &_char, sizeof(_char))) {
        printf("%c", _char);
    };
    puts("\".");

    destroyStack(&stack);

    return 0;
}
