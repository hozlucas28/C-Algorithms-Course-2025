
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./menu.h"
#include "./queue.h"
#include "./parsers.h"
#include "./structs.h"

// Constructor
unsigned char newMenu(
    Menu* menu,
    char* batchesFile,
    char* approvedBatchesFileName,
    char* observedBatchesFileName
) {
    menu->__failPercentage = -1;

    strcpy(menu->__batchesFile, batchesFile);
    strcpy(menu->__approvedBatchesFileName, approvedBatchesFileName);
    strcpy(menu->__observedBatchesFileName, observedBatchesFileName);

    return 0;
}

// Destructor
void destroyMenu(Menu* menu) {
}

// Methods
void initMenu(Menu* menu) {
    int operation = 0;
    unsigned char error = 0;

    do {
        puts("> Available operations:\n");
        puts("  1 - Set fail percentage");
        printf("  2 - Process \"%s\" batches file\n", menu->__batchesFile);
        printf("  3 - Show \"%s\" batches file\n", menu->__batchesFile);
        puts("  4 - Show approved and observed batches");
        puts("  0 - Exit\n");

        printf("> Enter an operation: ");
        scanf("%d", &operation);
        fflush(stdin);

        switch (operation) {
        case 1:
            __requestFailPercentage(menu);
            putchar('\n');
            break;

        case 2:
            putchar('\n');

            error = __processBatches(menu);
            if (error) {
                puts("> An error occurred on try to process batches.\n");
            } else {
                puts("> Batches processed.\n");
            };
            break;

        case 3:
            putchar('\n');

            error = __showBatches(menu);
            if (error) puts("> An error occurred on try to show batches.");
            putchar('\n');

            break;

        case 4:
            puts("\n> Approved batches:\n");

            error = __showApprovedBatches(menu);
            if (error) puts("> An error occurred on try to show approved batches.");

            puts("\n> Observed batches:\n");

            error = __showObservedBatches(menu);
            if (error) puts("> An error occurred on try to show observed batches.\n");

            putchar('\n');
            break;

        case 0:
            break;

        default:
            puts("> Invalid operation! Try again...\n");
            break;
        }
    } while (operation != 0);
}

void __requestFailPercentage(Menu* menu) {
    int percentage = -1;

    do {
        printf("\n> Enter the fail percentage: ");
        scanf("%d", &percentage);
        fflush(stdin);

        if (percentage < 0) puts("> Invalid fail percentage! Try again...");
    } while (percentage < 0);

    menu->__failPercentage = percentage;
    sprintf(menu->__approvedBatchesFile, "%s-%d.txt", menu->__approvedBatchesFileName, percentage);
    sprintf(menu->__observedBatchesFile, "%s-%d.txt", menu->__observedBatchesFileName, percentage);
}

unsigned char __processBatches(Menu* menu) {
    FILE* batchesFile;
    FILE* approvedBatchesFile;
    FILE* observedBatchesFile;

    Queue okProducts;
    Queue failProducts;

    size_t totalProducts = 0;
    size_t totalFailProducts = 0;

    ProductControl productCtrl;
    ProductControl auxProductCtrl = {"", -1, ""};

    if (menu->__failPercentage < 0) return 1;

    batchesFile = fopen(menu->__batchesFile, "rb");
    if (batchesFile == NULL) return 1;

    approvedBatchesFile = fopen(menu->__approvedBatchesFile, "wt");
    if (approvedBatchesFile == NULL) {
        fclose(batchesFile);
        return 1;
    };

    observedBatchesFile = fopen(menu->__observedBatchesFile, "wt");
    if (observedBatchesFile == NULL) {
        fclose(batchesFile);
        fclose(approvedBatchesFile);
        return 1;
    };

    newQueue(&okProducts);
    newQueue(&failProducts);

    while (fread(&productCtrl, sizeof(productCtrl), 1, batchesFile)) {
        if (strcmp(auxProductCtrl.batchCode, productCtrl.batchCode) != 0) {
            if (totalFailProducts < totalProducts * (menu->__failPercentage * 0.01)) {
                while (!shiftQueueElement(&okProducts, &auxProductCtrl, sizeof(auxProductCtrl))) {
                    fprintf(
                        approvedBatchesFile,
                        "%s,%d,%s\n",
                        auxProductCtrl.batchCode,
                        auxProductCtrl.id,
                        auxProductCtrl.result
                    );
                };

                while (!shiftQueueElement(&failProducts, &auxProductCtrl, sizeof(auxProductCtrl))) {
                    fprintf(
                        approvedBatchesFile,
                        "%s,%d,%s\n",
                        auxProductCtrl.batchCode,
                        auxProductCtrl.id,
                        auxProductCtrl.result
                    );
                };
            } else {
                while (!shiftQueueElement(&failProducts, &auxProductCtrl, sizeof(auxProductCtrl))) {
                    fprintf(
                        observedBatchesFile,
                        "%s,%d,%s\n",
                        auxProductCtrl.batchCode,
                        auxProductCtrl.id,
                        auxProductCtrl.result
                    );
                };

                while (!shiftQueueElement(&okProducts, &auxProductCtrl, sizeof(auxProductCtrl))) {
                    fprintf(
                        observedBatchesFile,
                        "%s,%d,%s\n",
                        auxProductCtrl.batchCode,
                        auxProductCtrl.id,
                        auxProductCtrl.result
                    );
                };
            };

            totalProducts = 0;
            totalFailProducts = 0;
        };

        totalProducts++;

        if (strcmp(productCtrl.result, "OK") == 0) {
            pushQueueElement(&okProducts, &productCtrl, sizeof(productCtrl));
        } else if (strcmp(productCtrl.result, "FALLA") == 0) {
            totalFailProducts++;
            pushQueueElement(&failProducts, &productCtrl, sizeof(productCtrl));
        };

        strcpy(auxProductCtrl.batchCode, productCtrl.batchCode);
    };

    if (totalFailProducts < totalProducts * (menu->__failPercentage * 0.01)) {
        while (!shiftQueueElement(&okProducts, &auxProductCtrl, sizeof(auxProductCtrl))) {
            fprintf(
                approvedBatchesFile,
                "%s,%d,%s\n",
                auxProductCtrl.batchCode,
                auxProductCtrl.id,
                auxProductCtrl.result
            );
        };

        while (!shiftQueueElement(&failProducts, &auxProductCtrl, sizeof(auxProductCtrl))) {
            fprintf(
                approvedBatchesFile,
                "%s,%d,%s\n",
                auxProductCtrl.batchCode,
                auxProductCtrl.id,
                auxProductCtrl.result
            );
        };
    } else {
        while (!shiftQueueElement(&failProducts, &auxProductCtrl, sizeof(auxProductCtrl))) {
            fprintf(
                observedBatchesFile,
                "%s,%d,%s\n",
                auxProductCtrl.batchCode,
                auxProductCtrl.id,
                auxProductCtrl.result
            );
        };

        while (!shiftQueueElement(&okProducts, &auxProductCtrl, sizeof(auxProductCtrl))) {
            fprintf(
                observedBatchesFile,
                "%s,%d,%s\n",
                auxProductCtrl.batchCode,
                auxProductCtrl.id,
                auxProductCtrl.result
            );
        };
    };

    destroyQueue(&okProducts);
    destroyQueue(&failProducts);

    fclose(batchesFile);
    fclose(approvedBatchesFile);
    fclose(observedBatchesFile);

    return 0;
}

unsigned char __showBatches(Menu* menu) {
    FILE* file;
    ProductControl productCtrl;

    if (menu->__failPercentage < 0) return 1;

    file = fopen(menu->__batchesFile, "rb");
    if (file == NULL) return 1;

    while (fread(&productCtrl, sizeof(productCtrl), 1, file)) {
        printf(
            "> [ %-4s | %02d | %-5s ]\n",
            productCtrl.batchCode,
            productCtrl.id,
            productCtrl.result
        );
    };

    fclose(file);

    return 0;
}

unsigned char __showApprovedBatches(Menu* menu) {
    FILE* file;
    char line[256];

    unsigned char error;
    ProductControl productCtrl;

    if (menu->__failPercentage < 0) return 1;

    file = fopen(menu->__approvedBatchesFile, "rt");
    if (file == NULL) return 1;

    while (fgets(line, sizeof(line), file)) {
        error = parseProductControl(line, &productCtrl);
        if (error) continue;

        printf(
            "> [ %-4s | %02d | %-5s ]\n",
            productCtrl.batchCode,
            productCtrl.id,
            productCtrl.result
        );
    };

    fclose(file);

    return 0;
}

unsigned char __showObservedBatches(Menu* menu) {
    FILE* file;
    char line[256];

    unsigned char error;
    ProductControl productCtrl;

    if (menu->__failPercentage < 0) return 1;

    file = fopen(menu->__observedBatchesFile, "rt");
    if (file == NULL) return 1;

    while (fgets(line, sizeof(line), file)) {
        error = parseProductControl(line, &productCtrl);
        if (error) continue;

        printf(
            "> [ %-4s | %02d | %-5s ]\n",
            productCtrl.batchCode,
            productCtrl.id,
            productCtrl.result
        );
    };

    fclose(file);

    return 0;
}
