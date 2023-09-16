/*

*/

#include <stdio.h>
#include <stdbool.h>

/*
The Computer Keyboard edition of the formula
Row 0 > 7   8   9
Row 1 > 4   5   6
Row 2 > 1   2   3
        ^   ^   ^
        0   1   2
          column
*/

bool keyboard[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};
void Num2RowAndCol_CK(int NUM) {
    NUM = (NUM-1)%3 + (2-(NUM-1)/3)*3;
    /*
    The explanation of this expression:

    */
    keyboard[0][NUM] = true;
    /*
    The explanation of this instruction:

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
        Num2RowAndCol_CK(PosiInput);
    }
}