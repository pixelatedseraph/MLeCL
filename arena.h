#ifndef ARENA_H
#define ARENA_H

/*
** type aliases
*/

typedef size_t u32;
typedef float  f32;
typedef int    i32;
 

#define ONE_GIGABYTE (1024 * 1024 * 1024)

/*
** forward declaration
*/

typedef struct Arena Arena;

Arena* allocate_arena();
void* pool_allocate(Arena* arena,u32 size);//retuns void* on failure
void clear_arena(Arena* arena);
void deallocate_arena(Arena* arena);

#endif 
