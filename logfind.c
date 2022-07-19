#include "debug.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp;
	char* line = NULL;
	size_t len =0;
	ssize_t read;

	check(1, "Everything is broken.");
	fp = fopen("/home/ezio/.logfind", "r");
	check(fp, "error opening logfind file.");
	
	while((read=getline(&line, &len, fp))!=-1){
		printf("Retrieved line of length %zu:\n", read);
		printf("%s", line);
	}	
	if(line)
		free(line);
	fp = fopen("/home/ezio/.logfind", "r");
	char c;
	c = fgetc(fp);
	while(c!=EOF){
		printf("Get a char: %c",c);
		c=fgetc(fp);
	}
	fclose(fp);
	return 0;
error:
	return -1;
}
