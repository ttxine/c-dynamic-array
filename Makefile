all: test

test: main.o arraylist.o
	gcc -g -Wall -o test arraylist.o main.o

main.o: main.c
	gcc -g -Wall -c main.c

arraylist.o: arraylist.c
	gcc -g -Wall -c arraylist.c

clean:
	rm -rf *.o test
