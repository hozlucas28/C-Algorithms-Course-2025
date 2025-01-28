
#include <stdio.h>

#include "./functions.h"

int cmpBranches(Branch* branch01, Branch* branch02) {
    int data01 = *(int*)getData(branch01);
    int data02 = *(int*)getData(branch02);
    return data01 - data02;
}

void printBranchDataInt(Branch* branch) {
    printf("%d", *(int*)getData(branch));
}
