CC = gcc
CFLAGS = -I../common
DEPS = ../common/common.h
OBJ = server.o ../common/common.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

server: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o server
