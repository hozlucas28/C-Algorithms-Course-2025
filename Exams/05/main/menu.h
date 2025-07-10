#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct {
    int __failPercentage;
    char __batchesFile[256];
    char __approvedBatchesFile[256];
    char __observedBatchesFile[256];
    char __approvedBatchesFileName[64];
    char __observedBatchesFileName[64];
} Menu;

// Constructor
unsigned char newMenu(
    Menu* menu,
    char* batchesFile,
    char* approvedBatchesFileName,
    char* observedBatchesFileName
);

// Destructor
void destroyMenu(Menu* menu);

// Methods
void initMenu(Menu* menu);

void __requestFailPercentage(Menu* menu);
unsigned char __processBatches(Menu* menu);
unsigned char __showBatches(Menu* menu);
unsigned char __showApprovedBatches(Menu* menu);
unsigned char __showObservedBatches(Menu* menu);

#endif // MENU_H_INCLUDED
