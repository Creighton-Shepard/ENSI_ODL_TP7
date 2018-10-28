CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic
TEST_EXE = ../../bin/testgame
HEADER = ../../include
LIB = ../../lib

all : $(TEST_EXE) main.o

$(TEST_EXE) : testgame.o game.o
	$(CC) $^ -o $@ -L$(LIB) -lmatrix

main.o : main.c $(HEADER)/matrix.h $(HEADER)/game.h
	$(CC) -g -I$(HEADER) -c $< $(CFLAGS)

game.o : game.c $(HEADER)/matrix.h
	$(CC) -g -I$(HEADER) -c $< $(CFLAGS) 

testgame.o : testgame.c $(HEADER)/matrix.h $(HEADER)/game.h
	$(CC) -g -I$(HEADER) -c $< $(CFLAGS)

clean :
	rm -rf *.o
