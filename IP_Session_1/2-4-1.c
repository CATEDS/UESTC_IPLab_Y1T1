/*
    @file   2-4-1.c
    @brief  Write a program to calculate the value of the expression:
            1+x+x^2/2+x^3/6+x^4/24
            where x = 1
*/

#include <stdio.h>  // Include the standard I/O library
#include <math.h>   // Include the math library

// Define a custom function to calculate the expression
float my_exp_x(float x) {  
    // Calculate the value of the return value
    return 1+(float)x+x*x/2+(float)x*x*x/6+(float)x*x*x*x/24;   
}

int main(void) {                // Define the main function
    int x = 1;                  // Init the default value of x input
    printf("%f", my_exp_x(x));  // Use the exp_x() to calculate the value of the expression and print it to the screen
    return 0;                   // Exit the main() program
}