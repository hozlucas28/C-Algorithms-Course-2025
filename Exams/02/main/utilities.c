
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./singly-linked-list.h"
#include "./structs.h"
#include "./utilities.h"

unsigned char createTestFile(const char* filePath) {
    FILE* file;

    char* careerCodes[] = CAREER_CODES;
    char* courseCodes[] = COURSE_CODES;

    size_t i;
    Student student;

    int rndInt;
    char* rndCareerCode;

    size_t j;

    int rndCode;
    char* rndCourseCode;
    int rndFinalScore;

    file = fopen(filePath, "wt");
    if (file == NULL) return 1;

    srand(time(NULL));

    for (i = 0; i < STUDENTS; i++) {
        rndInt = rand() % UINT_MAX;
        rndCareerCode = *(careerCodes + (rand() % AMOUNT_OF_CAREER_CODES));

        student.dni = rndInt;
        sprintf(student.lastName, "Last name %d", rndInt);
        sprintf(student.firstNames, "First names %d", rndInt);
        strcpy(student.careerCode, rndCareerCode);

        fprintf(
            file,
            "%u|%s|%s|%s/",
            student.dni,
            student.lastName,
            student.firstNames,
            student.careerCode
        );

        rndInt = rand() % (MAXIMUM_SUBJECTS + 1);
        student.subjects.amount = rndInt;

        fprintf(file, "%u/", student.subjects.amount);

        for (j = 0; j < rndInt; j++) {
            rndCode = rand() % UINT_MAX;
            rndCourseCode = *(courseCodes + (rand() % AMOUNT_OF_COURSE_CODES));
            rndFinalScore = (rand() % 10) + 1;

            student.subjects.subjects[i].code = rndCode;
            strcpy(student.subjects.subjects[i].courseCode, rndCourseCode);
            student.subjects.subjects[i].finalScore = rndFinalScore;

            fprintf(
                file,
                "%u|%s|%u/",
                student.subjects.subjects[i].code,
                student.subjects.subjects[i].courseCode,
                student.subjects.subjects[i].finalScore
            );
        };

        fprintf(file, "\n");
    };


    fclose(file);

    return 0;
}

unsigned char storeStudentsInOrder(
    SList* students,
    const char* filePath,
    int (*cmp)(const void* student02, const void* student01)
) {
    FILE* file;
    char line[LINE_LENGTH];

    Student student;

    file = fopen(filePath, "rt");
    if (file == NULL) return 1;

    while (fgets(line, LINE_LENGTH, file)) {
        if (parseStudent(line, &student)) continue;
        insertSListElementInOrder(students, &student, sizeof(student), cmp);
    };

    fclose(file);

    return 0;
}

unsigned char parseStudent(
    char* line,
    Student* student
) {
    size_t fields;

    char* sep;

    size_t i = 0;

    fields = sscanf(
        line,
        "%u|%[^|]|%[^|]|%[^/]/",
        &(student->dni),
        student->lastName,
        student->firstNames,
        student->careerCode
    );

    if (fields != 4) return 1;

    sep = strchr(line, '/');
    if (sep == NULL) return 1;

    line = sep + 1;

    fields = sscanf(line, "%u/", &(student->subjects.amount));

    if (fields != 1) return 1;

    sep = strchr(line, '/');
    if (sep == NULL) return 1;

    while (sep != NULL) {
        line = sep + 1;
        if (*line == '\n' || *line == '\0') break;

        fields = sscanf(
            line,
            "%u|%[^|]|%u/",
            &(student->subjects.subjects[i].code),
            (student->subjects.subjects[i].courseCode),
            &(student->subjects.subjects[i].finalScore)
        );

        if (fields != 3) return 1;

        sep = strchr(line, '/');
        i++;
    };

    return 0;
}

void printStudent(void* student) {
    Student* _student = (Student*)student;

    size_t i;

    printf("> DNI: %u.\n", _student->dni);
    printf("> Last name: \"%s\".\n", _student->lastName);
    printf("> First names: \"%s\".\n", _student->lastName);
    printf("> Career code: \"%s\".\n", _student->careerCode);

    printf("> Subjects: [");

    for (i = 0; i < _student->subjects.amount; i++) {
        printf(
            "{%u, %s, %u}",
            _student->subjects.subjects[i].code,
            _student->subjects.subjects[i].courseCode,
            _student->subjects.subjects[i].finalScore
        );

        if (i != (_student->subjects.amount - 1)) printf(", ");
    }

    printf("] (%u).\n\n", _student->subjects.amount);
}

int cmpStudentsByDNI(
    const void* student01,
    const void* student02
) {
    Student* _student01 = (Student*)student01;
    Student* _student02 = (Student*)student02;

    return _student01->dni - _student02->dni;
}

int cmpStudentsByNamesAndDNI(
    const void* student01,
    const void* student02
) {
    Student* _student01 = (Student*)student01;
    Student* _student02 = (Student*)student02;

    int cmpFirstNames = strcmp(_student01->firstNames, _student02->firstNames);
    int cmpLastNames = strcmp(_student01->lastName, _student02->lastName);
    int cmpDNIs = _student01->dni - _student02->dni;

    return cmpFirstNames + cmpLastNames + cmpDNIs;
}

int cmpStudentsByAverageScore(
    const void* student01,
    const void* student02
) {
    Student* _student01 = (Student*)student01;
    Student* _student02 = (Student*)student02;

    size_t i;
    int _student01AverageScore = 0;
    int _student02AverageScore = 0;


    for (i = 0; i < _student01->subjects.amount; i++) {
        _student01AverageScore += _student01->subjects.subjects[i].finalScore;
    };

    _student01AverageScore = _student01AverageScore / _student01->subjects.amount;

    for (i = 0; i < _student02->subjects.amount; i++) {
        _student02AverageScore += _student02->subjects.subjects[i].finalScore;
    };

    _student02AverageScore = _student02AverageScore / _student02->subjects.amount;

    return _student01AverageScore - _student02AverageScore;
}

int cmpStudentsByCareerAndAverageScore(
    const void* student01,
    const void* student02
) {
    Student* _student01 = (Student*)student01;
    Student* _student02 = (Student*)student02;

    int cmpCareers = strcmp(_student01->careerCode, _student02->careerCode);

    size_t i;
    int _student01AverageScore = 0;
    int _student02AverageScore = 0;


    for (i = 0; i < _student01->subjects.amount; i++) {
        if (_student01->subjects.subjects[i].finalScore < 4) continue;
        _student01AverageScore += _student01->subjects.subjects[i].finalScore;
    };

    _student01AverageScore = _student01AverageScore / _student01->subjects.amount;

    for (i = 0; i < _student02->subjects.amount; i++) {
        if (_student02->subjects.subjects[i].finalScore < 4) continue;
        _student02AverageScore += _student02->subjects.subjects[i].finalScore;
    };

    _student02AverageScore = _student02AverageScore / _student02->subjects.amount;

    return cmpCareers + (_student01AverageScore - _student02AverageScore);
}

