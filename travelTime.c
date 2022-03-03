/**
 * @file travelTime.c
 * @author Jeremy Embar
 * 
 * Handles the travel time for the trip:
 *  - the number of days spent on the trip
 *  - the departure time on the first day
 *  - the arrival time on the last day
 */
#include "travelTime.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Returns the number of days for the trip.
 * Prompts the user for the number of days spent on the trip.
 * If the user enters an invalid input, the user is prompted again.
 * 
 * @return int: the number of days
 */

int getNumDays() {
    char input[20];
    char *ptr;
    int num;
    
    while(1) { // loop until user enters a valid input
        printf("Enter the number of days: ");
        fgets(input, 20, stdin); // get input from user
        fflush(stdin);
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') { // remove newline from input, if exists
            input[strlen(input) - 1] = '\0';
        }
        num = strtol(input, &ptr, 10); // convert input to integer, store string part in ptr

        if(strcmp(ptr, "") != 0 || num < 1 || num >= INT_MAX) { // guess wasn't numeric or less than 1 - invalid input
                printf("Invalid input: please enter a valid number of days greater than 0.\n");
                continue;
        }
        break;
    }
    return num;
}

/**
 * Returns the departure time for the trip.
 * Time is in 24-hour format. Examples of valid input: "7:30", "15:00"
 * Returns an integer representing the 24-hour time. Examples: "730", "1500"
 * If the user enters an invalid input, the user is prompted again.
 * 
 * @return int: the departure time
 */
int getDepartureTime() {
    char input[20];
    char *ptr;
    int hours, minutes;
    
    while(1) { // loop until user enters a valid input
        printf("Enter the departure time (24-hour format): ");
        fgets(input, 20, stdin); // get input from user
        fflush(stdin);
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') { // remove newline from input, if exists
            input[strlen(input) - 1] = '\0';
        }
        hours = strtol(input, &ptr, 10); // get hour part, store rest in ptr

        if(ptr[0] == ':') { // check it's a valid time
            minutes = strtol(ptr + 1, &ptr, 10); // get minutes part
            if(hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59) { // times are within range
                return hours*100 + minutes;
            }
        }
        // Input was invlid
        printf("Invalid input: please enter a valid 24-hour time (7:30, 15:00)\n");
    }
}

/**
 * Returns the arrival time for the trip.
 * Time is in 24-hour format. Examples of valid input: "7:30", "15:00"
 * Returns an integer representing the 24-hour time. Examples: "730", "1500"
 * Makes sure that the total time of the trip isn't negative:
 *  - If the number of days of the trip is 1, the arrival time cannot be before the departue time.
 * If the user enters an invalid input, the user is prompted again.
 * 
 * @param departureTime: the departure time of the trip
 * @param numDays: the number of days of the trip
 * @return int: the arrival time
 */
int getArrivalTime(int departureTime, int numDays) {
    char input[20];
    char *ptr;
    int hours, minutes;
    
    while(1) { // loop until user enters a valid input
        printf("Enter the arrival time (24-hour format): ");
        fgets(input, 20, stdin); // get input from user
        fflush(stdin);
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') { // remove newline from input, if exists
            input[strlen(input) - 1] = '\0';
        }
        hours = strtol(input, &ptr, 10); // get hour part, store rest in ptr

        if(ptr[0] == ':') { // check it's a valid time
            minutes = strtol(ptr + 1, &ptr, 10); // get minutes part
            if(hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59) { // times are within range
                int arrivalTime = hours*100 + minutes;
                if(numDays == 1 && arrivalTime <= departureTime) {
                    printf("Invalid input: the total time of the trip cannot be negative.\n");
                    continue;
                }
                return arrivalTime;
            }
        }
        // Input was invlid
        printf("Invalid input: please enter a valid 24-hour time (7:30, 15:00)\n");
    }
}