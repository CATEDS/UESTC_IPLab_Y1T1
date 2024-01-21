/*
    This program converts the total time in seconds since the Unix Epoch (January 1, 1970) into a human-readable format (year, day, hour, minute). 
    The algorithm works as follows:
    1. The total time is divided into separate components (year, day, hour, minute) using modular arithmetic.
    2. The time is then printed in a human-readable format.
*/

/*---------------------Including Part---------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*---------------------User Functions Part---------------------*/

// The Original form of the function which deals with the Year and Day.
// The Time_total input can only be positive. This will be improve in Optional Versions.
void time2YearDay(time_t Time_total, int* year, int* day) {
    time_t Days_total = Time_total/(60*60*24);
    *year = Days_total/365 + 1970;
    *day = Days_total%365 + 1;
}

// The Original form of the function which deals with the hour and minute
// The Time_total input can only be positive. This will be improve in Optional Versions.
void time2HourMinute(time_t Time_total, int* hour, int* minute) {
    time_t Minutes_total = Time_total/60%(24*60);
    *hour = Minutes_total / 60;
    *minute = Minutes_total % 60;
}

// The Original form of the function that output the time
void printTime(int year, int day, int hour, int minute) {
    printf("Here's the time: %4d day-%d %02d:%02d",year,day,hour,minute);
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