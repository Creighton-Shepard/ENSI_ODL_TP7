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
* @file matrix.c
*/

#include <matrix.h>

/**
* Function used to allocate dynamically the array data with the right size
* @param ncol number of colunms of the matrix
* @param nrow number of rows of the matrix
* @return matrix containing a dynamic array of char sized by "ncol" and "nrow"
*/
struct Matrix alloc(int ncol, int nrow){
    struct Matrix m;
    int i;
    int j;

    if (ncol <= 0 || nrow <= 0){
        m.data = NULL;
        return m;
    }
    m.ncol = ncol;
    m.nrow = nrow;
    m.data=NULL;
    m.data = (char **) malloc(m.ncol * sizeof(char *));
    if (m.data == NULL){
        perror("Error during the dynamic allocation of the main part of the matrix\n");
        exit(1);
    }
    for (i = 0; i < m.ncol; i++){
        m.data[i] = (char *) malloc(m.nrow * sizeof(char));
        if (m.data[i] == NULL){
            perror("Error during the dynamic allocation of one of the secondary parts of the matrix\n");
            for (j = i - 1; j >= 0; j++){
                free(m.data[j]);
            }
            free(m.data);
            exit(1);
        }
    }
    return m;
}

/**
* Function used to init the Matrix data with default char 'o'
* @param Matrix struct whose data will be initialized
*/
void init_matrix(struct Matrix m){
    int i;
    int j;

    if (m.data != NULL){
        for (i = 0; i < m.ncol; i++){
            for (j = 0; j < m.nrow; j++){
                m.data[i][j] = 'o';
            }
        }
    } else {
        perror("Error : Can't init null matrix data !\n");
        exit(1);
    }
}

/**
* Function used to display the Matrix data
* @param Matrix struct whose data will be display
*/
void display_matrix(struct Matrix m){
    int i;
    int j;

    if (m.data != NULL){
        for (i = 0; i < m.nrow; i++){
            for (j = 0; j < m.ncol; j++){
                switch(m.data[j][i]){
                    case 'o':
                        printf("|     |");
                        break;
                    case '1':
                        printf("|  %c  |", 'X');
                        break;
                    case '0':
                        printf("|  %c  |", 'O');
                        break;
                    default :
                        printf("|  E  |");
                }
            }
            printf("\n");
        }
        for (i = 0; i < m.ncol; i++){
            printf("=======");
        }
        printf("\n");
        for (i = 0; i < m.ncol; i++){
            printf("|  %d  |", i);
        }
        printf("\n");
        for (i = 0; i < m.ncol; i++){
            printf("=======");
        }
        printf("\n");
    } else {
        perror("Error : Can't display null matrix data !\n");
        exit(1);
    }
}

/**
* Function used to free the dynamic data array of the Matrix
* @param Matrix struct whose dynamic data will be freed
*/
void free_matrix(struct Matrix m){
    int i;

    for (i = 0; i < m.ncol; i++){
        free(m.data[i]);
    }
    free(m.data);
}