/*
    This program is designed to implement the encoding process of combining two char values into one
    int value and performing the different-or operation according to the topic conditions, as well as
    the corresponding decoding operation.
*/

#include <stdio.h>  // Include the standard I/O Library

int char2int(char c1, char c2) {
    /*--------------------choice 1--------------------*/
    //  0 1 1 0 1 0 0 1 0 1 1 0 1 0 0 2
    //  |-----------------------------|
    //   (int*)&a
    //  |-------------| |-------------|       <= What I get from testing here is that the memory bits are
    //   (char*)&a+1      (char*)&a              sorted from lowest to highest, so this is the order

    // int a;
    // *((char*)&a) = c2;
    // *((char*)&a + 1) = c1;
    // return a;

    /*--------------------choice 2--------------------*/
    //  0 1 1 0 1 0 0 1 0 1 1 0 1 0 0 2
    //  |-----------------------------|
    //   return value (int)
    //  |-------------| |-------------|       <= What I get from testing here is that the memory bits are
    //   value of c1      value of c2            sorted from lowest to highest, so this is the order

    return (c1<<8) + c2;
}

void int2char(int input, char *c1, char *c2) {
    /*--------------------choice 1--------------------*/
    // The decoding process is the same as in choice 1 above.

    char *ptr = (char*)&input;
    *c1 = ptr[1];
    *c2 = ptr[0];

    /*--------------------choice 2--------------------*/

    // *c1 = (char)(input>>8); // Shift bits 9-16 of the int value to bits 1-8 to decode out c1
    // *c2 = (char)(input);    // Forced type conversion will directly intercept the last eight bits, so decode c2
}

int main(void) {    
    // Sample given in the Handbook
    int input[20] = {
        15643,  6913,   6916,   23040,
        2377,   6985,   6408,   3657,
        5638,   3084,   2119,   15910,
        23079,  13629,  23101,  10300,
        10557,  23073,  13092,  23369
    };
    // Part 1 : The value 31337 is used to perform a different-or operation on all the data,
    //          and the result is stored as a new array
    for (int i=0; i<20; i++)
        input[i] ^= 31337;
        /*
            The Explaination of this statement :
            The operation of dissimilarity has a special property - if a number is dissimilar to another number twice,
            then the result is the number itself.
            We can use this property to decode the different-or operation.
        */
    // Part 2 : Used the function defined to turn the int value into char values.
    //          I use the string output[41] to store it, then add a '\0' at the end
    //          to ensure the string have an end.
    char output[41];
    for (int i=0; i<20; i++)
        int2char(input[i],&output[2*i],&output[2*i+1]);
    output[40] = '\0'; // Add a void character on the end of the char array to make it a string
    printf("%s\n",output);
}