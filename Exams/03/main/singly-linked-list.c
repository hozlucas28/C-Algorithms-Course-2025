
#include <stdlib.h>
#include <string.h>

#include "./singly-linked-list.h"

/* ---------- Singly Linked List ---------- */

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

// Getters
unsigned char getSListHead(
    SList* _list,
    void* store,
    const size_t sizeOfStore
) {
    if (*_list == NULL) return 1;
    if ((*_list)->__sizeOfData != sizeOfStore) return 1;

    memcpy(store, (*_list)->__data, sizeOfStore);

    return 0;
}

unsigned char isSListFull(
    SList* _list,
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

unsigned char isSListEmpty(SList* _list) {
    return *_list == NULL;
}

// Methods
unsigned char shiftSListElement(
    SList* _list,
    void* store,
    const size_t sizeOfStore
) {
    Node* nextNode;

    if (*_list == NULL) return 1;
    if ((*_list)->__sizeOfData != sizeOfStore) return 1;

    memcpy(store, (*_list)->__data, sizeOfStore);

    nextNode = (*_list)->__next;

    free((*_list)->__data);
    free(*_list);

    *_list = nextNode;

    return 0;
}

unsigned char insertSListElementTop(
    SList* _list,
    void* data,
    const size_t sizeOfData,
    const size_t maximumTop,
    int (*cmp)(const void* data, const void* element)
) {
    size_t counter = 0;

    int cmpValue;
    Node* prevNode = NULL;

    Node* newNode;

    SList* listOutOfRange;

    Node* nextNode;

    while (*_list != NULL && counter < maximumTop && (cmpValue = cmp(data, (*_list)->__data)) >= 0) {
        prevNode = *_list;
        _list = &(*_list)->__next;
        if (cmpValue != 0) counter++;

        while (*_list != NULL && cmp(prevNode->__data, (*_list)->__data) == 0) {
            prevNode = *_list;
            _list = &(*_list)->__next;
        };
    };

    if (counter == maximumTop) return 0;

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

    if (*_list != NULL) newNode->__next = *_list;
    *_list = newNode;

    listOutOfRange = _list;

    while (*listOutOfRange != NULL && counter < maximumTop) {
        prevNode = *listOutOfRange;
        listOutOfRange = &(*listOutOfRange)->__next;
        counter++;

        while (*listOutOfRange != NULL && cmp(prevNode->__data, (*listOutOfRange)->__data) == 0) {
            prevNode = *listOutOfRange;
            listOutOfRange = &(*listOutOfRange)->__next;
        };
    };

    while (*listOutOfRange != NULL) {
        nextNode = (*listOutOfRange)->__next;
        free((*listOutOfRange)->__data);
        free(*listOutOfRange);
        *listOutOfRange = nextNode;
    };

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
    SList* _list,
    void (*callback)(void* data, const size_t index, const void* params),
    const void* params
) {
    size_t index = 0;

    while (*_list != NULL) {
        callback((*_list)->__data, index, params);
        _list = &(*_list)->__next;
        index++;
    }
}
