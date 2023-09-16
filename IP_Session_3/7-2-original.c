/*
To Write the fucking comments!



The Answer of the Question "What happens when NUM=50 and why" :
    
*/

#include <stdio.h>
#define NUM 50

int main(void) {
    unsigned long long fib[NUM];
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