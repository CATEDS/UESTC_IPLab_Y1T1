/*
    This program is designed to serve the X's and O's game.
    In this edition, player plays the game with the computer.
    And the computer put the chess totally randomly.
*/

/*-------------------The Include Part-------------------*/

#include <stdio.h>      // Include the standard I/O Library
#include <stdbool.h>    // Include the standard bool Library
#include <time.h>       // Include the time Library
#include <stdlib.h>     // Include the standard library

/*
        Computer Keyboard                     Easy

Row 0 >     7   8   9           Row 0 >     0   1   2
Row 1 >     4   5   6           Row 1 >     3   4   5
Row 2 >     1   2   3           Row 2 >     6   7   8

            ^   ^   ^                       ^   ^   ^
            0   1   2                       0   1   2
              column                          column
*/

/*-------------------The User Definition Part-------------------*/

typedef enum {None, X=-1, O=1} KB;  // Define the status of the keyboard
KB keyboard[3][3] = {  // Define and init the keyboard with 3 rows and 3 columns.
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

/*-------------------The User Function Part-------------------*/

void Print_Board(void) {                                                    // Define the function to clear the page and print the game board
    printf("\n\n\n\n\n\n\n\n\n\n");                                         // Use the given way to clear the page.
    for (int i=0; i<3; i++) {                                               // Use the loop to traverse the rows.
        for (int j=0; j<3; j++)                                             // Use the loop to traverse the columns.
            if (keyboard[i][j] == X) putchar('X');                          // Print the X if there is an X on the position
            else if (keyboard[i][j] == O) putchar('O');                     // Print the O if there is an O on the position
            else putchar('.');                                              // Print the . if there is no chessman here.
        putchar('\n');                                                      // Turn to print the next row.
    }
}

bool isEnded(void) {                                                        // Define the isEnded() function to test if someone won the game
    int isFilled = 0, Verti, Hori, Slant_1 = 0, Slant_2 = 0;                // Declare the variables
    for (int i=0; i<3; i++) {                                               // Use a loop to test all the conditions of winning the game
        Verti = 0; Hori = 0;                                                // Init the Verti(cally) and Hori(zonally) sum value of the lines
        for (int j=0; j<3; j++) {                                           // Use the second loop to test all the conditions of winning the game
            Verti += keyboard[j][i];                                        // Sum up all the chessman status of a line. If the sum is +3, then the man play O won the game.
            Hori += keyboard[i][j];                                         // And if the sum is -3, then the man plays X won the game.
            if (i==0) {                                                     // Only sum the slant line value for one time (or said "only in i==1")
                Slant_1 += keyboard[j][j];                                  // Calculate the sum of Slant line top-left corner up bottom-right corner.
                Slant_2 += keyboard[j][2-j];                                // Calculate the sum of Slant line top-right corner up bottom-left corner.
            }
            if (keyboard[i][j]) isFilled++;                                 // Examine if all the positions are filled with chessmans. If so, then end the game.
        }
        if (Verti == -3 || Hori == -3 || Slant_1 == -3 || Slant_2 == -3) {  // Whenever the sum of one line reach -3. the person plays X wins the game.
            printf("The person play X wins the game.\n");                   // Print the line to tell the winner of the game.
            return true;                                                    // Return the value to tell the program that the game is ended.
        }
        if (Verti == 3 || Hori == 3 || Slant_1 == 3 || Slant_2 == 3) {      // Whenever the sum of one line reach +3. the person plays O wins the game.
            printf("The person play O wins the game.\n");                   // Print the line to tell the winner of the game.
            return true;                                                    // Return the value to tell the program that the game is ended.
        }
    }
    if (isFilled == 9) {                                                    // Examine if all the positions are filled with chessmans. If so, then end the game.
        printf("No one won the game!\n");                                   // Print the line to tell the winner of the game.
        return true;                                                        // Return the value to tell the program that the game is ended.
    }
    return false;                                                           // Return the value to tell the program that the game is not ended.
}

void Put_O_ByRandom(void) {
    srand(time(NULL));              // Set the seed of the set of random number
    int row, col;
    do {
        row = rand()%3;             // Get the number by random
        col = rand()%3;
    } while (keyboard[row][col]);   // Which means do the process until it's not empty
    keyboard[row][col] = O;
    Print_Board();
}

void Put_X_fromPlayer(void) {
    while (1) {
        int PosiInput;
        printf("Choose the position you want to put X: _\b");
        scanf("%d", &PosiInput);
        PosiInput = (PosiInput-1)%3 + (2-(PosiInput-1)/3)*3;
        /*
            The explanation of this expression:
            It's an expression that can convert the input of the computer keyboard
            to the position of the "easy" pattern.
            We use (NUM-1)/3 to count the row number (Computer Keyboard), then use
            2-(NUM-1)/3 to count the row number (Easy).
            Also we use (NUM-1)%3 to count the column number.
            Finally, we use Row*3 + Colunm to calculate the number of the keyboard (Easy)
        */
        if (!keyboard[0][PosiInput]) {  // This statement means this block is empty
            keyboard[0][PosiInput] = X;
            Print_Board();
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
        Print_Board();
        printf("Invalid Input!\n");
    }
}
/*-------------------The Main Function Part-------------------*/

int main(void) {
    Print_Board();
    while (true) {
        Put_X_fromPlayer();
        if (isEnded()) break;
        Put_O_ByRandom();
        if (isEnded()) break;
    }
}