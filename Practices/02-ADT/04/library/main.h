
#ifndef MAIN_LIBRARY_H_INCLUDED
#define MAIN_LIBRARY_H_INCLUDED

#include <stdarg.h>
#include <stdlib.h>

/* ---------- Node ---------- */

typedef struct Node {
    void* __data;
    struct Node* __next;
} Node;

// Constructor
Node* newNode(void* data, const size_t sizeOfDataType);

// Destroyer
void destroyNode(Node* node);

// Getters
void* getData(Node* node);
Node* getNext(Node* node);

// Setters
unsigned char setData(
    Node* node,
    void* data,
    const size_t sizeOfDataType
);

void* setNext(
    Node* node,
    void* next
);


/* ---------- List ---------- */

typedef struct {
    Node* __head;
    size_t __length;
} List;

// Constructor
List* newList(const size_t length, ...);

// Destroyer
void destroyList(List* _list);

// Getters
Node* getHead(List* _list);
size_t getLength(List* _list);

Node* getNodeAt(List* _list, const size_t index);

unsigned char isListEmpty(List* _list);

// Methods
void appendNode(List* _list, Node* node);
void unshiftNode(List* _list, Node* node);

void insertNodeAt(
    List* _list,
    Node* node,
    const size_t index
);

#endif // MAIN_LIBRARY_H_INCLUDED
