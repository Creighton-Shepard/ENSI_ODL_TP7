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
* @file testgame.c
*/

#include <matrix.h>
#include <assert.h>
#include <game.h>

/* Prototype des fonctions de tests */
void test_f_d();
void test_c_r();
void test_c_c();
void test_c_d();
void test_r_i();
void test_p();

/**
* Main function used to run all the matrix tests at once
*/
int main(void){
    printf("Beginning of Game tests\n");

    test_f_d();
    test_c_r();
    test_c_c();
    test_c_d();
    test_r_i();
    test_p();

    printf("End of Game tests : tests succeed !\n");
    return 1;
}

/**
 * Test the function "find_dimension" of game.c file 
 */
void test_f_d(){
    int length;
    int height;

    printf("Next step must fail :\n");
    assert(find_dimension("No file", &length, &height) == 0);
    printf("Next step must fail :\n");
    assert(find_dimension("Test:Wrong_format.txt", &length, &height) == 0);
    assert(find_dimension("data/Current_dim.txt", &length, &height) == 1);
    assert(length == 8);
    assert(height == 6);
}

/**
 * Test the function "check_row" of game.c file 
 */
void test_c_r(){
    struct Matrix m;
    int i;

    m = alloc(8, 6);
    init_matrix(m);
    m.data[4][5] = '1';
    assert(check_row(m, 4, 5) == 0);

    for (i = 0; i < 8; i++){
        m.data[i][0] = '1';
    }
    for (i = 0; i < 8; i++){
        assert(check_row(m, i, 0) == 1);
    }
}

/**
 * Test the function "check_column" of game.c file 
 */
void test_c_c(){
    struct Matrix m;
    int i;

    m = alloc(8, 6);
    init_matrix(m);
    m.data[4][5] = '1';
    assert(check_column(m, 4, 5) == 0);

    for (i = 0; i < 8; i++){
        m.data[0][i] = '1';
    }
    for (i = 0; i < 8; i++){
        assert(check_column(m, 0, i) == 1);
    }
    free_matrix(m);
}

/**
 * Test the function "check_diagonal" of game.c file 
 */
void test_c_d(){
    struct Matrix m;
    int i;
    int j;

    m = alloc(8, 6);
    init_matrix(m);
    m.data[4][5] = '1';
    assert(check_diagonal(m, 4, 5) == 0);

    j = 0;
    for (i = 0; i < 8; i++){
        if (j == 6){
            break;
        }
        m.data[i][j] = '1';
        j++;
    }
    j = 0;
    for (i = 0; i < 8; i++){
        if (j == 6){
            break;
        }
        assert(check_diagonal(m, i, j) == 1);
        j++;
    }
    init_matrix(m);
    j = 5;
    for (i = 7; i > 0; i--){
        if (j == 0){
            break;
        }
        m.data[i][j] = '1';
        j--;
    }
    j = 5;
    for (i = 7; i > 0; i--){
        if (j == 0){
            break;
        }
        assert(check_diagonal(m, i, j) == 1);
        j--;
    }

    free_matrix(m);
}

/**
 * Test the function "randomInt" of game.c file 
 */
void test_r_i(){
    int i;
    int rand_int;

    for (i = 0; i < 10; i++){
        rand_int = random_int(i, 10);
        assert(rand_int >= i && rand_int <= 10);
    }
}

/**
 * Test the function "play" of game.c file 
 */
void test_p(){
    struct Matrix m;
    int i;
    int j;
    int nb_pion;
    int choice_col;
    int choice_row;

    m = alloc(8, 6);
    init_matrix(m);
    for (i = 0; i < 10; i++){
        play(m, 0, &choice_col, &choice_row);
    }
    nb_pion = 0;
    for (i = 0; i < 8; i++){
        for (j = 0; j < 6; j++){
            if (m.data[i][j] == '0'){
                nb_pion++;
            }
        }
    }
    assert(nb_pion == 10);
    init_matrix(m);
    for (i = 0; i < 10; i++){
        play(m, 0, &choice_col, &choice_row);
        assert(choice_col >= 0 && choice_col < 8);
        assert(choice_row >= 0 && choice_row < 6);
        assert(m.data[choice_col][choice_row] == '0');
    }

    free_matrix(m);
}