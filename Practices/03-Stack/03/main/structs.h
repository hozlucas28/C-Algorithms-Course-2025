#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

typedef struct {
    char code[7];
    char description[15];
    char provider[15];
    float purchasePrice;
    float salePrice;
    char purchaseDate[16];
    char expirationDate[16];
} Product;

#endif // STRUCTS_H_INCLUDED
