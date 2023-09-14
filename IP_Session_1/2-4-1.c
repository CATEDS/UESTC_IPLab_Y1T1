#include <stdio.h>  // Include the standard I/O library
#include <math.h>   // Include the math library

float my_exp_x(float x) {  // Define a custom function to calculate the expression
    return 1+(float)x+x*x/2+(float)x*x*x/6+(float)x*x*x*x/24;   // Calculate the value of the return value
}

int main(void) {    // Define the main function
    int x = 1;  // Init the default value of x input
    printf("%f", my_exp_x(x)); // Use the exp_x() to calculate the value of the expression and print it to the screen
    return 0;   // Exit the main() program
}