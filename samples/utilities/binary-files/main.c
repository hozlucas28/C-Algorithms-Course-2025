
#include "./binary-files.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file;
    const char filePath[] = "./file.dat";

    const int numbers[] = {1, 3, 5, 7, 8, 9, 10};
    const size_t numbersLength = sizeof(numbers) / sizeof(*numbers);

    size_t amountOfData;

    int i;

    int number;

    const int newNumbers[] = {17, 21, 50};
    const size_t newNumbersIndexes[] = {0, 3, 5};
    const size_t newNumbersLength = sizeof(newNumbers) / sizeof(*newNumbers);

    file = fopen(filePath, "wb+");
    if (file == NULL) {
        printf("> Error! An error occurred on create \"%s\" file.\n", filePath);
        return 1;
    };

    fwrite(numbers, sizeof(*numbers), numbersLength, file);

    amountOfData = getAmountOfData(file, sizeof(*numbers));
    printf("> Amount of data: %d\n", (int)amountOfData);

    for (i = numbersLength - 1; i >= 0; i--) {
        if (getDataAt(file, sizeof(*numbers), &number, 1, i)) {
            printf(
                "> Error! An error occurred on getDataAt(0x%p, %d, 0x%p, %d, %d).\n",
                (void*)file,
                (int)sizeof(*numbers),
                (void*)&number,
                1,
                (int)i
            );

            break;
        };

        printf("\n> Data at index %02d: %02d.", (int)i, number);
    };

    putchar('\n');

    for (i = 0; i < newNumbersLength; i++) {
        if (writeDataAt(file, sizeof(*numbers), newNumbers + i, 1, *(newNumbersIndexes + i))) {
            printf(
                "> Error! An error occurred on writeDataAt(0x%p, %d, 0x%p, %d, %d).\n",
                (void*)file,
                (int)sizeof(*numbers),
                (void*)(newNumbers + i),
                1,
                (int)*(newNumbersIndexes + i)
            );

            break;
        };

        printf(
            "\n> Written data at index %02d: %02d.",
            (int)*(newNumbersIndexes + i),
            *(newNumbers + i)
        );
    };

    putchar('\n');

    for (i = 0; i < numbersLength; i++) {
        if (getDataAt(file, sizeof(*numbers), &number, 1, i)) {
            printf(
                "> Error! An error occurred on getDataAt(0x%p, %d, 0x%p, %d, %d).\n",
                (void*)file,
                (int)sizeof(*numbers),
                (void*)&number,
                1,
                (int)i
            );

            break;
        };

        printf("\n> Data at index %02d: %02d.", (int)i, number);
    };

    fclose(file);

    remove(filePath);

    return 0;
}
