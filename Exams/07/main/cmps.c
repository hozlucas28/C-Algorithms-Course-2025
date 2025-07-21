
#include "./cmps.h"
#include "./structs.h"


int cmpTags(
    const void* a,
    const void* b
) {
    Tag* _a = (Tag*)a;
    Tag* _b = (Tag*)b;

    return _a->open - _b->open;
}
