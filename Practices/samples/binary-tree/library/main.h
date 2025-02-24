
#ifndef MAIN_LIBRARY_H_INCLUDED
#define MAIN_LIBRARY_H_INCLUDED

#include <stdlib.h>

/* ------- Tree Node -------- */

typedef struct TreeNode {
    void* __data;
    size_t __sizeOfData;
    struct TreeNode* __left;
    struct TreeNode* __right;
} TreeNode;


/* ---------- Tree ---------- */

typedef TreeNode* BTree;

// Constructor
void newBTree(BTree* tree);

// Destructor
void destroyBTree(BTree* tree);

// Getters
size_t getBTreeHeight(const BTree* tree);

unsigned char isTreeFull(
    const BTree* tree,
    const size_t sizeOfData
);

unsigned char isBTreeEmpty(const BTree* tree);

unsigned char isBTreeFull(
    const BTree* tree,
    const size_t sizeOfData
);

unsigned char isBTreeBalanced(const BTree* tree);

unsigned char isBTreeAVL(const BTree* tree);

// Methods
unsigned char insertInBTree(
    BTree* tree,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* data, const void* dataInTreeNode)
);

unsigned char mapBTreeOrder(
    const BTree* tree,
    void (*callback)(void* data)
);

unsigned char mapBTreePreOrder(
    const BTree* tree,
    void (*callback)(void* data)
);

unsigned char mapBTreePostOrder(
    const BTree* tree,
    void (*callback)(void* data)
);

#endif // MAIN_LIBRARY_H_INCLUDED
