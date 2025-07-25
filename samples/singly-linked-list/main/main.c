
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>

void printInt(void* data, const size_t sizeOfData, const size_t index, const void* params) {
    printf("%d ", *(int*)data);
}

int cmpIntegers(const void* data, const void* dataInList) {
    int* _data = (int*)data;
    int* _dataInList = (int*)dataInList;

    return *_data - *_dataInList;
}

int main() {
    int i;

    int numbers01[] = {1, 3, 5, 7, 8, 9, 10};
    const int numbers01Length = sizeof(numbers01) / sizeof(*(numbers01 + i));

    int numbers02[] = {1, 1, 3, 5, 7, 1, 9, 6};
    const int numbers02Length = sizeof(numbers02) / sizeof(*(numbers02 + i));

    SList _list;
    newSList(&_list);

    for (i = 0; i < numbers01Length; i++) {
        unshiftSListElement(&_list, numbers01 + i, sizeof(*(numbers01 + i)));
    };

    printf("> [ ");
    mapSList(&_list, &printInt, NULL);
    printf("]\n");

    for (i = 0; i < numbers01Length; i++) {
        pushSListElement(&_list, numbers01 + i, sizeof(*(numbers01 + i)));
    };

    printf("> [ ");
    mapSList(&_list, &printInt, NULL);
    printf("]\n");

    insertSListElementAt(
        &_list,
        numbers01 + numbers01Length - 1,
        sizeof(*(numbers01 + numbers01Length - 1)),
        numbers01Length
    );

    printf("> [ ");
    mapSList(&_list, &printInt, NULL);
    printf("]\n");

    clipAt(&_list, 3);

    printf("> [ ");
    mapSList(&_list, &printInt, NULL);
    printf("]\n");

    destroySList(&_list);

    newSList(&_list);

    puts("\n");

    for (i = 0; i < numbers02Length; i++) {
        insertSListElementTop(&_list, numbers02 + i, sizeof(*(numbers02 + i)), 5, &cmpIntegers);
    };

    printf("> [ ");
    mapSList(&_list, &printInt, NULL);
    printf("]\n");

    destroySList(&_list);

    return 0;
}
