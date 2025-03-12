
#include <stdio.h>
#include <stdlib.h>

int main() {
    int operation;

    puts(
        "> Available operations:\n\n"
        "  1 - XXX\n"
        "  X - XXX\n"
        "  0 - Exit\n"
    );

    printf("> Select an operation: ");
    fflush(stdin);
    scanf("%d", &operation);

    while (operation != 0) {
        switch (operation) {
        case 1:
            // TODO
            puts("\n> 1.");
            break;

        default:
            // TODO
            puts("\n> Default.");
        }

        puts(
            "\n> Available operations:\n\n"
            "  1 - XXX\n"
            "  X - XXX\n"
            "  0 - Exit\n"
        );

        printf("> Select an operation: ");
        fflush(stdin);
        scanf("%d", &operation);
    };

    return 0;
}
