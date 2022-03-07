/*
 * Unit Testing file for 'miscExpenses.c'
 */

#include <stdio.h>
#include "unity/src/unity.h"

void setUp() {}
void tearDown() {}
void main(){}
void testHotelFees()
{

    // Declare variables needed
    float totalSaved, totalExcess, totalHotelCost, allowedHotelCost, testCost;
    float nights = 5;
    float hotelFee = 85.0;
    float semFee = 150.0; 
    float allowedPerNight = 90;

    // Asks user for input of hotel fee per night, and total amount of nights at hotel
    printf("Enter the hotel fee per night: $");
    printf("%.2f", hotelFee);
    printf("Enter total nights at hotel: ");
    printf("%.2f", nights);
    printf("Enter total of seminar/conference fees: $");
    printf("%,2f", semFee);

    // Calculates costs of both allowed total and total businessperson spent
    totalHotelCost = hotelFee * nights;
    allowedHotelCost = allowedPerNight * nights;

    
    // Checks for hotelFee only, so rest of calcs are easier to check 
    if (hotelFee <= 89.99)
    {
        testCost = allowedHotelCost - totalHotelCost;
        printf("total cost is less than allowed, so we saved: $%.2f\n", testCost);
    }
    else if (hotelFee >= 90.99)
    {
        testCost = totalHotelCost - allowedHotelCost;
        printf("total cost is more than allowed, so we over spent: $%.2f\n", (totalHotelCost - allowedHotelCost));
    }
    else
    {  
        testCost = 0.0;
        printf("The company gave you the exact amount you needed! (for hotels): $%.2f\n", testCost);
    }

    TEST_ASSERT_EQUAL(testCost, 25);
}
void testSeminarFee()
{
    float semFee = 150.0;
    printf("Enter total of seminar/conference fees: $");
    printf("%.2f", semFee);

    TEST_ASSERT_EQUAL_(150, semFee);
}
