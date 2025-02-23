#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdlib.h>

#include "./macros.h"

typedef struct {
    unsigned int code;
    char courseCode[COURSE_CODE_LENGTH];
    unsigned int finalScore;
} Subject;

typedef struct {
    Subject subjects[MAXIMUM_SUBJECTS];
    unsigned int amount;
} Subjects;

typedef struct {
    unsigned int dni;
    char lastName[LAST_NAME_LENGTH];
    char firstNames[FIRST_NAMES_LENGTH];
    char careerCode[CAREER_CODE_LENGTH];
    Subjects subjects;
} Student;

#endif // STRUCTS_H_INCLUDED
