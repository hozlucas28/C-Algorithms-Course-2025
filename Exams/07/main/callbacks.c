
#include <stdio.h>

#include "./callbacks.h"

void onValidLine(
    const char* line,
    const size_t lineIndex,
    void* params
) {
    size_t i = 0;

    printf("> [%d] \"", (int)lineIndex);

    while (*(line + i) != '\n' && *(line + i) != '\0') {
        printf("%c", *(line + i));
        i++;
    };

    puts("\" is a valid line.");
}

void onInvalidLine(
    const char* line,
    const size_t lineIndex,
    void* params
) {
    size_t i = 0;

    printf("> [%d] \"", (int)lineIndex);

    while (*(line + i) != '\n' && *(line + i) != '\0') {
        printf("%c", *(line + i));
        i++;
    };

    puts("\" is an invalid line.");
}
