
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    SNode sNode01;
    SNode sNode02;

    DNode* dNode01;
    DNode* dNode02;

    int data01 = 5;
    int data02 = 10;

    unsigned char error;

    printf("> Static nodes...\n\n");

    error = newSNode(&sNode01, &data01, sizeof(data01));
    if (error) {
        printf("> Error! An error occurred on create a static node.");
        return 1;
    };

    error = newSNode(&sNode02, &data02, sizeof(data02));
    if (error) {
        destroySNode(&sNode01);
        printf("> Error! An error occurred on create a static node.");
        return 1;
    };

    printf(
        "> sNode01 [0x%p] data = %d.\n",
        (void*)&sNode01,
        *(int*)getSNodeData(&sNode01)
    );

    printf(
        "> sNode02 [0x%p] data = %d.\n",
        (void*)&sNode02,
        *(int*)getSNodeData(&sNode02)
    );

    chainSNodes(&sNode01, &sNode02);

    printf(
        "> sNode01 [0x%p] next = 0x%p.\n",
        (void*)&sNode01,
        (void*)getSNodeNext(&sNode01)
    );

    chainSNodes(&sNode02, &sNode01);

    printf(
        "> sNode02 [0x%p] next = 0x%p.\n\n",
        (void*)&sNode02,
        (void*)getSNodeNext(&sNode02)
    );

    destroySNode(&sNode01);
    destroySNode(&sNode02);

    printf("> Dynamic nodes...\n\n");

    dNode01 = newDNode(&data01, sizeof(data01));
    if (dNode01 == NULL) {
        printf("> Error! An error occurred on create a dynamic node.");
        return 1;
    };

    dNode02 = newDNode(&data02, sizeof(data02));
    if (dNode02 == NULL) {
        destroyDNode(dNode01);
        printf("> Error! An error occurred on create a dynamic node.");
        return 1;
    };

    printf(
        "> dNode01 [0x%p] data = %d.\n",
        (void*)dNode01,
        *(int*)getDNodeData(dNode01)
    );

    printf(
        "> dNode02 [0x%p] data = %d.\n",
        (void*)dNode02,
        *(int*)getDNodeData(dNode02)
    );

    chainDNodes(dNode01, dNode02);

    printf(
        "> dNode01 [0x%p] next = 0x%p.\n",
        (void*)dNode01,
        (void*)getDNodeNext(dNode01)
    );

    chainDNodes(dNode02, dNode01);

    printf(
        "> dNode02 [0x%p] next = 0x%p.",
        (void*)dNode02,
        (void*)getDNodeNext(dNode02)
    );

    destroyDNode(dNode01);
    destroyDNode(dNode02);

    return 0;
}
