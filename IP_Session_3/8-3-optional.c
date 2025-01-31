/*
    This program is designed to serve the X's and O's game.
    In this edition, player plays the game with the computer.
    And the computer put the chess in a more clever way.
*/

/*----------------------The Include Part----------------------*/

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

void Put_O_Clever(void) {
    // Part 1 : Declare the user's type definitions.
    //          I define 2 enums and 1 struct to store the data.
    typedef enum {Row_1, Row_2, Row_3, Col_1, Col_2, Col_3, Slant_1, Slant_2, None} Line;
    typedef enum {Rank_1, Rank_2, Rank_3} Priority;
    typedef struct { Line line; Priority priority; } ToDo;
    ToDo todo = {None,Rank_3}; // Use a struct to store it's decision.
    // Part 2 : To find whether there is a line already have 2 chesses of one player.
    //          This is the most prior thing the computer need to deal with.
    int Row_sum, Col_sum, Slant_sum_1 = 0, Slant_sum_2 = 0;
    for (int i=0; i<3; i++) {
        Row_sum = Col_sum = 0;
        for (int j=0; j<3; j++) {
            Row_sum += keyboard[i][j];
            Col_sum += keyboard[j][i];
        }
        if (Row_sum==2)     { todo.line = (Line)(i);   todo.priority = Rank_1; }
        if (Col_sum==2)     { todo.line = (Line)(i+3); todo.priority = Rank_1; }
        if (Row_sum==-2 && todo.priority>Rank_2)    { todo.line = (Line)(i);   todo.priority = Rank_2; }
        if (Col_sum==-2 && todo.priority>Rank_2)    { todo.line = (Line)(i+3); todo.priority = Rank_2; }
        Slant_sum_1 += keyboard[i][i];
        Slant_sum_2 += keyboard[i][2-i];
    }
    if (Slant_sum_1==2)     { todo.line = Slant_1; todo.priority = Rank_1; }
    if (Slant_sum_2==2)     { todo.line = Slant_2; todo.priority = Rank_1; }
    if (Slant_sum_1==-2 && todo.priority>Rank_2)    { todo.line = Slant_1; todo.priority = Rank_2; }
    if (Slant_sum_2==-2 && todo.priority>Rank_2)    { todo.line = Slant_2; todo.priority = Rank_2; }
    // Part 3 : Deal with the line according to the result.
    //          When the priority is upper than Rank_3, fill the only position left.
    if (todo.priority!=Rank_3) {
        if (todo.line>=Row_1 && todo.line<=Row_3) 
            for (int i=0; i<3; i++) 
                if (!keyboard[todo.line][i]) keyboard[todo.line][i] = O;
        if (todo.line>=Col_1 && todo.line<=Col_3)
            for (int i=0; i<3; i++)
                if (!keyboard[i][todo.line-3]) keyboard[i][todo.line-3] = O;
        if (todo.line==Slant_1)
            for (int i=0; i<3; i++)
                if (!keyboard[i][i]) keyboard[i][i] = O;
        if (todo.line==Slant_2)
            for (int i=0; i<3; i++)
                if (!keyboard[i][2-i]) keyboard[i][2-i] = O;
    }
    // Part 4 : If there are no line that must to be dealed with, check if the center was filled.
    //          If the center is filled, fill one corner randomly.
    //          If the corners are all filled, fill one side randomly.
    else if (todo.priority==Rank_3) {
        if (!keyboard[1][1]) keyboard[1][1] = O;
        else if (!keyboard[0][0]+!keyboard[0][2]+!keyboard[2][0]+!keyboard[2][2]) {
            int i, j;
            do {
                i = rand()%2*2; j = rand()%2*2;
            } while (keyboard[i][j]);
            keyboard[i][j] = O;
        }
        else {
            int i;
            do {
                i = rand()%4*2+1;
            } while (keyboard[0][i]);
            keyboard[0][i] = O;         // The comment is the same as Line 162
        }
    }
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
    srand(time(NULL));          // Init the Random Numbers according to the time.
    Print_Board();
    while (true) {
        Put_X_fromPlayer();
        if (isEnded()) break;
        Put_O_Clever();
        if (isEnded()) break;
    }
}