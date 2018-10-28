CC = gcc
CON4 = src/connect4/
MATR = src/matrix/
BIN = bin/
LIB = lib/
MAKE_CON = cd $(CON4) ; make
MAKE_MAT = cd $(MATR) ; make


all : testgame $(BIN)Connect4

testgame : 
	$(MAKE_MAT) ; cd ../.. ; $(MAKE_CON) 
	
$(BIN)Connect4 : $(CON4)main.o $(CON4)game.o
	$(CC) -o $@ $^ -L$(LIB) -lmatrix

clean :
	$(MAKE_MAT) clean ; cd ../.. ; $(MAKE_CON) clean 

clean_library :
	rm -rf $(LIB)*.a ; rm -rf $(LIB)*.so