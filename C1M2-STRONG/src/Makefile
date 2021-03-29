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

#------------------------------------------------------------------------------
# Makefile for module 2
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i - generate .i file from .c file input
#      <FILE>.o - generate object files from .c file input
#      <FILE>.asm - generate assembly source file from .c file OR from .out (uses objdump) 
#      	       file
#      compile-all - compile and assemble, but do not link .c source files
#      build - compile and link all .c source files. also build size report
#      clean - remove all generated build files, object files, assembly files,
#      	       dependency files, and preprocessor output files
#
# Platform Overrides:
#      Override PLATFORM variable to either HOST (for host machine) or MSP432 
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
# HOST platform by default

PLATFORM = HOST

# Output names

BASE = c1m2
TARGET = $(BASE).out
SZREPORT = $(BASE)_size_report.txt

# Flags

CPPFLAGS = -E -o
ODFLAGS = --disassemble
SZFLAGS = -Ax 
ifeq ($(PLATFORM),MSP432)
        $(info *** Detected MSP432 platform override *** )
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	OD = arm-none-eabi-objdump
	SZ = arm-none-eabi-size
	LDFLAGS = -Wl,-Map=$(BASE).map -T $(LINKER_FILE)
	CFLAGS = -D$(PLATFORM) -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard \
		 -mfpu=fpv4-sp-d16 --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99


endif

ifeq ($(PLATFORM),HOST)
        $(info *** Detected HOST platform ***)
	CC = gcc
	OD = objdump
	SZ = size
	LDFLAGS = -Wl,-Map=$(BASE).map
	CFLAGS= -D$(PLATFORM) -Wall -Werror -g -O0 -std=c99

endif

OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.asm)
PPS = $(SOURCES:.c=.i)
MAPS = $(SOURCES:.c=.map)



%.i : %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) $@ $< 

%.o : %.c
	$(CC) $(INCLUDES) -MD -c $< $(CFLAGS) -o $@

%.asm : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -S $< -o $@

%.asm : %.out

	$(OD) $(ODFLAGS) $< > $@


.PHONY: build
build : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(TARGET)
	$(SZ) $(TARGET) $(SZFLAGS) > $(SZREPORT)



.PHONY: compile-all
compile-all: $(OBJS)



.PHONY: clean
clean:
	$(info *** cleaning *** )
	$(shell rm -f *.o *.asm *.map *.out *.i *.d)
	@echo > /dev/null
	$(info *** done ***)
