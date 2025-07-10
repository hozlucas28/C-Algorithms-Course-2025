
#include <stdio.h>

#include "./structs.h"
#include "./test.h"

unsigned char createTestFile(char* filePath) {
    FILE* file;

    ProductControl records[] = {
        {"L001", 1, "OK"},
        {"L001", 4, "OK"},
        {"L001", 5, "OK"},
        {"L001", 3, "OK"},
        {"L001", 2, "FALLA"},
        {"L002", 1, "FALLA"},
        {"L003", 3, "OK"},
        {"L003", 4, "OK"},
        {"L004", 6, "FALLA"},
        {"L004", 7, "OK"},
        {"L004", 2, "FALLA"},
        {"L004", 9, "OK"},
        {"L005", 2, "OK"},
        {"L005", 5, "OK"},
        {"L005", 14, "FALLA"},
        {"L005", 21, "FALLA"},
        {"L005", 3, "OK"},
        {"L006", 1, "FALLA"},
        {"L006", 3, "FALLA"},
        {"L006", 34, "FALLA"},
        {"L006", 53, "FALLA"},
        {"L006", 36, "FALLA"},
        {"L006", 7, "FALLA"},
        {"L006", 9, "FALLA"},
        {"L006", 8, "FALLA"},
        {"L006", 12, "OK"},
        {"L006", 11, "FALLA"},
    };

    file = fopen(filePath, "wb");
    if (file == NULL) return 1;

    fwrite(records, sizeof(*records), sizeof(records) / sizeof(*records), file);

    fclose(file);

    return 0;
}
