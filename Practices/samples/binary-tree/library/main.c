
#include <stdlib.h>
#include <string.h>

#include "./main.h"

/* ------ Private ------ */

unsigned char __isBTreeFull(
    const BTree* tree,
    const size_t height
);


/* ------ Public ------- */

// Constructor
void newBTree(BTree* tree) {
    *tree = NULL;
}

// Destructor
void destroyBTree(BTree* tree) {
    if (*tree == NULL) return;

    destroyBTree(&(*tree)->__left);
    destroyBTree(&(*tree)->__right);

    free((*tree)->__data);
    free(*tree);

    *tree = NULL;
}

// Getters
unsigned char __isBTreeFull(
    const BTree* tree,
    const size_t height
) {
    if (*tree == NULL) return height < 0;
    if (height == 0) return 1;

    const unsigned char isFullLeftTree = __isBTreeFull(&(*tree)->__left, height - 1);
    const unsigned char isFullRightTree = __isBTreeFull(&(*tree)->__right, height - 1);

    return isFullLeftTree && isFullRightTree;
}

size_t getBTreeHeight(const BTree* tree) {
    size_t leftHeight;
    size_t rightHeight;

    size_t maxHeight;

    if (*tree == NULL) return 0;

    leftHeight = getBTreeHeight(&(*tree)->__left);
    rightHeight = getBTreeHeight(&(*tree)->__right);

    maxHeight = leftHeight > rightHeight ? leftHeight : rightHeight;

    return maxHeight + 1;
}

unsigned char isBTreeFull(
    const BTree* tree,
    const size_t sizeOfData
) {
    TreeNode* newNode;

    newNode = malloc(sizeof(TreeNode));
    if (newNode == NULL) return 1;

    newNode->__data = malloc(sizeOfData);
    if (newNode->__data == NULL) {
        free(newNode);
        return 1;
    };

    free(newNode->__data);
    free(newNode);

    return 0;
}

unsigned char isBTreeEmpty(const BTree* tree) {
    return *tree == NULL;
}

unsigned char isFullTree(const BTree* tree) {
    const size_t treeHeight = getBTreeHeight(tree);

    const unsigned char isFullLeftTree = __isBTreeFull(&(*tree)->__left, treeHeight - 1);
    const unsigned char isFullRightTree = __isBTreeFull(&(*tree)->__right, treeHeight - 1);

    return isFullLeftTree && isFullRightTree;
}

unsigned char isBTreeBalanced(const BTree* tree) {
    const size_t treeHeight = getBTreeHeight(tree);
    return __isBTreeFull(tree, treeHeight - 2);
}

unsigned char isBTreeAVL(const BTree* tree) {
    // TODO
    return 0;
}

// Methods
unsigned char insertInBTree(
    BTree* tree,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* data, const void* dataInTreeNode)
) {
    int cmpValue;

    TreeNode* newTreeNode;

    while (*tree != NULL) {
        cmpValue = cmp(data, (*tree)->__data);

        if (cmpValue < 0) {
            tree = &(*tree)->__left;
        } else if (cmpValue > 0) {
            tree = &(*tree)->__right;
        } else
            return 0;
    }

    newTreeNode = malloc(sizeof(TreeNode));
    if (newTreeNode == NULL) return 1;

    newTreeNode->__data = malloc(sizeOfData);
    if (newTreeNode->__data == NULL) {
        free(newTreeNode);
        return 1;
    };

    memcpy(newTreeNode->__data, data, sizeOfData);
    newTreeNode->__sizeOfData = sizeOfData;
    newTreeNode->__left = NULL;
    newTreeNode->__right = NULL;

    *tree = newTreeNode;

    return 0;
}

unsigned char mapBTreeOrder(
    const BTree* tree,
    void (*callback)(void* data, const size_t sizeOfData, const void* params),
    const void* params
) {
    if (*tree == NULL) return 1;

    mapBTreeOrder(&(*tree)->__left, callback, params);
    callback((*tree)->__data, (*tree)->__sizeOfData, params);
    mapBTreeOrder(&(*tree)->__right, callback, params);

    return 0;
}

unsigned char mapBTreePreOrder(
    const BTree* tree,
    void (*callback)(void* data, const size_t sizeOfData, const void* params),
    const void* params
) {
    if (*tree == NULL) return 1;

    callback((*tree)->__data, (*tree)->__sizeOfData, params);
    mapBTreePreOrder(&(*tree)->__left, callback, params);
    mapBTreePreOrder(&(*tree)->__right, callback, params);

    return 0;
}

unsigned char mapBTreePostOrder(
    const BTree* tree,
    void (*callback)(void* data, const size_t sizeOfData, const void* params),
    const void* params
) {
    if (*tree == NULL) return 1;

    mapBTreePostOrder(&(*tree)->__left, callback, params);
    mapBTreePostOrder(&(*tree)->__right, callback, params);
    callback((*tree)->__data, (*tree)->__sizeOfData, params);

    return 0;
}
