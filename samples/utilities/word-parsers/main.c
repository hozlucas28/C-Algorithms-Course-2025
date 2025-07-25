
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./parsers.h"

unsigned char printWord(const char* word, const void* params) {
    printf("> \"%s\"\n", word);
    return 0;
}

int main() {
    char line[] = "Hello world! My name is Lucas.";
    const char separators[] = " !,.\n\t";

    const char filePath[] = "./book.txt";

    int words;

    words = parseWordsBySeps(line, separators, &printWord, NULL);
    printf("\n> Total words: %d.\n\n", words);

    words = parseBrakedWordsFromFile(filePath, separators, &printWord, NULL);
    if (words == -1) {
        printf("\n> Error! An error occurred on parse braked words from file.");
        return 0;
    };

    printf("\n> Total words: %d.", words);

    return 0;
}


