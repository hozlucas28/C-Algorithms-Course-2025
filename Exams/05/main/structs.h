#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#define BATCH_CODE_LENGTH (4 + 1)
#define CONTROL_RESULT_LENGTH (5 + 1)

typedef struct {
    char batchCode[BATCH_CODE_LENGTH];
    int id;
    char result[CONTROL_RESULT_LENGTH];
} ProductControl;

#endif // STRUCTS_H_INCLUDED
