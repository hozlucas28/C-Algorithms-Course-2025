
#include <stdio.h>
#include <stdlib.h>

#include "./callbacks.h"
#include "./utilities.h"

#define FILE_PATH "./file.txt"
#define TAGS_FILE_PATH "./tags.txt"

int main() {
    unsigned char error = validateFile(
        FILE_PATH,
        TAGS_FILE_PATH,
        &onValidLine,
        &onInvalidLine,
        NULL
    );

    if (error) {
        puts("> An error occurred on try to validate the file.");
    };

    return 0;
}
