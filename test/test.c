#include<stdio.h>
#include<stdlib.h>


#define ONE_GIGABYTE (1024 * 1024 * 1024)
#define UNCHARP unsigned char*

typedef struct Arena{
	void *start, *end;
	void *current;
	size_t length;
}Arena;

Arena* allocate_arena(){
	Arena* arena = malloc(sizeof(Arena));

	arena->start = arena->current = malloc(ONE_GIGABYTE); // byte -> kb -> mb ->gb 1024 bytes = 1kb , 1024kb = 1mb , 1024mb = 1gb
	arena->end = (UNCHARP) arena->start + (ONE_GIGABYTE - 1);
	arena->length = ONE_GIGABYTE;
	

	return arena;
}

typedef struct Hi{
	int x;
	float y;
}Hi;


typedef struct FatArray{
	int* data;
	size_t length;
}FatArray;

void* pool_allocate(Arena* arena,size_t size){
	void* ptr = arena->current;
	arena->current = (UNCHARP) arena->current + size; 
	return ptr;
}

void deallocate_arena(Arena* arena){
	free(arena->start);
	free(arena);
}


FatArray* new_array(Arena *arena,int number,size_t len){
	
	FatArray* fatarray = pool_allocate(arena,sizeof(FatArray));
	fatarray->data = pool_allocate(arena,sizeof(int) * len);
	
	for(size_t i = 0 ; i < len ; ++i ){
		fatarray->data[i] = number;
	}

	return fatarray;
}

int main(){
	Arena* arena = allocate_arena();

	Hi* h1 = pool_allocate(arena,sizeof(h1));
	h1->x = 10;
	h1->y = 10.4;

	FatArray* a1 = new_array(arena,10,10);
	FatArray* a2 = new_array(arena,20,5);
	
	for(int i = 0 ; i < 10 ; ++i) {
		printf("%d\n",a1->data[i]);
	}

	for(int i = 0 ; i < 5 ; ++i) {
		printf("%d\n",a2->data[i]);
	}


	printf("%d %.2f \n",h1->x,h1->y);
	

	deallocate_arena(arena);
	return 0;
}
