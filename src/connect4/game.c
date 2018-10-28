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
#include <time.h>
#include <game.h>

/**
* Clears the console that runs the programs
*/
void clear_console(){
    system("clear");
}

/**
* Find the dimension of the board into a file in arguments
* @param filename where to find the dimension
* @param length pointeur that collect the length of the board
* @param height pointeur that collect the height of the board
* @return int value 1 if the dimension have been found and 0 otherwise 
*/
int find_dimension(char *filename, int *length, int *height){
    FILE *fd;

    fd = NULL;
    fd = fopen(filename, "r");
    if (fd != NULL){
        if (fscanf(fd, "%d, %d", length, height) != 2){
            perror("Wrong format of file !\n");
            fclose(fd);
            return 0;
        }
        fclose(fd);
        return 1;
    } else {
        perror("File not found ! \n");
        return 0;
    }
}

/**
* Check if there is a winner in the board
* @param Matrix that stocking the board
* @param col of the last placed pawn
* @param row of the last placed pawn
* @return int value 1 if there is a winner in the game and 0 otherwise 
*/
int check_winner(struct Matrix m, int col, int row){
    return check_row(m, col, row) || check_column(m, col, row) || check_diagonal(m, col, row);
}

/**
* Check if there is a winner in the row of the last pawn 
* @param Matrix that stocking the board
* @param col of the last placed pawn
* @param row of the last placed pawn
* @return int value 1 if there is a winning situation in the row and 0 otherwise 
*/
int check_row(struct Matrix m, int col, int row){
    char pawn;
    int i;
    int j;

    pawn = m.data[col][row];

    i = col - 1;
    while (i >= 0 && m.data[i][row] == pawn){
        i--;
    }
    i++;

    j = col + 1;
    while (j < m.ncol && m.data[j][row] == pawn){
        j++;
    }
    j--;

    if (j-i+1 >= 4){
        return 1;
    } else {
        return 0;
    }
}

/**
* Check if there is a winner in the column of the last pawn 
* @param Matrix that stocking the board
* @param col of the last placed pawn
* @param row of the last placed pawn
* @return int value 1 if there is a winning situation in the column and 0 otherwise 
*/
int check_column(struct Matrix m, int col, int row){
    char pawn;
    int i;
    int j;

    pawn = m.data[col][row];

    i = row - 1;
    while (i >= 0 && m.data[col][i] == pawn){
        i--;
    }
    i++;

    j = row + 1;
    while (j < m.nrow && m.data[col][j] == pawn){
        j++;
    }
    j--;

    if (j-i+1 >= 4){
        return 1;
    } else {
        return 0;
    }
}

/**
* Check if there is a winner in the diagonals of the last pawn 
* @param Matrix that stocking the board
* @param col of the last placed pawn
* @param row of the last placed pawn
* @return int value 1 if there is a winning situation in the diagonals of the last pawn and 0 otherwise 
*/
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

/**
* Randomly shoot a integer between min and max
* @param min Minus bound of the search interval
* @param max Max bound of the search interval
* @return int randomly shot 
*/
int random_int(int min, int max){
    
    srand(time(NULL));
    return rand() % (max - min) + min;
}

/**
* Launches the pawn placement procedure
* @param Matrix that stocking the board
* @param player integer of the current player
* @param choice_c pointer that collect the column choice of the player
* @param choice_r pointer that collect the row of the pawn after the placement
*/
void play(struct Matrix m, int player, int *choice_c, int *choice_r){
    int choice;
    int i;

    do {
        if (player == 1){
            do{
                printf("Which colum do you choose, player ?");
                scanf("%d", &choice);
            } while (choice < 0 || choice >= m.ncol);
        } else {
            choice = random_int(0, m.ncol - 1);
        }  
    } while (m.data[choice][0] != 'o');

    i=m.nrow-1;
    while (m.data[choice][i] != 'o'){
        i--;
    }
    m.data[choice][i] = player + '0';
    *choice_c = choice;
    *choice_r = i;
}