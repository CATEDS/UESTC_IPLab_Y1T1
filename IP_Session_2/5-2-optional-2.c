/*
This Program is designed to deal with the (second) optional form of
5.2 Exercise, which required to generate a number between
a random range. Then ask the user to guess the accurate number generated.
In addition, the program will tell the user extra information of the number.
And the game will work for 4 times in total. After the whole process, 
the program is required not to tell you the best score you have made during the game.
*/

// TODO

#include <stdio.h>      // Include the standard I/O library
#include <stdlib.h>     // Include the standard library
#include <stdbool.h>    // Include the standard boolean library
#include <time.h>       // Include the time library

int GuessNumber(void);  // Declare the GuessNumber() function

int main(void) {                                                            // Define the main() function
    for (int i=0; i<4; i++) {                                               // Doing the guess game for 4 times
        int Guesses = GuessNumber();                                        // Process GuessNumber() and get the guesses number as return value
        printf("It takes you %d guesses to find the number.\n", Guesses);   // Print the result of the guess game
    }
    printf("Let's end the game :)\n");                                      // Print the end of the game
    return 0;                                                               // Exit the main function
}

int GuessNumber(void) {
    srand((int)time(NULL));                                                             // Set the random seed for rand()
    int canBeDividedBy = rand()%10;
    int RightAnswer = (rand()%100-50)*canBeDividedBy;
    int LowerBound = RightAnswer - rand()%100;
    int UpperBound = RightAnswer + rand()%100;
    int Answer;                                                                         // Init the random variable to get the answer from the user
    int GuessesTime = 0;                                                                // Init the Guess times variable to calculate the result
    printf("Guess the integer between %d and %d.\n", LowerBound, UpperBound);           // Output the guide line
    printf("The number can be exactly divided by %d.\n", canBeDividedBy);               // Print the extra information of the right answer
    while (true) {                                                                      // Loop until the answer was right
        printf("Please enter your guess: __\b\b");                                      // Print the line to get the value
        scanf("%d", &Answer);                                                           // Get the value from the user's input
        GuessesTime++;                                                                  // Count the guess times
        if (Answer == RightAnswer) break;                                               // If get the right answer, the game will end
        else if (Answer < RightAnswer)                                                  // If get the answer smaller than the right one, it gives user some help
            printf("Your answer is smaller than the right answer.\n");
        else if (Answer > RightAnswer)                                                  // If get the answer bigger than the right one, it gives user some help
            printf("Your answer is bigger than the right answer.\n");
    }
    printf("Your find the right answer!\n");                                              // Print the line to tell the user the game ended
    return GuessesTime;                                                                 // Return the guess times as the return value
}
