#include "sin_helpers.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

	/*Declaring and typecasting variables*/
	int array[8];
 	int sin_num = atoi(argv[1]);
	
	/*Checking whether the integer is the right size and filling holder array*/
	if(populate_array(array,sin_num) == 1){
	fprintf (stdout, "Invalid SIN\n");
	return 1;
	}
	
	/*Checking whether the sin is valid or with Luhn Algorithm*/
	if(check_sin(array) == 1){
	fprintf (stdout, "Invalid SIN\n");
	return 1;
	}
	
	
	fprintf (stdout, "Valid SIN\n");
}
