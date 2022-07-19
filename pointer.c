#include "debug.h"
#define MAGIC 0

int alter_pointer(int* int_pointer){
	check(int_pointer, "bad argument");
	printf("the data pointed to is: %d\n", *int_pointer);
	(*int_pointer)--;
	printf("the data has been altered to: %d\n", *int_pointer);
	return 0;
error:
	return -1;

}

int main(){

	int x=MAGIC;
	int* pointer=&x;
	check(alter_pointer(pointer)==0, "Alternation failed.");
	check(x==MAGIC-1, "x was not modified in place");
	printf("x is now: %d\n",x);
	return 0;
error:
	return -1;
}
