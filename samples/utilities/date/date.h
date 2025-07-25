#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

typedef struct {
    int day;
    int month;
    int year;
} Date;

// Getters
unsigned char isLeapDate(const Date* date);

unsigned char isValidDate(const Date* date);

// Methods
unsigned char cmpDates(
    const Date* date01,
    const Date* date02
);

#endif // DATE_H_INCLUDED
