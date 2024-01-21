/*
    @file   2-5.c
    @brief  Write a program to calculate the value of the expression:
            a/b
            where a = 6, b = 7
*/

#include <stdio.h>                      // Include the standard I/O library

int main(void) {                        // define the main() function
    int a =6, b =7;                     // Init the default value of the variables
    float c = (float)a/b;               // Init the default value of x input
    printf("a:%d\nb:%d\nc:%f\n",a,b,c); // Print the value of the variables on the screen
    return 0;                           // Exit the main() function
}