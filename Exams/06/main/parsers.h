#ifndef PARSERS_H_INCLUDED
#define PARSERS_H_INCLUDED

#include "./structs.h"

unsigned char parseKeyValue(
    char* line,
    KeyValue* keyValue
);

#endif // PARSERS_H_INCLUDED
