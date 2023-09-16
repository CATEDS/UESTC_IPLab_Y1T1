/*

*/

#include <stdio.h>
#include <stdbool.h>

/*
The Mobile edition of the formula
Row 0 > 1   2   3
Row 1 > 4   5   6
Row 2 > 7   8   9
        ^   ^   ^
        0   1   2
          column
*/

bool keyboard[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};
void Num2RowAndCol_Mobile(int NUM) {
    keyboard[0][NUM-1] = true;
    /*
    The explanation the code I white here:

    */
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
        Num2RowAndCol_Mobile(PosiInput);
    }
}