
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

size_t getBTreeNodesAtHeight(
    const BTree* tree,
    const size_t height
);

size_t getBTreeNodesAtLevel(
    const BTree* tree,
    const size_t level
);

unsigned char getBTreeElement(
    const BTree* tree,
    void* store,
    const size_t sizeOfStore,
    int (*cmp)(const void* a, const void* b)
);

unsigned char isBTreeFull(
    const BTree* tree,
    const size_t sizeOfData
);

unsigned char isBTreeEmpty(const BTree* tree);

unsigned char isFullBTree(const BTree* tree);

size_t isFullBTreeAtLevel(
    const BTree* tree,
    const size_t level
);

unsigned char isBalancedBTree(const BTree* tree);

unsigned char isAVLBTree(const BTree* tree);

// Methods
unsigned char deleteBTreeRootNode(BTree* tree);

unsigned char insertInBTree(
    BTree* tree,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* data, const void* dataInTreeNode)
);

void mirrorBTree(BTree* tree);

unsigned char mapBTreeOrder(
    const BTree* tree,
    void (*callback)(void* data, const size_t sizeOfData, const void* params),
    const void* params
);

unsigned char mapBTreePreOrder(
    const BTree* tree,
    void (*callback)(void* data, const size_t sizeOfData, const void* params),
    const void* params
);

unsigned char mapBTreePostOrder(
    const BTree* tree,
    void (*callback)(void* data, const size_t sizeOfData, const void* params),
    const void* params
);

#endif // MAIN_LIBRARY_H_INCLUDED
