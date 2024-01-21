/*
    @file   3-2.c
    @brief  Write a program to calculate the tax of a person's income.
            The tax rate is as follows:
            Personal Allowance: £12,500
            Starter Rate: £12,501 - £14,585 19%
            Basic Rate: £14,586 - £25,158 20%
            Intermediate Rate: £25,159 - £43,430 21%
            Higher Rate: £43,431 - £150,000 41%
            Top Rate: Over £150,000 46%
            Print the take-home salary and the total tax paid.
*/

#include <stdio.h>                      // Include the standard I/O library

double calculateTax(int salary) {       // Define the tax calculate function
    if (salary<=12500)                  // Under Personal Allowance
        return 0;
    else if (salary<=14585)             // Achieve Starter rate
        return (salary-12500)*0.19;
    else if (salary<=25158)             // Achieve Basic rate
        return (salary-14585)*0.2+(14585-12500)*0.19;
    else if (salary<=43430)             // Achieve Intermediate rate
        return (salary-25158)*0.21+(25158-14585)*0.2+(14585-12500)*0.19;
    else if (salary<=150000)            // Achieve Higher rate
        return (salary-43430)*0.41+(43430-25158)*0.21+(25158-14585)*0.2+(14585-12500)*0.19;
    else                                // Achieve Top rate
        return (salary-150000)*0.46+(150000-43430)*0.41+(43430-25158)*0.21+(25158-14585)*0.2+(14585-12500)*0.19;
}

int main(void) {                                    // define the main() function
    int Income;                                     // Init the integer variable "Income"
    printf("Enter Gross Income in £: ");            // Print the line to get the income
    scanf("%d",&Income);                            // Get the income from standard input
    double Tax = calculateTax(Income);              // Calculate the Tax
    printf("Your Take-Home salary is: £%.2f\n",Income-Tax); // Print the Take-Home salary
    printf("The total tax paid is: £%.2f\n",Tax);   // Print the total tax
    return 0;                                       // Exit the main() function
}

/*
    Actually there are something wrong with the output.
    Because of the difference of the alphabet sets of the terminal and the editor,
    the sign of european pound is not displayed correctly.
*/