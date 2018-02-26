all: trout.o util.o main.o main

trout.o: trout.c trout.h util.h
	gcc -c trout.c

util.o: util.c util.h
	gcc -c util.c

main.o: main.c trout.h util.h
	gcc -c main.c

main: trout.o util.o main.o
	gcc -Wall trout.o util.o main.o -o main
