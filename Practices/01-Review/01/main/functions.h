#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdlib.h>

int cmpInts01(char* key, char* element);
int cmpInts02(void* key, void* element);

void printInt01(char* element, const size_t index);
void printInt02(void* element, const size_t index);

#endif // FUNCTIONS_H_INCLUDED
