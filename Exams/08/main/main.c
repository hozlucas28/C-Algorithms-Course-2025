
#include <stdio.h>
#include <stdlib.h>

#define FILE_A_PATH "./A.txt"
#define FILE_B_PATH "./B.txt"

#define OUTPUT_FILE_PATH "./A-B.txt"

#include "./test.h"
#include "./cmps.h"
#include "./macros.h"
#include "./actions.h"
#include "./utilities.h"
#include "./binary-tree.h"

int main() {
    unsigned char error;

    const char fileALines[][LINE_LENGTH] = {
        "  HTML5 ",
        "Golang J",
        "avaScrip",
        "t CSS3 J",
        "ava % Pr",
        "olog Cob",
        "ol/Haske",
        "ll TypeS",
        "cript++P",
        "ython C#",
        "-Git Git",
        "Hub&&192",
        "8"
    };

    const char fileBLines[][LINE_LENGTH] = {
        "$$Abap H",
        "TML5 Jav",
        "a % Prol",
        "og / &&%",
        " TypeScr",
        "ipt JQue",
        "ry ++Pyt",
        "hon ##-G",
        "it Bash ",
        "&&1928 R",
        "eact////"
        ""
    };

    BTree treeA;
    BTree treeB;

    FILE* file;

    error = createTestFile(FILE_A_PATH, fileALines, sizeof(fileALines) / sizeof(*fileALines));
    if (error) {
        puts("> An error occurred on create the test file A.");
        return 1;
    };

    error = createTestFile(FILE_B_PATH, fileBLines, sizeof(fileBLines) / sizeof(*fileBLines));
    if (error) {
        puts("> An error occurred on create the test file B.");
        return 1;
    };

    newBTree(&treeA);

    error = loadBTree(&treeA, FILE_A_PATH);
    if (error) {
        puts("> An error occurred on load the test file A content within the binary tree A.");
        destroyBTree(&treeA);
        return 1;
    };

    newBTree(&treeB);

    error = loadBTree(&treeB, FILE_B_PATH);
    if (error) {
        puts("> An error occurred on load the test file B content within the binary tree B.");
        destroyBTree(&treeA);
        destroyBTree(&treeB);
        return 1;
    };

    file = fopen(OUTPUT_FILE_PATH, "wt");
    if (file == NULL) {
        destroyBTree(&treeA);
        destroyBTree(&treeB);
        return 1;
    };

    mapExclusiveLeft(&treeA, &treeB, &cmpWords, &printAndSave, &file);

    destroyBTree(&treeA);
    destroyBTree(&treeB);

    fclose(file);

    return 0;
}
