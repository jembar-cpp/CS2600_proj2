/** main.c
 * CS 2600 Project 2 (Group) - Travel Expenses
 * 
 * Calculates and displays the total travel expenses of a businessperson on a trip.
 * 
 * File structure:
 * 
 * travelTime.c: asks for and returns:
 *  - the number of days spent on the trip
 *  - the departure time on the first day
 *  - the arrival time on the last day
 * 
 * vehicleExpenses.c: asks for and returns:
 *  - total amount spent on round-trip airfare
 *  - total amount of any car rentals
 *  - miles driven in a private vehicle
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
 */
#include "mealExpenses.h"
#include "miscExpenses.h"
#include "travelTime.h"
#include "vehicleExpenses.h"

#include <stdio.h>
#include <stdlib.h>

// Calls all the functions to calculate total expenses
int main() {
    // Variable definitions
    const int ALLOWED_COST_PER_DAY = 96;
    float totalCost = 0;
    float allowedCost = 0;
    float totalPtr, allowedPtr;
    
    // Get details of trip length and allowance of businessperson
    int numDays = getNumDays();
    allowedCost += numDays * ALLOWED_COST_PER_DAY; // set static allowed cost based on number of days
    int departureTime = getDepartureTime();
    int arrivalTime = getArrivalTime(departureTime, numDays);

    // Get vehicle expenses
    totalCost += getAirfare();
    totalCost += getCarRental();
    totalCost += getMiles();
    totalCost += getParkingFees();
    getTaxi(&totalPtr, &allowedPtr);
    totalCost += totalPtr;
    allowedCost += allowedPtr;

    // Get miscellaneous expenses
    totalCost += getHotelExpenses() * numDays;
    totalCost += getSemFee();
    
    // Get meal costs
    calculateMealCosts(numDays,departureTime,arrivalTime,&totalPtr,&allowedPtr);
    totalCost += totalPtr;
    allowedCost += allowedPtr;
    
    // Print the results
    float excess = _abs64(allowedCost - totalCost);
    printf("\nTotal expenses for the trip: %.2f\n", totalCost);
    printf("Total allowable expenses: %.2f\n", allowedCost);
    if(totalCost < allowedCost) { // person didn't go over allowed total
        printf("Within company-allowed total. Amount saved: %.2f\n", excess);
    }
    else { // person went over - needs to reimburse company
        printf("Amount needing to be reimbursed: %.2f\n", excess);
    }
    return 0;
}