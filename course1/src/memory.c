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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdint.h>
#include <stdlib.h>
/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t* my_memmove(uint8_t* src, uint8_t* dst, size_t length) {
	
	
	uint8_t* k = src;
	uint8_t* j = dst;
	if (src == dst || length == 0) {
		return dst; 
	}

	/* first case is copying in reverse 
	 * [----src----]
	 * 	    [----dst----]
	 * 
	 * we don't want to overwrite our source
	 * 
	 *
	 * */
	if (dst > src && dst - src < length ) {
		j += length;
		k += length;
		while (length--) {
			*--j = *--k;

		}

		return dst;

	}


	/* second case is copying forwards
	 *           [----src----]
	 * [----dst----]
	 *
	 * we don't want to overwrite our source
	 *
	 *
	 */
	
	if (src > dst && src - dst < length) {
		for (uint8_t i = 0; i < length; i++) {
			*j++ = *k++;
		}

		return dst;
		
	}


	//otherwise just a regular memcpy (no overlap)
	
	my_memcopy(k, j, length);

	return dst;
}


uint8_t* my_memcopy(uint8_t* src, uint8_t* dst, size_t length) {
	
	unsigned int i;
	uint8_t* k = src;
	for (i = 0; i < length; i++) {
		*dst = *k;
		dst++;
		k++;	

	}
	
	return dst;

}


uint8_t* my_memset(uint8_t* src, size_t length, uint8_t value) {
	
	uint8_t* k = src;
	for (uint8_t i = 0; i < length; i++) {
		*k = value;
		k++;
		
	}
	
	return src;
}

uint8_t* my_memzero(uint8_t* src, size_t length) {

	uint8_t* k = src;
	for (uint8_t i = 0; i < length; i++) {
		*k = 0;
		k++;
		
	}

	return src;

}


uint8_t* my_reverse(uint8_t* src, size_t length) {
	
	uint8_t tmp = 0;
	uint8_t* src_l = src + length - 1;
	uint8_t* k = src;
	while (k < src_l) {
		tmp = *k;
		*k = *src_l;
		*src_l = tmp;
		k++;
		src_l--;
		

	}
	

	return src;

}



int32_t* reserve_words(size_t length) {
	
	int32_t* reserved = calloc(length, sizeof *reserved);
	
	return reserved;

}


void free_words(int32_t* src) {
	
	free(src);

}
