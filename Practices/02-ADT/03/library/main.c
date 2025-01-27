
#include <stdlib.h>
#include <string.h>

#include "./main.h"

/* ------ Static Node ------- */

// Constructor
unsigned char newSNode(
    SNode* node,
    void* data,
    const size_t dataBytes
) {
    if (sizeof(node->__data) < dataBytes) return 1;

    memcpy(node->__data, data, dataBytes);
    node->__maxDataBytes = sizeof(node->__data);
    node->__next = NULL;

    return 0;
}

// Destroyer
void destroySNode(SNode* node) {
    memset(node->__data, '\0', node->__maxDataBytes);
    node->__maxDataBytes = 0;
}

// Getters
char* getSNodeData(SNode* node) {
    return node->__data;
}

SNode* getSNodeNext(SNode* node) {
    return node->__next;
}

// Setters
unsigned char setSNodeData(
    SNode* node,
    void* data,
    const size_t dataBytes
) {
    if (node->__maxDataBytes < dataBytes) return 1;

    memcpy(node->__data, data, dataBytes);

    return 0;
}


/* ------ Dynamic Node ------ */

// Constructor
DNode* newDNode(void* data, const size_t sizeOfDataType) {
    DNode* node = malloc(sizeof(DNode));
    if (node == NULL) return NULL;

    node->__data = malloc(sizeOfDataType);
    if (node->__data == NULL) {
        free(node);
        return NULL;
    };

    memcpy(node->__data, data, sizeOfDataType);
    node->__next = NULL;

    return node;
}

// Destroyer
void destroyDNode(DNode* node) {
    free(node->__data);
    free(node);
}

// Getters
void* getDNodeData(DNode* node) {
    return node->__data;
}

DNode* getDNodeNext(DNode* node) {
    return node->__next;
}

// Setters
unsigned char setDNodeData(
    DNode* node,
    void* data,
    const size_t sizeOfDataType
) {
    void* aux = malloc(sizeOfDataType);
    if (aux == NULL) return 1;

    free(node->__data);

    node->__data = aux;
    memcpy(node->__data, data, sizeOfDataType);

    return 0;
}

/* ------- Utilities -------- */

void chainSNodes(SNode* node01, SNode* node02) {
    node01->__next = node02;
}

void chainDNodes(DNode* node01, DNode* node02) {
    node01->__next = node02;
}
