#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

# if no platform is defined here, default it to host
ifndef ($(PLATFORM))
        $(warning *** No platform detected, defaulting to HOST ***)
	PLATFORM = HOST

endif

ifeq ($(PLATFORM),HOST)
        $(info *** Using HOST includes ***)
	SOURCES = ./main.c \
	  	./memory.c \

	INCLUDES = -I../include/common/

endif


ifeq ($(PLATFORM),MSP432)
        $(info *** Using MSP432 includes ***)
	SOURCES = ./interrupts_msp432p401r_gcc.c \
		  ./startup_msp432p401r_gcc.c \
		  ./system_msp432p401r.c  \
		  ./memory.c \
		  ./main.c 


	INCLUDES = -I/home/ecee/ese-coursera-course1/assessments/m2/include/CMSIS/ \
		   -I/home/ecee/ese-coursera-course1/assessments/m2/include/msp432/ \
		   -I/home/ecee/ese-coursera-course1/assessments/m2/include/common/ \

		

endif

