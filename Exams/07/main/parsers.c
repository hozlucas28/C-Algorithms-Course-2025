
#include <stdio.h>

#include "./parsers.h"
#include "./structs.h"

unsigned char parseTag(
    const char* line,
    Tag* tag
) {
    int scannedFields = sscanf(line, "%c%c", &(tag->open), &(tag->close));
    return scannedFields == 2 ? 0 : 1;
}
