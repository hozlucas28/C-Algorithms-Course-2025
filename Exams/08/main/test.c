
#include <stdio.h>

#include "./test.h"
#include "./macros.h"

unsigned char createTestFile(
    const char* filePath,
    const char lines[][LINE_LENGTH],
    const size_t linesLength
) {
    FILE* file;

    size_t i;

    file = fopen(filePath, "wt");
    if (file == NULL) return 1;

    for (i = 0; i < linesLength; i++) {
        fprintf(file, "%s\n", *(lines + i));
    };

    fclose(file);

    return 0;
}
