
#ifndef MAIN_LIBRARY_H_INCLUDED
#define MAIN_LIBRARY_H_INCLUDED

#include <stdlib.h>

#define MAXIMUM_ENDS_WITH 256

/* --------- Branch ---------- */

typedef struct Branch {
    void* __data;
    size_t __level;
    struct Branch* __leftBranch;
    struct Branch* __rigthBranch;
    size_t __sizeOfDataType;
    void (*__printMethod)(struct Branch* branch);
} Branch;

// Constructor
Branch* newBranch(
    void* data,
    const size_t sizeOfDataType,
    void (*printMethod)(Branch* branch)
);

// Destroyer
void destroyBranch(Branch* branch);

// Getters
void* getData(Branch* branch);
size_t getLevel(Branch* branch);
Branch* getLeftBranch(Branch* branch);
Branch* getRightBranch(Branch* branch);
size_t getSizeOfDataType(Branch* branch);

size_t getDeep(Branch* branch);

// Setters
unsigned char setData(
    Branch* branch,
    void* data,
    const size_t sizeOfDataType,
    void (*printMethod)(Branch* branch)
);

Branch* setLeftBranch(Branch* branch, Branch* leftBranch);
Branch* setRightBranch(Branch* branch, Branch* rigthBranch);

// Loggers
void branchRepr(
    Branch* branch,
    const int padStart,
    char endsWith[MAXIMUM_ENDS_WITH]
);

/*------- BinaryTree -------- */

typedef struct BinaryTree {
    Branch* __root;
    size_t __leafs;
    void (*__printRootMethod)(Branch* branch);
    int (*__cmpBranches)(Branch* branch01, Branch* branch02);
} BinaryTree;

// Constructor
BinaryTree* newBinaryTree(
    void* rootData,
    const size_t sizeOfRootData,
    void (*printRootMethod)(Branch* branch),
    int (*cmpBranches)(Branch* branch01, Branch* branch02)
);

// Destroyer
void destroyBinaryTree(BinaryTree* tree);

// Getters
Branch* getRoot(BinaryTree* tree);
size_t getLeafs(BinaryTree* tree);

size_t getHeight(BinaryTree* tree);

// Methods
void insertBranch(BinaryTree* tree, Branch* branch);

// Loggers
void binaryTreeRepr(
    BinaryTree* tree,
    const int padStart,
    char endsWith[MAXIMUM_ENDS_WITH]
);

#endif // MAIN_LIBRARY_H_INCLUDED
