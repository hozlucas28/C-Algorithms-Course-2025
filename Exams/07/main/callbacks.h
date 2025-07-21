#ifndef CALLBACKS_H_INCLUDED
#define CALLBACKS_H_INCLUDED

#include <stdlib.h>

void onValidLine(
    const char* line,
    const size_t lineIndex,
    void* params
);

void onInvalidLine(
    const char* line,
    const size_t lineIndex,
    void* params
);

#endif // CALLBACKS_H_INCLUDED
