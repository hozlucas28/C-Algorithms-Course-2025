#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "./binary-tree.h"

typedef struct {
    int __valueToCount;
    BTree* __binaryTree;
    const char* __keyValueFilePath;
    unsigned char __mirroredTree;
} Menu;

// Constructor
void newMenu(
    Menu* menu,
    BTree* binaryTree,
    const char* keyValueFilePath
);

// Destructor
void destroyMenu(Menu* menu);

// Methods
void initMenu(Menu* menu);

// Options
unsigned char __loadKeyValueFile(Menu* menu);

// Helpers
void __requestValueToCount(Menu* menu);

#endif // MENU_H_INCLUDED
