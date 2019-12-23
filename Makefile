output: main.o LinkedList.o
	gcc main.o LinkedList.o -o linkedListExample

main.o: main.c 
	gcc -c main.c

LinkedList.o: LinkedList.c LinkedList.h
	gcc -c LinkedList.c

clean:
	rm *.o linkedListExample