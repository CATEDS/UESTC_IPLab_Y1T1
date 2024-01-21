/*
 *  This Program is designed to deal with the original form of
 *  5.2 Exercise, which required to generate a number between
 *  1 and 32. Then ask the user to guess the accurate number generated.
 *  And the game will work for 4 times in total. After the whole process, 
 *  the program will tell you the best score you have made during the game.
 */

#include <stdio.h>                                                          // Include the standard I/O library
#include <stdlib.h>                                                         // Include the standard library
#include <stdbool.h>                                                        // Include the standard boolean library
#include <time.h>                                                           // Include the time library

int GuessNumber(void);                                                      // Declare the GuessNumber() function

int main(void) {                                                            // Define the main() function
    int BestScore = INT_MAX;                                                // Init the variable to store the best score of the game
    while (BestScore > 4) {                                                 // Play the game until the player finish the game within 4 guesses.
        int Guesses = GuessNumber();                                        // Process GuessNumber() and get the guesses number as return value
        BestScore = (BestScore>Guesses)?Guesses:BestScore;                  // Refresh the best score if user achieves a lower score
        printf("It takes you %d guesses to find the number.\n", Guesses);   // Print the result of the guess game
        printf("The best score is %d till now.\n", BestScore);              // Print the best score till now
    }
    printf("Let's end the game :)\n");                                      // Print the end of the game
    return 0;                                                               // Exit the main function
}

int GuessNumber(void) {
    srand((int)time(NULL));                                                 // Set the random seed for rand()
    int RightAnswer = rand()%32+1;                                          // Decide the right answer of the game by random
    int Answer;                                                             // Init the random variable to get the answer from the user

        // CHEAT LINE
        printf("%d\n",RightAnswer);

    int GuessesTime = 0;                                                    // Init the Guess times variable to calculate the result
    printf("Guess the integer between 1 and 32.\n");                        // Output the guide line
    while (true) {                                                          // Loop until the answer was right
        printf("Please enter your guess: __\b\b");                          // Print the line to get the value
        scanf("%d", &Answer);                                               // Get the value from the user's input
        GuessesTime++;                                                      // Count the guess times
        if (Answer == RightAnswer) break;                                   // If get the right answer, the game will end
        else if (Answer < RightAnswer)                                      // If get the answer smaller than the right one, it gives user some help
            printf("Your answer is smaller than the right answer.\n");
        else if (Answer > RightAnswer)                                      // If get the answer bigger than the right one, it gives user some help
            printf("Your answer is bigger than the right answer.\n");
    }
    printf("Your find the right answer!\n");                                // Print the line to tell the user the game ended
    return GuessesTime;                                                     // Return the guess times as the return value
}
