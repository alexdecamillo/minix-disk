cc=gcc
CFLAGS =-I.
DEPS = minix.h

%.o: %.c %(DEPS)
	%(CC) -c -o %@ $< $(CFLAGS)

all: main.o
	$(CC) -o MinixConsole main.o $(CFLAGS)
