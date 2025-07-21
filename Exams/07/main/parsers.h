#ifndef PARSERS_H_INCLUDED
#define PARSERS_H_INCLUDED

#include "./structs.h"

unsigned char parseTag(
    const char* line,
    Tag* tag
);

#endif // PARSERS_H_INCLUDED
