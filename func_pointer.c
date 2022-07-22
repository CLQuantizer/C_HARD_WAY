#include "debug.h"
#include <stdlib.h>
#define MAGIC 0
#define HELLO "hello"

int add(int x, int y){
	return x+y;
}

int multiply(int x, int y){
	return x*y;
}

int subtraction(int x, int y){
	return x-y;
}

int division(int x, int y){
	return x/y;
}

int manipulate_two_integers(int x, int y, int (*operation)()){
	return (operation(x,y));
}

int main(){

	/*What is the difference between specifying the types of 
	 * function pointers and not specifying em?*/
	int (*p_add)()= &add;
	check((*p_add)(3,40)==43, "Addition is wrong.");
	check(manipulate_two_integers(3,40,&multiply)==120, "Wrong.");
	check(manipulate_two_integers(3,40,&division)==0, "Division wrong.");
	return 0;
error:
	return -1;
}


