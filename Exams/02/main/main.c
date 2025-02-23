
#include <stdio.h>
#include <stdlib.h>

#include "./macros.h"
#include "./singly-linked-list.h"
#include "./utilities.h"

int main() {
    SList students;

    newSList(&students);

    if (createTestFile(TEST_FILE_PATH)) {
        puts("> Error! An error occurred on create the test file.");
        destroySList(&students);
        return 1;
    };

    if (storeStudentsInOrder(&students, TEST_FILE_PATH, &cmpStudentsByDNI)) {
        puts("> Error! An error occurred on store students.");
        destroySList(&students);
        return 1;
    };

    puts("> Students sorted by DNI...\n");
    mapSList(&students, &printStudent);

    sortSList(&students, &cmpStudentsByNamesAndDNI);

    puts("> Students sorted by first names, last name, and DNI...\n");
    mapSList(&students, &printStudent);

    sortSList(&students, &cmpStudentsByAverageScore);

    puts("> Students sorted by average score...\n");
    mapSList(&students, &printStudent);

    sortSList(&students, &cmpStudentsByCareerAndAverageScore);

    puts(
        "> Students sorted by career, and average score (not taking into account scores under 4)...\n"
    );
    mapSList(&students, &printStudent);

    reverSList(&students);

    puts("> Reversed students...\n");
    mapSList(&students, &printStudent);

    destroySList(&students);

    return 0;
}
