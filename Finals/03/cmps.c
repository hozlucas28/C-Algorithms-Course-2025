
#include "./cmps.h"
#include "./structs.h"

int cmpRunners(
    const void* a,
    const void* b
) {
    Runner* _a = (Runner*)a;
    Runner* _b = (Runner*)b;

    return _a->position - _b->position;
}
