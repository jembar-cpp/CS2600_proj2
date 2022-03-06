/** main.c
 * CS 2600 Project 2 (Group) - Travel Expenses
 * 
 * OUTLINE:
 * Proposed structure
 * 
 * main.c: accepts input, calls functions from other files, prints output
 * 
 * travelTime.c: asks for and returns:
 *  - the number of days spent on the trip
 *  - the departure time on the first day
 *  - the arrival time on the last day
 * 
 * vehicleExpenses.c: asks for and returns:
 *  - total amount spent on round-trip airfare
 *  - total amount of any car rentals
 *  - miles driven in a private vehicle (returns amount: miles * $0.27)
 *  - parking fees
 *  - taxi expenses
 * 
 * miscExpenses.c: asks for and returns:
 *  - conference or seminar registration fees
 *  - total hotel expenses
 * 
 * mealExpenses.c: asks for, calculates expenses for, and returns:
 *  - amount for each allowable meal eaten (program only asks for allowable meals):
 *    - a meal is "allowable" only during the trip, such that:
 *      - first day: breakfast allowed if time of departure is before 7AM
 *      - first day: lunch allowed if time of departure is before 12PM (noon)
 *      - first day: dinner allowed if time of departure is before 6PM
 *      - last day: breakfast allowed if time of arrival is after 8AM
 *      - last day: lunch allowed if time of arrival is after 1PM
 *      - last day: dinner allowed if time of arrival is after 7PM
 *  - calculate the excess expenses which must be paid:
 *    - company allows $9 for breakfast, $12 for lunch, and $16 for dinner
 *    - returned values should be the total expenses, allowable expenses, and excess expenses
 * 
 * Input validation:
 *  - No negative numbers
 *  - Number of days need to be 1 or greater
 *  - Times for departure and arrival must be valid
 * 
 * TODO: Functions in the files should return total expenses and allowable expenses for everything
 */
#include "travelTime.h"
#include "mealExpenses.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    // TODO
    return 0;
}