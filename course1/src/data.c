#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t* ptr,uint32_t base) {

	//verify radix is within range
	if (base < 2 || base > 16 ) {
		return 0;
	}
	
	//handle zero input
	if (data == 0) {
		*ptr = 0 + '\0';
		return 1;

	}
	
	//handle negatives
	//increase length of output if negative
	uint8_t len = 0;
	int is_neg = (data < 0);
	if (is_neg) {
		data = -data;
		len++;
	}
	uint8_t* keeper = ptr;
	

	uint8_t rem = 1;
	while (data > 0) {
		rem = data % base;
		if (rem >= 10) {
			*ptr = 'a' + (rem - 10);
		}

		else {
			*ptr = '0' + rem;
		
		}
		data /= base;
		ptr++;
		len++;
	}
	
	
	//add negative sign
	if (is_neg) {
		*ptr++ = '-';
		
		
	}

	//reverse and null-terminate
	my_reverse(keeper, len);

	*ptr = '\0';
	ptr = keeper;
	return len;
	

}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {

	//first check if its negative
	
	int sign = 1;
	int i = 0;
 
	if (*ptr == '-') {
		sign = -1;
		ptr++;
	}
	
	// run through the string
	while (*ptr != '\0') {
		if ((*ptr >= '0' && *ptr <= '9') || (*ptr >= 'a' && *ptr <= 'f')) {
			i *= base;
			if (*ptr >= 'a') {
				i += (*ptr + 10 - '0');
				

			}
			else {
			
				i += (*ptr - '0');
				
			}

				ptr++;

			}

			// there's non hex digits in our string, quit
		else {
			return -1;

		}

	}
		
		
	return i *= sign;


}


