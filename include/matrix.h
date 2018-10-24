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

struct Matrix alloc(int ncol, int nrow);

void init_matrix(struct Matrix m);

void display_matrix(struct Matrix m);

void free_matrix(struct Matrix m);

#endif
