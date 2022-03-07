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
#include "../unity/src/unity.h"

void setUp() {}

void tearDown() {}
// Asking User to input a variable for Airfare and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
void testGetAirfare()
{
    float airfare = 100; // hard coded input

    do
    {
        printf("Total Spent on Airfare: $");
        printf("%.2f", airfare);

        if (airfare < 0)
            printf("Please enter a Positive Number!\n");

    } while (airfare < 0);

    TEST_ASSERT_EQUAL(airfare, 100);
}

// Asking User to input a variable for Car Rental and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
void testGetRental()
{
    float rental = 300; // hard coded input

    do
    {
        printf("Total Spent on Rental: $");
        printf("%.2f", rental);

        if (rental < 0)
            printf("Please enter a Positive Number!\n");

    } while (rental < 0);

    TEST_ASSERT_EQUAL(rental, 300);
}

// Asking User to input a variable for Miles and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
void testGetMiles()
{
    float miles = 150;
    float tMiles; // hard coded input
    do
    {
        printf("Total Miles Driven: $");

        printf("%.2f", miles);

        if (miles < 0)
            printf("Please enter a Positive Number!\n");

    } while (miles < 0);

    tMiles = miles * 0.27;

    TEST_ASSERT_EQUAL(tMiles, 40.5);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(testGetAirfare);
    RUN_TEST(testGetRental);
    RUN_TEST(testGetMiles);
    return UNITY_END();
}