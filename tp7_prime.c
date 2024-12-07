#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BOARD_SIZE 4        // La taille du plateau (il y aura BOARD_SIZE^2 cases)
#define ALIGNED_SIZE 3      // La taille des symboles qu'il fait aligner
#define HUMAN_SYMBOL 'X'    // Quand l'humain met son symbole
#define COMPUTER_SYMBOL 'O' // Quand l'ordi met son symbole
#define EMPTY_SYMBOL ' '    // Quand la case est vide, par défaut toutes les cases sont vides


void init_board(char (*board)[BOARD_SIZE]) { // Permet d'initialiser le plateau avec full cases vides
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_SYMBOL;
        }
    }
}


int ask_human_input(char (*board)[BOARD_SIZE]) { // Demande l'entrée du joueur sous la forme "x y"
    int col, row;

    printf("Votre coup (Ctrl + C pour abandonner) : ");
    scanf("%d %d", &row, &col);

    if (board[row][col] != EMPTY_SYMBOL || row >= BOARD_SIZE || col >= BOARD_SIZE || row < 0 || col < 0) {
        return 1; // retourne 1 si l'input n'est pas valide
    } 

    board[row][col] = HUMAN_SYMBOL;
    return 0;
}


void computer_input(char (*board)[BOARD_SIZE]) {
    int random_row, random_column;

    while (1) {
        random_row = rand() % BOARD_SIZE;
        random_column = rand() % BOARD_SIZE;

        if (board[random_row][random_column] == EMPTY_SYMBOL) {
            break;
        }
    }

    board[random_row][random_column] = COMPUTER_SYMBOL;
}


void print_board(char (*board)[BOARD_SIZE]) {   // Clairement explicite, mais il s'adapte à la taille du tableau !
    int i, row, col;

    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (col == 0) {
                printf("%c", board[row][col]);
            } else {
                printf("|%c", board[row][col]);
            }
        }

        if (row != BOARD_SIZE - 1) {
            printf("\n");
            for (i = 0; i < (BOARD_SIZE * 2) - 1; i++) {
                printf("-");
            }
        }
        printf("\n");
    }
}


char check_win_horizontally(char (*board)[BOARD_SIZE]) {    // Check toutes les lignes pour voir qui a gagné
    int i, j;
    int aligned_count = 1;
    char winner_symbol = '\0';

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 1; j < BOARD_SIZE; j++) {
            if (board[i][j] == board[i][j - 1] && board[i][j] != EMPTY_SYMBOL) {
                aligned_count++;
                if (aligned_count == ALIGNED_SIZE) {
                    winner_symbol = board[i][j];
                    return winner_symbol;
                }
            } else {
                aligned_count = 1;
            }
        }
    }

    return winner_symbol;
}

char check_win_vertically(char (*board)[BOARD_SIZE]) {
    int i, j;
    int aligned_count;
    char winner_symbol = '\0';

    // Lowkey not doing this rn 😭

    return winner_symbol;
}


int main(void) {
    srand(time(NULL));  // <--- Those who know 💀 *indian phonk fl studio prime*
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);

    // temporaire, jsp moi
    while (1) {
        while (ask_human_input(board) == 1);
        computer_input(board);
        print_board(board);
    }

    return 0;
}