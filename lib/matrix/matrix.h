#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include "../boolean.h"
typedef struct matrix
{
    char Buffer[5][10];
} Matrix;

void CreateMatrix(Matrix *mat);

#endif