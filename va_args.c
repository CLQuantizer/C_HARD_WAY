#include "debug.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int reverse_print_string_array(int num_args,...){
	char** string_list = (char**)malloc(num_args*sizeof(char**));	
	check(num_args>0, "No arguments here");
	va_list args;
	va_start(args, num_args);
	printf("Original strings: ");
	for(int i=0;i<num_args;i++){
		char* string = va_arg(args, char*);
		printf("%s ", string);
		string_list[num_args-i-1]=string;
	}
	va_end(args);
	printf("\nReversed String: ");
	for(int i=0;i<num_args;i++){
		printf("%s ", string_list[i]);
	}
	printf("\n");
	free(string_list);
	return 0;
error:
	return -1;
}


int main(){
	reverse_print_string_array(3,"33d","4s","ff5");
	return 0;
}
