
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

// Methods
unsigned char insertBTreeElement(
    BTree* tree,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* a, const void* b)
) {
    // TODO
    BTreeNode* newNode;
    int cmpValue;

    newNode = malloc(sizeof(BTreeNode));
    if (newNode == NULL) return 1;

    newNode->__data = malloc(sizeOfData);
    if (newNode->__data == NULL) {
        free(newNode);
        return 1;
    };

    memcpy(newNode->__data, data, sizeOfData);
    newNode->__sizeOfData = sizeOfData;
    newNode->__left = NULL;
    newNode->__right = NULL;

    while (*tree != NULL) {
        cmpValue = cmp((*tree)->__data, newNode->__data);

        if (cmpValue > 0) {
            tree = &(*tree)->__left;
        } else if (cmpValue < 0){
            tree = &(*tree)->__right;
        } else return 1;
    };

    *tree = newNode;

    return 0;
}

void mirrorBTree(BTree* tree) {
    BTreeNode* left;
    BTreeNode* right;

    if (*tree == NULL) return;

    left = (*tree)->__left;
    right = (*tree)->__right;

    (*tree)->__left = right;
    (*tree)->__right = left;

    mirrorBTree(&(*tree)->__left);
    mirrorBTree(&(*tree)->__right);
}

void mapBTreePreOrder(
    BTree* tree,
    void (*callback)(void* value, void* params),
    void* params
) {
    if (*tree == NULL) return;

    callback((*tree)->__data, params);
    mapBTreePreOrder(&(*tree)->__left, callback, params);
    mapBTreePreOrder(&(*tree)->__right, callback, params);
}
