
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "./singly-linked-list.h"
#include "./structs.h"
#include "./utilities.h"

unsigned char storeWords(
    SList* words,
    const char* filePath
) {
    FILE* file;
    char line[LINE_LENGTH];

    Word word;
    char* _word;

    file = fopen(filePath, "rt");
    if (file == NULL) return 1;

    while (fgets(line, LINE_LENGTH, file)) {
        _word = strtok(line, DELIMITERS);

        while (_word != NULL) {
            strcpy(word.word, _word);
            word.appearances = 1;

            toLower(word.word);

            insertSListElementInOrder(
                words,
                &word,
                sizeof(word),
                &cmpWords
            );

            _word = strtok(NULL, DELIMITERS);
        };
    };

    fclose(file);

    return 0;
}

void toLower(char* str) {
    while (*str != '\0') {
        *str = tolower(*str);
        str++;
    };
}

void printWord(void* word, const size_t index) {
    Word* _word = (Word*)word;
    printf("> %-*s [%d]\n", WORD_LENGTH, _word->word, (int)_word->appearances);
}

int cmpWords(const void* word, const void* wordInList) {
    Word* _word = (Word*)word;
    Word* _wordInList = (Word*)wordInList;

    const int cmpValue = strcmp(_word->word, _wordInList->word);

    if (!cmpValue) _wordInList->appearances++;

    return cmpValue;
}

int cmpWordsAppearances(const void* word01, const void* word02) {
    Word* _word01 = (Word*)word01;
    Word* _word02 = (Word*)word02;

    return _word02->appearances - _word01->appearances;
}
