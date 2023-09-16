/*

*/

#include <stdio.h>
#include <stdbool.h>

/*
The Easy edition of the formula
Row 0 > 0   1   2
Row 1 > 3   4   5
Row 2 > 6   7   8
        ^   ^   ^
        0   1   2
          column
*/

bool keyboard[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};
void Num2RowAndCol_Easy(int NUM) {
    keyboard[0][NUM] = true;
}

void PrintTheBoard(void) {
    putchar('\f');
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++)
            if (keyboard[i][j]) putchar('X');
            else putchar('.');
        putchar('\n');
    }
}


int main(void) {
    while (true) {
        PrintTheBoard();
        int PosiInput;
        printf("Choose the position you want to put X: _\b");
        scanf("%d", &PosiInput);
        Num2RowAndCol_Easy(PosiInput);
    }
}