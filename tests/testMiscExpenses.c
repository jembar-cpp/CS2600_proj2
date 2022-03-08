/*
 * Unit Testing file for 'miscExpenses.c'
 */

#include "../unity/src/unity.h"
#include "../miscExpenses.h"

void setUp() {}

void tearDown() {}

void testGetHotelExpenses() {
    freopen("./tests/inputs/hotelFee.txt", "r", stdin); // change standard input method
    float hotelExpenses = getHotelExpenses();
    TEST_ASSERT_EQUAL(hotelExpenses, 50);
}

void testGetSemFee() {
    freopen("./tests/inputs/seminarFee.txt", "r", stdin);
    float semFee = getSemFee();
    TEST_ASSERT_EQUAL(semFee, 150);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(testGetHotelExpenses);
    RUN_TEST(testGetSemFee);
    return UNITY_END();
}