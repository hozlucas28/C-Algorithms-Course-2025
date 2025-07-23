
#include <stdlib.h>
#include <string.h>

#include "./singly-linked-list.h"

// Constructor
void newSList(SList* _list) {
    *_list = NULL;
}

// Destructor
void destroySList(SList* _list) {
    Node* nextNode;

    while (*_list != NULL) {
        nextNode = (*_list)->__next;
        free((*_list)->__data);
        free(*_list);
        *_list = nextNode;
    };
}

// Methods
unsigned char insertSListTop(
    SList* _list,
    void* data,
    const size_t sizeOfData,
    const size_t top,
    int (*cmp)(const void* a, const void* b)
) {
    int cmpValue = -1;
    size_t counter = 0;

    Node* newNode;

    SList subList;
    Node* nextNode;

    while (*_list != NULL && (cmpValue = cmp(data, (*_list)->__data) > 0)) {
        _list = &(*_list)->__next;
        counter++;
    };

    if (counter >= top && cmpValue != 0) return 0;

    newNode = malloc(sizeof(Node));
    if (newNode == NULL) return 1;

    newNode->__data = malloc(sizeOfData);
    if (newNode->__data == NULL) {
        free(newNode);
        return 1;
    };

    memcpy(newNode->__data, data, sizeOfData);
    newNode->__sizeOfData = sizeOfData;
    newNode->__next = *_list;

    *_list = newNode;

    while (*_list != NULL && counter < top) {
        while (
            (*_list)->__next != NULL &&
            cmp((*_list)->__data, (*_list)->__next->__data) == 0
        ) {
            _list = &(*_list)->__next;
            counter++;
        };

        _list = &(*_list)->__next;
        counter++;
    };

    if (*_list != NULL) {
        subList = *_list;
        *_list = NULL;

        while (subList != NULL) {
            nextNode = subList->__next;
            free(subList->__data);
            free(subList);
            subList = nextNode;
        };
    };

    return 0;
}

void mapSList(
    SList* _list,
    void (*callback)(void* data, const size_t sizeOfData, const size_t index, void* params),
    void* params
) {
    size_t index = 0;

    while (*_list != NULL) {
        callback((*_list)->__data, (*_list)->__sizeOfData, index, params);
        _list = &(*_list)->__next;
        index++;
    };
}
