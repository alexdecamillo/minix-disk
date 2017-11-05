
cc=gcc
CFLAGS =-I.
DEPS = minix.h
 

%.o: %.c %(DEPS)
	%(CC) -c -o %@ $< $(CFLAGS)

main: main.o
		$(CC) -o main main.o $(CFLAGS)


