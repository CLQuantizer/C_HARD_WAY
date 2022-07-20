#include "debug.h"
#include <stdlib.h>
#define MAGIC 0
#define HELLO "hello"

int alter_pointer(int* int_pointer){
	check(1,"Not Good");
	printf("the data pointed to is: %d\n", *int_pointer);
	(*int_pointer)--;
	printf("the data has been altered to: %d\n", *int_pointer);
	return 0;
error:
	return -1;

}

int string_manipulation(char* char_pointer){
	check(char_pointer, "Wrong input");
	printf("Enter the while loop with: %s\n", char_pointer);
	while(*char_pointer!='\0'){
		printf("Now manipulating %c\n", *char_pointer);
		char* x = &*char_pointer;
		printf("x is %c\n",(*x)+3);
		printf("The string is: %s\n", char_pointer);
		char_pointer++;
	}
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

	/*try some char* stuff here*/
	char* hello = HELLO;
	printf("Before manipulation: %s\n", hello);
	check(string_manipulation(hello)==0, "Manipulation failed.");
	printf("After manipulation: %s\n", hello);


	return 0;
error:
	return -1;
}
