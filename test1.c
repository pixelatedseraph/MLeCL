#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct test{
	void* start;
	void* end;
	void* cirr;
}test;

int main(){
	printf("%d : Bytes \n",sizeof(test));
	return 0;
}
