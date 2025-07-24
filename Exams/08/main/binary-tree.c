
#include <stdlib.h>
#include <string.h>

#include "./binary-tree.h"

// Constructor
void newBTree(BTree* tree) {
    *tree = NULL;
}

// Destructor
void destroyBTree(BTree* tree) {
    if (*tree == NULL) return;

    free((*tree)->__data);

    destroyBTree(&(*tree)->__left);
    destroyBTree(&(*tree)->__right);

    free(*tree);

    *tree = NULL;
}

// Getters
unsigned char hasBTreeElement(
    BTree* tree,
    const void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* a, const void* b)
) {
    int cmpValue = -1;

    while (*tree != NULL && cmpValue != 0) {
        cmpValue = cmp(data, (*tree)->__data);

        if (cmpValue < 0) {
            tree = &(*tree)->__left;
        } else if (cmpValue > 0) {
            tree = &(*tree)->__right;
        } else {
            if ((*tree)->__sizeOfData != sizeOfData) return 0;
        };
    };

    return *tree != NULL;
}

// Methods
unsigned char insertBTreeElement(
    BTree* tree,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* a, const void* b)
) {
    int cmpValue;

    BTreeNode* newNode;

    while (*tree != NULL) {
        cmpValue = cmp(data, (*tree)->__data);

        if (cmpValue < 0) {
            tree = &(*tree)->__left;
        } else if (cmpValue > 0) {
            tree = &(*tree)->__right;
        } else {
            return 1;
        };
    };

    newNode = malloc(sizeof(BTreeNode));
    if (newNode == NULL) return 1;

    newNode->__data = malloc(sizeof(BTreeNode));
    if (newNode->__data == NULL) {
        free(newNode);
        return 1;
    };

    memcpy(newNode->__data, data, sizeOfData);
    newNode->__sizeOfData = sizeOfData;
    newNode->__left = NULL;
    newNode->__right = NULL;

    *tree = newNode;

    return 0;
}

void mapExclusiveLeft(
    BTree* treeA,
    BTree* treeB,
    int (*cmp)(const void* a, const void* b),
    void (*callback)(void* data, const size_t sizeOfData, void* params),
    void* params
) {
    unsigned char inTreeB;

    if (*treeA == NULL) return;

    inTreeB = hasBTreeElement(treeB, (*treeA)->__data, (*treeA)->__sizeOfData, cmp);
    if (!inTreeB) callback((*treeA)->__data, (*treeA)->__sizeOfData, params);

    mapExclusiveLeft(&(*treeA)->__left, treeB, cmp, callback, params);
    mapExclusiveLeft(&(*treeA)->__right, treeB, cmp, callback, params);
}
