/*
    TODO
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

enum KB {None, X=-1, O=1};
enum KB keyboard[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};
void Put_Num2RowAndCol_CK(int NUM, enum KB piece) {
    NUM = (NUM-1)%3 + (2-(NUM-1)/3)*3;
    /*
    The explanation of this expression:
        ODO
    */
    keyboard[0][NUM] = piece;
    /*
    The explanation of this instruction:
        TODO
    */
}

void PrintTheBoard(void) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++)
            if (keyboard[i][j] == -1) putchar('X');
            else if (keyboard[i][j] == 1) putchar('O');
            else putchar('.');
        putchar('\n');
    }
}

bool isEnded(void) {
    int isFilled = 0;
    int Verti, Hori;
    int Slant_1 = 0, Slant_2 = 0;
    for (int i=0; i<3; i++) {
        Verti = 0; Hori = 0;
        for (int j=0; j<3; j++) {
            Verti += keyboard[j][i];
            Hori += keyboard[i][j];
            if (i==0) {
                Slant_1 += keyboard[j][j];
                Slant_2 += keyboard[j][2-j];
            }
            if (keyboard[i][j]) isFilled++;
        }
        if (Verti == -3 || Hori == -3 || Slant_1 == -3 || Slant_2 == -3) {
            printf("The person play X win the game.\n");
            return true;
        }
        if (Verti == 3 || Hori == 3 || Slant_1 == 3 || Slant_2 == 3) {
            printf("The person play O win the game.\n");
            return true;
        }
    }
    if (isFilled == 9) {
        printf("No one won the game!\n");
        return true;
    }
    return false;
}

int main(void) {
    PrintTheBoard();
    while (true) {
        int PosiInput;
        printf("Choose the position you want to put X: _\b");
        scanf("%d", &PosiInput);
        Put_Num2RowAndCol_CK(PosiInput, X);
        PrintTheBoard();
        if (isEnded()) break;
        printf("Choose the position you want to put O: _\b");
        scanf("%d", &PosiInput);
        Put_Num2RowAndCol_CK(PosiInput, O);
        PrintTheBoard();
        if (isEnded()) break;
    }
}