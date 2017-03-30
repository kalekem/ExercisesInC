trout.o: trout.c trout.h 
	gcc -c trout.c 

util.o: util.c util.h 
	gcc -c util.c 

main: main.c trout.o util.o
	gcc -Wall main.c trout.o util.o -o main


 