
#include "../library/main.h"

#include "./functions.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    BinaryTree* tree;
    int rootData = 1;

    Branch* branch01;
    int data01 = 2;

    Branch* branch02;
    int data02 = 2;

    tree = newBinaryTree(
        &rootData,
        sizeof(rootData),
        &printBranchDataInt,
        *cmpBranches
    );

    printf("> Binary tree...\n\n");
    binaryTreeRepr(tree, 2, "};");

    printf("\n\n> Deep of the binary tree = %d.", (int)getHeight(tree));

    branch01 = newBranch(&data01, sizeof(data01), &printBranchDataInt);
    if (branch01 == NULL) {
        destroyBinaryTree(tree);
        printf("\n\n> Error! An error occurred on create branch.");
        return 1;
    };

    insertBranch(tree, branch01);

    branch02 = newBranch(&data02, sizeof(data02), &printBranchDataInt);
    if (branch02 == NULL) {
        destroyBinaryTree(tree);
        printf("\n\n> Error! An error occurred on create branch.");
        return 1;
    };

    insertBranch(tree, branch02);

    printf("\n\n> Binary tree after inserting two branches...\n\n");
    binaryTreeRepr(tree, 2, "};");

    printf("\n\n> Deep of the binary tree = %d.", (int)getHeight(tree));

    destroyBinaryTree(tree);

    return 0;
}
