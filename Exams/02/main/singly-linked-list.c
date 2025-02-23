
#include <stdlib.h>
#include <string.h>

#include "./singly-linked-list.h"

/* ---- Singly Linked List ---- */

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
unsigned char isSListFull(
    const SList* _list,
    const size_t sizeOfData
) {
    Node* newNode;

    newNode = malloc(sizeof(Node));
    if (newNode == NULL) return 1;

    newNode->__data = malloc(sizeOfData);
    if (newNode->__data == NULL) {
        free(newNode);
        return 1;
    };

    free(newNode->__data);
    free(newNode);

    return 0;
}

unsigned char isSListEmpty(const SList* _list) {
    return *_list == NULL;
}

// Methods
unsigned char insertSListElementInOrder(
    SList* _list,
    void* data,
    const size_t sizeOfData,
    int (*cmp)(const void* data, const void* dataInList)
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

    while (*_list != NULL && cmp(data, (*_list)->__data) < 0) {
        _list = &(*_list)->__next;
    };

    if (*_list != NULL) newNode->__next = *_list;
    *_list = newNode;

    return 0;
}

void mapSList(
    SList* _list,
    void (*callback)(void* element)
) {
    while (*_list != NULL) {
        callback((*_list)->__data);
        _list = &(*_list)->__next;
    };
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

void reverSList(SList* _list) {
    Node* nextNode;
    Node* prevNode = NULL;

    if (*_list == NULL) return;

    while (*_list != NULL) {
        nextNode = (*_list)->__next;
        (*_list)->__next = prevNode;
        prevNode = *_list;
        *_list = nextNode;
    };

    *_list = prevNode;
}
