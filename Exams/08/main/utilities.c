
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "./cmps.h"
#include "./macros.h"
#include "./binary-tree.h"

unsigned char loadBTree(
    BTree* tree,
    const char* filePath
) {
    FILE* file;

    char line[LINE_LENGTH];
    const size_t lineLength = sizeof(line) / sizeof(*line);

    char word[WORD_LENGTH];
    const size_t wordLength = sizeof(word) / sizeof(*word);

    char* _line;
    size_t wordOffset;

    file = fopen(filePath, "rt");
    if (file == NULL) return 1;

    *word = '\0';

    while (fgets(line, lineLength, file)) {
        _line = line;

        while (*_line != '\0') {
            while (*_line != '\0' && !isalnum(*_line)) {
                _line++;
            };

            if (*word == '\0') wordOffset = 0;

            while (isalnum(*_line) && wordOffset < (wordLength - 1)) {
                *(word + wordOffset) = *_line;
                _line++;
                wordOffset++;
            };

            *(word + wordOffset) = '\0';

            if (*_line != '\n' && *_line != '\0') {
                insertBTreeElement(tree, word, wordLength, &cmpWords);
                *word = '\0';
            };
        };
    };

    if (*word != '\0') insertBTreeElement(tree, word, wordLength, &cmpWords);

    fclose(file);

    return 0;
}
