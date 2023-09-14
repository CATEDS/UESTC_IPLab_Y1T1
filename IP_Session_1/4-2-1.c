#include <stdio.h>  // Include the standard I/O library

double Ohm_Law(int Volt, double R) { return (float)Volt*1000/R; }   // Define the Ohm_Law() function
double series(double R1, double R2) { return R1+R2; }   // Define the series() function
double parallel(double R1, double R2) { return 1/(1/R1+1/R2); } // Define the parallel() function
double parallel_three(double R1, double R2, double R3) { return 1/(1/R1+1/R2+1/R3); }   // Define the parallel_three() function

int main(void) {    // Define the main() function
    int r1 = 100,   // Init the default resistance data
        r2 = 200,
        r3 = 300,
        r4 = 400,
        r5 = 500,
        r6 = 600,
        r7 = 700;
    int Voltage = 12;   // Init the default voltage data
    double total_R = parallel_three(series(r1,r2),parallel(r3,r4),series(r5,parallel(r6,r7)));  // Calculate the total Resistance
    double electricCurrent = Ohm_Law(Voltage, total_R); // Calculate the Electric Current
    printf("Answer: %.1f mA\n",electricCurrent);    // Print the answer on screen
    return 0;   // Exit the main() function
}