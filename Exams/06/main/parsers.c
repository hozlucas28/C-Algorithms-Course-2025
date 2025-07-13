
#include <stdio.h>
#include <stdlib.h>

#include "./parsers.h"

unsigned char parseKeyValue(
    char* line,
    KeyValue* keyValue
) {
    char key[sizeof(int)];
    char value[sizeof(int)];

    int scannedFields = sscanf(line, "%[^,],%[^,]", key, value);
    if (scannedFields != 2) return 1;

    keyValue->key = atoi(key);
    keyValue->value = atoi(value);

    return 0;
}
