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
#include "unity/src/unity.h"
#include "vehicleExpenses.h"

void setUp() {}

void tearDown() {}
// Asking User to input a variable for Airfare and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
void testGetAirfare(float airfare)
{
    do
    {
        printf("Total Spent on Airfare: $");
        float airfare = 100; // hard coded input
        printf("%.2f", airfare);

        if (airfare < 0)
            printf("Please enter a Positive Number!\n");

    } while (airfare < 0);

    TEST_ASSERT_EQUAL(airfare, 100);
}

// Asking User to input a variable for Car Rental and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
void testGetRental(float rental)
{
    do
    {
        printf("Total Spent on Rental: $");
        float rental = 100; // hard coded input
        printf("%.2f", rental);

        if (rental < 0)
            printf("Please enter a Positive Number!\n");

    } while (rental < 0);

    TEST_ASSERT_EQUAL(rental, 300);
}

// Asking User to input a variable for Miles and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
void testGetMiles(float miles, float tMiles)
{
    do
    {
        printf("Total Miles Driven: $");
        float miles = 150; // hard coded input
        printf("%.2f", miles);

        if (miles < 0)
            printf("Please enter a Positive Number!\n");

    } while (miles < 0);
    {
        tMiles = miles * 0.27;
    }
    TEST_ASSERT_EQUAL(tMiles, 40.5);
}

/* // Asking User to input a variable for Parking Fees and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
void getFees(float *totalFeeCost, float *owedFeeCost, float *totalFeeAllowed)
{
    float total, owed, days, allowed;

    do
    {
        printf("Total Spent on Parking: $");
        scanf("%f", &total);

        if (total < 0)
            printf("Please enter a Positive Number!\n");

    } while (total < 0);

    do
    {
        printf("Total Days on Parking:");
        scanf("%f", &days);

        if (days < 0)
            printf("Please enter a Positive Number!\n");

    } while (days < 0);

    allowed = days * 6;
    owed = total - (6 * days);

    *totalFeeAllowed = allowed;
    *totalFeeCost = total;
    *owedFeeCost = owed;
}

// Asking User to input a variable for Taxi and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
void getTaxi(float *totalTaxiCost, float *owedTaxiCost, float *totalTaxiAllowed)
{
    float tTotal, tOwed, days, tAllowed;

    do
    {
        printf("Total Spent on Parking: $");
        scanf("%f", &tTotal);

        if (tTotal < 0)
            printf("Please enter a Positive Number!\n");

    } while (tTotal < 0);

    do
    {
        printf("Total Days on Parking:");
        scanf("%f", &days);

        if (days < 0)
            printf("Please enter a Positive Number!\n");

    } while (days < 0);

    tAllowed = days * 10;
    tOwed = tTotal - (10 * days);

    *totalTaxiAllowed = tAllowed;
    *totalTaxiCost = tTotal;
    *owedTaxiCost = tOwed;
} */
int main()
{
    UNITY_BEGIN();
    RUN_TEST(testGetAirfare);
    RUN_TEST(testGetRental);
    RUN_TEST(testGetMiles);
    return UNITY_END();
}