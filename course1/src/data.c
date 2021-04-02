#include "data.h"
#define ASCII_LOW_ALPHA (97)
#define ASCII_ZERO (48)


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
	
	uint8_t len = 0;
	int is_neg = (data < 0 && base == 10);
	if (is_neg) {
		data = -data;
		len++;
	}
	uint8_t* keeper = ptr;
	
	uint8_t rem = 1;
	uint8_t quot = 1;
	while (data > 0) {
		rem = data % base;
		if (rem >= 10) {
			*ptr = ASCII_LOW_ALPHA + (rem - 10);
		}

		else {
			*ptr = ASCII_ZERO + rem;
		
		}
		data /= base;
		ptr++;
		len++;
	}
	
	
	
	if (is_neg) {
		*ptr++ = '-';
		
		
	}
	my_reverse(keeper, len);

	*ptr = '\0';
	ptr = keeper;
	return len;
	

}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {


}
