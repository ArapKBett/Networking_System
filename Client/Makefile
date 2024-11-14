CC = gcc
CFLAGS = -I../common
DEPS = ../common/common.h
OBJ = client.o ../common/common.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

client: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o client
