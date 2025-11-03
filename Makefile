CC = g++ -g
main: main.o Sorting.o
	$(CC) main.o Sorting.o -o main

main.o: main.cpp Sorting.h
	$(CC) main.cpp -c

Sorting.o: Sorting.cpp Sorting.h
	$(CC) Sorting.cpp -c

.PHONY: clean

clean: 
	rm -rf main main.o Sorting.o