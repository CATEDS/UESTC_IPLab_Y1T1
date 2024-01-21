/*
    @file   2-3-1.c
    @brief  Write a program to calculate the volume and weight of a box
            with the height of 4, length of 5 and width of 6.
            The weight of the box is calculated by the volume divided by 1.5.
            Print the height, length, width, volume and weight of the box.
*/

#include <stdio.h>                                          // Include the standard I/O library

int main(void) {                                            // Define the main function
    int height = 4, length = 5, width = 6;                  // Init the default data of the box
    int volume = height * length * width;                   // Calculate the volume of the box
    int weight = volume / 1.5;                              // Calculate the weight of the box
    printf("The height of the box: %d\n", height);          // Print the height of the box
    printf("The length of the box: %d\n", length);          // Print the length of the box
    printf("The width of the box: %d\n", width);            // Print the width of the box
    printf("The volume of the box: %d\n", volume);          // Print the volume of the box
    printf("Total Weight: %d\n", height);                   // Print the total weight of the box
    return 0;                                               // Exit the main() function
}
