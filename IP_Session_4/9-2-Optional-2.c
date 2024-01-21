/*
    This program converts the total time in seconds since the Unix Epoch (January 1, 1970) into a human-readable format (year, day, hour, minute). 
    The algorithm works as follows:
    1. The total time is divided into separate components (year, day, hour, minute) using modular arithmetic.
    2. Leap years are accounted for in the calculation of the year and day.
    3. The time is then printed in a human-readable format.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// The functions 'isLeap' take the input of the number of year
// then calculate it, and finally return the answer whether the year
// input is a leap year.
bool isLeap(int year) {
    return (!(year%400))||((year%100)&&!(year%4));
}

// The function `time2YearDay` converts the total time in seconds (represented by `Time_total`) 
// into the corresponding year and day. The results are stored in `year_output` and `day_output` respectively.
// It starts from the year 1970 and adds or subtracts years based on whether `Time_total` is positive or negative.
// The function takes into account leap years when calculating the total time.
void time2YearDay(time_t Time_total, int* year_output, int* day_output) {
    int Year = 1970; int secondPerYear[2] = {365*24*60*60,366*24*60*60};
    if (Time_total>=0) while (Time_total>=secondPerYear[isLeap(Year)])
        Time_total -= secondPerYear[isLeap(Year++)];
    else while (Time_total<0)
        Time_total += secondPerYear[isLeap(--Year)];
    *year_output = Year;
    *day_output = Time_total%secondPerYear[isLeap(Year)]/(24*60*60);
}

// This function converts total time into hours and minutes.
// Actually it's too easy to explain the process it does.
void time2HourMinute(time_t Time_total, int* hour, int* minute) {
    Time_total %= 24*60*60; if (Time_total<0) Time_total += 24*60*60;
    time_t Minutes_total = Time_total/60;
    *hour = Minutes_total / 60;
    *minute = Minutes_total % 60;
}

// This function prints the time in the format: year-month-day hour:minute.
/*
    The printTime function takes the current year, day of the year, hour, and minute as inputs and prints 
    the time in a human-readable format. Here's how it works:

    It first defines a 2D array Month that stores the number of days in each month for both non-leap years 
    (first row) and leap years (second row).

    It then determines whether the current year is a leap year or not. A year is a leap year if it is 
    divisible by 4 but not by 100, or if it is divisible by 400.

    The function then iterates through the months of the year, subtracting the number of days in each month 
    from the current day of the year until the day of the year is less than the number of days in the current 
    month. This determines the current month and the day of the month.

    Finally, the function prints the time in the format: year-month-day hour:minute. The month and day are 
    incremented by 1 because they are 0-indexed, but in the Gregorian calendar, months and days are 1-indexed.
*/
void printTime(int year, int day, int hour, int minute) {
    const static int Month[2][12] = {
        {31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31},
    };
    int month=0;
    while (day >= Month[isLeap(year)][month])
        day -= Month[isLeap(year)][month++];
    month++; day++;
    printf("Here's the time: (UTC+8) %d-%d-%d %02d:%02d",year,month,day,hour,minute);
}

/*---------------------The Main Function ---------------------*/
int main(void) {
    int year, day, hour, minute;

    /*----------------The Test Cases Start----------------*/
        // time_t Time_total = time(NULL) + 8*60*60;
        time_t Time_total = 951780000 + 8*60*60;
        // time_t Time_total = -1;
        // time_t Time_total = -24*60*60;
    /*---------------- The Test Cases End ----------------*/

    time2HourMinute(Time_total,&hour,&minute);
    time2YearDay(Time_total,&year,&day);
    printTime(year,day,hour,minute);
}
