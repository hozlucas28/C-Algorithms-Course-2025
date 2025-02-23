#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

#define COURSE_CODES {"20231C", "20232C", "20233C", "20241C", "20242C", "20243C"}

#define AMOUNT_OF_COURSE_CODES 6

#define COURSE_CODE_LENGTH (6 + 1)

#define MAXIMUM_SUBJECTS 50

#define LAST_NAME_LENGTH (20 + 1)

#define FIRST_NAMES_LENGTH (20 + 1)

#define CAREER_CODES {"INF", "ELE", "IND", "MED", "ABO"}

#define AMOUNT_OF_CAREER_CODES 5

#define CAREER_CODE_LENGTH (3 + 1)

#define TEST_FILE_PATH "students.txt"

#define STUDENTS 20

#define LINE_LENGTH \
    sizeof(unsigned int) + \
    LAST_NAME_LENGTH + \
    FIRST_NAMES_LENGTH + \
    CAREER_CODE_LENGTH + \
    sizeof(unsigned int) + \
    (sizeof(unsigned int) + COURSE_CODE_LENGTH + sizeof(unsigned int)) * 50 + \
    1

#endif // MACROS_H_INCLUDED
