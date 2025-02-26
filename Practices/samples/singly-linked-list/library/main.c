
#include <string.h>

#include "./main.h"

// Constructor
void newSList(SList* _list) {
    *_list = NULL;
}

// Destroyer
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

    memcpy(
        store,
        (*_list)->__data,
        sizeOfStore
    );

    return 0;
}

unsigned char getSListTail(
    SList* _list,
    void* store,
    const size_t sizeOfStore
) {
    if (*_list == NULL) return 1;

    while ((*_list)->__next != NULL) {
        _list = &(*_list)->__next;
    };

    if ((*_list)->__sizeOfData != sizeOfStore) return 1;

    memcpy(
        store,
        (*_list)->__data,
        sizeOfStore
    );

    return 0;
}

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
unsigned char unshiftSListElement(
    SList* _list,
    void* data,
    const size_t sizeOfData
) {
    Node* newHead;

    newHead = malloc(sizeof(Node));
    if (newHead == NULL) return 1;

    newHead->__data = malloc(sizeOfData);
    if (newHead->__data == NULL) {
        free(newHead);
        return 1;
    };

    memcpy(newHead->__data, data, sizeOfData);
    newHead->__sizeOfData = sizeOfData;
    newHead->__next = *_list != NULL ? *_list : NULL;

    *_list = newHead;

    return 0;
}

unsigned char pushSListElement(
    SList* _list,
    void* data,
    const size_t sizeOfData
) {
    Node* newTail;

    while (*_list != NULL) {
        _list = &(*_list)->__next;
    };

    newTail = malloc(sizeof(Node));
    if (newTail == NULL) return 1;

    newTail->__data = malloc(sizeOfData);
    if (newTail->__data == NULL) {
        free(newTail);
        return 1;
    };

    memcpy(newTail->__data, data, sizeOfData);
    newTail->__sizeOfData = sizeOfData;
    newTail->__next = NULL;

    *_list = newTail;

    return 0;
}

unsigned char insertSListElementAt(
    SList* _list,
    void* data,
    const size_t sizeOfData,
    const size_t index
) {
    Node* newNode;

    size_t currentIndex = 0;

    while (*_list != NULL && currentIndex != index) {
        _list = &(*_list)->__next;
        currentIndex++;
    };

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

    return 0;
}

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

unsigned char insertSListElementTop(
    SList* _list,
    void* data,
    const size_t sizeOfData,
    const size_t maximumTop,
    int (*cmp)(const void* data, const void* element)
) {
    size_t counter = 0;

    Node* newNode;

    SList* listOutOfRange;

    Node* nextNode;

    while (*_list != NULL && counter < maximumTop && cmp(data, (*_list)->__data) > 0) {
        _list = &(*_list)->__next;
        counter++;
    };

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
        listOutOfRange = &(*listOutOfRange)->__next;
        counter++;
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
    void (*callback)(const void* element)
) {
    while (*_list != NULL) {
        callback((*_list)->__data);
        _list = &(*_list)->__next;
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
