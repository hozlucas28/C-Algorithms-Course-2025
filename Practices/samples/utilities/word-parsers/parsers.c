
#include <stdio.h>
#include <string.h>

#include "./parsers.h"

size_t parseWordsBySeps(
    char* line,
    const char* separators,
    unsigned char (*onGetWord)(const char* word, const void* params),
    const void* params
) {
    char* _word;

    char word[WORD_LENGTH];
    unsigned char shouldCount = 0;
    size_t words = 0;

    _word = strtok(line, separators);

    while (_word != NULL) {
        strcpy(word, _word);
        shouldCount = onGetWord(word, params);
        _word = strtok(NULL, separators);
        words = words + 1 - !!shouldCount;
    };

    return words;
}

int parseBrakedWordsFromFile(
    const char* filePath,
    const char* wordSeparators,
    unsigned char (*onGetWord)(const char* word, const void* params),
    const void* params
) {
    FILE* file;

    char line[LINE_LENGTH];

    char* _word;

    char word[WORD_LENGTH];
    unsigned char shouldCount = 0;
    size_t words = 0;

    file = fopen(filePath, "rt");
    if (file == NULL) return -1;

    while (fgets(line, LINE_LENGTH, file)) {
        _word = strtok(line, wordSeparators);

        while (_word != NULL) {
            strcpy(word, _word);

            if (
                !(_word = strtok(NULL, wordSeparators)) &&
                fgets(line, LINE_LENGTH, file) &&
                !strchr(wordSeparators, *line)
            ) {
                _word = strtok(line, wordSeparators);
                strcat(word, _word);
                _word = strtok(NULL, wordSeparators);
            };

            shouldCount = onGetWord(word, params);
            words = words + 1 - !!shouldCount;
        };
    };

    fclose(file);

    return words;
}



