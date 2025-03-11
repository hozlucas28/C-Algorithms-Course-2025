
#include <stdio.h>
#include <stdlib.h>

#include "./structs.h"
#include "./utilities.h"

unsigned char createStockFile(const char* path) {
    FILE* file;

    Product products[] = {
        {
            .code = "A01 01",
            .description = "Description A01 01",
            .batch = 20,
            .expirationDate = {.day = 21, .month = 9, .year = 2024},
            .stock = 10
        },
        {
            .code = "A02 01",
            .description = "Description A02 01",
            .batch = 20,
            .expirationDate = {.day = 15, .month = 10, .year = 2023},
            .stock = 5
        },
        {
            .code = "A03 01",
            .description = "Description A03 01",
            .batch = 20,
            .expirationDate = {.day = 21, .month = 9, .year = 2024},
            .stock = 21
        },
        {
            .code = "A01 02",
            .description = "Description A01 02",
            .batch = 20,
            .expirationDate = {.day = 12, .month = 12, .year = 2021},
            .stock = 81
        },
        {
            .code = "A02 02",
            .description = "Description A02 02",
            .batch = 20,
            .expirationDate = {.day = 10, .month = 12, .year = 2021},
            .stock = 24
        },
        {
            .code = "A03 02",
            .description = "Description A03 02",
            .batch = 20,
            .expirationDate = {.day = 21, .month = 9, .year = 2024},
            .stock = 8
        },
        {
            .code = "A01 03",
            .description = "Description A01 03",
            .batch = 20,
            .expirationDate = {.day = 5, .month = 8, .year = 2024},
            .stock = 29
        },
        {
            .code = "A02 03",
            .description = "Description A02 03",
            .batch = 20,
            .expirationDate = {.day = 12, .month = 10, .year = 2025},
            .stock = 26
        },
        {
            .code = "A03 03",
            .description = "Description A03 03",
            .batch = 20,
            .expirationDate = {.day = 12, .month = 12, .year = 2021},
            .stock = 35
        },
        {
            .code = "A01 04",
            .description = "Description A01 04",
            .batch = 20,
            .expirationDate = {.day = 18, .month = 5, .year = 2025},
            .stock = 14
        }
    };

    const size_t sizeOfProduct = sizeof(*products);
    const size_t productsLength = sizeof(products) / sizeOfProduct;

    file = fopen(path, "wb");
    if (file == NULL) return 1;

    fwrite(products, sizeOfProduct, productsLength, file);

    fclose(file);

    return 0;
}

unsigned char loadProducts(
    const char* path,
    SList* products,
    const int top,
    Date* date
) {
    FILE* file;

    Product product;

    file = fopen(path, "rb");
    if (file == NULL) return 1;

    destroySList(products);

    newSList(products);

    while (fread(&product, sizeof(product), 1, file)) {
        if (cmpDates(date, &product.expirationDate) < 1) {
            if (insertSListElementTop(products, &product, sizeof(product), top, &cmpProductsByDate)) break;
        };
    };

    sortSList(products, &cmpProductsByDateAndStock);

    fclose(file);

    return 0;
}

unsigned char saveProducts(
    const char* path,
    SList* products
) {
    FILE* file;

    Product product;

    file = fopen(path, "wt");
    if (file == NULL) return 1;

    while (!shiftSListElement(products, &product, sizeof(product))) {
        fprintf(
            file,
            "%6s%02d/%02d/%04d%010d\n",
            product.code,
            product.expirationDate.day,
            product.expirationDate.month,
            product.expirationDate.year,
            product.stock
        );
    };

    fclose(file);

    return 0;
}

void requestTop(int* top) {
    printf("\n> Top: ");
    fflush(stdin);
    scanf("%d", top);

    while (*top < 1) {
        puts("\n> Invalid top! Try again...");

        printf("\n> Top: ");
        fflush(stdin);
        scanf("%d", top);
    };
}

void requestCurrentDate(Date* date) {
    printf("\n> Current date (dd/mm/yyyy): ");
    fflush(stdin);
    scanf(
        "%02d/%02d/%04d",
        &date->day,
        &date->month,
        &date->year
    );

    while (!isValidDate(date)) {
        puts("\n> Invalid date! Try again...");

        printf("\n> Current date (dd/mm/yyyy): ");
        fflush(stdin);
        scanf(
            "%02d/%02d/%04d",
            &date->day,
            &date->month,
            &date->year
        );
    };
}

unsigned char isValidDate(Date* date) {
    return (date->day > 0 && date->day < 32) &&
        (date->month > 0 && date->month < 13) &&
        date->year > 0;
}

int cmpDates(
    const Date* date01,
    const Date* date02
) {
    int result;

    result = date01->year - date02->year;
    if (result) return result;

    result = date01->month - date02->month;
    if (result) return result;

    return date01->day - date02->day;
}

int cmpProductsByDate(
    const void* product01,
    const void* product02
) {
    Product* _product01 = (Product*)product01;
    Product* _product02 = (Product*)product02;

    return cmpDates(&_product01->expirationDate, &_product02->expirationDate);
}

int cmpProductsByDateAndStock(
    const void* product01,
    const void* product02
) {
    Product* _product01 = (Product*)product01;
    Product* _product02 = (Product*)product02;

    int result;

    result = cmpDates(&_product01->expirationDate, &_product02->expirationDate);
    if (!result) result = _product02->stock - _product01->stock;

    return result;
}

void printProduct(
    void* product,
    const size_t index,
    const void* params
) {
    Product* _product = (Product*)product;

    printf(
        "> #%d = { code: %s, description: %s, batch: %d, expirationDate: %02d/%02d/%02d, stock: %d}.\n",
        (int)index + 1,
        _product->code,
        _product->description,
        _product->batch,
        _product->expirationDate.day,
        _product->expirationDate.month,
        _product->expirationDate.year,
        _product->stock
    );
}
