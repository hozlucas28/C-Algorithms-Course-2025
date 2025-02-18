
#include <stdlib.h>
#include <string.h>

#include "./main.h"

/* -------- Queue -------- */

// Constructor
void newQueue(Queue* _queue) {
    _queue->__head = NULL;
    _queue->__tail = NULL;
}

// Destroyer
void destroyQueue(Queue* _queue) {
    Node* head = _queue->__head;
    Node* headNext;

    while (head != NULL) {
        headNext = head->__next;
        free(head->__data);
        free(head);
        head = headNext;
    };

    _queue->__head = NULL;
    _queue->__tail = NULL;
}

// Getters
unsigned char getTopQueueElement(
    const Queue* _queue,
    void* store,
    const size_t sizeOfStore
) {
    if (_queue->__head == NULL) return 1;
    if (_queue->__head->__sizeOfData != sizeOfStore) return 1;

    memcpy(store, _queue->__head->__data, sizeOfStore);

    return 0;
}

unsigned char isQueueEmpty(const Queue* _queue) {
    return _queue->__head == NULL;
}

unsigned char isQueueFull(
    const Queue* _queue,
    const size_t sizeOfData
) {
    Node* node;
    Node* nodeData;

    node = malloc(sizeof(Node));
    nodeData = malloc(sizeOfData);

    free(node);
    free(nodeData);

    return node == NULL || nodeData == NULL;
}

// Methods
unsigned char shiftQueueElement(
    Queue* _queue,
    void* store,
    const size_t sizeOfStore
) {
    Node* head = _queue->__head;
    Node* headNext;

    if (head == NULL) return 1;
    if (head->__sizeOfData != sizeOfStore) return 1;

    memcpy(store, head->__data, sizeOfStore);

    headNext = head->__next;
    free(head->__data);
    free(head);

    _queue->__head = headNext;

    return 0;
}

unsigned char pushQueueElement(
    Queue* _queue,
    void* data,
    const size_t sizeOfData
) {
    Node* newTail;
    Node* oldTail;

    newTail = malloc(sizeof(Node));
    if (newTail == NULL) return 1;

    newTail->__data = malloc(sizeOfData);
    if (newTail->__data == NULL) {
        free(newTail);
        return 1;
    };

    memcpy(newTail->__data, data, sizeOfData);

    newTail->__sizeOfData= sizeOfData;
    newTail->__next = NULL;

    if (_queue->__head == NULL) {
        _queue->__head = newTail;
        _queue->__tail = newTail;

        return 0;
    };

    oldTail = _queue->__tail;
    oldTail->__next = newTail;
    _queue->__tail = newTail;

    return 0;
}
