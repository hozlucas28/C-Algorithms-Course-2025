
#include <stdlib.h>
#include <string.h>

#include "./queue.h"

// Constructor
void newQueue(Queue* _queue) {
    _queue->__head = NULL;
    _queue->__tail = NULL;
}

// Destructor
void destroyQueue(Queue* _queue) {
    Node* head = _queue->__head;
    Node* nextHead;

    while (head != NULL) {
        nextHead = head->__next;
        free(head->__data);
        free(head);
        head = nextHead;
    }

    _queue->__head = NULL;
    _queue->__tail = NULL;
}

// Getters
unsigned char isQueueFull(
    Queue* _queue,
    const size_t sizeOfData
) {
    Node* node;
    void* nodeData;

    node = malloc(sizeof(Node));
    nodeData = malloc(sizeOfData);

    free(node);
    free(nodeData);

    return node == NULL || nodeData == NULL;
}

unsigned char isQueueEmpty(Queue* _queue) {
    return _queue->__head == NULL;
}

// Methods
unsigned char shiftQueueElement(
    Queue* _queue,
    void* store,
    const size_t sizeOfStore
) {
    Node* head = _queue->__head;
    Node* nextHead;

    if (head == NULL) return 1;
    if (head->__sizeOfData != sizeOfStore) return 1;

    memcpy(store, head->__data, head->__sizeOfData);

    nextHead = head->__next;
    free(head->__data);
    free(head);

    _queue->__head = nextHead;

    return 0;
}

unsigned char pushQueueElement(
    Queue* _queue,
    void* data,
    const size_t sizeOfData
) {
    Node* tail;
    Node* newTail;

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

    if (_queue->__head == NULL) {
        _queue->__head = newTail;
        _queue->__tail = newTail;
    } else {
        tail = _queue->__tail;
        tail->__next = newTail;
        _queue->__tail = newTail;
    };

    return 0;
}
