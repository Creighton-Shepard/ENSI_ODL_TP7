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
* @file game.h
*/
#ifndef _GAME
#define _GAME

/**
* Clears the console that runs the programs
*/
void clear_console();

/**
* Find the dimension of the board into a file in arguments
* @param filename where to find the dimension
* @param length pointeur that collect the length of the board
* @param height pointeur that collect the height of the board
* @return int value 1 if the dimension have been found and 0 otherwise 
*/
int find_dimension(char *filename, int *length, int *height);

/**
* Check if there is a winner in the board
* @param Matrix that stocking the board
* @param col of the last placed pawn
* @param row of the last placed pawn
* @return int value 1 if there is a winner in the game and 0 otherwise 
*/
int check_winner(struct Matrix m, int col, int row);

/**
* Check if there is a winner in the row of the last pawn 
* @param Matrix that stocking the board
* @param col of the last placed pawn
* @param row of the last placed pawn
* @return int value 1 if there is a winning situation in the row and 0 otherwise 
*/
int check_row(struct Matrix m, int col, int row);

/**
* Check if there is a winner in the column of the last pawn 
* @param Matrix that stocking the board
* @param col of the last placed pawn
* @param row of the last placed pawn
* @return int value 1 if there is a winning situation in the column and 0 otherwise 
*/
int check_column(struct Matrix m, int col, int row);

/**
* Check if there is a winner in the diagonals of the last pawn 
* @param Matrix that stocking the board
* @param col of the last placed pawn
* @param row of the last placed pawn
* @return int value 1 if there is a winning situation in the diagonals of the last pawn and 0 otherwise 
*/
int check_diagonal(struct Matrix m, int col, int row);

/**
* Randomly shoot a integer between min and max
* @param min Minus bound of the search interval
* @param max Max bound of the search interval
* @return int randomly shot 
*/
int random_int(int min, int max);

/**
* Launches the pawn placement procedure
* @param Matrix that stocking the board
* @param player integer of the current player
* @param choice_c pointer that collect the column choice of the player
* @param choice_r pointer that collect the row of the pawn after the placement
*/
void play(struct Matrix m, int player, int *choice_c, int *choice_r);

#endif
