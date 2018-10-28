/*
* ENSICAEN
* 6 boulevard Maréchal Juin
* F-14050 Caen Cedex
*
* This file is owned by ENSICAEN students. No portion of this
* document may be reproduced, copied or revised without written
* permission of the authors
*/

/**
* @author Christophe Génard <christophe.genard@ecole.ensicaen.fr>
* @version 1.0.0 - 2018-10-24
*
* @todo Nothing Known
* @bug Nothing Known
*/

/**
* @file testmatrix.c
*/

#include <matrix.h>
#include <assert.h>

/* Prototype des fonctions de tests */
void test_a();
void test_i_m();

/**
* Main function used to run all the matrix tests at once
*/
int main(void){
    printf("Beginning of Matrix tests\n");

    test_a();
    test_i_m();

    printf("End of Matrix tests : tests succeed !\n");
    return 1;
}

/**
 * Test the function "alloc" of matrix.c file 
 */
void test_a(){
    struct Matrix m;

    m.ncol = -1;
    m.nrow = 6;
    m = alloc(m.ncol, m.nrow);
    assert(m.data == NULL);

    m.nrow = -1;
    m = alloc(m.ncol, m.nrow);
    assert(m.data == NULL);

    m.ncol = 8;
    m.nrow = -1;
    m = alloc(m.ncol, m.nrow);
    assert(m.data == NULL);

    m.ncol=8;
    m.nrow=6;
    m = alloc(m.ncol, m.nrow);
    assert(m.data != NULL);

    free_matrix(m);
}

/**
 * Test the function "init_matrix" of matrix.c file 
 */
void test_i_m(){
    struct Matrix m;
    int i;
    int j;

    m.ncol = 8;
    m.nrow = 6;
    m = alloc(m.ncol, m.nrow);
    init_matrix(m);
    for (i = 0; i < m.ncol; i++){
        for (j = 0; j < m.nrow; j++){
            assert(m.data[i][j] == 'o');
        }
    }
    free_matrix(m);
}