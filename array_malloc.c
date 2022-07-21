#include "debug.h"
#include <stdlib.h>
#define MAGIC 30
#define HELLO "hello"

int array_manipulation(int* int_arr, int size){
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
	int size = MAGIC;
        int *int_arr;
	int_arr = malloc(MAGIC * sizeof(int));

	for(int i=0; i<MAGIC; i++){
		int_arr[i]=3*i;
	}
        check(0==array_manipulation(int_arr,size), "Manip failed");
        printf("After manipulation, the array is now:");
        for(int i=0; i<size; i++)printf("%d ",int_arr[i]);
        printf("\n");
	//free(int_arr);
        return 0;
error:
        return -1;
}

