// 43920122_HOZ_LUCAS

#include "./xml.h"

#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "./test.xml"

int main() {
    FILE* file;

    file = fopen(FILE_PATH, "rt");
    if (file == NULL) {
        printf("> Error! An error occurred on open \"%s\" file.", FILE_PATH);
        return 1;
    };

    if (isXML(file)) {
        printf("> \"%s\" is a valid xml file.", FILE_PATH);
    } else {
        printf("> \"%s\" is not a valid xml file.", FILE_PATH);
    };

    fclose(file);

    return 0;
}
