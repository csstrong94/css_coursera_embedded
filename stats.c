/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Statistics functions implemented in this file are:
 * 	-Min
 * 	-Max
 * 	-Mean
 * 	-Median
 * 	-Sort in descending order 
 *
 * This file implements various statistics functions
 * and displays them to stdout.
 *
 * @author Chris Strong
 * @date 03/20/2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
	
  printf("\nInput Array: ");
  print_array(test, SIZE);
  sort_array(test, SIZE);
  printf("Array sorted: ");
  print_array(test, SIZE);
  printf("\n");
  print_statistics(test, SIZE);
 
  


}


/**
 * @brief Calculates min of array of integers
 *
 * Finds and returns the minimum value of the data set
 *
 * @param arr - a pointer to an array of integers
 * @param len - length of the associated array
 * 
 * 
 *
 * @return an integer representing the minimum value in the array
 */




unsigned char find_minimum(unsigned char* arr, unsigned int len) {

	unsigned char min = arr[0];
	
	for(int i = 1; i < len; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}

	}

	return min;
}



/**
 * @brief Calculates max of array of integers
 *
 * Finds and returns the maximum value of the data set
 *
 * @param arr - a pointer to an array of integers 
 * @param len - length of the associated array
 * 
 * 
 *
 * @return an integer representing the maximum value in the array
 */




unsigned char find_maximum(unsigned char* arr, unsigned int len) {

	unsigned char max = arr[0];

	for(int i = 1; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}

	}

	return max;
}


/**
 * @brief Calculates mean of array of integers
 *
 * Finds and returns the average value of the data set
 *
 * @param arr - a pointer to an array of integers
 * @param len - length of the associated array
 * 
 * 
 *
 * @return an integer representing the mean value in the array
 */


unsigned char find_mean(unsigned char* arr, unsigned int len) {


	int sum = 0;
	
	for(int i = 0; i < len; i++) {
		sum += arr[i];
	
	}

	return (sum / len);

}


/**
 * @brief Calculates median of array of integers
 *
 * Calculates and returns the median value of the data set
 *
 * @param arr - a pointer to an array of integers
 * @param len - length of the associated array
 * 
 * 
 *
 * @return an integer representing the median value in the array
 */



unsigned char find_median(unsigned char* arr, unsigned int len) {

	sort_array(arr, len);

	if(len % 2 != 0) {
		return arr[len / 2];
	}	

	unsigned int m1 = len / 2;
	unsigned int m2 = (len / 2) + 1;


	return (arr[m1] + arr[m2]) / 2;
}



/**
 * @brief Sorts the array from largest to smallest
 *
 * Sorts the dataset from largest to smallest
 *
 * @param arr - a pointer to an array of integers
 * @param len - length of the associated array
 * 
 * 
 *
 * @return None
 */


void sort_array(unsigned char* arr, unsigned int len) {
	for(int i = 0; i < len; i++) {
	
		for(int j = 0; j < len - 1; j++) {
			
			if(arr[j] < arr[j + 1]) {
				unsigned char temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			
			}
	

		}

	}
	

}




/**
 * @brief Prints the data set to the screen
 *
 * Prints the array to the screen
 *
 * @param arr - a pointer to an array of integers
 * @param len - length of the associated array
 * 
 * 
 *
 * @return None
 */


void print_array(unsigned char* arr, unsigned int len) {

	
	printf("[");
	for(int i = 0; i < len; i++) {
		
		printf("%d ", arr[i]);
		
	}
	printf("]\n");
}

/**
 * @brief Pretty prints statistics of the array
 *
 * Pretty prints the minimum, maximum, mean, and median
 * of the supplied data set
 *
 * @param arr - a pointer to an array of integers
 * @param len - length of the associated array
 * 
 * 
 *
 * @return None
 */


void print_statistics(unsigned char* arr, unsigned int len) {

	printf("Array Statistics: \n\n");
	printf("Minimum value: %d\n", find_minimum(arr, len));
	printf("Maximum value: %d\n", find_maximum(arr, len));
	printf("Mean value: %d\n", find_mean(arr, len));
	printf("Median value: %d\n", find_median(arr, len));
	

}


