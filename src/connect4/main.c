#include <matrix.h>
#include <game.h>

/**
* Main function of the game
* @param argc number of arguments of the function
* @param argv String array stocking arguments of the function
* @return int value 0 if the program ran without errors
*/
int main(int argc, char* argv[]){
    int currentplayer; /* 0 = Computer and 1 = Player */ 
    struct Matrix m;
    int length;
    int height;
    int choice_r;
    int choice_c;

    if (argc == 2){
        if (find_dimension(argv[1], &length, &height) == 1){
            m = alloc(length, height);
            init_matrix(m);
            currentplayer = 1;
            currentplayer = random_int(0, 1);
            if (currentplayer == 1){
                printf("The Player starts !\n");
            } else {
                printf("The Computer starts !\n");
            }
            do {
                clear_console();
                display_matrix(m);
                play(m, currentplayer, &choice_c, &choice_r);
                currentplayer == 1 ? currentplayer-- : currentplayer++;
            } while (check_winner(m, choice_c, choice_r) != 1);
            clear_console();
            display_matrix(m);
            if (currentplayer == 1){
                printf("The Computer wons !\n");
            } else {
                printf("The Player wons !\n");
            }
            free_matrix(m);
        } else {
            exit(1);
        }
    } else {
        if (argc < 2){
            perror ("Too few arguments for this program !\n");
        } else {
            perror ("Too many arguments for this program !\n");
        }
        exit(1);
    }
    return 0;
}