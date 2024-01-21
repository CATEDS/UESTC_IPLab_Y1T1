/*
    This program converts the total time in seconds since the Unix Epoch (January 1, 1970) into a human-readable format (year, day, hour, minute). 
    The algorithm works as follows:
    1. The total time is divided into separate components (year, day, hour, minute) using modular arithmetic.
    2. Leap years are accounted for in the calculation of the year and day.
    3. The time is then printed in a human-readable format.
*/

/*--------------------The Include Part--------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// This function converts total time into year and day.
/*
    The `time2YearDay` function converts the total time since Unix Epoch (January 1, 1970)
    into the current year and day of the year. 

    It calculates the total days since Epoch, adjusts for the difference between Epoch and
    2001, and then calculates the number of 400-year, 100-year, 4-year, and 1-year periods
    that have passed. 

    If the total days is negative (time before 2001), it subtracts 400-year periods until
    the total is non-negative. 

    The current year is calculated by adding 2001 to the number of passed periods. 

    The current day of the year is calculated by taking the remainder of the total days 
    divided by 365, and adding 1 (as day numbers start from 1).
*/
void time2YearDay(time_t Time_total, int* year, int* day) {
    time_t Days_total = Time_total/(60*60*24) - (23*365+8*366);
    if (Time_total<0 && Time_total%(24*60*60)) Days_total--;
    int Year_400=0, Year_100, Year_4, Year_1;
    if (Days_total>=0) { 
        Year_400 = Days_total/(303*365+97*366); Days_total %= (303*365+97*366);
    }
    else do {
        Year_400--; Days_total += 303*365+97*366;
    } while (Days_total<0);
    Year_100 = Days_total/(76*365+24*366); Days_total %= (76*365+24*366);
    Year_4 = Days_total/(3*365+366); Days_total %= (3*365+366);
    Year_1 = Days_total/365;
    *year = 2001 + Year_400*400 + Year_100*100 + Year_4*4 + Year_1;
    *day = Days_total%365;
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
    int month=0; bool isLeap = (year%400==0)||((year%4==0)&&(year%100!=0));
    while (day >= Month[isLeap][month])
        day -= Month[isLeap][month++];
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
