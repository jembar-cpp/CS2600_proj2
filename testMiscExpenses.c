/*
 * Unit Testing file for 'miscExpenses.c'
 */

#include <stdio.h>
#include "unity/src/unity.h"

void setUp() {}
void tearDown() {}

void testHotelFees()
{

    // Declare variables needed
    float totalHotelCost, allowedHotelCost, testCost;
    float nights = 5;
    float hotelFee = 85.0;
    float allowedPerNight = 90;

    // Calculates costs of both allowed total and total businessperson spent
    totalHotelCost = hotelFee * nights;
    allowedHotelCost = allowedPerNight * nights;

    
    // Checks for hotelFee only, so rest of calcs are easier to check 
    if (hotelFee <= 89.99)
    {
        testCost = (allowedHotelCost - totalHotelCost);
    }
    else if (hotelFee >= 90.99)
    {
        testCost = (totalHotelCost - allowedHotelCost);
    }
    else
    {  
        testCost = 0;
    }

    TEST_ASSERT_EQUAL(testCost, 25);
}

void testSemFee()
{
    float semFee = 150.0; 
    TEST_ASSERT_EQUAL(semFee, 150);
}

