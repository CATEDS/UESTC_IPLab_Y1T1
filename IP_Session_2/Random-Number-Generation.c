// The example program in "Random Number generation.pdf"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// Random number generation
float getRand() {
    return rand() / (RAND_MAX + 1.0);
}
// guessing function where we pass the correct answer as an argument
int guess(int correct_answer) {
    int count = 0;
    while (count < 5) {
        printf("guess the number from 1 - 32:\t");
        int i;
        scanf("%d", &i); // enters the value to be guessed
        if (i == correct_answer) {
            printf("correct\n");
            printf("you win\n");
            return 1;
        }
        else if (i < correct_answer) {
            printf("too low\n");
            if (count == 4) {
                printf("you lose\n");
                printf("0");
                return 0;
            }
            count++;
            continue;
        }
        else { 
            printf("too high\n");
            if (count == 4) {
                printf("you lose\n");
                printf("0");
                return 0;
            }
            count++;
            continue;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL)); // init random
    float a = getRand(); // kick-start the random numbers
    int correct_answer = ceil(a * 32); //the ceiling function ensures we get an integer
    guess(correct_answer);
}