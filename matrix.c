#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"arena.h"
#include"matrix.h"

typedef struct Matrix{
	u32 rows,cols;
	f32* data;
}Matrix;


Matrix* new_matrix(Arena* arena,u32 rows, u32 cols){
	Matrix* matrix = pool_allocate(arena,sizeof(Matrix));
	
	matrix->rows = rows;
	matrix->cols = cols;	
	matrix->data = pool_allocate(arena,sizeof(f32) * rows * cols);

	return matrix;
}

Matrix* random_matrix(Arena* arena,u32 rows, u32 cols){
	Matrix* matrix = new_matrix(arena,rows,cols);


	srand(time(NULL));	
		
	for(u32 idx = 0 ; idx < matrix->rows * matrix->cols ; ++idx){
		matrix->data[idx] = (float) (rand() % RAND_MAX);
	}
	
	return matrix;
}


f32 get_value(Matrix* matrix,u32 row, u32 column){
	return matrix->data[row * matrix->cols + column];
}

void set_value(Matrix* matrix,f32 number,u32 row, u32 column){
	matrix->data[row * matrix->cols + column] = number;
}

void print_matrix(Matrix* matrix){
	for(u32 i = 0 ; i < matrix->rows ; ++i){
		for(u32 j = 0 ; j < matrix->cols ; ++j){
			printf("%.3f ",get_value(matrix,i,j));
		}
		printf("\n");
	}
}

i32 main(){
	Arena* arena = allocate_arena();
	
	Matrix* m1 = random_matrix(arena,3,3);
	print_matrix(m1);

	deallocate_arena(arena);

}
