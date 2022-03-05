/**
 * @file mealExpenses.c
 * @author Jeremy Embar
 * 
 * Handles the meal expenses for the trip:
 *  - amount for each allowable meal eaten (only asks for allowable meals):
 *    - a meal is "allowable" only during the trip, such that:
 *      - first day: breakfast allowed if time of departure is before 7AM
 *      - first day: lunch allowed if time of departure is before 12PM (noon)
 *      - first day: dinner allowed if time of departure is before 6PM
 *      - last day: breakfast allowed if time of arrival is after 8AM
 *      - last day: lunch allowed if time of arrival is after 1PM
 *      - last day: dinner allowed if time of arrival is after 7PM
 *  - calculates the excess expenses which must be paid:
 *    - company allows $9 for breakfast, $12 for lunch, and $16 for dinner
 */
#include "mealExpenses.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Prompts the user and calculates meal costs.
 * Modifies two pointers to the total meal cost, and the allowable meal cost.
 * 
 * @param numDays: the number of days of the trip
 * @param departureTime: the departure time of the trip (24-hour format)
 * @param arrivalTime: the arrival time (24-hour format)
 * @param totalMealCost: the total meal cost, modified on return
 * @param allowableMealCost: the allowable meal cost, modified on return
 */
void calculateMealCosts(int numDays, int departureTime, int arrivalTime, int *totalMealCost, int *allowableMealCost) {
    int total = 0, allowable = 0, cost;

    for(int day = 1; day <= numDays; day++) { // loop through each day
        if(day == 1) { // check the first day
            if(departureTime < 700) { // breakfast is allowed
                cost = promptBreakfast(day);
                total += cost;
                allowable += (cost > 9) ? 9 : cost;
            }
            if(departureTime < 1200) { // lunch is allowed
                cost = promptLunch(day);
                total += cost;
                allowable += (cost > 12) ? 12 : cost;
            }
            if (departureTime < 1800) { // dinner is allowed
                cost = promptDinner(day);
                total += cost;
                allowable += (cost > 16) ? 16 : cost;
            }
        }
        else if(day != numDays) { // normal day, check all meals
            cost = promptBreakfast(day);
            total += cost;
            allowable += (cost > 9) ? 9 : cost;
            cost = promptLunch(day);
            total += cost;
            allowable += (cost > 12) ? 12 : cost;
            cost = promptDinner(day);
            total += cost;
            allowable += (cost > 16) ? 16 : cost;
        }
        else { // check the last day
            if(arrivalTime > 800) { // breakfast is allowed
                cost = promptBreakfast(day);
                total += cost;
                allowable += (cost > 9) ? 9 : cost;
            }
            if(arrivalTime > 1300) { // lunch is allowed
                cost = promptLunch(day);
                total += cost;
                allowable += (cost > 12) ? 12 : cost;
            }
            if (arrivalTime > 1900) { // dinner is allowed
                cost = promptDinner(day);
                total += cost;
                allowable += (cost > 16) ? 16 : cost;
            }
        }
    }

    // Update pointers
    *totalMealCost = total;
    *allowableMealCost = allowable;
}

/**
 * Prompts the user for a breakfast cost.
 * Cost cannot be negative.
 * 
 * @param day: the current day
 * @return the cost entered by the user
 */
int promptBreakfast(int day) {
    printf("Enter the breakfast cost for day %d: ", day);
    return promptCost();
}

/**
 * Prompts the user for a lunch cost.
 * Cost cannot be negative.
 * 
 * @param day: the current day
 * @return the cost entered by the user
 */
int promptLunch(int day) {
    printf("Enter the lunch cost for day %d: ", day);
    return promptCost();
}

/**
 * Prompts the user for a dinner cost.
 * Cost cannot be negative.
 * 
 * @param day: the current day
 * @return the cost entered by the user
 */
int promptDinner(int day) {
    printf("Enter the dinner cost for day %d: ", day);
    return promptCost();
}

/** 
 * Helper function for validating and returning user input.
 * 
 * @return the cost entered by the user
 */
int promptCost() {
    char input[20];
    char *ptr;
    int cost;
    while(1) { // loop until a valid number is entered
        fgets(input, 20, stdin); // get input from user
        fflush(stdin);
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') { // remove newline from input, if exists
            input[strlen(input) - 1] = '\0';
        }
        cost = strtol(input, &ptr, 10); // get numerical part, store rest in ptr

        if(ptr[0] == '$') { // user put a dollar sign
            cost = strtol(ptr + 1, &ptr, 10); // get the cost without the dollar sign
        }

        if(strcmp(ptr, "") == 0 && cost >= 0) { // input is valid, return it
            return cost;
        }
        printf("Invalid cost: please enter a valid cost.\nEnter the cost: ");
    }
}