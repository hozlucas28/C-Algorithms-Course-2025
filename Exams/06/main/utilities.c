
#include <stdio.h>

#include "./structs.h"
#include "./utilities.h"

void countValueOcurrences(
    void* keyValue,
    void* params
) {
    KeyValue* _keyValue = (KeyValue*)keyValue;
    int* _valueToCount = *((int**)params);
    int* _counter = *((int**)params + 1);

    if (_keyValue->value == *_valueToCount) (*_counter)++;
}

void printInt(
    void* keyValue,
    void* params
) {
    KeyValue* _data = (KeyValue*)keyValue;
    printf("> %d\n", _data->key);
}
