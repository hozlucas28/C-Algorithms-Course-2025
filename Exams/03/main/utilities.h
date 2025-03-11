#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "./structs.h"
#include "./singly-linked-list.h"

unsigned char createStockFile(const char* path);

unsigned char loadProducts(
    const char* path,
    SList* products,
    const int top,
    Date* date
);

unsigned char saveProducts(
    const char* path,
    SList* products
);

void requestTop(int* top);

void requestCurrentDate(Date* date);

unsigned char isValidDate(Date* date);

int cmpDates(
    const Date* date01,
    const Date* date02
);

int cmpProductsByDate(
    const void* product01,
    const void* product02
);

int cmpProductsByDateAndStock(
    const void* product01,
    const void* product02
);

void printProduct(
    void* product,
    const size_t index,
    const void* params
);

#endif // UTILITIES_H_INCLUDED
