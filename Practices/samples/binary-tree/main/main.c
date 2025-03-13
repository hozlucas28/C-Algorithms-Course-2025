
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

void printInt(void* integer, const size_t sizeOfInteger, const void* params) {
    int* _integer = (int*)integer;
    printf("%d ", *_integer);
}

int cmpInts(const void* data, const void* dataInTreeNode) {
    int* _data = (int*)data;
    int* _dataInTreeNode = (int*)dataInTreeNode;

    return (*_data) - (*_dataInTreeNode);
}

int main() {
    int numbers[] = {5, 2, 7, 8, 3, 6, 1, 9, 4, 10};
    const size_t numbersLength = sizeof(numbers) / sizeof(*numbers);

    BTree tree;

    size_t i;

    size_t remainingNodes;

    newBTree(&tree);

    for (i = 0; i < numbersLength; i++) {
        if (insertInBTree(&tree, numbers + i, sizeof(*(numbers + i)), &cmpInts)) {
            printf(
                "> Error! An error occurred on insertInBTree(%d, %d).\n",
                *(numbers + i),
                (int)sizeof(*numbers)
            );
        } else {
            printf(
                "> insertInBTree(%d, %d).\n",
                *(numbers + i),
                (int)sizeof(*numbers)
            );
        }
    }

    printf("\n> Is a full binary tree? %s.\n", isFullBTree(&tree) ? "Yes" : "False");
    printf("> Is a balanced binary tree? %s.\n", isBalancedBTree(&tree) ? "Yes" : "False");
    printf("> Is an AVL binary tree? %s.\n", isAVLBTree(&tree) ? "Yes" : "False");

    printf("\n> Nodes at level %d: %d.\n", 0, (int)getBTreeNodesAtLevel(&tree, 0));
    printf("> Nodes at level %d: %d.\n", 2, (int)getBTreeNodesAtLevel(&tree, 2));

    printf("\n> Nodes at height %d: %d.\n", 0, (int)getBTreeNodesAtHeight(&tree, 0));
    printf("> Nodes at height %d: %d.\n", 3, (int)getBTreeNodesAtHeight(&tree, 3));
    printf("> Nodes at height %d: %d.\n", 5, (int)getBTreeNodesAtHeight(&tree, 5));
    printf("> Nodes at height %d: %d.\n", 6, (int)getBTreeNodesAtHeight(&tree, 6));

    remainingNodes = isFullBTreeAtLevel(&tree, 2);

    printf("\n> Is a full binary tree at level %d? ", 2);
    remainingNodes == 0 ? printf("Yes.\n") : printf("The binary tree needs %d nodes more to be a full one.\n", (int)remainingNodes);

    remainingNodes = isFullBTreeAtLevel(&tree, 4);

    printf("> Is a full binary tree at level %d? ", 4);
    remainingNodes == 0 ? printf("Yes.\n") : printf("The binary tree needs %d nodes more to be a full one.\n", (int)remainingNodes);

    printf("\n> Map tree in pre-order: ");
    mapBTreePreOrder(&tree, &printInt, NULL);

    printf("\n> Map tree in order: ");
    mapBTreeOrder(&tree, &printInt, NULL);

    printf("\n> Map tree in post-order: ");
    mapBTreePostOrder(&tree, &printInt, NULL);

    destroyBTree(&tree);

    printf("%d", isBTreeEmpty(&tree));

    return 0;
}
