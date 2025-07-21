
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
}

// Getters
unsigned char getBTreeElement(
    BTree* tree,
    void* store,
    const size_t sizeOfStore,
    int (*cmp)(const void* a, const void* b)
) {
    int cmpValue = -1;

    while (*tree != NULL && cmpValue != 0) {
        cmpValue = cmp((*tree)->__data, store);

        if (cmpValue < 0) {
            tree = &(*tree)->__left;
        } else if (cmpValue > 0) {
            tree = &(*tree)->__right;
        } else {
            if ((*tree)->__sizeOfData != sizeOfStore) return 1;
            memcpy(store, (*tree)->__data, sizeOfStore);
        };
    };

    return *tree == NULL;
}

// Methods
unsigned char insertBTreeElement(
    BTree* tree,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* a, const void* b)
) {
    BTreeNode* newBTreeNode;

    int cmpValue;

    newBTreeNode = malloc(sizeof(BTreeNode));
    if (newBTreeNode == NULL) return 1;

    newBTreeNode->__data = malloc(sizeOfData);
    if (newBTreeNode->__data == NULL) {
        free(newBTreeNode);
        return 1;
    };

    memcpy(newBTreeNode->__data, data, sizeOfData);
    newBTreeNode->__sizeOfData = sizeOfData;
    newBTreeNode->__left = NULL;
    newBTreeNode->__right = NULL;

    while (*tree != NULL) {
        cmpValue = cmp((*tree)->__data, newBTreeNode->__data);

        if (cmpValue < 0) {
            tree = &(*tree)->__left;
        } else if (cmpValue > 0) {
            tree = &(*tree)->__right;
        } else {
            free(newBTreeNode->__data);
            free(newBTreeNode);
            return 1;
        };
    };

    *tree = newBTreeNode;

    return 0;
}
