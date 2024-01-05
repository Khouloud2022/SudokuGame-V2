#include "sudoku.h"


int main() {
    

    int sudokuGrid[9][9] = {0};
    int level;

    printf("                   _____ WELCOME TO SUDOKU GAME _____\n");
    printf("\n");
    printf("      ***   To Start the Game choose the level of difficulty *** \n ");
    printf("                     1. Devil Level \n");
    printf("                     2. Med Level \n");
    printf("                     3. Starter Level \n");
    printf("\n\n Choose the level to Start : ");

    while (1) {
        scanf("%d", &level);
        if (level < 1 || level > 3) {
            printf("Invalid level! Please choose a valid level (1-3): ");
            continue;
        }
        break;
    }
    printf("\n");

    Mask_Pattern(sudokuGrid, level);

    printf("\n                      ** Generated Sudoku **\n");
    SK_print(sudokuGrid);
    printf("\n");
    printf("              * To quit the game tap (-1) \n");
    printf("              To Start you can access the Cells just by (row,col,value)\n");
    printf("\n Your Solution [row] [col] [value] :\n");

    int row, col, val;
    

    while (!EstComplet(sudokuGrid)) {
        printf("Row : ");
        scanf("%d", &row);
        if (row == -1) {
            printf("Quitting the game...\n");
            break;
        }
        printf("Col : ");
        scanf("%d", &col);
        printf("Value : ");
        scanf("%d", &val);

        if (row < 1 || row > 9 || col < 1 || col > 9 || val < 1 || val > 9) {
            printf("Invalid input! Please enter valid row, col, and value (1-9).\n");
            continue;
        }

        row--;
        col--;

        if (!isSafe(sudokuGrid, row, col, val)) {
            printf("Invalid move! Try a different value.\n");
            continue;
        }

        sudokuGrid[row][col] = val;

        printf("\033[H\033[J");
        printf("\n                      ** Generated Sudoku **\n");
        SK_print(sudokuGrid);
    }
    printf("\nCongratulations! You've solved the Sudoku!\n");

    return 0;
}
