
#include "../library/main.h"

#include "./structs.h"
#include "./utils.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t i;

    Stack* stack;
    size_t stackLength;
    Product poppedProduct;

    unsigned char error;

    stack = newStack();
    if (stack == NULL) {
        printf("Error! An error occurred on create dynamic Stack.");
        return 1;
    };

    pushRndProducts(stack);

    stackLength = getStackLength(stack);

    for (i = 0; i < stackLength; i++) {
        error = pop(stack, &poppedProduct);
        if (error) {
            printf(
                "> Error! An error occurred on pop(0x%p, 0x%p).",
                (void*)stack,
                (void*)&poppedProduct
            );
            continue;
        };

        printf("\n");
        printProduct(&poppedProduct);
    };

    destroyStack(stack);

    return 0;
}
