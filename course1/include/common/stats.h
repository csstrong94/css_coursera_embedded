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
 * @file stats.h
 * @brief Function declarations for stats.c
 *
 * Function declarations for different
 * statistics functions. Calculates
 * min, max, mean, median, sorts, 
 * and different print functions
 *
 * @author Chris Strong
 * @date 03/20/2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


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
unsigned char find_minimum(unsigned char* arr, unsigned int len);


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

unsigned char find_maximum(unsigned char* arr, unsigned int len);



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
unsigned char find_mean(unsigned char* arr, unsigned int len);


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
unsigned char find_median(unsigned char* arr, unsigned int len);




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
void sort_array(unsigned char* arr, unsigned int len);



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
void print_array(unsigned char* arr, unsigned int len);



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
void print_statistics(unsigned char* arr, unsigned int len);








#endif /* __STATS_H__ */
