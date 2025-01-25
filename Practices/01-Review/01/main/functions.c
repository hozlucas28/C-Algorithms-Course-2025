
#include <stdio.h>

#include "./functions.h"

int cmpInts01(char* key, char* element) {
    int _key = *((int*)key);
    int _element = *((int*)element);
    return _element - _key;
}

int cmpInts02(void* key, void* element) {
    int _key = *((int*)key);
    int _element = *((int*)element);
    return _key - _element;
}

void printInt01(char* element, const size_t index) {
    int _element = *((int*)element);
    index ? printf(" %d", _element) : printf("%d", _element);
}

void printInt02(void* element, const size_t index) {
    int _element = *((int*)element);
    index ? printf(" %d", _element) : printf("%d", _element);
}
