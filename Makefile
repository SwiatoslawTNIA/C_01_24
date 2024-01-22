r: c
	valgrind --track-origins=yes -s ./c this is to be displayed 
c: c1.o c.o c2.o
	gcc c.o c1.o c2.o -o c -Wall

c.o: c.h c.c
	gcc -c c.c -Wall
	
c1.o: c1.c c1.h
	gcc -c c1.c -Wall

c2.o: c2.c c2.h
	gcc -c c2.c -Wall