
#include "./cmps.h"
#include "./structs.h"

int cmpKeyValue(const void* a, const void* b) {
    KeyValue* _a = (KeyValue*)a;
    KeyValue* _b = (KeyValue*)b;

    return _a->key - _b->key;
}
