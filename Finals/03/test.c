
#include <stdio.h>

#include "./test.h"
#include "./structs.h"

unsigned char createTestFile(const char* filePath) {
    FILE* file;

    size_t i;

    const char lines[][LINE_LENGTH] = {
        "Maxis Gomez|2",
        "Juan Clinton|10",
        "Matilda Ramos|3",
        "Mia Ortiz|1",
        "Luna Marquez|10",
        "Steven Macdonald|1",
        "Tomas Phillips|2",
        "Julian Romero|3",
        "Alfred Johnson|4",
        "Juana De Luca|2"
    };

    const size_t linesLength = sizeof(lines) / sizeof(*lines);

    file = fopen(filePath, "wt");
    if (file == NULL) return 1;

    for (i = 0; i < linesLength; i++) {
        fprintf(file, "%s\n", *(lines + i));
    };

    fclose(file);

    return 0;
}
