# # VPATH = files headers
# # a more precise manner:
# vpath %.c files
# vpath %.h headers
# r: c
# 	valgrind --track-origins=yes -s ./c this is to be displayed 

# # trying to debug command:
# dbg: c1.o c.o c2.o
# 	gcc -g $^ -Wall
# 	gdb ./c

# CFLAGS = -I headers
# run: c
# 	./c 

# c: c1.o c.o c2.o
# 	gcc $(CFLAGS) $^ -o $@ -Wall

# c.o: c.c c.h
# 	gcc $(CFLAGS) -c $< -Wall
	
# c1.o: c1.c c1.h
# 	gcc $(CFLAGS) -c $< -Wall

# c2.o: c2.c c2.h
# 	gcc $(CFLAGS) -c $< -Wall
# # Add the stack module:
# stack.o: stack.c stack.h
# 	gcc $(CFLAGS) -c $< -o $@ -Wall

# .PHONY: clean
# clean:
# 	rm -f *.o 
# 	rm -f *.out
# VPATH = files headers
# a more precise manner:
vpath %.c files
vpath %.h headers

CFLAGS = -I headers
run: c
	./c 
%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $< -o $@
%: %.o
	$(LINK.o) $^ $(LOADLIBLES) $(LDLIBS) -o $@
c: c.o c1.o c2.o stack.o 
c.o: c.c c.h
c1.o: c1.c c1.h
c2.o: c2.c c2.h
stack.o: stack.c stack.h
%: %.o
	$(COMPILE.c) $^ $(OUTPUT_OPTION) $< 

#  the last is required, so the output file name will be the name of the first element 
# in the rule


.PHONY: clean
clean:
	rm -f *.o c
