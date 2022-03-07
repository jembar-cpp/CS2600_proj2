/** main.c
 * CS 2600 Project 2 (Group) - Travel Expenses
 * 
 * OUTLINE:
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
 * Allowed expenses:
 *  - Parking: $6 / day
 *  - Taxi fees: $10 / day for each day a taxi was used
 *  - Lodging: $90 / day
 *  - Allowable meals: breakfast / lunch / dinner, $9 / $12, $16
 * 
 * Assuming allowed costs are compounded:
 *  - Static allowed cost: $96 / day
 *  - Taxi / meals: only when applicable 
 */
#include "travelTime.h"
#include "mealExpenses.h"

#include <stdio.h>
#include <stdlib.h>

// Calls all the functions to calculate total expenses
int main() {
    // Variable definitions
    const int ALLOWED_COST_PER_DAY = 96;

    float totalCost = 0;
    float allowedCost = 0;
    float totalMealCost = 0;
    float allowedMealCost = 0;
    // other variable definitions...
    
    // TODO: functions should be called in this order
    int numDays = getNumDays();
    allowedCost += numDays * ALLOWED_COST_PER_DAY; // set static allowed cost based on number of days
    int departureTime = getDepartureTime();
    int arrivalTime = getArrivalTime(departureTime, numDays);
    // get amount of any round-trip airfare
    // get amount of any car rentals
    // get amount of miles driven in private vehicle
    // get parking fees
    // get taxi fees
    // get conference and seminar registration fees
    // get hotel expenses
    calculateMealCosts(numDays,departureTime,arrivalTime,&totalMealCost,&allowedMealCost);
    totalCost += totalMealCost;
    allowedCost += allowedMealCost;
    printf("%f, %f", totalMealCost, allowedMealCost);
    // Print the results

    return 0;
}