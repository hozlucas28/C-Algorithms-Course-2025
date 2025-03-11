#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#define CODE_LENGTH 6 + 1

#define DESCRIPTION_LENGTH 25 + 1

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char code[CODE_LENGTH];
    char description[DESCRIPTION_LENGTH];
    int batch;
    Date expirationDate;
    int stock;
} Product;

#endif // STRUCTS_H_INCLUDED
