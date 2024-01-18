r: c
	valgrind ./c
c: c1.o c.o
	gcc c.o c1.o -o c -Wall

c.o: c.h c.c
	gcc -c c.c -Wall
	
c1.o: c1.c c1.h
	gcc -c c1.c -Wall
