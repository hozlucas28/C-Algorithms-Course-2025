
#include <stdio.h>

#include "./test.h"

unsigned char createTestFile(const char* filePath) {
    FILE* file;

    char* lines[] = {
        "5,1",
        "3,1",
        "8,3",
        "1,9",
        "4,7",
        "7,5",
        "10,8",
        "-1,9",
        "2,5",
        "9,7",
        "11,6"
    };

    int i;
    char* line;

    file = fopen(filePath, "wt");
    if (file == NULL) return 1;

    for (i = 0; i < sizeof(lines) / sizeof(*lines); i++) {
        line = *(lines + i);
        fprintf(file, "%s\n", line);
    };

    fclose(file);

    return 0;
}
