#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#define NAME_LENGTH (sizeof(char) * (32 + 1))
#define POSITION_LENGTH ((sizeof(unsigned int) / sizeof(char)) + sizeof(char))

#define LINE_LENGTH (NAME_LENGTH + POSITION_LENGTH + sizeof(char))

typedef struct {
    char name[NAME_LENGTH];
    unsigned int position;
} Runner;

#endif // STRUCTS_H_INCLUDED
