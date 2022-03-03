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