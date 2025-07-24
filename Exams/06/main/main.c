#include <stdio.h>
#include <stdlib.h>

#define TEST_FILE_PATH "./binary-tree.csv"

#include "./test.h"
#include "./menu.h"
#include "./binary-tree.h"

int main() {
    unsigned char error;

    BTree tree;
    Menu menu;

    error = createTestFile(TEST_FILE_PATH);
    if (error) {
        puts("> An error occurred on try to create the test file.");
        return 1;
    };

    newBTree(&tree);
    newMenu(&menu, &tree, TEST_FILE_PATH);

    initMenu(&menu);

    destroyMenu(&menu);
    destroyBTree(&tree);

    remove(TEST_FILE_PATH);

    return 0;
}
