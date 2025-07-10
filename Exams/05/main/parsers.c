
#include <stdio.h>
#include <stdlib.h>

#include "./parsers.h"

unsigned char parseProductControl(char* line, ProductControl* product) {
    int scannedFields;
    char id[sizeof(int)];

    scannedFields = sscanf(
        line,
        "%[^,],%[^,],%s",
        product->batchCode,
        id,
        product->result
    );

    product->id = atoi(id);

    return scannedFields != 3;
}
