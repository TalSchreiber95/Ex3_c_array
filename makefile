GCC = gcc -Wall -g

all: isort txtfind

isort: mainSort.o isort.o
	$(GCC) -o isort mainSort.o isort.o 

mainSort.o: mainSort.c isort.h
	$(GCC) -c mainSort.c 

isort.o: isort.c isort.h
	$(GCC) -c isort.c 

txtfind: mainFind.o textfind.o
	$(GCC) -o txtfind mainFind.o textfind.o 

mainFind.o: mainFind.c textfind.h
	$(GCC) -c mainFind.c 

textfind.o: textfind.c textfind.h
	$(GCC) -c textfind.c

.PHONY: clean all

clean:
	rm -f *.o isort main txtfind