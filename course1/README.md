					
* author: chris strong                    
* build instructions for final assessment 


* to build/clean for MSP432 architecture, use override PLATFORM=MSP432 i.e make build PLATFORM=MSP432
* Leave PLATFORM flag blank for HOST architecture

to build all supporting files 
(object files, preproccessor outputs, assembly files, linker map, etc):

make build-all


---------------------------

to compile only:

make compile


---------------------------

to build without full suite of output files:

make build


---------------------------

to make specific file:

make <file output name>

i.e make memory.o


---------------------------

to clean:

make clean


---------------------------

to execute:

./main.out
