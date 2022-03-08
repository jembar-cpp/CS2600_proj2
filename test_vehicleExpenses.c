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

void setUp() {}

void tearDown() {}
// Asking User to input a variable for Airfare and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
/*void testGetAirfare()
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
}*/

 // Asking User to input a variable for Parking Fees and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
void testerGetFees()
{
    float total= 100; //hardcoded
    float owed;
    float days= 5;  //hardcoded
    float allowed;

    do
    {
        printf("Total Spent on Parking: $");

        printf("%.2f", total);

        if (total < 0)
            printf("Please enter a Positive Number!\n");

    } while (total < 0);

    do
    {
        printf("Total Days on Parking:");
    
        printf("%.2f", days);

        if (days < 0)
            printf("Please enter a Positive Number!\n");

    } while (days < 0);

    allowed = days * 6;
    owed = total - (6 * days);


TEST_ASSERT_EQUAL(allowed, 30);
TEST_ASSERT_EQUAL(owed, 70);

}



// Asking User to input a variable for Taxi and if that vairbale is negative it will ask again
// for a postive number using Do/While and If Statements
void testGetTaxi()
{
    float tTotal=500;//hardcoded
    float tOwed; 
    float days=4; //hardcoded
    float tAllowed;

    do
    {
        printf("Total Spent on Taxi: $");
         printf("%.2f", tTotal);

        if (tTotal < 0)
            printf("Please enter a Positive Number!\n");

    } while (tTotal < 0);

    do
    {
        printf("Total Days Taxi was used:");
         printf("%.2f", days);

        if (days < 0)
            printf("Please enter a Positive Number!\n");

    } while (days < 0);

    tAllowed = days * 10;
    tOwed = tTotal - (10 * days);


    TEST_ASSERT_EQUAL(tAllowed, 40);
    TEST_ASSERT_EQUAL(tOwed, 460);
}
int main()
{
    UNITY_BEGIN();
    //RUN_TEST(testGetAirfare);
    //RUN_TEST(testGetRental);
    //RUN_TEST(testGetMiles);
    RUN_TEST(testerGetFees);
    RUN_TEST(testGetTaxi);
    return UNITY_END();
}