
#include <stdio.h>

#include "./parsers.h"
#include "./structs.h"

unsigned char parseRunner(
    char* line,
    Runner* runner
) {
    int scannedFields = sscanf(line, "%[^|]|%u", runner->name, &(runner->position));
    return scannedFields != 2;
}
