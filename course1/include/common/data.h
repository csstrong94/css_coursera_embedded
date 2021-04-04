#ifndef __DATA_H__
#define __DATA_H__


/*
 * author: chris strong
 * coursera embedded systems intro class
 *
 *
 * this file is a header file for data.c
 * which implements the itoa and atoi
 * functions
 *
 *
 */

#include <stddef.h>
#include <inttypes.h>



/*
 * @brief converts int to string
 *
 * this function converts an signed ints to a string 
 * given a radix
 *
 * @param data integer to convert
 * @param ptr string to store converted int
 * @param base radix to convert to
 *
 * @return length of converted string
 *
 */


uint8_t my_itoa(int32_t data , uint8_t* ptr, uint32_t base);


/*
 * @brief converts string to int
 *
 * this function converts an ascii string to an integer
 * given a radix
 *
 * @param ptr source string 
 * @param digits integer resulting from conversion
 * @param base radix to convert to
 *
 * @return the 32-bit signed integer
 */

int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */
