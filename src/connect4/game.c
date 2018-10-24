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
* @file game.c
*/

#include <matrix.h>

int check_winner(struct Matrix m, int col, int row){
    return check_row || check_column || check_diagonal;
}

int check_row(struct Matrix m, int col, int row){
    char pawn;
    int i;
    int j;

    pawn = m.data[i][j];

    i = col - 1;
    while (i >= 0 && m.data[i][row] == pawn){
        i--;
    }
    i++;

    j = col + 1;
    while (j >= m.ncol && m.data[j][row] == pawn){
        j++;
    }
    j--;

    if (j-i+1 >= 4){
        return 1;
    } else {
        return 0;
    }
}

int check_column(struct Matrix m, int col, int row){
    char pawn;
    int i;
    int j;

    pawn = m.data[i][j];

    i = row - 1;
    while (i >= 0 && m.data[col][i] == pawn){
        i--;
    }
    i++;

    j = row + 1;
    while (j >= m.nrow && m.data[col][j] == pawn){
        j++;
    }
    j--;

    if (j-i+1 >= 4){
        return 1;
    } else {
        return 0;
    }
}

int check_diagonal(struct Matrix m, int col, int row){
    char pawn;
    int i_diag_h;
    int j_diag_h;
    int i_diag_b;
    int j_diag_b;

    pawn = m.data[col][row];

    i_diag_h = col - 1;
    j_diag_h = row - 1;
    while (i_diag_h >= 0 && j_diag_h >= 0 && m.data[i_diag_h][j_diag_h] == pawn){
        i_diag_h--;
        j_diag_h--;
    }
    i_diag_h++;
    j_diag_h++;

    i_diag_b = col + 1;
    j_diag_b = row + 1;
    while (i_diag_b < m.ncol  && j_diag_b < m.nrow && m.data[i_diag_b][j_diag_b] == pawn){
        i_diag_b++;
        j_diag_b++;
    }
    i_diag_b--;
    j_diag_b--;

    if (i_diag_b-i_diag_h+1 >= 4 && j_diag_b-j_diag_h+1 >= 4){
        return 1;
    } else {
        i_diag_h = col + 1;
        j_diag_h = row - 1;
        while (i_diag_h < m.ncol && j_diag_h >= 0 && m.data[i_diag_h][j_diag_h] == pawn){
            i_diag_h++;
            j_diag_h--;
        }
        i_diag_h--;
        j_diag_h++;

        i_diag_b = col - 1;
        j_diag_b = row + 1;
        while (i_diag_b >= 0  && j_diag_b < m.nrow && m.data[i_diag_b][j_diag_b] == pawn){
            i_diag_b--;
            j_diag_b++;
        }
        i_diag_b++;
        j_diag_b--;

        if (i_diag_h-i_diag_b+1 >= 4 && j_diag_b-j_diag_h+1 >= 4){
            return 1;
        } else {
            return 0;
        }
    }
}

void play(struct Matrix m, int player){
    int choice;

    do{
        printf("Which colum do you choose, player ?");
        scanf("%d", &choice);
    } while (choice < 0 || choice >= m.ncol);
}