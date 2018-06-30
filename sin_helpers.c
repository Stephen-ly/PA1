
#include <stdio.h>

/*Fills array with given integer*/
int populate_array (int array[], int sin){
	int populating_digit;
	int digit_count;
	int counter = 0;

	/*Modulus and floor divison allow the int to be truncated and placed into array*/
	for (digit_count = 0; digit_count <= 8; digit_count++){
		populating_digit = sin % 10;
		sin = sin/10;
		array[8-digit_count] = populating_digit;
		counter++;
                if (sin == 0 && counter != 9){
                return 1;
                }
	}	
	return 0;
}

/*Checks the validity based on Luhn's algorithm*/
int check_sin (int array[]){
	int count;
	int carry_variable;
	int sum_variable;
	int modded_number;
	int total;
	
	/*The arithmetic of the algorithm, double's every other digit*/
	for (count = 0; count <= 8; count++){
		if (count % 2 == 1){
			carry_variable = array[count] * 2;
			if (carry_variable >= 10){
				modded_number = carry_variable % 10;
				carry_variable = carry_variable/10;
				sum_variable = modded_number + carry_variable;
				array[count] = sum_variable;
				} else {
				array[count] = carry_variable;
			} 
		}		
	}
	
	/*Totals up each digit in the array*/
	for (count = 0; count <=8; count++){
		total += array[count];
	}
	
	/*Checks validity based on divisibility by 10*/
	if (total % 10 == 0){
		return 0;
	} else {
		return 1;
	}				

}

