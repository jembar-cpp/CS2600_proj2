#include "unity/src/unity.h"
#include "travelTime.h"

void setUp() {}

void tearDown() {}

void testGetNumDays() {
    freopen("test_travelTime_input/numDays.txt", "r", stdin); // change standard input method
    int numDays = getNumDays();
    TEST_ASSERT_EQUAL(numDays, 5);
}

void testGetDepartureTime() {
    freopen("test_travelTime_input/departureTime.txt", "r", stdin);
    int departureTime = getDepartureTime();
    TEST_ASSERT_EQUAL(departureTime, 1130);
}

void testGetArrivalTime() {
    freopen("test_travelTime_input/arrivalTime.txt", "r", stdin);
    int arrivalTime = getArrivalTime(1130, 3);
    TEST_ASSERT_EQUAL(arrivalTime, 1400);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(testGetNumDays);
    RUN_TEST(testGetDepartureTime);
    RUN_TEST(testGetArrivalTime);
    return UNITY_END();
}