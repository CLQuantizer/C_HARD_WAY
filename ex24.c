#include <stdio.h>
#include "debug.h"

#define MAX_DATA 100

typedef enum LinguisticsSchool {
	CHOMSKY, COGNITIVE, DEEPLEARNING,
	CONSTRUCTION, OTHER
} LinguisticsSchool;

const char *LINGUISTICS_SCHOOL_NAMES[] = {
	"Chomsky", "Cognitive", "Deeplearning", "Construction", "Other"	
};

typedef struct Linguist {
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	LinguisticsSchool school;
	float influence_factor;
} Linguist;

int main(int argc, char *argv[]){
	Linguist Toby = {.age=24};
	
	int i = 0;
	char *in = NULL;

	printf("What is your First Name? ");
	in = fgets(Toby.first_name, MAX_DATA-1,stdin);
	check(in != NULL, "Failed to read first name.");

	printf("What is your Last Name? ");
	in = fgets(Toby.last_name, MAX_DATA-1, stdin);
	check(in != NULL, "Failed to read last name.");
	
	printf("How old are you? ");
	int rc = fscanf(stdin, "%d", &Toby.age);
	check(rc>0, "You have to enter a number.");

	printf("What school of linguistics to you subscribe to:\n");
	for(i=0; i <= OTHER; i++){
		printf("%d) %s\n", i+1, LINGUISTICS_SCHOOL_NAMES[i]);
	}
	printf("> ");

	int School = -1;
	rc = fscanf(stdin, "%d", &School);
	check(rc>0, "You have to enter a number.");

	Toby.school = School-1;
	check(Toby.school <=OTHER && Toby.school>=0, "Do it right, that is not an option.");
	
	printf("How much does Toby influence the academia? ");
	rc = fscanf(stdin, "%f", &Toby.influence_factor);
	check(rc>0, "Enter a floating point number.");

	printf("----- RESULTS -----\n");
	printf("First name: %s", Toby.first_name);
	printf("Last name: %s", Toby.last_name);
	printf("Age: %d\n", Toby.age);
	printf("Linguistics School: %s\n", LINGUISTICS_SCHOOL_NAMES[Toby.school]);
	printf("Influence factor: %f\n", Toby.influence_factor);
	
	return 0;
error:
	return -1;
}







