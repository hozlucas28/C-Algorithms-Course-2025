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
unsigned char getBTreeElement(
    BTree* tree,
    void* store,
    const size_t sizeOfStore,
    int (*cmp)(const void* a, const void* b)
);

// Methods
unsigned char insertBTreeElement(
    BTree* tree,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* a, const void* b)
);

#endif // BINARY_TREE_H_INCLUDED
