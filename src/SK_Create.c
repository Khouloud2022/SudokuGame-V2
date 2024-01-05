#include "sudoku.h"

void SK_print(int SG[9][9]) {

        printf("                  --------- --------- ---------\n");
   for (int i = 0; i < 9; i++){
        printf("                 |");
        for (int j = 0; j < 9; j++) {
            printf(" %d ", SG[i][j]);
             if(((j+1) % 3) == 0)
                  {
                       printf("|");
                  }
        }
        printf("\n");
        if(((i+1) % 3) == 0)
          {
         printf("                  --------- -------- ----------\n");
          }
    }
}

//fonction pour confirmer si la valeur safe pour le deplacer dans la position donner
bool isSafe(int SG[9][9], int l, int c, int num) {
    // controler les lignes
    for (int x = 0; x < 9; x++) {
        if (SG[l][x] == num) {
            return false;
        }
    }

    // controler les colonnes
    for (int y = 0; y < 9; y++) {
        if (SG[y][c] == num) {
            return false;
        }
    }

     // Controle de grid
    int startligne = l - (l % 3);
    int startCol = c - (c % 3);
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (SG[x + startligne][y + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}


// Fonction pour resoudre Sudoku on utilisant le backtracking method
bool ResoudreSudoku(int SG[9][9]) {
    int lig, col;

    // Controler les cells vide
    bool EstVide = false;
    for (lig = 0; lig < 9; lig++) {
        for (col = 0; col < 9; col++) {
            if (SG[lig][col] == 0) {
                EstVide = true;
                break;
            }
        }
        if (EstVide) {
            break;
        }
    }

      // Si il n ya pas des case vide le sudoku est solved
    if (!EstVide) {
        return true;
    }

    // try des autres nbres pour les cases vide
    for (int num = 1; num <= 9; num++) {
        if (isSafe(SG, lig, col, num)) {
            SG[lig][col] = num;

            if (ResoudreSudoku(SG)) {
                return true;
            }

            SG[lig][col] = 0; // Reset les cases si pas de solution trouver
        }
    }

    return false;
}


// fonction pour initialer une soduko grid unique
void Generate_SG(int SG[9][9]) {
 
     // 1er etape creation de matrice intiale: prototype matrice pour le shuffle
    int Grid_intial[9][9] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {4, 5, 6, 7, 8, 9, 1, 2, 3},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {2, 3, 1, 5, 6, 4, 8, 9, 7},
        {5, 6, 4, 8, 9, 7, 2, 3, 1},
        {8, 9, 7, 2, 3, 1, 5, 6, 4},
        {3, 1, 2, 6, 4, 5, 9, 7, 8},
        {6, 4, 5, 9, 7, 8, 3, 1, 2},
        {9, 7, 8, 3, 1, 2, 6, 4, 5}
    };

    // 2eme etape  shuffle les nombres dans le matrice 
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            SG[i][j] = Grid_intial[i][j];
        }
    }
}

// fonction pour confirmer si le sudoku est unique utilisant le fonction ResoudreSoduku
bool SolutionUnique(int SG[9][9]) {
    int tmp[9][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            tmp[i][j] = SG[i][j];
        }
    }

    // Resoudre le grid
    return ResoudreSudoku(tmp);
}

// fonction pour masker les cases 
void Mask_Pattern(int SG[9][9],int level) {
    Generate_SG(SG);

    //easy level : 27 to 36 -->45 emty cells
    //Med level : 19 to 26 --->55 emty cells
    //devil level: under 18 --> 64 empty cells
    int maskedCase=0;

    if (level == 1)
            maskedCase = 64;
    else if (level == 2)
            maskedCase = 55;
    else
            maskedCase = 45;

    while (maskedCase > 0) {
        int ligne = rand() % 9;
        int col = rand() % 9;

        if (SG[ligne][col] != 0) {
            int tmp = SG[ligne][col];
            SG[ligne][col] = 0;

            if (!SolutionUnique(SG)) {
                SG[ligne][col] = tmp;
            } else {
                maskedCase--;
            }
        }
    }
}

bool EstComplet(int sudokuGrid[9][9]) {
    
    for (int ligne = 0; ligne < 9; ligne++) {
        for (int col = 0; col < 9; col++) {
            if (sudokuGrid[ligne][col] == 0) {
                return false;
            }
        }
    }
    return true;
}
