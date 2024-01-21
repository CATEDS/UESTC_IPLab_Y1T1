/*
    This function is designed to calculate the Fibonacci Numbers and store it
    in an array, then see what would happen if n=10, n=20 or n=50.

    The Answer of the Question "What happens when NUM=50 and why" :
        The value of No.48 is magically negative, but there can't be negative integer
        in the Fibonacci Numbers. That means something wrong with the program.
        Actually, this is because the value of the 48th number in Fibonacci Numbers
        is more than the maximun of long long type. So there is an Buffer Overflow
        happend when the program is running.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // The First Part: Get the value of num from the input
    int num;
    printf("Please enter the num you want to count: __\b\b");
    scanf("%d", &num);

    // The Second Part: Calculate the Fibonacci numbers to the num
    long long *fib = malloc(num * sizeof(long long));
    /*
        This statement use the malloc() function to request memory dynamically.
    */
    fib[0] = 0;
    fib[1] = 1;
    for (int i=2; i<num; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // The Third Part: Output the result of the Fibonacci numbers
    printf("The Result is :\n");
    for (int i=0; i<num; i++) {
        printf("No.%2d : %-15d ", i+1, fib[i]);
        if (i%2)
            putchar('\n');  // Print a new line every two numbers
    }

    // Finally, do NOT forget to free the block of memory from malloc() :)
    free(fib);
    return 0;   // The program ends here
}