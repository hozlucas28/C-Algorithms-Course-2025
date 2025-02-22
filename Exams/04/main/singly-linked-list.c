
#include <string.h>

#include "./singly-linked-list.h"

// Constructor
void newSList(SList* _list) {
    *_list = NULL;
}

// Destructor
void destroySList(SList* _list) {
    SList* subList;

    while (*_list != NULL) {
        subList = &(*_list)->__next;
        free((*_list)->__data);
        free(*_list);
        _list = subList;
    };
}

// Getters
unsigned char getSListHead(
    const SList* _list,
    void* store,
    const size_t sizeOfStore
) {
    if (*_list == NULL) return 1;

    memcpy(
        store,
        (*_list)->__data,
        sizeOfStore
    );

    return 0;
}

unsigned char getSListTail(
    const SList* _list,
    void* store,
    const size_t sizeOfStore
) {
    if (*_list == NULL) return 1;

    while ((*_list)->__next != NULL) {
        _list = &(*_list)->__next;
    };

    memcpy(
        store,
        (*_list)->__data,
        sizeOfStore
    );

    return 0;
}

// Methods
unsigned char insertSListElementInOrder(
    SList* _list,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* data, const void* element)
) {
    Node* newNode;

    newNode = malloc(sizeof(Node));
    if (newNode == NULL) return 1;

    newNode->__data = malloc(sizeOfData);
    if (newNode->__data == NULL) {
        free(newNode);
        return 1;
    };

    memcpy(newNode->__data, data, sizeOfData);
    newNode->__sizeOfData = sizeOfData;
    newNode->__next = NULL;

    while (*_list != NULL && cmp(data, (*_list)->__data) > 0) {
        _list = &(*_list)->__next;
    };

    if (*_list != NULL) newNode->__next = *_list;
    *_list = newNode;

    return 0;
}

void sortSList(
    SList* _list,
    int (*cmp)(const void* a, const void* b)
) {
    void* oldNodeData;
    size_t oldNodeSizeOfData;

    SList* nextNode;
    SList* minorNode;

    if (*_list == NULL) return;

    while ((*_list)->__next != NULL) {
        nextNode = &(*_list)->__next;
        minorNode = _list;

        while (*nextNode != NULL) {
            if (cmp((*minorNode)->__data, (*nextNode)->__data) > 0) minorNode = nextNode;
            nextNode = &(*nextNode)->__next;
        };

        if (*minorNode != *_list) {
            oldNodeData = (*_list)->__data;
            oldNodeSizeOfData = (*_list)->__sizeOfData;

            (*_list)->__data = (*minorNode)->__data;
            (*_list)->__sizeOfData = (*minorNode)->__sizeOfData;

            (*minorNode)->__data = oldNodeData;
            (*minorNode)->__sizeOfData = oldNodeSizeOfData;
        };

        _list = &(*_list)->__next;
    };
}

void mapSList(
    const SList* _list,
    void (*callback)(void* element, const size_t index)
) {
    size_t index = 0;

    while (*_list != NULL) {
        callback((*_list)->__data, index);
        _list = &(*_list)->__next;
        index++;
    };
}

void __reverseMapSList(
    const SList* _list,
    const size_t currentIndex,
    void (*callback)(void* element, const size_t index)
) {
    if (*_list == NULL) return;

    __reverseMapSList(&(*_list)->__next, currentIndex + 1, callback);
    callback((*_list)->__data, currentIndex);
}

void reverseMapSList(
    const SList* _list,
    void (*callback)(void* element, const size_t index)
) {
    __reverseMapSList(_list, 0, callback);
}
