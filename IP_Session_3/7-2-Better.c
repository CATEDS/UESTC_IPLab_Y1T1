/*
To Write the fucking comments!
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int NUM;
    printf("Please enter the num you want to count: __\b\b");
    scanf("%d", &NUM);
    unsigned long long *fib = malloc(NUM * sizeof(unsigned long long));
    fib[0] = 0;
    fib[1] = 1;
    for (int i=2; i<NUM; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("The Result is :\n");
    for (int i=0; i<NUM; i++) {
        printf("No.%2d : %d\n", i+1, fib[i]);
    }

    return 0;
}