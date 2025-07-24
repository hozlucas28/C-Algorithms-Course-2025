#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include <stdlib.h>

typedef struct BTreeNode {
    void* __data;
    size_t __sizeOfData;
    struct BTreeNode* __left;
    struct BTreeNode* __right;
} BTreeNode;

typedef BTreeNode* BTree;

// Constructor
void newBTree(BTree* tree);

// Destructor
void destroyBTree(BTree* tree);

// Getters
unsigned char hasBTreeElement(
    BTree* tree,
    const void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* a, const void* b)
);

// Methods
unsigned char insertBTreeElement(
    BTree* tree,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* a, const void* b)
);

void mapExclusiveLeft(
    BTree* treeA,
    BTree* treeB,
    int (*cmp)(const void* a, const void* b),
    void (*callback)(void* data, const size_t sizeOfData, void* params),
    void* params
);

#endif // BINARY_TREE_H_INCLUDED

