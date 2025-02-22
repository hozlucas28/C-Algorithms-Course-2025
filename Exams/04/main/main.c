
#include <stdio.h>

#include "./singly-linked-list.h"
#include "./structs.h"
#include "./utilities.h"

int main(const int argsLength, char* args[]) {
    SList words;

    char* filePath;

    int operation;
    Word word;

    if (argsLength != 2) {
        printf(
            "> Error! Invalid number of program arguments (expected %d, but received %d).",
            2,
            argsLength
        );

        return 1;
    };

    newSList(&words);

    filePath = *(args + 1);

    if (storeWords(&words, filePath)) {
        printf("> Error! An error occurred on read \"%s\" file.", filePath);
        destroySList(&words);
        return 1;
    };

    sortSList(&words, cmpWordsAppearances);

    puts(
        "> Available operations:\n\n"
        "  1 - Show words (ascending order)\n"
        "  2 - Show words (desending order)\n"
        "  3 - Show word with most appearances\n"
        "  4 - Show word with lest appearances\n"
        "  0 - Exit\n"
    );

    printf("> Select an operation: ");
    scanf("%d", &operation);

    while (operation != 0) {
        switch (operation) {
        case 1:
            putchar('\n');
            reverseMapSList(&words, &printWord);
            break;

        case 2:
            putchar('\n');
            mapSList(&words, &printWord);
            break;

        case 3:
            getSListHead(&words, &word, sizeof(word));
            printf("\n> \"%s\" is the word with most appearances.\n", word.word);
            break;

        case 4:
            getSListTail(&words, &word, sizeof(word));
            printf("\n> \"%s\" is the word with least appearances.\n", word.word);
            break;

        default:
            puts("\n> Error! Invalid operation, try again...");
        };

        puts(
            "\n> Available operations:\n\n"
            "  1 - Show words (ascending order)\n"
            "  2 - Show words (descending order)\n"
            "  3 - Show word with most appearances\n"
            "  4 - Show word with lest appearances\n"
            "  0 - Exit\n"
        );

        printf("> Select an operation: ");
        scanf("%d", &operation);
    };

    destroySList(&words);

    return 0;
}
