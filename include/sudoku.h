#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void SK_print(int SG[9][9]);
void Mask_Pattern(int SG[9][9],int level);
bool isSafe(int SG[9][9], int l, int c, int num);
bool ResoudreSudoku(int SG[9][9]);
bool EstComplet(int sudokuGrid[9][9]);
