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
* @file matrix.h
*/
#ifndef _MATRIX
#define _MATRIX

#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    char **data; /* !< The concrete matrix data. */
    int nrow; /* !< Number of rows. */
    int ncol; /* !< Number of colums. */
};

/**
* Function used to allocate dynamically the array data with the right size
* @param ncol number of colunms of the matrix
* @param nrow number of rows of the matrix
* @return matrix containing a dynamic array of char sized by "ncol" and "nrow"
*/
struct Matrix alloc(int ncol, int nrow);

/**
* Function used to init the Matrix data with default char 'o'
* @param Matrix struct whose data will be initialized
*/
void init_matrix(struct Matrix m);

/**
* Function used to display the Matrix data
* @param Matrix struct whose data will be display
*/
void display_matrix(struct Matrix m);

/**
* Function used to free the dynamic data array of the Matrix
* @param Matrix struct whose dynamic data will be freed
*/
void free_matrix(struct Matrix m);

#endif
