
#include <stdio.h>
#include <stdlib.h>

#include "./macros.h"
#include "./singly-linked-list.h"
#include "./utilities.h"

int main() {
    int operation;

    Date currentDate;
    unsigned char _currentDate = 0;

    int top;
    SList products;
    Product product;

    puts(
        "> Available operations:\n\n"
        "  1 - Create stock file\n"
        "  2 - Set current date\n"
        "  3 - Store and show top products near to expire\n"
        "  4 - Create a file with top products near to expire\n"
        "  5 - Show nearest product to expire\n"
        "  0 - Exit\n"
    );

    printf("> Select an operation: ");
    fflush(stdin);
    scanf("%d", &operation);

    newSList(&products);

    while (operation != 0) {
        switch (operation) {
        case 1:
            if (createStockFile(STOCK_PATH)) {
                puts("\n> Error! An error occurred on create stock file.");
                break;
            };

            puts("\n> Stock file created!");
            break;

        case 2:
            requestCurrentDate(&currentDate);
            _currentDate = 1;
            break;

        case 3:
            if (_currentDate) {
                requestTop(&top);

                if (loadProducts(STOCK_PATH, &products, top, &currentDate)) {
                    puts("\n> Error! An error occurred on load products near to expire.");
                    break;
                };

                putchar('\n');
                mapSList(&products, &printProduct, NULL);
                break;
            };

            puts("\n> Error! First, you must set the current date.");
            break;

        case 4:
            if (!isSListEmpty(&products)) {
                if (saveProducts(EXPIRED_PRODUCTS_PATH, &products)) {
                    puts("\n> Error! An error occurred on save products near to expire.");
                };

                printf("\n> Products near to expire saved in \"%s\".\n", EXPIRED_PRODUCTS_PATH);
                break;
            };

            puts("\n> Error! First, you must store top products near to expire.");
            break;

        case 5:
            if (!isSListEmpty(&products)) {
                if (getSListHead(&products, &product, sizeof(product))) {
                    puts("\n> Error! An error occurred on get nearest product to expire.");
                    break;
                };

                printf(
                    "\n> Nearest product to expire: "
                    "{ code: %s, description: %s, batch: %d, expirationDate: %02d/%02d/%02d, stock: %d}.\n",
                    product.code,
                    product.description,
                    product.batch,
                    product.expirationDate.day,
                    product.expirationDate.month,
                    product.expirationDate.year,
                    product.stock
                );
                break;
            };

            puts("\n> Error! First, you must store top products near to expire.");
            break;

        default:
            puts("> Invalid operation! Try again...");
        }

        puts(
            "\n> Available operations:\n\n"
            "  1 - Create stock file\n"
            "  2 - Set current date\n"
            "  3 - Store and show top products near to expire\n"
            "  4 - Create a file with top products near to expire\n"
            "  5 - Show nearest product to expire\n"
            "  0 - Exit\n"
        );

        printf("> Select an operation: ");
        fflush(stdin);
        scanf("%d", &operation);
    };

    destroySList(&products);

    return 0;
}
