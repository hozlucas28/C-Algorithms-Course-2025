#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "./singly-linked-list.h"
#include "./structs.h"

unsigned char createTestFile(const char* filePath);

unsigned char storeStudentsInOrder(
    SList* students,
    const char* filePath,
    int (*cmp)(const void* student02, const void* student01)
);

unsigned char parseStudent(
    char* line,
    Student* student
);

void printStudent(void* student);

int cmpStudentsByDNI(
    const void* student01,
    const void* student02
);

int cmpStudentsByNamesAndDNI(
    const void* student01,
    const void* student02
);

int cmpStudentsByAverageScore(
    const void* student01,
    const void* student02
);

int cmpStudentsByCareerAndAverageScore(
    const void* student01,
    const void* student02
);

#endif // UTILITIES_H_INCLUDED
