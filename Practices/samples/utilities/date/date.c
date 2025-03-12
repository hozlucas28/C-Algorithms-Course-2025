
#include "./date.h"

// Getters
unsigned char isLeapDate(const Date* date) {
    return date->year % 400 == 0 || (date->year % 4 == 0 && date->year % 100 != 0);
}

unsigned char isValidDate(const Date* date) {
    char daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const unsigned char isLeapYear = date->year % 400 == 0 || (date->year % 4 == 0 && date->year % 100 != 0);

    if  (isLeapYear) *(daysPerMonth + 1) = *(daysPerMonth + 1) + 1;

    return date->year > 0 &&
        (date->month > 0 && date->month < 13) &&
        (date->day > 0 && daysPerMonth[date->month - 1] < 13);
}

// Methods
unsigned char cmpDates(
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
