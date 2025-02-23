
#include <stdio.h>

#include "./macros.h"
#include "./stack.h"
#include "./utilities.h"

unsigned char createTestFile(const char* filePath) {
    FILE* file;

    size_t i;
    size_t j;

    const size_t innersStacks = 3;
    const size_t integersPerStack = 5;

    file = fopen(filePath, "wt");
    if (file == NULL) return 1;

    for (i = 0; i < innersStacks; i++) {
        for (j = 0; j < integersPerStack; j++) fprintf(file, "%d\n", (int)(i + j + 1));
        fprintf(file, "\n");
    };

    fclose(file);

    return 0;
}


unsigned char storeData(
    Stack* _stack,
    const char* filePath
) {
    FILE* file;

    Stack innerStack;

    char line[LINE_LENGTH];

    int fields;
    int integer;

    file = fopen(filePath, "rt");
    if (file == NULL) return 1;

    newStack(&innerStack);

    while (fgets(line, LINE_LENGTH, file)) {
        fields = sscanf(line, "%d\n", &integer);

        if (fields == 1) {
            unshiftStackElement(&innerStack, &integer, sizeof(integer));
            continue;
        };

        unshiftStackElement(_stack, &innerStack, sizeof(innerStack));
        newStack(&innerStack);
    };

    fclose(file);

    return 0;
}
