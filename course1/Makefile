include sources.mk

CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
BASE = main
TARGET = $(BASE).out
GRAPH = $(BASE).graph
VERBOSITY = VERBOSE
COURSE_FLAG = COURSE1

LINKER_FILE = msp432p401r.lds

ODFLAGS = -d -x -S -t
SZFLAGS = -Ad
NMFLAGS = --print-size --size-sort --radix=d

ifeq ($(PLATFORM), MSP432)

	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SZ = arm-none-eabi-size
	NM = arm-none-eabi-nm
	OD = arm-none-eabi-objdump
	CFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard \
 		 -mfpu=fpv4-sp-d16 --specs=$(SPECS) $(INCLUDES) -Wall -g -O0 -std=c99 \
		 -D$(PLATFORM) -D$(VERBOSITY) -D$(COURSE_FLAG) -fverbose-asm
 
	LDFLAGS = -Wl,-Map=$(BASE).map -T $(LINKER_FILE)
else

	CC = gcc
	SZ = size
	NM = nm
	OD = objdump
	CFLAGS = $(INCLUDES) -D$(PLATFORM) -D$(VERBOSITY) -Wall -g -O0 -std=c99 \
		 -D$(COURSE_FLAG)
	LDFLAGS = -Wl,-Map=$(BASE).map
endif


OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.asm)
NMREPS = $(OBJS:.o=.nm_report)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@	
	$(OD) $(ODFLAGS) $@ > $@.obj_report

%.asm : %.c
	$(CC) $(CFLAGS) -S $< -o $@

%.i : $(SOURCES)
	$(CC) $(CFLAGS) -E $< -o $@ 

%.nm_report : %.o
	$(NM) $(NMFLAGS) $< > $@


.PHONY: asm
asm: $(ASMS)

.PHONY: compile
compile: $(OBJS) $(NMREPS)


.PHONY: build
build: $(TARGET)

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	$(SZ) $(SZFLAGS) $@ > $(BASE).report
	$(NM) $(NMFLAGS) $@ > $(BASE).nm_report
	$(OD) $(ODFLAGS) $@ > $@.obj_report


.PHONY: build-all
build-all: $(ASMS) $(OBJS) $(TARGET)


.PHONY: clean
clean:
	$(info *** cleaning *** )
	rm -f *.o *.asm *.map *.out *.i *.d *.report *.nm_report *.obj_report
	cd src; rm -f *.o *.asm *.map *.out *.i *.d *.report *.nm_report *.obj_report
	$(info *** done ***)
