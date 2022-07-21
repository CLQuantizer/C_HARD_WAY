#include "debug.h"
#include <stdlib.h>
#define MAGIC 0
#define HELLO "hello"

int array_manipulation(int int_arr[], int size){
	check(int_arr, "Everything broken");
	check(size, "The size information is needed.");
	for(int i=0;i<size; i++){
		printf("This number is %d\n",int_arr[i]);
		int_arr[i]++;
	}
	return 0;
error:
	return -1;
}

int main(){
	int int_arr[] = {3,4,6};
	int size = sizeof(int_arr)/sizeof(int);
	check(0==array_manipulation(int_arr,size), "Manip failed");
	printf("After manipulation, the array is now:");
	for(int i=0; i<size; i++)printf("%d ",int_arr[i]);
	printf("\n");
	return 0;
error:
	return -1;
}
