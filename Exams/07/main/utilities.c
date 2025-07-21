
#include <stdio.h>

#include "./cmps.h"
#include "./stack.h"
#include "./structs.h"
#include "./parsers.h"
#include "./utilities.h"
#include "./binary-tree.h"

unsigned char validateFile(
    const char* filePath,
    const char* tagsFilePath,
    void (*onValidLine)(const char* line, const size_t lineIndex, void* params),
    void (*onInvalidLine)(const char* line, const size_t lineIndex, void* params),
    void* params
) {
    BTree tags;

    unsigned char error;

    FILE* file;
    Stack closeTags;

    char line[LINE_LENGTH];
    const size_t lineLength = sizeof(line) / sizeof(*line);

    char* lineHead;
    unsigned char isValidLine;

    Tag tag;

    char closeTag;
    size_t lineIndex = 0;

    newBTree(&tags);

    error = loadTagsOnBTree(&tags, tagsFilePath);
    if (error) return 1;

    file = fopen(filePath, "rt");
    if (file == NULL) {
        destroyBTree(&tags);
        return 1;
    };

    while (fgets(line, lineLength, file)) {
        lineHead = line;
        isValidLine = 1;

        newStack(&closeTags);

        while (*lineHead != '\n' && *lineHead != '\0') {
            tag.open = *lineHead;

            error = getBTreeElement(&tags, &tag, sizeof(tag), &cmpTags);
            if (!error) {
                unshiftStackElement(&closeTags, &(tag.close), sizeof(tag.close));
                lineHead++;
                continue;
            };

            error = shiftStackElement(&closeTags, &closeTag, sizeof(closeTag));
            if (error || closeTag != *lineHead) {
                isValidLine = 0;
                break;
            };

            lineHead++;
        };

        if (isValidLine && isStackEmpty(&closeTags)) {
            onValidLine(line, lineIndex, params);
        } else {
            onInvalidLine(line, lineIndex, params);
        };

        destroyStack(&closeTags);

        lineIndex++;
    };

    destroyBTree(&tags);

    fclose(file);

    return 0;
}

unsigned char loadTagsOnBTree(
    BTree* tree,
    const char* filePath
) {
    FILE* file;

    char line[TAG_LINE_LENGTH];
    const size_t lineLength = sizeof(line) / sizeof(*line);

    Tag tag;

    file = fopen(filePath, "rt");
    if (file == NULL) return 1;

    while (fgets(line, lineLength, file)) {
        if (parseTag(line, &tag)) continue;
        if (insertBTreeElement(tree, &tag, sizeof(tag), &cmpTags)) break;
    };

    fclose(file);

    return 0;
}
