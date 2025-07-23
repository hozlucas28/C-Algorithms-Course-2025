
#include <stdio.h>
#include <stdlib.h>

#include "./cmps.h"
#include "./structs.h"
#include "./parsers.h"
#include "./utilities.h"
#include "./singly-linked-list.h"

unsigned char processRunners(
    const char* filePath,
    SList* runners,
    const size_t top
) {
    FILE* file;

    char line[LINE_LENGTH];
    const size_t lineLength = sizeof(line) / sizeof(*line);

    Runner runner;

    file = fopen(filePath, "rt");
    if (file == NULL) return 1;

    while (fgets(line, lineLength, file)) {
        if (parseRunner(line, &runner)) continue;
        insertSListTop(runners, &runner, sizeof(Runner), top, &cmpRunners);
    };

    fclose(file);

    return 0;
}

void printRunner(
    void* runner,
    const size_t sizeOfRunner,
    const size_t index,
    void* params
) {
    Runner* _runner = (Runner*)runner;

    printf("> #%u %s.\n", _runner->position, _runner->name);
}
