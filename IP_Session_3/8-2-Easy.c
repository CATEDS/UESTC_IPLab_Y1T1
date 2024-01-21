/*
    This function is designed to get the EASY form of input and store it in
    the correct position of the array. And if the keyboard is filled, we
    should end the game.
*/

#include <stdio.h>
#include <stdbool.h>

/*
    The Easy edition of the formula

    Row 0 >     0   1   2
    Row 1 >     3   4   5
    Row 2 >     6   7   8

                ^   ^   ^
                0   1   2
                column
*/

// The array to store the content of keyboard
bool board[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

// This function is designed to print the content in the array board[3][3],
// and I use for loop twice to deal with the problem.
void Print_Board(void) {
    putchar('\f');
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++)
            if (board[i][j]) putchar('X');
            else putchar('.');
        putchar('\n');
    }
}

// The function to get input from player, check whether the input is valid,
// then put the value in the array board[3][3].
void Put_X(void) {   // For the Easy edition of the fomula
    while (true) {
        printf("Choose the position you want to put X: _\b");
        int PosiInput;
        scanf("%d", &PosiInput);
        if (
            PosiInput>=0 && PosiInput <= 8 &&
            !board[0][PosiInput]
            ) {
            board[0][PosiInput] = true;
            /*
                The explanation of this instruction:
                Actually, we know that the 2-D Array of y rows and x columns can also be treated
                as an 1-D Array of x*y nodes.
                And the type of the name of a 2-D Array can be treated as int**. So the value of the 
                Keyboard[0][NUM] (Even NUM is bigger than the colunms) is actually **(ptr + NUM)
                So it's also a accessible way to use the array.
            */
            break;
        }
        else printf("Invalid Input!\n");
        Print_Board();
    }
}

bool isEnded(void) {
    int sum = 0;
    for (int i=0; i<9; i++)
        sum += board[0][i];
    return (sum==9)?true:false;
    /*
        The value of true is 1, and the value of false is 0.
        If and only if we fill the keyboard, the sum of all the value could be 9.
        That's the reason I write the function like this.
    */
}

/*--------------------The Main Function Part--------------------*/


int main(void) {    // The Main Function
    while (true) {
        Print_Board();      // Print the board at first
        if (isEnded()) {    // If the board is filled, make the game ended
            printf("The board is filled.\n");
            break;
        }
        Put_X();            // Get the input
    }
}