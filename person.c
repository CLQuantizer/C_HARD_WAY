#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
struct Person {
	char* name;
	char* job;
	short unsigned int age;
	struct Person* next;
};

struct Person* person_create(char* name, char* job, short unsigned int age, struct Person* next){
	struct Person* p = malloc(sizeof(struct Person));
	p->name = name;
	p->job = job;
	p->age = age;
	p->next = next;
	return p;
}

void print_person(struct Person* p){
	printf("name: %s\n",p->name);
	printf("job: %s\n",p->job);
	printf("age: %hu\n", p->age);
	return;
}

int main(){
	struct Person* Shuman = person_create("Shuman", "Catering", 70, NULL);
	check(Shuman, "Person not cerated.");
	struct Person* Kevin = person_create("Kevin","Student",15, Shuman);
	print_person(Kevin);
	return 0;
error:
	return -1;
}


