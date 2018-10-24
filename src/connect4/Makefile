CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic
TEST_EXE = ../../bin/testgame
HEADER = ../../include

$(TEST_EXE) : testgame.o game.o
	$(CC) $^ -o $@

game.o : game.c $(HEADER)/matrix.h
	$(CC) -g -I$(HEADER)  -c $< -o $@ $(CFLAGS)

testgame.o : testgame.c $(HEADER)/matrix.h
	$(CC) -g -I$(HEADER) -c $< $(CFLAGS)

clean :
	rm -rf *.o
