#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*Checks the required permissions provided by the user through indexing through the string as an array of characters and simple comparisons*/
int check_permissions (char user_permissions[], char file_permissions[]){
        int num_index;
        for (num_index = 0; num_index < 9; num_index++){
            if (!((user_permissions[num_index] == file_permissions[num_index])||(user_permissions[num_index] == '-' ))){
       	    return 1;
            }
	}
        return 0;
}

int main(int argc, char *argv[]){
    
    /*If theres no arguments, then the program will provide an error*/
    if (argc <= 1){
	fprintf(stderr, "USAGE: count_small size [permissions]\n");
	return 1;
	}	

    /*initialize variables*/
    char buffer[100];
    int byte_size;
    int line_number = -6;
    int permissions_number = -2;
    char permissions[11];
    int update_num = 0;
    int update_num2 = 0;
    int counted = 0;
    int criteria_match = 0;
    int max_byte_size = atoi(argv[1]);

    /*Scan stdin provided by piping ls -l, by scanf*/
    while(scanf("%s",buffer)==1){
   
    /*identifying which line is for permissions*/

	if ((permissions_number % 9) == 0){
            strncpy(permissions,buffer,10);
	    update_num++;
	    counted = 0;	   
        }
   
    /*identifying which line is for byte_size*/

        if ((line_number % 9) == 0){
	    byte_size = atoi(buffer);
	    update_num2++;
	    counted = 0;
    	}

    /*process for when there is only 1 argument*/

	if ((argc == 2)  && (byte_size < max_byte_size) && (counted == 0)&& (update_num == update_num2) && line_number > -5 ){
            counted = 1;
            criteria_match++;

    /*process for when there are 2 arguments*/

	} else if (argc == 3 && (update_num == update_num2) && (counted == 0) && (check_permissions(argv[2],permissions) == 0) && (byte_size < max_byte_size)){
	    counted = 1;
	    criteria_match++;
	}
	
    /*indexing the lines*/

	line_number++;
	permissions_number++;

	}	

    /*printing the lines that satisfied criteria*/

    printf("%d\n",criteria_match);
    return 0;
}


