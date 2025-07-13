
#include <stdio.h>

#include "./menu.h"
#include "./cmps.h"
#include "./parsers.h"
#include "./structs.h"
#include "./utilities.h"

// Constructor
void newMenu(
    Menu* menu,
    BTree* binaryTree,
    const char* keyValueFilePath
) {
    menu->__valueToCount = 0;
    menu->__binaryTree = binaryTree;
    menu->__keyValueFilePath = keyValueFilePath;
    menu->__mirroredTree = 0;
}

// Destructor
void destroyMenu(Menu* menu) {
}

// Methods
void initMenu(Menu* menu) {
    int error;
    int operation;

    int valueOccurrences = 0;
    int* valueOccurrencesArr[] = {&(menu->__valueToCount), &valueOccurrences};

    do {
        puts("> Available operations:\n");
        printf("  1 - Load binary tree from \"%s\" (key-value file)\n", menu->__keyValueFilePath);
        puts("  2 - Show binary tree in pre-order");
        puts("  3 - Count occurrences of the desired value");
        puts("  4 - Mirror binary tree");
        puts("  0 - Exit\n");

        printf("> Enter an operation: ");
        scanf("%d", &operation);

        switch (operation) {
        case 1:
            if (menu->__mirroredTree) {
                puts(
                    "\n> The binary tree was mirrored, "
                    "so it can not be loaded from the file again. "
                    "The function to compare has an invalid logic of greater and lower keys.\n"
                );
                break;
            };

            error = __loadKeyValueFile(menu);

            if (error) {
                puts("\n> An error occurred on try to load key-value file.\n");
            } else {
                puts("\n> Key-value file loaded into the binary tree.\n");
            };
            break;

        case 2:
            puts("\n> Binary tree content:\n");
            mapBTreePreOrder(menu->__binaryTree, &printInt, NULL);
            putchar('\n');
            break;

        case 3:
            putchar('\n');
            __requestValueToCount(menu);

            **(valueOccurrencesArr + 1) = 0;
            mapBTreePreOrder(menu->__binaryTree, &countValueOcurrences, valueOccurrencesArr);

            printf("\n> %d appears %d times.\n\n", **valueOccurrencesArr, **(valueOccurrencesArr + 1));
            break;

        case 4:
            mirrorBTree(menu->__binaryTree);
            menu->__mirroredTree = !menu->__mirroredTree;

            puts("\n> Binary tree mirrored.\n");
            break;

        case 0:
            break;

        default:
            puts("\n> Invalid operation! Try again...\n");
        }
    } while (operation != 0);
}

// Options
unsigned char __loadKeyValueFile(Menu* menu) {
    FILE* file;

    const  size_t lineLength = sizeof(int) + sizeof(char) + sizeof(int);
    char line[lineLength];

    KeyValue keyValue;


    file = fopen(menu->__keyValueFilePath, "rt");
    if (file == NULL) return 1;

    while (fgets(line, lineLength, file)) {
        if (!parseKeyValue(line, &keyValue)) {
            insertBTreeElement(
                menu->__binaryTree,
                &keyValue,
                sizeof(keyValue),
                &cmpKeyValue
            );
        };
    };

    fclose(file);

    return 0;
}

// Helpers
void __requestValueToCount(Menu* menu) {
    int valueToCount;
    int scannedFields;

    do {
        printf("> Enter the value to count: ");
        scannedFields = scanf("%d", &valueToCount);
        if (scannedFields != 1) puts("> Invalid value! Try again...");
    } while (scannedFields != 1);

    menu->__valueToCount = valueToCount;
}
