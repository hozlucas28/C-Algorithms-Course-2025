
#include <stdio.h>

#include "../library/main.h"

#include "./utils.h"

void pushRndProducts(Stack* _stack) {
    Product rndProduct;

    size_t i;
    const size_t numbersOfProducts = 21;

    int productNumber;

    for (i = 0; i < numbersOfProducts; i++) {
        productNumber = (int)(i + 1);

        sprintf(rndProduct.code, "AA %02d", productNumber);
        sprintf(rndProduct.description, "Description of AA %02d", productNumber);
        sprintf(rndProduct.provider, "Provider of AA %02d", productNumber);
        rndProduct.purchasePrice = 1000.10 * productNumber;
        rndProduct.salePrice = 1000.10 * productNumber;
        sprintf(rndProduct.purchaseDate, "01/01/20%02d", productNumber);
        sprintf(rndProduct.expirationDate, "31/12/20%02d", productNumber);

        push(_stack, &rndProduct, sizeof(rndProduct));
    };
}

void printProduct(Product* product) {
    printf("> Product 0x%p {\n", (void*)product);
    printf("    code[7] = \"%s\",\n", product->code);
    printf("    description[15] = \"%s\",\n", product->description);
    printf("    provider[15] = \"%s\",\n", product->provider);
    printf("    purchasePrice = %f,\n", product->purchasePrice);
    printf("    salePrice = %f,\n", product->salePrice);
    printf("    purchaseDate[10] = \"%s\",\n", product->purchaseDate);
    printf("    expirationDate[10] = \"%s\"\n", product->expirationDate);
    printf("};\n");
}
