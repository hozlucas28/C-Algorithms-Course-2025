
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "./main.h"

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

size_t __getBTreeNodesAtHeight(
    const BTree* tree,
    const size_t targetHeight,
    const size_t currentHeight
) {
    if (*tree == NULL) return 0;
    if (currentHeight >= targetHeight) return 1;

    return __getBTreeNodesAtHeight(&(*tree)->__left, targetHeight, currentHeight + 1) +
        __getBTreeNodesAtHeight(&(*tree)->__right, targetHeight, currentHeight + 1);
}

size_t getBTreeNodesAtHeight(
    const BTree* tree,
    const size_t height
) {
    if (!height) return 0;

    return __getBTreeNodesAtHeight(tree, height, 1);
}

size_t getBTreeNodesAtLevel(
    const BTree* tree,
    const size_t level
) {
    return __getBTreeNodesAtHeight(tree, level, 0);
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

unsigned char __isFullBTree(
    const BTree* tree,
    const size_t height
) {
    int isFullLeftTree;
    int isFullRightTree;

    if (*tree == NULL) return height < 0;
    if (height == 0) return 1;

    isFullLeftTree = __isFullBTree(&(*tree)->__left, height - 1);
    isFullRightTree = __isFullBTree(&(*tree)->__right, height - 1);

    return isFullLeftTree && isFullRightTree;
}

unsigned char isFullBTree(const BTree* tree) {
    const size_t treeHeight = getBTreeHeight(tree);
    if(treeHeight == 0) return 1;

    return __isFullBTree(tree, treeHeight - 1);
}

size_t isFullBTreeAtLevel(
    const BTree* tree,
    const size_t level
) {
    size_t nodesAtLevel = __getBTreeNodesAtHeight(tree, level, 0);
    size_t remainingNodes = pow(2, level) - nodesAtLevel;

    return remainingNodes;
}

unsigned char isBalancedBTree(const BTree* tree) {
    const size_t treeHeight = getBTreeHeight(tree);
    if(treeHeight == 0) return 1;

    return __isFullBTree(tree, treeHeight - 2);
}

unsigned char isAVLBTree(const BTree* tree) {
    int leftHeight;
    int rightHeight;

    if (*tree == NULL) return 1;

    leftHeight = getBTreeHeight(&(*tree)->__left);
    rightHeight = getBTreeHeight(&(*tree)->__right);
    if (abs(leftHeight - rightHeight) > 1) return 0;

    return isAVLBTree(&(*tree)->__left) && isAVLBTree(&(*tree)->__right);
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
