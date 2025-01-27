
#ifndef MAIN_LIBRARY_H_INCLUDED
#define MAIN_LIBRARY_H_INCLUDED

#include <stdlib.h>

/* ------ Static Node ------- */

#define MAXIMUM_STATIC_NODE_BYTES 1024

typedef struct SNode {
    char __data[MAXIMUM_STATIC_NODE_BYTES];
    size_t __maxDataBytes;
    struct SNode* __next;
} SNode;

// Constructor
unsigned char newSNode(
    SNode* node,
    void* data,
    const size_t dataBytes
);

// Destroyer
void destroySNode(SNode* node);

// Getters
char* getSNodeData(SNode* node);
SNode* getSNodeNext(SNode* node);

// Setters
unsigned char setSNodeData(
    SNode* node,
    void* data,
    const size_t dataBytes
);


/* ------ Dynamic Node ------ */

typedef struct DNode {
    void* __data;
    struct DNode* __next;
} DNode;

// Constructor
DNode* newDNode(void* data, const size_t sizeOfDataType);

// Destroyer
void destroyDNode(DNode* node);

// Getters
void* getDNodeData(DNode* node);
DNode* getDNodeNext(DNode* node);

// Setters
unsigned char setDNodeData(
    DNode* node,
    void* data,
    const size_t sizeOfDataType
);


/* ------- Utilities -------- */

void chainSNodes(SNode* node01, SNode* node02);
void chainDNodes(DNode* node01, DNode* node02);

#endif // MAIN_LIBRARY_H_INCLUDED
