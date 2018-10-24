CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic
TEST_EXE = ../../bin/testmatrix
HEADER = ../../include
LIB = ../../lib
DYN_OPTION = -fPIC

all : staticlib dynamiclib $(TEST_EXE) 

$(TEST_EXE) : testmatrix.o stat_matrix.o
	$(CC) $^ -o $@

stat_matrix.o : matrix.c $(HEADER)/matrix.h
	$(CC) -g -I$(HEADER)  -c $< -o $@ $(CFLAGS)

dyn_matrix.o : matrix.c $(HEADER)/matrix.h
	$(CC) -g -I$(HEADER)  -c $< -o $@ $(CFLAGS) $(DYN_OPTION)

testmatrix.o : testmatrix.c $(HEADER)/matrix.h
	$(CC) -g -I$(HEADER) -c $< $(CFLAGS)

staticlib: stat_matrix.o
	ar crv $(LIB)/libmatrix.a $^

dynamiclib: dyn_matrix.o
	$(CC) -shared -o $(LIB)/libmatrix.so $^


clean :
	rm -rf *.o

clean_library:
	rm -rf $(LIB)/*.a ; rm -rf $(LIB)/*.so