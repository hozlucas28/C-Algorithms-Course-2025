
#include <stdio.h>
#include <stdlib.h>

#include "./actions.h"

void printAndSave(
    void* data,
    const size_t sizeOfData,
    void* params
) {
    char* word = (char*)data;
    FILE** file = (FILE**)params;

    printf("> \"%s\"\n", word);
    fprintf(*file, "%s\n", word);
}
