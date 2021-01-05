CC = gcc 
FLAGS = -Wall -g

all: isort txtfind

isort: mainSort.o isort.o
	$(CC) $(FLAGS) -o isort mainSort.o isort.o 

mainSort.o: mainSort.c isort.h
	$(CC) $(FLAGS) -c mainSort.c 

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c 


txtfind: mainFind.o textfind.o
	$(CC) $(FLAGS) -o txtfind mainFind.o textfind.o 

mainFind.o: textfind.c textfind.h
	$(CC) $(FLAGS) -c mainFind.c 

textfind.o: textfind.c textfind.h
	$(CC) $(FLAGS) -c textfind.c

.PHONY: clean all