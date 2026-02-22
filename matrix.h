#ifndef MATRIX_H
#define MATRIX_H

#include "arena.h"

typedef struct Matrix Matrix;

Matrix* new_matrix(Arena* arena,u32 rows, u32 cols);
Matrix* random_matrix(Arena* arena,u32 rows, u32 cols);
f32 get_value(Matrix* matrix,u32 row, u32 column);
void set_value(Matrix* matrix,f32 number,u32 row, u32 column);
void print_matrix(Matrix* matrix);


#endif
