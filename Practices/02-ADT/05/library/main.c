
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./main.h"

/* --------- Branch ---------- */

// Constructor
Branch* newBranch(
    void* data,
    const size_t sizeOfDataType,
    void (*printMethod)(Branch* branch)
) {
    Branch* branch = malloc(sizeof(Branch));
    if (branch == NULL) return NULL;

    branch->__data = malloc(sizeOfDataType);
    if (branch->__data == NULL) {
        free(branch);
        return NULL;
    };

    memcpy(branch->__data, data, sizeOfDataType);
    branch->__level = 0;
    branch->__leftBranch = NULL;
    branch->__rigthBranch = NULL;
    branch->__sizeOfDataType = sizeOfDataType;
    branch->__printMethod = printMethod;

    return branch;
}

// Destroyer
void destroyBranch(Branch* branch) {
    if (branch->__leftBranch != NULL) destroyBranch(branch->__leftBranch);
    if (branch->__rigthBranch != NULL) destroyBranch(branch->__rigthBranch);
    free(branch->__data);
    free(branch);
}

// Getters
void* getData(Branch* branch) {
    return branch->__data;
}

size_t getLevel(Branch* branch) {
    return branch->__level;
}

Branch* getLeftBranch(Branch* branch) {
    return branch->__leftBranch;
}

Branch* getRightBranch(Branch* branch) {
    return branch->__rigthBranch;
}

size_t getSizeOfDataType(Branch* branch) {
    return branch->__sizeOfDataType;
}

size_t getDeep(Branch* branch) {
    size_t leftHeigth;
    size_t rigthHeigth;

    if (branch == NULL) return 0;

    if (branch->__leftBranch == NULL && branch->__rigthBranch == NULL) return 0;

    leftHeigth = getDeep(branch->__leftBranch);
    rigthHeigth = getDeep(branch->__rigthBranch);

    return 1 + (leftHeigth > rigthHeigth ? leftHeigth : rigthHeigth);
}

// Setters
unsigned char setData(
    Branch* branch,
    void* data,
    const size_t sizeOfDataType,
    void (*printMethod)(Branch* branch)
) {
    Branch* aux = malloc(sizeOfDataType);
    if (aux == NULL) return 1;

    free(branch->__data);
    branch->__data = aux;

    memcpy(branch->__data, data, sizeOfDataType);
    branch->__sizeOfDataType = sizeOfDataType;
    branch->__printMethod = printMethod;

    return 0;
}

Branch* setLeftBranch(Branch* branch, Branch* leftBranch) {
    Branch* prevLeftBranch = branch->__leftBranch;

    branch->__leftBranch = leftBranch;
    branch->__leftBranch->__level = branch->__level + 1;

    return prevLeftBranch;
}

Branch* setRightBranch(Branch* branch, Branch* rigthBranch) {
    Branch* prevRightBranch = branch->__rigthBranch;

    branch->__rigthBranch = rigthBranch;
    branch->__rigthBranch->__level = branch->__level + 1;

    return prevRightBranch;
}

// Loggers
void branchRepr(
    Branch* branch,
    const int padStart,
    char endsWith[MAXIMUM_ENDS_WITH]
) {
    size_t i;
    char innerBranchEndsWith[MAXIMUM_ENDS_WITH];

    if (branch == NULL) {
        printf("NULL");
        return;
    };

    printf("Branch [0x%p] {\n", (void*)branch);

    printf("%*s = ", padStart + (int)sizeof("__data") - 1, "__data");
    branch->__printMethod(branch);
    printf(",\n");

    printf("%*s = %d,\n", padStart + (int)sizeof("__level") - 1, "__level", (int)branch->__level);

    // Left
    if (branch->__leftBranch == NULL) {
        printf("%*s = NULL,\n", padStart + (int)sizeof("__leftBranch") - 1, "__leftBranch");
    } else {
        printf("%*s = {\n", padStart + (int)sizeof("__leftBranch") - 1, "__leftBranch");

        for (i = 0; i < padStart + 2; i++) printf(" ");
        sprintf(innerBranchEndsWith, "%*s", padStart + 2 + (int)sizeof("},\n") - 1, "},\n");
        branchRepr(branch->__leftBranch, padStart + 4, innerBranchEndsWith);

        for (i = 0; i < padStart; i++) printf(" ");
        printf("},\n");
    };

    // Right
    if (branch->__rigthBranch == NULL) {
        printf("%*s = NULL,\n", padStart + (int)sizeof("__rigthBranch") - 1, "__rigthBranch");
    } else {
        printf("%*s = {\n", padStart + (int)sizeof("__rigthBranch") - 1, "__rigthBranch");

        for (i = 0; i < padStart * 2; i++) printf(" ");
        sprintf(innerBranchEndsWith, "%*s", padStart + 2 + (int)sizeof("},\n") - 1, "},\n");
        branchRepr(branch->__rigthBranch, padStart * 4, innerBranchEndsWith);

        for (i = 0; i < padStart; i++) printf(" ");
        printf("},\n");
    };

    printf("%*s %d,\n", padStart + (int)sizeof("__sizeOfDataType") - 1, "__sizeOfDataType", (int)branch->__sizeOfDataType);
    printf("%*s [0x%p],\n", padStart + (int)sizeof("__printMethod") - 1, "__printMethod", (void*)&branch->__printMethod);
    printf("%s", endsWith);
}


/*------- BinaryTree -------- */

// Constructor
BinaryTree* newBinaryTree(
    void* rootData,
    const size_t sizeOfRootData,
    void (*printRootMethod)(Branch* branch),
    int (*cmpBranches)(Branch* branch01, Branch* branch02)
) {
    BinaryTree* tree = malloc(sizeof(BinaryTree));
    if (tree == NULL) return NULL;

    tree->__root = newBranch(rootData, sizeOfRootData, printRootMethod);
    if (tree->__root == NULL) {
        free(tree);
        return NULL;
    };

    tree->__leafs = 1;
    tree->__printRootMethod = printRootMethod;
    tree->__cmpBranches = cmpBranches;

    return tree;
}

// Destroyer
void destroyBinaryTree(BinaryTree* tree) {
    destroyBranch(tree->__root);
    free(tree);
}

// Getters
Branch* getRoot(BinaryTree* tree) {
    return tree->__root;
}

size_t getLeafs(BinaryTree* tree) {
    return tree->__leafs;
}

size_t getHeight(BinaryTree* tree) {
    return getDeep(tree->__root);
}

// Methods
void insertBranch(BinaryTree* tree, Branch* branch) {
    /* TODO */
    setLeftBranch(tree->__root, branch);
}

// Loggers
void binaryTreeRepr(
    BinaryTree* tree,
    const int padStart,
    char endsWith[MAXIMUM_ENDS_WITH]
) {
    size_t i;
    char branchEndsWith[MAXIMUM_ENDS_WITH];

    printf("BinaryTree [0x%p] {\n", (void*)tree);

    printf("%*s = {\n", padStart + (int)sizeof("__root") - 1, "__root");

    for (i = 0; i < padStart + 2; i++) printf(" ");
    sprintf(branchEndsWith, "%*s", padStart + 2 + (int)sizeof("},\n") - 1, "},\n");
    branchRepr(tree->__root, padStart + 4, branchEndsWith);

    for (i = 0; i < padStart; i++) printf(" ");
    printf("},\n");

    printf("%*s = %d,\n", padStart + (int)sizeof("__leafs") - 1, "__leafs", (int)tree->__leafs);
    printf("%*s [0x%p],\n", padStart + (int)sizeof("__printRootMethod") - 1, "__printRootMethod", (void*)&tree->__printRootMethod);
    printf("%*s [0x%p],\n", padStart + (int)sizeof("__cmpBranches") - 1, "__cmpBranches", (void*)&tree->__cmpBranches);
    printf("%s", endsWith);
}
