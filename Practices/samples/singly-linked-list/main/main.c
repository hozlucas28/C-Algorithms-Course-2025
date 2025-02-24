
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

void printInt(const void* element) {
    printf("%d ", *(int*)element);
}

int main() {
    int i;

    int numbers[] = {1, 3, 5, 7, 8, 9 , 10};
    const int numbersLength = sizeof(numbers) / sizeof(*(numbers + i));

    SList _list;
    newSList(&_list);

    for (i = 0; i < numbersLength; i++) {
        unshiftSListElement(&_list, numbers + i, sizeof(*(numbers + i)));
    };

    printf("> [ ");
    mapSList(&_list, &printInt);
    printf("]\n");

    for (i =0; i < numbersLength; i++) {
        pushSListElement(&_list, numbers + i, sizeof(*(numbers + i)));
    };

    printf("> [ ");
    mapSList(&_list, &printInt);
    printf("]\n");

    insertSListElementAt(
        &_list,
        numbers + numbersLength - 1,
        sizeof(*(numbers + numbersLength - 1)),
        numbersLength
    );

    printf("> [ ");
    mapSList(&_list, &printInt);
    printf("]\n");

    destroySList(&_list);

    return 0;
}
