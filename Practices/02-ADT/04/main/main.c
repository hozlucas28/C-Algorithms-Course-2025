
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    Node* node;
    int data = 1;

    List* list;

    size_t i;
    const size_t nNodes = 9;

    // Create list with one node
    node = newNode(&data, sizeof(data));
    if (node == NULL) {
        printf("> Error! An error occurred on create a node.");
        return 1;
    };

    list = newList(1, node);

    // Append nodes to list
    printf("> Append nodes to list...\n\n");

    for (i = 0; i < nNodes; i++) {
        data *= 2;
        node = newNode(&data, sizeof(data));
        if (node == NULL) break;

        appendNode(list, node);
    };

    // Print list content
    for (i = 0; i < getLength(list); i++) {
        node = getNodeAt(list, i);

        printf(
            "> Node %02d [0x%p] = %d.\n",
            (int)(i + 1),
            (void*)node,
            *(int*)getData(node)
        );
    };

    // Unshift node to list
    printf("\n> Unshift node to list...\n\n");

    data = -128;
    node = newNode(&data, sizeof(data));
    if (node == NULL) {
        destroyList(list);
        printf("> Error! An error occurred on create a node.");
        return 1;
    };

    unshiftNode(list, node);

    // Print list content
    for (i = 0; i < getLength(list); i++) {
        node = getNodeAt(list, i);

        printf(
            "> Node %02d [0x%p] = %d.\n",
            (int)(i + 1),
            (void*)node,
            *(int*)getData(node)
        );
    };

    // Insert node at 4 index to list
    printf("\n> Insert node at 4 index to list...\n\n");

    data = 777;
    node = newNode(&data, sizeof(data));
    if (node == NULL) {
        destroyList(list);
        printf("> Error! An error occurred on create a node.");
        return 1;
    };

    insertNodeAt(list, node, 4);

    // Print list content
    for (i = 0; i < getLength(list); i++) {
        node = getNodeAt(list, i);

        printf(
            "> Node %02d [0x%p] = %d.\n",
            (int)(i + 1),
            (void*)node,
            *(int*)getData(node)
        );
    };

    destroyList(list);

    return 0;
}
