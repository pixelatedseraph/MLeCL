#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arena.h"
#define UNCHARP unsigned char*


typedef struct Arena{
	void *start, *end;
	void *current;
	u32 available,capacity;			
}Arena;


Arena* allocate_arena(){
	Arena* arena = malloc(sizeof(Arena));

	arena->start = arena->current = malloc(ONE_GIGABYTE); // byte -> kb -> mb ->gb 1024 bytes = 1kb , 1024kb = 1mb , 1024mb = 1gb
	arena->end = arena->start + (ONE_GIGABYTE - 1);
	arena->available = arena->capacity = ONE_GIGABYTE;

	return arena;
}


void* pool_allocate(Arena* arena,size_t size){
	if(size >= ONE_GIGABYTE || size > arena->available) return nullptr;
	void* ptr = arena->current;
	arena->current  = (UNCHARP) arena->current + size; 
	arena->available -= size; 
	return ptr;
}


//look up alignment!
void clear_arena(Arena* arena){
	arena->current = 0;
}

//destructor
void deallocate_arena(Arena* arena){
	free(arena->start);
	free(arena);
}

