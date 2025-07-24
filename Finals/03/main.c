
#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "./runners.txt"
#define TOP 8

#include "./test.h"
#include "./parsers.h"
#include "./utilities.h"
#include "./singly-linked-list.h"

int main() {
    SList topRunners;

    if (createTestFile(FILE_PATH)) {
        puts("> An error occurred on create the test file.");
        return 1;
    };

    newSList(&topRunners);

    if (processRunners(FILE_PATH, &topRunners, TOP)) {
        puts("> An error occurred on process the runners file.");
    } else {
        mapSList(&topRunners, &printRunner, NULL);
    };

    destroySList(&topRunners);

    remove(FILE_PATH);

    return 0;
}
