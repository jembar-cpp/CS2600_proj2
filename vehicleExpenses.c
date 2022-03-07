/**
 * @file VehicleExpenses.c
 * @author Conner Ramirez
 *
 *  * vehicleExpenses.c: asks for and returns:
 *  - total amount spent on round-trip airfare
 *  - total amount of any car rentals
 *  - miles driven in a private vehicle (returns amount: miles * $0.27)
 *  - parking fees
 *  - taxi expenses
 */

#include <stdio.h>
#include "vehicleExpenses.h"

// Asking User to input a variable for Airfare and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
float getAirfare(float airfare)
{
    do
    {
        printf("Total Spent on Airfare: $");
        scanf("%f", &airfare);

        if (airfare < 0)
            printf("Please enter a Positive Number!\n");

    } while (airfare < 0);

    return airfare;
}

// Asking User to input a variable for Car Rental and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
float getRental(float rental)
{
    do
    {
        printf("Total Spent on Rental: $");
        scanf("%f", &rental);

        if (rental < 0)
            printf("Please enter a Positive Number!\n");

    } while (rental < 0);

    return rental;
}

// Asking User to input a variable for Miles and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
float getMiles(float miles, float tMiles)
{
    do
    {
        printf("Total Miles Driven: $");
        scanf("%f", &miles);

        if (miles < 0)
            printf("Please enter a Positive Number!\n");

    } while (miles < 0);
    {
        tMiles = miles * 0.27;
    }
    return tMiles;
}

// Asking User to input a variable for Parking Fees and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
float getFees(float totalFeeCost, float days)
{

    do
    {
        printf("Total Spent on Parking: $");
        scanf("%f", &totalFeeCost);

        if (totalFeeCost < 0)
            printf("Please enter a Positive Number!\n");

    } while (totalFeeCost < 0);

    do
    {
        printf("Total Days on Parking:");
        scanf("%f", &days);

        if (days < 0)
            printf("Please enter a Positive Number!\n");

    } while (days < 0);

    //  allowed = days * 6;
    //  owed = total - (6 * days);

    return totalFeeCost;
}

// Asking User to input a variable for Taxi and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
void getTaxi(float *totalTaxiCost, float *totalTaxiAllowed)
{
    float tTotal, tOwed, days, tAllowed;

    do
    {
        printf("Total Spent on Taxi: $");
        scanf("%f", &tTotal);

        if (tTotal < 0)
            printf("Please enter a Positive Number!\n");

    } while (tTotal < 0);

    do
    {
        printf("Total Days Taxi was used:");
        scanf("%f", &days);

        if (days < 0)
            printf("Please enter a Positive Number!\n");

    } while (days < 0);

    tAllowed = days * 10;

    *totalTaxiAllowed = tAllowed;
    *totalTaxiCost = tTotal;
}
