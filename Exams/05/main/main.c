#include <stdio.h>
#include <stdlib.h>

#define BATCHES_FILE "entrada.bin"
#define APPROVED_BATCHES_FILE_NAME "lotesAprobados"
#define OBSERVED_BATCHES_FILE_NAME "lotesObservados"

#include "./menu.h"
#include "./test.h"

int main() {
    Menu menu;
    unsigned char error;

    error = createTestFile(BATCHES_FILE);
    if (error) {
        printf("> An error occurred on try to create the test file.");
        return 1;
    };

    error = newMenu(
        &menu,
        BATCHES_FILE,
        APPROVED_BATCHES_FILE_NAME,
        OBSERVED_BATCHES_FILE_NAME
    );

    if (error) {
        printf("> An error occurred on try to create the menu.");
        return 1;
    };

    initMenu(&menu);

    destroyMenu(&menu);

    return 0;
}
