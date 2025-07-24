
#include <string.h>

#include "./cmps.h"

int cmpWords(
    const void* a,
    const void* b
) {
    char* _a = (char*)a;
    char* _b = (char*)b;

    return strcmp(_a, _b);
}
