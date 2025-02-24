
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

void printInt(void* integer) {
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

    putchar('\n');

    printf("> Map tree in pre-order: ");
    mapBTreePreOrder(&tree, &printInt);

    printf("\n\n> Map tree in order: ");
    mapBTreeOrder(&tree, &printInt);

    printf("\n\n> Map tree in post-order: ");
    mapBTreePostOrder(&tree, &printInt);

    destroyBTree(&tree);

    printf("%d", isBTreeEmpty(&tree));

    return 0;
}
