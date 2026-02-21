#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef size_t u32;

#define ONE_GIGABYTE (1024 * 1024 * 1024)


typedef struct Arena{
	void *start, *end;
	void *current;
	u32 length;			
}Arena;

typedef struct MemPool{
	void *start, *end;
	u32 length;
}MemPool;


Arena* allocate_arena(){
	Arena* arena = malloc(sizeof(Arena));

	arena->start = malloc(ONE_GIGABYTE); // byte -> kb -> mb ->gb 1024 bytes = 1kb , 1024kb = 1mb , 1024mb = 1gb
	arena->end = arena->start + (ONE_GIGABYTE - 1);
	arena->length = ONE_GIGABYTE;

	return arena;
}

MemPool* pool_allocate(Arena* arena, u32 size){
	if(size > ONE_GIGABYTE) abort();
	Mem
}

