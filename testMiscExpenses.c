/*
 * Unit Testing file for 'miscExpenses.c'
 */

#include <stdio.h>
#include "unity/src/unity.h"

void setUp() {}
void tearDown() {}

void testHotelFees()
{
    float hotelFee = 50;

    TEST_ASSERT_EQUAL(testCost, 50);
}

void testSemFee()
{
    float semFee = 150; 

    TEST_ASSERT_EQUAL(semFee, 150);
}

