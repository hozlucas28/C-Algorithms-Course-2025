
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "./main.h"

/* ---------- Node ---------- */

// Constructor
Node* newNode(void* data, const size_t sizeOfDataType) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) return NULL;

    node->__data = malloc(sizeOfDataType);
    if (node->__data == NULL) {
        free(node);
        return NULL;
    };

    memcpy(node->__data, data, sizeOfDataType);
    node->__next = NULL;

    return node;
}

// Destroyer
void destroyNode(Node* node) {
    free(node->__data);
    free(node);
}

// Getters
void* getData(Node* node) {
    return node->__data;
}


Node* getNext(Node* node) {
    return node->__next;
}

// Setters
unsigned char setData(
    Node* node,
    void* data,
    const size_t sizeOfDataType
) {
    void* aux = malloc(sizeOfDataType);
    if (aux == NULL) return 1;

    free(node->__data);

    node->__data = aux;
    memcpy(node->__data, data, sizeOfDataType);

    return 0;
}

void* setNext(
    Node* node,
    void* next
) {
    void* prevNext = node->__next;

    node->__next = next;

    return prevNext;
}


/* ---------- List ---------- */

// Constructor
List* newList(const size_t length, ...) {
    va_list nodes;

    size_t i;

    Node* node;
    Node* nextNode;

    List* list = malloc(sizeof(List));
    if (list == NULL) return NULL;

    va_start(nodes, length);

    list->__head = va_arg(nodes, Node*);
    list->__length = length;

    node = list->__head;

    for (i = 1; i < length; i++) {
        nextNode = va_arg(nodes, Node*);
        setNext(node, nextNode);
        node = nextNode;
    };

    va_end(nodes);

    return list;
}

// Destroyer
void destroyList(List* _list) {
    Node* node = _list->__head;
    Node* aux;

    while (node != NULL) {
        aux = getNext(node);
        destroyNode(node);
        node = aux;
    };

    free(_list);
}

// Getters
Node* getHead(List* _list) {
    return _list->__head;
}

size_t getLength(List* _list) {
    return _list->__length;
}

Node* getNodeAt(List* _list, const size_t index) {
    const size_t _index = ((index % _list->__length) + _list->__length) % _list->__length;

    size_t i;

    Node* node = _list->__head;
    for (i = 0; i < _index; i++) node = getNext(node);

    return node;
}

unsigned char isListEmpty(List* _list) {
    return _list->__length ? 0 : 1;
}

// Methods
void appendNode(List* _list, Node* node) {
    Node* lastNode = _list->__head;

    while (getNext(lastNode) != NULL) {
        lastNode = getNext(lastNode);
    };

    setNext(lastNode, node);
    _list->__length++;
}

void unshiftNode(List* _list, Node* node) {
    Node* aux = _list->__head;
    _list->__head = node;
    setNext(node, aux);
    _list->__length++;
}

void insertNodeAt(
    List* _list,
    Node* node,
    const size_t index
) {
    const size_t _index = ((index % _list->__length) + _list->__length) % _list->__length;

    size_t i;

    Node* nodeBeforeI = NULL;
    Node* nodeI = _list->__head;

    for (i = 0; i < _index; i++) {
        nodeBeforeI = nodeI;
        nodeI = getNext(nodeI);
    };

    if (nodeBeforeI != NULL) {
        setNext(nodeBeforeI, node);
        setNext(node, nodeI);
    } else {
        setNext(node, nodeI);
        _list->__head = node;
    };

    _list->__length++;
}
